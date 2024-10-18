# Dynamisch große Eingabe

In diesem Übungsbeispiel soll das Arbeiten mit malloc und realloc geübt werden. 

---

## Lernziel

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Strings, Pointer
  - Dynamisches Speichermanagement

Lines of Code der Musterlösung: 60

---

## Anleitung

Es soll vom User ein String engelesen werden, welcher beliebig groß sein kann. Je nach Größe des Strings soll verschieden auf den Input reagiert werden. In der Datei `main.c` ist bereits die main-Funktion sowie der Funktionsaufruf von `getLine()` implementiert. Die Funktionalität soll nun ergänzt werden.



### Usereingabe

Es ist die Logik der Funktion `getLine()` zu schreiben. Diese Funktion soll wie folgt aufgebaut sein.

1. Allokieren von 8 Character (siehe define `BLOCK_BUFFERSIZE` = 8 Zeichen) am Heap

2. Einlesen von `stdin` mittels `fgets()` von 8 Zeichen auf die soeben erstellte Variable.

3. Abhängig ob die gesamte Eingabe eingelesen wurde soll nun reagiert werden:

   - Wurde die gesamte Eingabe bereits eingelesen ist Schritt 3 beendet.

   - Wurde noch nicht die gesamte Eingabe erfasst soll die Meldung `This input has more than 7 characters (incl. the \\n)\n` ausgegeben werden.  Der zuvor allokierte Speicher soll mit `realloc` nochmals um 8 Character vergrößert und mit `fgets()` 8 weitere Zeichen eingelesen werden. 
     Ist nun das Ende der Eingabe erreicht ist Schritt 3 beendet, andernfalls soll die Meldung `This input has more than 14 characters (incl. the \\n) and is too big for this example\n` ausgegeben werden. Der String enthält in diesem Fall dann nur die ersten 14 Zeichen. 

     (**Hinweis** `fgets()` ließt nicht wirklich 8 Zeichen ein, sondern nur 7 und schreibt an die 8. Stelle das `\0` - siehe [Stackoverflow](https://stackoverflow.com/questions/1660228/does-fgets-always-terminate-the-char-buffer-with-0). Deshalb können nach dem ersten Einlesen maximal 7 Zeichen und nach dem zweiten Einlesen max 14 Zeichen im String gespeichert werden. 

4. Die Funktion soll den String zurückgeben. Dieser wird in der `main()`-Funktion dann ausgegeben. Nach der Ausgabe in der `main`-Funktion soll der allokierte Speicher wieder freigegeben werden.







---

## Testen

Zum Testen stehen wieder automatische Tests bereits, welche mittels `make test` ausgeführt werden können.
