# Bring the drinks! – Ein kulinarischer Einstieg zu Smart Pointern

In diesem Übungsbeispiel soll eine Studierendengruppe in einem Restaurant simuliert werden.

## Lernziele

Ziel dieses Übungsbeispiels ist es, den Umgang mit Smart Pointern zu üben und selbstständig mögliche Anwendungsfälle zu erkennen.

## Anleitung

### Wie soll das ganze aussehen?

*"Exemplarische Darstellung einer achtköpfigen hungrigen und durstigen Studierendengruppe an einem Tisch"* - (ca. 2019 AD), Quelle: *unbekannt*:

```
M M M M
o o o o
O   O 
o o o o
W W W W
```

Hierbei stellen `'M'` und `'W'` die Studierenden auf ihren Sitzplätzen dar. Ihre Getränke werden durch `'o'` dargestellt und jeweils zwei gegenübersitzende Studierende teilen sich eine Speise `'O'` in der Mitte des Tisches.

### Grundsätzlicher Ablauf und Befehle

Zu Beginn befinden sich noch keine Gäste, Getränke oder Speisen auf dem Tisch. Der Tisch wird also nur durch Leerzeichen an allen freien Plätzen dargestellt. (Folgendes Feld mit dem Mauszeiger markieren, um Leerzeichen anzuzeigen)

```
       
       
       
       
       
```

#### Befehl `sit`

Mithilfe des `sit` Befehls kann man nun die\*den ersten Studierende\*n am gewünschten Platz positionieren. Alle Befehle, die sich auf Sitzplätze beziehen, sind im linken oberen Eck startend im Uhrzeigersinn von 0 bis 7 durchnummeriert.

```
> sit 1
  M    
       
       
       
       
```

#### Befehl `order`

Mithilfe des `order` Befehls kann nun ein Getränk mit einer bestimmten Füllmenge (in Litern) bestellt werden. Dieses wird unmittelbar serviert.

Format des Befehls: <br>
`> order <guest_index> <liters>`

```
> order 1 0.5
  M    
  o    
       
       
       
```

#### Befehl `leave`

Verlässt die*der Studierende die Feier mithilfe des `leave` Befehls, so wird ihr\*sein Getränk umgehend abserviert.

Format des Befehls: <br>
`> leave <guest_index>`

```
> leave 1
       
       
       
       
       
```

Nehmen wir nun folgenden Ausgangszustand an: Unser\*e Studierende\*r sitzt wieder auf Platz 1 mit einem Getränk vor sich:

```
  M    
  o    
       
       
       
```

#### Befehl `food`

Mithilfe des `food` Befehls bestellt sie\*er nun Essen. Der Teller steht in der Mitte des Tisches. Würde die\*der Studierende nun mithilfe des `leave` Befehls den Tisch verlassen, würde sowohl der Teller, als auch das Getränk umgehend abserviert werden.

```
> food 1
  M    
  o    
  O    
       
       
```

Nun setzt sich aber ein weiterer Gast auf den Platz gegenüber. Dieser *teilt* sein Essen mit der\*dem gegenübersitzenden Studierenden.

```
> sit 6
  M    
  o    
  O    
       
  W    
```

Verlässt die*der Studierende auf Platz 1 nun den Tisch, so wird der Teller **nicht** abserviert, da es mit Studierender\*m 6 geteilt wird. Das Getränk von Studierender\*m 1 wird jedoch abserviert.

```
> leave 1
       
       
  O    
       
  W    
```

Verlässt die\*der Studierende 6 nun auch ihren\*seinen Platz, so wird der Teller abserviert.

```
> leave 6
       
       
       
       
       
```

### Weitere Befehle

#### Befehl `pass`

Jeder Gast gibt ihr\*sein Getränk im Uhrzeigersinn an die\*den nächste\*n weiter. Dies entspricht zwar vielleicht nicht den aktuellen Hygieneempfehlungen, stellt jedoch eine perfekte Übungsmöglichkeit dar. ;)

```
M M   M
o     o
    O  
    o  
  W W  
> pass
M M   M
  o    
    O  
  o o  
  W W  
```

#### Befehl `drink`

Jeder Gast mit einem Getränk vor sich nimmt einen 0.1 l Schluck. (Also der Füllstand aller Gläser wird um 0.1 l verringert) Sollte ein Glas danach einen Füllstand < 0 l haben, so wird das Glas sofort abserviert.

#### Befehl `eat`

Jeder Gast mit einem Teller vor sich nimmt einen Bissen der 50% des auf dem Teller vorhandenen Essens beträgt. Bedienen sich nun beispielsweise 2 Gäste von einem vollen Teller, so lässt sich der prozentuelle Essensrest mit $`1 *0.5* 0.5 = 0.25 \widehat{=}  25\%`$ berechnen. Ist ein Teller zu weniger als 10% gefüllt, so wird es umgehend abserviert.

#### Befehl `quit`

Wird der Befehl `quit` eingegeben, so wird das Programm umgehend beendet.

### Behandlung von Eingabefehlern

Die Behandlung von Eingabefehlern ist weder vorgeschrieben, noch zu implementieren und wird in den Testcases nicht getestet. Eine zusätzliche Implementierung kann jedoch nach eigenem Ermessen erfolgen. Die Musterlösung hält sich bei der Fehlerbehandlung auch bewusst stark zurück, um den Fokus nicht von den eigentlichen Lernzielen abzuwenden.

## Sinnvolle Lösung des Beispiels und Implementierungshinweise

Um den größten Lerneffekt zu erzielen, sollte das Beispiel objektorientiert und unter zuhilfenahme von Smart Pointern umgesetzt werden. Die Musterlösung (zu finden unter `solution/`) sollte möglichst erst **nach** einem vollständigen Implementierungsversuch durchgegangen werden.

Für deine Lösung kannst du die Datei `drinks.cpp` nutzen. Hier findest du ein Grundgerüst für einen schnelleren Start. Neben dem vorgegebenen Code findest du darin auch TODO-Kommentare. Der Einfachheit halber kannst du deine gesamte Lösung in diesem Übungsbeispiel in diese Datei schreiben. Natürlich kannst du dich aber auch gegen die Verwendung von `drinks.cpp` entscheiden und deine Lösung auch von Grund auf selbst schreiben.

### Aufteilung in Klassen

Folgende Fragestellungen sollten beantwortet werden, um Klassen für das Beispiel zu finden:

- Welche *unterschiedlichen Objekte* existieren? (z.B.: Glas)
- Welche *Eigenschaften* weisen diese auf? (z.B.: Füllstand in Litern)
- Welche *Aktionen* können von diesen ausgeführt werden? (z.B.: Ein\*e Studierende\*r kann trinken)

### Verwendung von Smart Pointern

Folgende Fragestellungen sollten beantwortet werden, um festzustellen ob ein Smart Pointer für ein jeweiliges Objekt verwendet werden soll, und wenn ja, welcher Typ Anwendung finden sollte.

- Ist das Objekt statisch oder dynamisch? (z. B.: Kann es den Tisch betreten/verlassen? Wenn ja: Smart Pointer)
- Was/wer *besitzt* das Objekt? (z. B.: Ein\*e Studierende*r kann ein Glas besitzen.)
- Wird das Objekt zwischen mehreren Besitzern *geteilt*, oder kann es *ausschließlich einen* Besitzer geben? (Shared Pointer vs. Unique Pointer)
