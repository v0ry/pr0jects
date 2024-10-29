# Abgesicherte Eingabe von einzelnen Zeichen

In diesem Übungsbeispiel soll eine Funktion implementiert werden, die das sichere Einlesen von einzelnen Zeichen vom Benutzer ermöglicht. Für ungültige Eingaben soll eine entsprechende Fehlerbehandlung implementiert werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen
  - (logische) Operatoren
  - Verzweigungen
  - Schleifen
  - Funktionen
  - Ein- und Ausgabe

Lines of Code der Musterlösung: 76 inkl. Main-Funktion

---

## Anleitung

In diesem Beispiel ist bereits die Main-Funktion vorgegeben. Dort wird in Zeile 8 die Funktion `safeInput` aufgerufen, welche jetzt zu implementieren ist.

### Einführung

In den vorangegangen Übungsbeispielen war es immer so, dass wir von einer korrekten Eingabe vom Benutzer ausgegangen sind. Im Allgemeinen müssen wir aber davon ausgehen, dass nicht immer das richtige eingegeben wird. An der Stelle ist es dann wichtig, dass wir in unserem Programm robust darauf reagieren können. Es ist auf jeden Fall zu vermeiden, dass unser Programm mit einer falschen Eingabe unvorhersehbar weiterarbeitet, nicht mehr reagiert oder terminiert. Eine entsprechende Fehlermeldung und erneute Eingabeaufforderung für den Benutzer kann schließlich verwendet werden, um auf den Fehler aufmerksam zu machen und schließlich eine richtige Eingabe zu erhalten.

### Anforderungen

Als Vorbereitung für das nachfolgende Übungsbeispiel "Schere-Stein-Papier", möchten wir die Funktion `safeInput` gleich darauf angepasst implementieren. Die gültigen Inputs sind `s` bzw. `S` für "Scissors", `r` bzw. `R` für "Rock" und `p` bzw. `P` für "Paper". Weiters sollen noch `q`, `Q` bzw. `EOF` (=End of File, das ist **nicht** die Zeichenkette `"EOF"`) gültige Inputs sein, welche aber das Programm beenden. Dies ist bereits in der vorgegebenen Main-Funktion implementiert. `EOF` wird üblicherweise von I/O-Funktionen zurückgegeben, falls das Ende von einer (Text-)Datei erreicht wird und ist als Konstante in C definiert. `EOF` kann auch auf der Tastatur eingegeben werden mittels der Tastenkombination `STRG+D`. Falls dies nicht am Anfang einer Eingabe gemacht wird, muss `STRG+D` zweimal eingegeben werden. 

Nach folgenden Kriterien soll nun `safeInput` ablaufen:
1. Vor jeder Eingabe wird das Command-Prompt `> ` ausgegeben.
2. Anschließend wird auf die Eingabe vom Benutzer gewartet, welche anschließend verarbeitet wird.
3. Falls der User-Input mit `EOF` beendet wird, unabhängig davon, ob zuvor andere Zeichen eingegeben wurden, soll die Funktion `EOF` zurückgeben.
4. Falls nur Enter eingegeben wurde, oder der Input mehr als ein Zeichen vor dem Enter enhält, soll `Invalid input!\n` ausgegeben werden und wieder bei Schritt 1 begonnen werden. Damit bleiben nur mehr Eingaben übrig, die genau ein Zeichen lang sind (plus nachfolgendes Enter).
5. Falls dieses eine Zeichen einem der oben aufgezählten Zeichen entspricht, soll es von der Funktion zurückgegeben werden. Andernfalls ist die Eingabe ungültig, es soll `Invalid input!\n` ausgeben werden und wieder bei Schritt 1 begonnen werden.

---

## Tipps

Es ist wahrscheinlich hilfreich die Funktion `getchar` zu verwenden, anstatt mit `scanf` zu arbeiten. `getchar` liest das nächste Zeichen vom Eingabestream und gibt es zurück. Falls `EOF` gelesen wird, wird `EOF` zurückgegeben.

Ein Beispiel zu besseren Vorstellung: Angenommen es wird im Code `getchar` einmal aufgerufen und der Benutzer gibt `ESP\n` ein. Dann wird bei diesem Aufruf `E` zurückgegeben. Da sich dann aber noch weitere Zeichen im Eingabestream befinden, wird beim nächsten Aufruf von `getchar` das Programm nicht gestoppt, sodass der Benutzer etwas eingeben kann, sondern es wird einfach das nächste Zeichen `S` gelesen. Dies wiederholt sich solange, bis `\n` gelesen wird und der Eingabepuffer wieder leer ist.

---

## Testen

Es gibt bei diesem Beispiel wieder automatische Tests, welche mit `make test` ausgeführt werden können.
