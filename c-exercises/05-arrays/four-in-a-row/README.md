# Vier gewinnt

In diesem Übungsbeispiel soll das Spiel "Vier gewinnt" implementiert werden. Der Hauptfokus liegt dabei auf der Umsetzung des "Spielfelds" als zweidimensionales Array und der Spiellogik.

**Achtung:** Es empfiehlt sich zuvor das Übungsbeispiel "Abgesicherte Eingabe von einzelnen Zeichen" zu erarbeiten. Zwingend erforderlich ist es aber nicht.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Ein- und Ausgabe (Übungsbeispiel: "Abgesicherte Eingabe von einzelnen Zeichen" + "Funktionspointer" hilfreich)

Lines of Code der Musterlösung: 298 inkl. Funktionen für die abgesicherte Eingabe

---

## Anleitung

Bei unserem "Vier gewinnt" treten die Spieler RED und YELLOW gegeneinander an. Spieler RED beginnt immer das Spiel.

Für das "Spielfeld" soll ein zweidimensionales Array implementiert werden.

### Ablauf eines Spielzugs

Zu Beginn jedes Spielzugs wird das Spielfeld ausgegeben. Anschließend wird noch augegeben, welcher der beiden Spieler gerade am Zug ist mit `REDs turn:\n` bzw. `YELLOWs turn:\n`. Nun wird der Spieler mit dem Commandprompt ` > ` zur Eingabe aufgefordert. Gültige Eingaben sind die Zahlen von `1` bis `7` - die Spalten auf dem "Spielfeld" - und `Q`, `q` und `EOF`, um das Spiel zu beenden. Alle anderen Eingaben sind nicht gültig und es soll `Invalid input!\n` ausgegeben werden. Dies entspricht der Funktion `safeInput` aus dem Übungsbeispiel "Abgesicherte Eingaben von einzelnen Zeichen", welche im Beispiel "Funktionspointer" bereits auf Vier gewinnt angepasst wurde. (Natürlich ist das Beispiel aber auch ohne diese Funktion lösbar.) 

Falls eine Spalte bereits bis oben gefüllt ist und somit kein weitere Spielstein mehr Platz hat, soll die Fehlermeldung `Column is full!\n` ausgegeben werden. Nach beiden genannten Fehlermeldungen ist jeweils wieder das Prompt auszugeben und auf eine neue Eingabe zu warten.

Ist eine gültige Eingabe erfolgt, wird ein Spielstein auf das unterste freie Feld in der entsprechenden Spalte gesetzt - analog zum Originalspiel, in dem der Spielstein von oben eingeworfen wird. Erreicht ein Spieler mit dem eingeworfenen Spielstein, dass sich nun vier Steine horizontal, vertikal oder diagonal nebeneinaner befinden, hat der Spieler gewonnen. In diesem Fall soll der Text `Player RED won the game!\n` bzw. `Player YELLOW won the game!\n` ausgegeben werden.

Falls das letzte freie Platz am "Spielfeld" belegt wurde und keiner der beiden Spieler gewonnen hat, soll der Text `Draw! Nobody won the game!\n` ausgegeben werden.

### Ausgabe des Spielfelds

Die grundsätzliche Struktur des Spielfelds ist folgende:

```
\n
  01   02   03   04   05   06   07\n
------------------------------------\n
|    |    |    |    |    |    |    |\n
------------------------------------\n
|    |    |    |    |    |    |    |\n
------------------------------------\n
|    |    |    |    |    |    |    |\n
------------------------------------\n
|    |    |    |    |    |    |    |\n
------------------------------------\n
|    |    |    |    |    |    |    |\n
------------------------------------\n
|    |    |    |    |    |    |    |\n
------------------------------------\n
  01   02   03   04   05   06   07\n
```

Falls ein Platz am "Spielfeld" leer ist, wird dieser einfach mit 4 Leerzeichen ausgefüllt. Falls an einem Feld ein Stein vom Spieler RED liegt, sind die Leerzeichen durch ` \x1b[31;1m\u2b24\x1b[0m ` zu ersetzen, im Falle von Spieler YELLOW durch ` \x1b[33;1m\u2b24\x1b[0m `. Das schaut auf den ersten Blick jetzt komplizierter aus, als es ist. Durch `\x1b[31;1m` wird die Farbe des Terminals auf rot gesetzt (analog durch `\x1b[33;1m` auf gelb), anschließend wird ein Kreis (`\u2b24`) ausgegeben und zuletzt wird die Farbe wieder auf weiß (`\x1b[0m`) zurückgesetzt. Das macht die Ausgabe vom Spielfeld viel übersichtlicher und schaut richtig cool aus.

### Überprüfung, ob das Spiel gewonnen wurde

Im wesentlichen gibt es hier zwei Methoden, mit denen überprüft werden kann, ob das Spiel nach einem Spielzug gewonnen wurde. 

1. Nach jedem Zug wird das gesamte "Spielfeld" abgesucht, dh. jede Zeile, Spalte und Diagonale wird durchgegangen und überprüft, ob sich vier Steine unmittelbar hintereinander befinden.

2. Als Alternative kann man sich auch merken, welcher Spielstein neu dazugekommen ist und es wird speziell nur diese eine Spalte, Zeile und die beiden Diagonale überprüft.

Bei beiden Methoden ist es ausreichend, nur die Steine des Spielers zu überprüfen, der gerade am Zug war.

---

## Testen

Es gibt fünf kurze Testcases, bei denen fünf verschiedenen Spielausgänge überprüft werden. Aufgrund der farbigen Ausgaben schauen leider die Testfiles nicht allzu übersichtlich aus, anhand der Inputs, die unter den Testcases angezeigt werden, ist es aber leicht möglich, den Testcase "händisch" einmal im Terminal durchzugehen. Alternativ kann auch der `stdin` beim Ausführen umgeleitet werden, sodass der Testcase-Input direkt verwendet wird. Dazu muss das Programm so ausgeführt werden, beispielhaft für den dritten Testcase: `./main < tests/03/in`. 

Die Eingabefunktion wird nicht gesondert auf ungültige Eingabe mit Ausnahme voller Spalten überprüft.
