# Paint

In diesem Übungsbeispiel soll ein Zeichenprogramm im Terminal implementiert werden. Außerdem soll es möglich sein, das Bild im Anschluss als eine Bilddatei abzuspeichern.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Arrays, Strings, Pointer
  - Dynamisches Speichermanagement
  - Enums
  - Files

Lines of Code der Musterlösung: 234

---

## Anleitung

### Erstellen der Zeichenfläche

Zu Beginn des Programms soll der Benutzer nach der Größe der Zeichenfläche gefragt werden. Zum einen wird nach der Höhe `Insert height: ` und zum anderen nach der Breite `Insert width: ` gefragt. Es kann davon ausgegangen werden, dass nur Ganzzahl eingegeben werden. (Zusätzliche Überprüfungen dahingehend können als Übung implementiert werden.) Falls eine eingegebene Ganzzahl im Bereich eins bis zehn liegt, ist die Eingabe gültig. Ansonsten soll die Fehlermeldung `Invalid height!\n` bzw. `Invalid width!\n` ausgegeben werden und die Eingabe wiederholt werden.

Nachdem nun die Größe der Zeichenfläche bekannt ist, soll diese nun als zweidimensionales Array am Heap erstellt werden. Die erste Koordinate soll die Zeile angeben und zweite Koordinate die Spalte. Als Datentyp für ein Feld soll ein Enum erstellt werden, welches eine Farbe repräsentiert. Zum Beginn soll die gesamte Zeichenfläche schwarz gefärbt sein.

### Farben

Folgende Farben sind zu unterstützen. In der Tabelle werden sowohl die Escape-Sequenzen angeführt, die für die Ausgabe im Terminal wichtig sind. Außerdem wird die RGB-Farbzusammensetzung angegeben, die für das Erstellen des Bildes am Ende wichtig ist.

| Farbe | Terminal | RGB (Rot - Grün - Blau) |
| :---: | :------: | :-: |
| BLACK | `\x1b[30m` | `0 - 0 - 0` |
| RED | `\x1b[31m` | `255 - 0 - 0` |
| GREEN | `\x1b[32m` | `0 - 255 - 0` |
| YELLOW | `\x1b[33m` | `255 - 255 - 0` |
| BLUE | `\x1b[34m` | `0 - 0 - 255` |
| MAGENTA | `\x1b[35m` | `255 - 0 - 255` |
| CYAN | `\x1b[36m` | `0 - 255 - 255` |
| WHITE | `\x1b[37m` | `255 - 255 - 255` |

### Ausgabe der Zeichenfläche

Im Falle einer Größe von 3 mal 5 soll die Ausgabe folgendermaßen aussehen:

```
    0 1 2 3 4\n
   ----------\n
0 |##########|\n
1 |##########|\n
2 |##########|\n
   ----------\n
```

Wichtig dabei ist, dass die Indices von 0 bis - abhängig von der Größe - maximal 9 laufen. Die `#` in der Beispielausgabe sind nur Platzhalter. Diese sind in der echten Ausgabe durch Unicode-Rechtecke (`\u2588`) zu ersetzen. Außerdem müssen diese entsprechend gefärbt werden, mit den oben stehenden Codes. Zu jedem Pixel gehören immer zwei dieser Rechtecke, da dadurch die Proportionen besser im Terminal umgesetzt werden. Beispielsweise stehen die ersten beiden Platzhalter-`#` in der ersten Zeile für das Pixel `(0, 0)` aus dem Array.

Tipp: Zum Ausgaben eines roten Pixels müsste beispielsweise `\x1b[31m\u2588\u2588` geprintet werden. Die Begrenzung der Zeichenfläche ist jedenfalls wieder in weiß auszugeben (`\x1b[37m|`).

### Zeichnen

Nachdem die Zeichenfläche erstellt wurde, soll diese wie oben beschrieben ausgegeben werden. Anschließend soll mittels ` > ` zu einer Eingabe aufgefordert werden. Um zu Zeichnen muss ein Befehl der Form `[color] [row] [column]` eingegeben werden. Mit `[color]` (eine Farbe aus obiger Tabelle) soll der Pixel in Zeile `[row]` und Spalte `[col]` entsprechend eingefärbt werden. Falls die Eingabe ungültig ist, soll `Invalid input!\n` ausgegeben werden. Dies ist beispielsweise der Fall, wenn die Zeilenummer größer als das Spielfeld ist oder keine korrekt Farbe angegeben wurde. (Natürlich sind weitere differenziertere Fehlermeldungen nie schlecht und eine gute Übung, aber nicht Hauptziel des Übungsbeispiels.)

Falls erfolgreich ein Pixel eingefärbt wurde, soll das Zeichenfeld erneut ausgegeben werden und auf eine neue Eingabe gewartet werden.

Mit dem Befehl `quit` soll das Zeichnen beendet werden können.

### Speichern des Bildes

Nachdem vom Benutzer `quit` eingegeben wurde, soll vom Programm `Enter filename (.ppm): ` ausgegeben werden. An dieser Stelle soll der Benutzer einen Dateinamen eingeben können, um das gezeichnete Bild speichern zu können.

Hierzu muss vom Programm eine Textdatei mit dem eingegeben Namen zum Schreiben geöffnet werden. Falls dies nicht möglich ist, soll die Fehlermeldung `Unable to safe painting to the file!\n` ausgegeben werden und die Zeichnung geht verloren.

Die Textdatei wird das .ppm-Format besitzen, ein sehr einfaches textbasiertes Format für Bilder. In die erste Zeile muss `P3` geschrieben werden. Dies gibt an, dass es sich um ein Farbbild handelt. In die zweite Zeile muss die Breite und die dritte Zeile die Höhe des Bildes geschrieben werden. In die vierte Zeile kommt schließlich noch der höchste Wert, der nachfolgend bei den Pixeln verwendet wird - in diesem Fall `255`. Anschließend soll zur Übersichtlichkeit eine Zeile freigelassen werden.

Nun wird jedes Pixel der ersten Zeile der Zeichenfläche in eine eigene Zeile in die Textdatei geschrieben. Dazu soll der Format-String `%3d %3d %3d\n` verwendet werden, wobei die drei Integer-Werte genau der RGB-Farbzusammensetzung entsprechen sollen. Anschließend ist wieder eine Zeile in der Textdatei freizuhalten.

In dieser Form soll mit allen weiteren Zeilen fortgefahren werden.

Es befindet sich im Ordner die Datei `esp_ref.ppm`, welche als Beispiel angesehen werden kann. Diese kann zu einem mit einem Editor aufgemacht werden, zum anderen aber auch mit einem Bilddarstellungsprogramm. Falls das Bild unscharf dargestellt werden sollte, muss in den Einstellungen die Kantenglätte gegebenenfalls ausgeschaltet werden.

### Fehlermeldungen

Falls es nicht möglich ist, Speicher für das zweidimensionale Array zu reservieren, soll sämtlicher bisher reservierte Speicher wieder freigegeben, die Fehlermeldung `Out of memory!\n` ausgegeben und das Programm mit dem Wert `1` beendet werden.

Falls es nicht möglich war die Datei zum Speichern der Zeichnung zu erstellen, soll die Fehlermeldung `Unable to safe painting to the file!\n`ausgegeben und das Programm mit Wert `2` beendet werden. Auch hier ist darauf zu achten, dass sämtlicher Speicher zuvor freigegeben wurde.

---

## Testen

Zum Testen stehen automatische Tests zur Verfügung, die sowohl die Terminalausgaben, als auch das Ergebnis überprüfen. Aufgrund der Farben und der Unicode-Zeichen ist die Terminalausgabe im Testreport leider nicht wirklich gut lesbar. Die Tests können wie bekannt mit `make test` ausgeführt werden. Fehlermeldungen werden in den Testcases nicht getestet und müssen selbstständig überprüft werden.
