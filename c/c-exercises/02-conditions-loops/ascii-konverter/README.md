# Number - ASCII Konverter Weiterentwicklung

Dieses Übungsbeispiel ist eine Fortsetzung des einfachen [Number - ASCII Konverter](https://gitlab.tugraz.at/coding_tug/coding-exercises/-/tree/main/01-datatypes-operators/ascii_converter). Programmiere bitte zuerst dieses Beispiel, damit du hier die Weiterenwicklungen durchführen kannst. Details zur ASCII Tabelle findet man unter https://www.asciitable.com/

Um die Beispiele einfach und übersichtlich zu halten gehen wir davon aus, dass der Benutzer richtige EIngaben tätigt und nicht alle Fehlerfälle/Falscheingaben abgefangen werden müssen.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen
  - Verzweigungen
  - Schleifen
  - Ein- und Ausgabe

Lines of Code der Musterlösung: 50

---

## Anleitung

Wir erweitern den [einfachen Number - ASCII Konverter](https://gitlab.tugraz.at/coding_tug/coding-exercises/-/tree/main/01-datatypes-operators/ascii_converter) um ein paar Features.

### Abfrage beim Einlesen des Characters

Nach dem ersten Einlesen des Characters soll mittels einer Abfrage überprüft werden ob es sich um einen Buchstaben des Alphabet handelt (A-Z bzw a-z).  Wird ein gültiger Buchstabe eingegeben soll wie gehabt die beiden Ausgaben in Zahlen- und ASCII-Format erfolgen. Andernfalls soll die Fehlermeldung `[ERROR] not a valid Character [A-Z or a-z]` ausgegeben werden und keine Ausgabe in Zahlen- und ASCII-Format.

### Abfrage beim Einlesen der Ganzzahl

Genau wie oben soll auch hier eine Abfrage die Korrektheit der Eingabe überprüfen. Wird eine Ganzzahl zwischen zwischen 31 und 127 eingegeben sollen wie gehabt die beiden Ausgaben in Zahlen- und ASCII-Format erfolgen. Andernfalls soll die Fehlermeldung `[ERROR] not a visible ASCII-Character` ausgegeben werden und keine Ausgabe in Zahlen- und ASCII-Format.

### Wiederholung der Abfrage

Als letzten Teil soll das Programm so umgebaut werden, dass die beiden Eingaben in einer Dauerschleife immer wieder abgefragt werden. Zwischen den Blöcken bestehend aus der Charactereingabe und der Ganzzahleingabe folgen 2 Trennstriche (34x) - siehe Beispiel.

### Programmende

Wenn bei der Eingabe des Characters ein `Q` bzw. `q` eingegeben wird (Q=Quit) soll das Programm nach der Ausgabe in Zahlen- und ASCII-Format beendet werden.  Zuvor soll noch in einer neuen Zeile `GOODBYE` ausgegeben werden.

## Beispiel

Dieses Beispiel soll einen möglichen Ablauf des Programms nochmals verdeutlichen.

```
Insert character: #
[ERROR] not a valid Character [A-Z or a-z]
----------------------------------
Insert number: 2
[ERROR] not a visible ASCII-Character
----------------------------------
----------------------------------
Insert character: d
Number:           100
ASCII Character:  d
----------------------------------
Insert number: 89
Number:           89
ASCII Character:  Y
----------------------------------
----------------------------------
Insert character: 1
[ERROR] not a valid Character [A-Z or a-z]
----------------------------------
Insert number: 45
Number:           45
ASCII Character:  -
----------------------------------
----------------------------------
Insert character: G
Number:           71
ASCII Character:  G
----------------------------------
Insert number: 0
[ERROR] not a visible ASCII-Character
----------------------------------
----------------------------------
Insert character: q
Number:           113
ASCII Character:  q
GOODBYE
```



### Automatisches Testen

Um das Programm mit dem Testrunner auszuführen, ist es nur notwendig `make test` im Terminal einzugeben. Anschließend werden alle Testcases ausgeführt. Die Auswertung befindet sich dann in der Datei `testreport.html`, die beispielsweise in einem Browser geöffnet werden kann. Dort sind dann die Ergebnisse aller Tests zu finden.

Mit `make clean` ist es möglich, den Ordner wieder aufzuräumen und den Testreport zu löschen, falls man dies nicht händisch machen möchte.