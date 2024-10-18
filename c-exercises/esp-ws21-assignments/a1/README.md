# Assignment 1 : Anordnung von Löschwasserpumpen

<span style="color:red">
Achtung: Dies ist ein Assignment aus dem *Wintersemester 2021*, welches nun als freiwilliges Übungsbeispiel implementiert werden kann. Die Assignments des aktuellen Semesters sind auf Gitlab in eigenen Repositories zu finden.
</span>
<p>

## Lernziel
Datentypen, Kontrollstrukturen, Ein-/Ausgabe, Funktionen, Konstanten

Lines of Code der Musterlösung: 145

## Aufgabenstellung
Es soll ein Programm geschrieben werden, welches die Anzahl der benötigten Pumpen sowie deren Positionen an einem Hang berechnet, sodass ein Zielpunkt mit ausreichend Löschwasser versorgt werden kann. Dabei wird der Hang vereinfacht als Gerade zwischen einem Start- und Zielpunkt angenommen. Die erste Pumpe (Pumpe0) steht immer an der Position (0, 0). 


### Eingabe des Durchflusses

Im ersten Schritt wird die/der Benutzer\*in zur Eingabe des benötigten Durchflusses aufgefordert. Dieser muss zwischen 100 und 1200 Litern liegen. Eine valide Eingabe ist deshalb eine Ganzzahl ≥ 100 und ≤ 1200. 

```
Erforderlicher Durchfluss [l/min]: <wert>
```
Dabei wird `<wert>` durch die (mit Enter abgeschlossene) Benutzereingabe ersetzt. Die spitzen Klammern sind *nicht* Teil der Benutzereingabe. Unsere [Beispielausgabe](#beispielausgabe) verdeutlicht, wie die Ausgabe auszusehen hat.

Sollte die Eingabe nicht valide sein, erscheint folgende Fehlermeldung:
```
Invalide Eingabe! Der Durchfluss muss mindestens 100 l/min und maximal 1200 l/min betragen.\n
```
Die hier abgebildeten Zeichen `\` und `n` sind nicht als einzelne Zeichen auszugeben, sondern sind als Newline-Character (`\n`) zu verstehen.

Nach der Fehlermeldung startet das Einlesen von vorne (so lange, bis die Eingabe valide ist).
(Tipp: Bei den Test Cases wird nur auf einzelne Ganzzahlen getestet. Sie müssen sich also keine Gedanken darüber machen, wie das Programm mit anderen Eingaben (z.B. Buchstaben) umgehen soll.)


### Eingabe des Zielpunktes
Der Zielpunkt ist durch die Koordinaten `(x, y)` definiert, wobei `x` den horizontalen und `y` den vertikalen Abstand zum Startpunkt angibt. Der Startpunkt hat daher stets die Koordinaten `(0, 0)`. Dabei ergibt sich ein rechtwinkeliges Dreieck mit `x` und `y` als Katheten. Die Hypotenuse des Dreiecks stellt den Hang dar, auf welchem die Löschwasserschläuche verlegt werden.

#### Horizontale Distanz
Zuerst soll die horizontale Distanz eingelesen werden.
```
Horizontale Distanz [m]: <wert>
```
Auch hier ist `<wert>` ein Platzhalter für die Benutzereingabe, welche eine positive Ganzzahl (größer als 0) sein muss. Bei Falscheingabe soll folgende Fehlermeldung ausgegeben werden:
```
Invalide Eingabe!\n
```
Auch für diesen Wert startet das Einlesen nach der Fehlermeldung  von vorne (so lange, bis die Eingabe valide ist).

#### Vertikale Distanz
Die vertikale Distanz soll nach nach dem gleichen Schema eingelesen werden.
```
Vertikale Distanz [m]: <wert>
```
Auch die Behandlung von Falscheingaben ist gleich wie im Fall der horizontalen Distanz (siehe auch [Beispielausgabe](#beispielausgabe)).

### Bestimmung des Reibungsverlustes in Schläuchen
Abhängig vom vorhandenen Durchfluss treten unterschiedliche Reibungsverluste auf. Der Verlustbeiwert ($`\lambda`$), welcher für die folgenden Berechnungen nötig ist, kann anhand folgender Tabelle bestimmt werden. 

Durchfluss [l/min] | Verlustbeiwert $`\lambda`$ zufolge Reibung [bar/m] |
------------------ | -------------------------------------------------- | 
≤ 200              | 0.001                                              |
201 - 400          | 0.0025                                             |
401 - 600          | 0.005                                              |
601 - 800          | 0.01                                               |
801 - 1000         | 0.015                                              |
1001 - 1200        | 0.025                                              |

### Berechnung der Hangneigung
Außerdem ist die Neigung des Hanges ($`\alpha`$) erforderlich. Diese soll in Radiant berechnet werden. Die benötigten Winkelfunktionen sind in der Standardbibliothek **math.h** zu finden.
```math
\begin{equation}
\alpha = \arctan (\frac{y}{x})
\end{equation}
```

### Berechnung des auftretenden Druckverlustes und der Pumpenanordnung
In diesem Beispiel wird ein **Pumpenausgangsdruck** von **10 bar** sowie ein notwendiger **Pumpeneingangsdruck** von **mindestens 1.5 bar** angenommen. Daher ist ein **Druckverlust** zwischen zwei Pumpen von maximal **8.5 bar** zulässig.
Ein bar entspricht einem Druck von 10m Wassersäule (vertikale Distanz), das heißt der **Druckverlust**(ohne Reibung) beträgt **0.1 bar/m**. Durch Pumpe0 herrscht am **Startpunkt** (0,&nbsp;0) ein Druck von **10 bar**.

Der Druck $`p`$ an einer bestimmten Stelle kann somit folgendermaßen bestimmt werden:
```math
\begin{equation}
p = 10 - (0.1 \cdot \Delta y + \lambda \cdot \frac{\Delta y}{\sin(\alpha)})
\end{equation}
```
Hierbei ist $`\Delta y`$ die Höhendifferenz zwischen einem gegebenen Punkt und der letzten Pumpe, welche sich vor dem gesuchten Punkt befindet.

Damit können wir den vertikalen Abstand zwischen der aktuell letzten Pumpe und der nächsten notwendigen Pumpe berechnen. Dazu setzen wir in obiger Gleichung $`p`$ auf den notwendigen Mindestdruck von 1.5 bar und erhalten:
```math
\begin{equation}
\Delta y = \frac{8.5}{0.1 + \frac{\lambda}{\sin(\alpha)}}
\end{equation}
```

Der horizontale Abstand ergibt sich dann aus dieser errechneten Höhendifferenz und der Neigung des Hanges $`\alpha`$:
```math
\begin{equation}
\Delta x = \frac{\Delta y}{\tan(\alpha)}
\end{equation}
```

Es werden so lang Pumpen eingefügt, bis am Zielpunkt ein Druck von mindestens 6 bar vorhanden ist. Die Pumpen sollen dabei jeweils in der berechneten Distanz gesetzt werden. Sollte diese Distanz das Ziel überschreiten, so soll die letzte Pumpe am Zielpunkt gesetzt werden. Dabei soll eine minimale Menge an Pumpen verwendet werden. Sobald am Ziel ein Druck von ≥ 6 bar erreicht wurde, dürfen also keine weiteren Pumpen mehr eingefügt werden.

Ein Beispiel für die Berechnung kann unter dem Punkt [Beispielberechnung](#beispielberechnung) gefunden werden.


### Ausgabe
Nachdem alle oben beschriebenen Eingaben getätigt wurden, gibt das Programm eine
Übersicht über die Berechnungen aus. Zuerst werden die Eingabewerte und die daraus berechneten Parameter ausgegeben.
```
\n
Ziel: (<x>, <y>)\n
Neigung [rad]: <wert_alpha>\n
Durchfluss [l/min]: <wert_d>\n
Reibungsbeiwert [bar/m]: <wert_lambda>\n
```
---
Danach werden die einzelnen Pumpen mit ihren Koordinaten ausgegeben (Pumpe0 bei (0, 0) wird nicht ausgegeben):
```
  Pumpe1: (<x_p1>, <y_p1>)\n
  Pumpe2: (<x_p1>, <y_p1>)\n
  ...
```
Sollte keine weitere Pumpe notwendig sein, soll anstatt der Liste der Pumpen folgende Zeile ausgegeben werden:
```
  Keine zusaetzliche Pumpe notwendig!\n
```
*Bitte beachten Sie jeweils die beiden Leerzeichen am Zeilenanfang!*

---
Zu guter Letzt soll auch der Austrittsdruck am Zielpunkt angegeben werden.
```
Austrittsdruck Zielpunkt [bar]: <wert_pZiel>\n
```
---
Die Platzhalter `<XX>` sind durch die entsprechenden Werte zu ersetzen. Beachten Sie bitte folgende Hinweise:
* Der Reibungsbeiwert (<wert_lambda>) sowie die Neigung (<wert_alpha>) sollen auf **4 Nachkommastellen** genau angezeigt werden.
* Die Koordinaten der Pumpen (<x_p>, <y_p>) sowie der Austrittsdruck (<wert_pZiel>) sollen jeweils auf **2 Nachkommastellen** genau angezeigt werden.
* Alle weiteren Werte sollen **ohne Nachkommastellen** angezeigt werden.


## Beispielberechnung
Gegeben ist der Durchfluss mit **1020** [l/min] und der Zielpunkt mit **(150, 100)**.
Zuerst werden der Reibungsbeiwert und die Neigung berechnet.
```math
\begin{equation}
\begin{aligned}
\lambda = 0.0250 \\
\alpha = \arctan (\frac{100}{150}) = 0.5880 \text{ [rad]}
\end{aligned}
\end{equation}
```
---
Danach folgt die Berechnung der ersten Pumpe:
```math
\begin{equation}
p_{\text{Ziel}} = 10 - (0.1 \cdot 100 + 0.0250 \cdot \frac{100}{\sin(0.5880)}) = -4.5069 < 6 \text{ [bar]}
\end{equation}
```
*=> Pumpe nötig*

```math
\begin{equation}
\begin{aligned}
\Delta y = \frac{8.5}{0.1 + \frac{0.0250}{\sin(0.5880)}} = 58.5926 \text{ [m]} \\
\Delta x = \frac{58.5926}{\tan(0.5880)} = 87.8890 \text{ [m]} \\
y_{P1} = 0 + 58.5926 = 58.5926 \text{ [m]} \\
x_{P1} = 0 + 87.8890 = 87.8890 \text{ [m]}
\end{aligned}
\end{equation}
```
**Pumpe 1 an (87.89, 58.59)**

---
Sowie die Berechnung der zweiten Pumpe:
```math
\begin{equation}
\begin{aligned}
y_{Neu} = y - y_{P1} = 100 - 58.5926 = 41.4074 \text{ [m]} \\
p_{\text{Ziel}} = 10 - (0.1 \cdot 41.4074 + 0.0250 \cdot \frac{41.4074}{\sin(0.5880)}) = 3.9931 < 6 \text{ [bar]}
\end{aligned}
\end{equation}
```
*=> weitere Pumpe nötig*

```math
\begin{equation}
\begin{aligned}
y_{P2} = y_{P1} + \Delta y = 58.5926 + 58.5926 = 117.1853 \text{ [m]} \\
y_{P2} > y \Rightarrow y_{P2} = y = 100 \text{ [m]}
\end{aligned}
\end{equation}
```
**Pumpe 2 am Zielpunkt (150.00, 100.00)**

---
Zu guter Letzt wird noch der Druck am Zielpunkt berechnet (hier eigentlich überflüssig, da Pumpe am Zielpunkt).
```math
\begin{equation}
\begin{aligned}
y_{Neu} = y - y_{P2} = 100 - 100 = 0.0000 \text{ [m]} \\
p_{\text{Ziel}} = 10 - (0.1 \cdot 0.0000 + 0.0250 \cdot \frac{0.0000}{\sin(0.5880)}) = 10 \text{ [bar]}
\end{aligned}
\end{equation}
```
**Austrittsdruck = 10 [bar]**

## Beispielausgabe
```
Erforderlicher Durchfluss [l/min]: 50000
Invalide Eingabe! Der Durchfluss muss mindestens 100 l/min und maximal 1200 l/min betragen.
Erforderlicher Durchfluss [l/min]: 300
Horizontale Distanz [m]: 250
Vertikale Distanz [m]: 0
Invalide Eingabe!
Vertikale Distanz [m]: 200

Ziel: (250, 200)
Neigung [rad]: 0.6747
Durchfluss [l/min]: 300
Reibungsbeiwert [bar/m]: 0.0025
  Pumpe1: (102.16, 81.73)
  Pumpe2: (204.32, 163.46)
Austrittsdruck Zielpunkt [bar]: 6.20
```
