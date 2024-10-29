# Hangman

Das Arbeiten mit eigenen Datentypen und Dateioperationen soll am Beispiel eines Hangman-Spiels geübt werden.

---

## Lernziel

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Arrays, Strings, Pointer
  - Dynamisches Speichermanagement
  - Structs
  - Files

Lines of Code der Musterlösung: 215 (einige Fehlerfälle werden nicht überprüft)

---

## Anleitung

Es ist ein Programm zu schreiben, welches Wortlisten aus einer Datei einliest. Diese Wortlisten bilden die Basis für mehrere Runden Hangman. In jeder Runde rät der Benutzer einzelne Buchstaben und muss auf diese Weise das gesuchte Wort innerhalb eines Limits von 11 Zügen erraten.

### Datenstruktur

Die Wortlisten und das Spielergebnis des Benutzers (die Anzahl der benötigten Rateversuche) sollen in einer einfach verketteten Liste gespeichert werden. Die Wörter sollen als dynamische C-Strings am Heap gespeichert werden.

### Dateiformat

Wortlisten werden in einer Textdatei gespeichert, wobei jeweils ein Wort in jeder einzelnen Zeile steht.

Einzelne Zeilen sind mit einem Zeilenumbruch (\n) abgeschlossen. Es dürfen zu Zeilenbeginn und Zeilenende beliebig viele Leerzeichen vorliegen, nicht jedoch innerhalb des Wortes. Wörter dürfen nur aus Zeichen des englischen Alphabets (A-Z und a-z) bestehen.

Sollte eine Zeile nicht den Anforderungen entsprechen, so ist die Vokabeldatei ungültig (siehe Fehlermeldungen).

### Funktionsweise

Das Programm wird mit einem Kommandozeilenparameter aufgerufen. Dieser gibt den Dateinamen der zu öffnenden Wortliste an. Sollte das Programm nicht auf diese Weise aufgerufen werden, so kommt es zu einer Fehlermeldung.

In jeder Runde gibt das Programm in einer Zeile den Anfangsbuchstaben des gesuchten Wortes und eine Anzahl an `'_'` gefolgt von `" ([guesses])"` aus, wobei die Anzahl der `'_'` der Anzahl der restlichen Buchstaben entspricht und [guesses] durch die Anzahl der bisherigen falschen Rateversuche für dieses Wort zu ersetzen ist.

In einer weiteren Zeile wird der Benutzer mit dem Text `"Your guess: "` zur Eingabe eines Zeichens aufgefordert.

Das Programm liest im Anschluss ein Zeichen vom Benutzer ein. Die Verarbeitung der Eingabe erfolgt case insensitive. Sollte das Zeichen im gesuchten Wort vorkommen, so wird es an allen zutreffenden Stellen "aufgedeckt" und das `'_'` wird für zukünftige Ausgaben durch das entsprechende Zeichen ersetzt. Sollte das Zeichen im gesuchten Wort nicht vorkommen so wird der Wert [guesses] um 1 erhöht.

Wenn der Wert [guesses] größer oder gleich 11 wird hat der Spieler diese Runde verloren. Es wird noch das gesuchte Wort gefolgt von `" (x_x)"` ausgegeben.

Wenn der Spieler alle Zeichen des Wortes erraten hat, so hat er diese Runde gewonnen. Es wird das gesuchte Wort gefolgt von `" ([guesses])"` ausgegeben, wobei [guesses] durch die Anzahl der falschen Rateversuche ersetzt wird.

Es wird insgesamt für jedes Wort der Wortliste eine Runde gespielt, wobei die Reihenfolge von der der eingelesenen Datei vorgegeben ist.

Im Anschluss an die letzte Runde wird der Text `"won ([correct]/[numtotal])"` ausgegeben, wobei [correct] durch die Anzahl der korrekt erratenen Wörter und [numtotal] durch die Gesamtanzahl der zu erratenden Wörter zu ersetzen ist.

### Beispiel

gültige Wortliste

```
Progpipe
      ESP
```

ungültige Wortliste

```
Progpipe ESP
```

Programmaufruf mit gültiger Wortliste und Userinput

```
$./main wortliste.txt
P_______ (0)
Your guess: R
Pr______ (0)
Your guess: o
Pro_____ (0)
Your guess: g
Prog____ (0)
Your guess: j
Prog____ (1)
Your guess: h
Prog____ (2)
Your guess: p
Progp_p_ (2)
Your guess: i
Progpip_ (2)
Your guess: e
Progpipe (2)
E__ (0)
Your guess: q
E__ (1)
Your guess: w
E__ (2)
Your guess: e
E__ (2)
Your guess: r
E__ (3)
Your guess: t
E__ (4)
Your guess: z
E__ (5)
Your guess: u
E__ (6)
Your guess: i
E__ (7)
Your guess: o
E__ (8)
Your guess: a
E__ (9)
Your guess: s
ES_ (9)
Your guess: d
ES_ (10)
Your guess: f
ESP (x_x)
won (1/2)
```
Zu beachten: Das "$" vor dem Programmaufruf stellt die Komandozeile des Terminals dar.

### Rückgabewerte

| Wert | Bedeutung   | Fehlermeldung   |
| :--: | ----------- | ----------- |
| 0    | Erfolgsfall | |
| 1    | falsche Anzahl an Kommandozeilenparameter | usage: [executable] filename\n |
| 2    | Wortdatei kann nicht geöffnet werden | ERROR: cannot open file [filename]\n |
| 3    | Wortdatei ungültig | ERROR: file [filename] invalid\n |
| 4    | kein Speicher kann mehr angefordert werden | ERROR: Out of Memory\n |

---

## Testen

Zum Testen stehen wie gehabt automatische Tests zur Verfügung, welche mit `make test` ausgeführt werden können. Außerdem befindet sich im Ordner eine Datei `wortliste.txt`, welche zwei Wörter enthält. Diese kann zum händischen Testen verwendet werden.

Die Musterlösung soll bei diesem Beispiel nur eine mögliche Lösungsrichtung andeuten. Einige Fehlerfälle werden in der Lösung gar nicht oder nicht ausreichend behandelt.
