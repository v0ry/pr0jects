# A3 : ESP-Scrabble

<span style="color:red">
Achtung: Dies ist ein Assignment aus dem *Wintersemester 2020*, welches nun als freiwilliges Übungsbeispiel implementiert werden kann. Die Assignments des aktuellen Semesters sind auf Gitlab in eigenen Repositories zu finden.
</span>
<p>

## Lernziele

Das Arbeiten mit dynamischem Speicher, `enum`s, `struct`s, File I/O und Command Line Arguments.

Lines of Code des Musterlösung: 1012

**Achtung:** Für einen Buchstabenstein – also die Verknüpfung eines Buchstabens mit seinem Wert – ist ein `struct` zu verwenden. Spielfeld und Liste der Buchstabensteine müssen am Heap angelegt werden. Es soll dabei nicht mehr Speicher angefordert werden als notwendig ist. *(Zumindest im WS21 war dies so gefordert.)*

## Beschreibung
ESP-Scrabble ist eine Abwandlung des Spiels Scrabble. In der ESP-Version bilden zwei Spieler\*innen aus einer Liste von Buchstabensteinen Wörter auf einem Spielfeld und versuchen damit, einen höheren Punktestand als die\*der Gegenspieler\*in zu erzielen.

## Dateiformat
Die Konfigurationsdatei verwendet ein Textformat. Es kann davon ausgegangen
werden, dass die Datei korrekt formatiert ist, wenn sie mit der korrekten
[Magic-Number](https://de.wikipedia.org/wiki/Magische_Zahl_(Informatik)) beginnt.
Die Reihenfolge der einzelnen Teile der Konfigurationsdatei wird durch folgende Tabelle spezifiziert:

| Inhalt der Konfigurationsdatei                                          |
| ----------------------------------------------------------------------- |
| *Magic-Number* (Muss der ASCII-Text "Scrabble" sein)                    |
| Spielfeld (Quadrat aus den Zeichen `'A'`-`'Z'` und `' '`)                 |
| Spieler\*in 1 oder 2 an der Reihe (`'1'`: Spieler\*in 1, `'2'`: Spieler\*in 2)  |
| Spielstand Spieler\*in 1 (Zahl in Dezimalschreibweise)                          |
| Spielstand Spieler\*in 2 (Zahl in Dezimalschreibweise)                          |
| Auflistung verwendbarer Buchstabensteine (Details unter [Buchstabenstein](#buchstabenstein))|

Die einzelnen Teile der Konfigurationsdatei sind jeweils durch `'\n'` getrennt. Die Auflistung aller verwendbaren Buchstabensteine befindet sich in einer Zeile. Dabei wird ein Buchstabenstein durch einen Buchstaben und eine Ziffer (größer gleich 1 und kleiner gleich 9) repräsentiert, also zum Beispiel `'C1'`. Zwischen den Angaben zu einzelnen Buchstabensteinen befindet sich immer ein Leerzeichen. Ein Beispiel für eine gültige Konfigurationsdatei ist [config.txt](./config.txt).

## Buchstabensteine
| Erforderliche Membervariablen eines Buchstabensteins. (Weitere Membervariablen sind erlaubt.) |
| ------------------------------ |
| Buchstabe (a-z, ohne Umlaute)  |
| Wert des Buchstabenstein (1-9) |

Ein Buchstabenstein wird durch einen Buchstaben und eine Ziffer beschrieben. Diese Ziffer bestimmt, wie viele Punkte Spieler\*innen bekommen, wenn sie diesen Buchstabenstein auf das Spielfeld legen. In der Konfigurationsdatei sind die erlaubten Buchstaben mit ihrem Wert aufgelistet. Im Programm soll ein Buchstabenstein durch ein `struct` dargestellt werden.

Jeder Buchstabenstein in der Konfigurationsdatei kann während des Spiels **beliebig oft** eingesetzt werden.



## Spielfeld
Die Größe und der Inhalt des Spielfeldes sind anhand der Konfigurationsdatei ersichtlich. In ESP-Scrabble ist das Spielfeld immer quadratisch, wobei die kleinstmögliche Größe 4x4 und die größtmögliche Größe 26x26 Felder beträgt. Ein Feld wird in der Konfigurationsdatei mithilfe eines ASCII-Characters dargestellt. `'A'`–`'Z'` stellen dabei die von den Spieler\*innen eingesetzten Buchstaben dar.

> **Wichtig**: Das Spielfeld **muss** bei der Implementierung am Heap gespeichert werden!

### Leeres Beispielspielfeld
Folgendes Beispiel zeigt die Ausgabe eines 15x15 Felder großen, leeren Spielfeldes. Dabei sind die Zeilen- und Spaltenbezeichnungen, sowie die Trennlinien nicht in der Konfigurationsdatei enthalten.

Die Buchstaben, welche die Koordinaten bilden, müssen der Reihenfolge des Alphabets folgen und lassen sich somit berechnen. Bei einem 26x26 Felder großen Spielfeld stellen daher A-Z die Koordinaten dar; bei einem 5x5 Spielfeld wären A-E die Koordinaten.


```
 |ABCDEFGHIJKLMNO
-----------------
A|               
B|               
C|               
D|               
E|               
F|               
G|               
H|               
I|               
J|               
K|               
L|               
M|               
N|               
O|               
```

## Programmablauf

### Spielstart

Das Programm wird mit einem Kommandozeilenparameter aufgerufen. Dieser gibt den
Pfad zur Konfigurationsdatei an, die geladen werden soll. Sollte das Programm

- mit mehr oder weniger Parametern aufgerufen werden oder
- die Konfigurationsdatei nicht geöffnet werden können oder
- die Konfigurationsdatei nicht mit der korrekten *Magic-Number* beginnen,

soll die entsprechende Fehlermeldung ausgegeben werden und das Programm mit dem
entsprechenden Rückgabewert beendet werden (siehe 
[Programm-Rückgabewerte und Fehlermeldungen](#programm-rückgabewerte-und-fehlermeldungen)).

Anschließend beginnt die\*der in der Konfigurationsdatei genannte Spieler\*in mit dem ersten Spielzug.

### Spielablauf

Zu Beginn jedes Spielzugs wird das Spielfeld mit Zusatzinformationen (Punktestand, verfügbare Buchstabensteine) ausgegeben. (siehe [Beispielausgabe](#beispielausgabe))

Anschließend wird die Befehlszeile mit der Spielernummer (1 oder 2) ausgegeben:

```lang-none
Player 1 > 
```

Danach wird auf eine Benutzereingabe gewartet.

Wird nichts (Enter) oder nur *Whitespace* eingegeben, soll die Befehlszeile erneut
ausgegeben werden sowie auf eine neue Benutzereingabe gewartet werden.

Wird ein unbekannter Befehl oder ein bekannter Befehl mit falschen oder ungültigen Parametern
eingegeben, soll die entsprechende Fehlermeldung (siehe 
[Programm-Rückgabewerte und Fehlermeldungen](#programm-rückgabewerte-und-fehlermeldungen))
ausgegeben werden und die Befehlszeile erneut ausgegeben werden sowie auf
eine neue Benutzereingabe gewartet werden.

#### Befehl `quit`:

Der Befehl `quit` (alternativ *EOF*, ausgelöst durch z. B. `Ctrl-D`) beendet das
Programm.

#### Befehl `help`:
Der Befehl `help` gibt folgenden Hilfetext aus:

```lang-none
Commands:
 - insert <ROW> <COLUMN> <H/V> <WORD>
    <H/V> stands for H: horizontal, V: vertical.

 - help
    Prints this help text.

 - quit
    Terminates the game.

 - save
    Saves the game to the current config file.

 - load <CONFIGFILE>
    load config file and start game.\n
```

Dabei repräsentiert das `\n` am Ende der Ausgabe einen Zeilenumbruch. Nach diesem wird die Befehlszeile erneut ausgegeben.

#### Befehl `insert`:

Mithilfe des `insert`-Befehls kann ein Wort in das Spielfeld eingefügt werden. Dabei werden die Zeile und die Spalte des ersten Buchstabens sowie die Richtung (horizontal/vertikal) und das einzufügende Wort als Parameter angegeben. Um das Wort zu bilden, werden die in der Konfigurationsdatei definierten Buchstabensteine und etwaige bereits am Spielfeld liegende Buchstabensteine verwendet.

Die 4 Parameter lauten wie folgt:
 - ROW: Die Zeilenbezeichnung, an der das Wort beginnen soll (Aa-Zz).
 - COLUMN: Die Spaltenbezeichnung, an der das Wort beginnen soll (Aa-Zz).
 - H/V: Die Orientierung in der das Wort eingefügt wird
    - Entweder `H` bzw. `h` für horizontal (von links nach rechts)
    - Oder `V` bzw. `v` für vertikal (von oben nach unten).
 - WORD: Das einzufügende Wort.

Die Groß-/Kleinschreibung soll für alle Parameter des `insert`-Befehls ignoriert werden; das heißt die Eingabe erfolgt case-insensitive. Auf dem Spielfeld wird jedes Wort in Großbuchstaben dargestellt.

Wurde das Wort erfolgreich eingefügt, so wird die Punktewertung ausgelöst:
Zum Spielstand der aktiven Spielerin bzw. des aktiven Spielers wird die Summe der durch die **neu** gelegten Buchstabensteine erreichten Punkte hinzuaddiert.

Der `insert`-Befehl beendet einen Spielzug, wenn kein Fehler auftritt. Dann beginnt der nächste Spielzug, in welchem die/der nächste Spieler\*in an der Reihe ist (siehe [Spielablauf](#spielablauf)).

##### `insert` Befehle mit falschen Parametern:

 Wenn mindestens einer der Parameter ROW, COLUMN und H/V nicht valide ist, wird die entsprechende Fehlermeldung laut [Programm-Rückgabewerte und Fehlermeldungen](#programm-rückgabewerte-und-fehlermeldungen) ausgegeben.

##### Unmögliche Züge:
Bei unmöglichen Spielzügen wird die Fehlermeldung `Error: Impossible move!\n` laut [Programm-Rückgabewerte und Fehlermeldungen](#programm-rückgabewerte-und-fehlermeldungen) ausgegeben. Unmögliche Spielzüge verstoßen gegen mindestens eine der folgenden Bedingungen:


 - Das Wort muss am Spielfeld Platz haben.

 - Das Wort darf nur Buchstaben von A-Z (a-z) beinhalten.

 - Die für die Bildung des Wortes nötigen Buchstaben müssen in der Liste erlaubter Buchstaben vorhanden sein (siehe Konfigurationsdatei).

 - Ein neu hinzugefügtes Wort muss mit mindestens einem Wort, das bereits auf dem Spielfeld liegt, verbunden sein (Ausnahme: Erster Spielzug). Zwei Wörter sind verbunden, wenn sie sich zumindest einen Buchstabenstein teilen.

 - Das neue Wort darf mit bestehenden Wörtern zu keinem Widerspruch führen. Das heißt, dass das Hinlegen eines Wortes keine bereits ausgelegten Buchstaben mit anderen Buchstaben überschreiben darf.

 >Hinweis: Wenn ein bestehendes Wort an der exakt gleichen Stelle noch einmal eingefügt wird, handelt es sich um einen gültigen Zug, der aber keine Punkte bringt, da keine neuen Buchstaben eingefügt wurden.

 >Hinweis: Wenn das Spielfeld in einem Config-File bereits ausgelegte Wörter enthält, so müssen diese _nicht_ verbunden sein. Sie können annehmen, dass in solchen Config-Files zumindest ein\*e Spieler\*in bereits Punkte hat. Da bereits ein\*e Spieler\*in über Punkte verfügt, gilt der erste Zug als vergangen. Somit müssen in diesem Fall _alle_ neu hinzugefügten Wörter – also auch das erste nach dem Laden der Config-Datei – mit (zumindest) einem bestehenden Wort verbunden sein.
 
##### Beispiel für einen gültigen Zug

Im ersten Zug wurde das Wort PLAY auf das Spielfeld gelegt und in diesem Beispiel sind auch die Buchstaben E und S erlaubt.

```
 |ABCDEF
--------
A|      
B|      
C|      
D| PLAY 
E|      
F|      
```
PLAY kann im zweiten Zug mit `insert B B V esp` um das Wort ESP erweitert werden:
```
 |ABCDEF
--------
A|      
B| E    
C| S    
D| PLAY 
E|      
F|      
```
 Das Einfügen ist in diesem Fall erlaubt, weil sich das neue Wort ESP einen Buchstaben (`'P'`) mit dem bereits gelegten Wort PLAY teilt. Für diesen Zug erhält die\*der ziehende Spieler\*in Punkte für die Buchstaben `'E'` und `'S'`. Der letzte Buchstabe des Wortes ESP liefert keine Punkte, weil er bereits auf dem Spielfeld lag.

>Hinweis: Da für diese Scrabble-Version keine Verknüpfung mit einem Wörterbuch besteht, überprüft das Programm nicht, ob das eingegebene Wort existiert.


#### Befehl `save`:
Der `save`-Befehl speichert den Spielstand in der Konfigurationsdatei, von der das Spiel geladen wurde. Dadurch wird das Spielfeld, die\*der als nächste ziehende Spieler\*in sowie die Spielstände überschrieben. Die Liste der verfügbaren Buchstabensteine bleibt gleich.

Kann die Datei nicht geschrieben werden, so wird die Fehlermeldung in [Programm-Rückgabewerte und Fehlermeldungen](#programm-rückgabewerte-und-fehlermeldungen) ausgegeben.

Nach Ende des Befehls wird die Befehlszeile erneut ausgegeben.

### Spielende
Das Spiel wird beendet, sobald ein\*e Spieler\*in einen bestimmten Punktestand erreicht. Der Punktestand für die Siegesbedingung wird folgendermaßen berechnet: (Länge x Breite des Spielfeldes) / 2.
Etwaige Nachkommastellen werden abgeschnitten. Bei einem 9x9 Spielfeld gewinnt somit der\*die Spieler\*in, welche\*r zuerst mindestens 40 Punkte erreicht.


Gewinnt ein\*e Spieler\*in, so wird folgende Nachricht ausgegeben:
```
Player <player_num> has won the game with <score> points!\n
```

Dabei ist der Platzhalter `<player_num>` durch die Nummer der\*des Siegerin\*Siegers und `<score>` durch ihre\*seine Punkte zu ersetzen. Danach wird das Programm beendet.


>Hinweis: Der Fall in welchem alle Felder besetzt werden, ohne dass es eine\*n Gewinner\*in gibt, wird nicht getestet.


## Programm-Rückgabewerte und Fehlermeldungen
Das Programm soll im Verlauf des Spiels auf Fehler mit entsprechenden Fehlermeldungen reagieren. Manche Fehler führen sogar zum Ende des Programms mit einem bestimmten Rückgabewert. Alle Fehler inklusive der entsprechenden Fehlermeldungen und etwaiger Rückgabewerte des Programms sind der folgenden Tabelle zu entnehmen. Aus dieser geht auch hervor, dass das Programm beendet werden soll, wenn nicht genügend Speicher zur Verfügung steht. Daher ist beim Reservieren von Speicher auf dem Heap auch immer zu prüfen, ob das Reservieren erfolgreich war.

| Wert | Fehlermeldung                              | Bedeutung                                                      |
| ---- | ------------------------------------------ | -------------------------------------------------------------- |
| 0    |                                            | Erfolgsfall                                                    |
| 1    | `Usage: ./a3 configfile\n`                 | Falsche Anzahl von Kommandozeilenparametern                    |
| 2    | `Error: Cannot open file: <CONFIG_FILE>\n` | Konfigurationsdatei kann nicht geöffnet werden                 |
| 3    | `Error: Invalid file: <CONFIG_FILE>\n`     | Konfigurationsdatei beginnt nicht mit korrekter *Magic-Number* |
| 4    | `Error: Out of memory\n`                   | Kein Speicher kann mehr angefordert werden                     |
|      | `Error: Unknown command: <COMMAND>\n`      | Unbekannter Befehl eingegeben                                  |
|      | `Error: Insert parameters not valid!\n` | `insert` Befehl mit falschen Parametern / Parameteranzahl|
|      | `Error: Impossible move!\n` | Ungültiger `insert` Befehl (für die unter [Unmögliche Züge](#unmögliche-züge) angeführten Fälle)|
|      | `Error: Could not save to file!\n`| Fehler beim Speichern |

> Hinweis: Bei `<COMMAND>` wird die gesamte Eingabe in gleicher Form wieder ausgegeben.  Bei `<CONFIG_FILE>` wird der Dateiname bzw. Kommandozeilenparameter wieder ausgegeben.

## Beispielausgabe

```

A1, B1, D2, E1, F2, I1, K2, L2, Q3, 
S2, T2, U1
  P1:    0 Points
  P2:    7 Points
 |ABCDEFGHIJKLMNO
-----------------
A|               
B|               
C|               
D|               
E|               
F|               
G|    S          
H|    A          
I|    L          
J|    T          
K|               
L|               
M|               
N|               
O|               

Player 1 > insert G C H test

A1, B1, D2, E1, F2, I1, K2, L2, Q3, 
S2, T2, U1
  P1:    5 Points
  P2:    7 Points
 |ABCDEFGHIJKLMNO
-----------------
A|               
B|               
C|               
D|               
E|               
F|               
G|  TEST         
H|    A          
I|    L          
J|    T          
K|               
L|               
M|               
N|               
O|               

Player 2 > insert g c v TELEGRAM
Error: Impossible move!
Player 2 > insert g c v TALL

A1, B1, D2, E1, F2, I1, K2, L2, Q3, 
S2, T2, U1
  P1:    5 Points
  P2:   12 Points
 |ABCDEFGHIJKLMNO
-----------------
A|               
B|               
C|               
D|               
E|               
F|               
G|  TEST         
H|  A A          
I|  L L          
J|  L T          
K|               
L|               
M|               
N|               
O|               

Player 1 > 

```

Die verfügbaren Buchstabensteine werden in der Reihenfolge ausgegeben, in der sie auch in der Konfigurationsdatei angegeben sind. Pro Zeile werden dabei bis zu neun Buchstabensteine ausgegeben, wobei der entsprechende Buchstabe groß geschrieben ist. (Beachten Sie die leere Zeile vor Ausgabe der Liste und das Leerzeichen nach den Kommas!)

### Wertung

In diesem Beispiel wurden für die Buchstaben T und S der Wert 2 und für E der Wert 1 angenommen. Die Werte der einzelnen Buchstabensteine werden aus der Konfigurationsdatei eingelesen. S war schon gelegt; daher ist das Wort TEST in obigem Beispiel
```
2(T) + 1(E) + 2(T) = 5
```
Punkte wert.

## Framework
Ein Framework zum Einlesen der Befehle wird in [framework.h](./framework.h) bereitgestellt. Dieses Framework beinhaltet die Funktion `parseCommand`, die eine Kommandozeileneingabe in eine Datenstruktur vom Typ `Input` (auch in [framework.h](./framework.h) definiert) umwandelt. Der Rückgabewert von `parseCommand` liefert somit nützliche Informationen über die Eingabe eines Befehls. Weitere Informationen hierzu sind der Datei [framework.h](./framework.h) zu entnehmen.

>**Hinweis:** Im Falle des `insert`-Kommandos kann Heap-Speicher alloziert werden. Dieser muss vom Benutzer der Funktion wieder freigegeben werden!


## Bonus - Befehl `load`

Um Bonuspunkte zu bekommen, kann zusätzlich der Befehl `load` implementiert werden.

Der `load`-Befehl lädt eine Konfigurationsdatei wie beim Spielstart. Dafür wird ein Parameter verwendet, der den Pfad zur zu ladenden Konfigurationsdatei angibt. Etwaige Änderungen am derzeitigen Spiel werden *nicht* automatisch gespeichert.

Beim `load`-Befehl kann es zu Fehlermeldungen sowie zum Beenden des Programms kommen. Das Verhalten im Falle eines Fehlers soll jenem zum Start des Programms entsprechen.

Nach dem erfolgreichen Laden wird mit der neuen Konfiguration weitergespielt. (Dadurch kann es zum Beispiel vorkommen, dass auf einem Spielfeld weitergespielt wird, dass eine andere Größe besitzt als das bisherige Spielfeld. Außerdem ist es möglich, dass in der neu geladenen Konfigurationsdatei andere Buchchstabensteine zur Verfügung stehen.)

>Hinweis: Achten Sie auch hier besonders auf den richtigen Umgang mit dem dynamischen Speicher.

### Bonus und Framework
Sollte der [Bonus](#bonus-befehl-load) implementiert und das Framework genutzt werden, so muss der Bonus zuerst mithilfe eines `#define`s aktiviert werden.
Dazu muss `BONUS` **vor** dem `#include` des [framework.h](./framework.h)-Files definiert werden:
```diff
 ...
+#define BONUS
 #include "framework.h"
 ...
```

Das oben abgebildete `+` ist dabei nicht Teil des Codes sondern soll nur verdeutlichen, dass die entsprechende Zeile für den Bonus hinzugefügt werden muss.
