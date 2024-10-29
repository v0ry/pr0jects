# Number - ASCII Konverter

In diesem Übungsbeispiel soll die Darstellung von Character geübt werden. Details zur ASCII Tabelle findet man unter https://www.asciitable.com/

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen
  - Ein- und Ausgabe

Lines of Code der Musterlösung: 21

---

## Anleitung

Das Programm soll nach einem Charachter (Buchstabe) fragen. Diese Eingabe soll danach als Zahl und als Character ausgegeben werden. Danach soll der umgekehrte Prozess ausgeführt werden.

### Einlesen des Characters

Zu Beginn des Programm sollen wir den Benutzer nach einem Character fragen:

```
Insert character: 
```

**Wichtig:** Bei beiden Eingaben ist hinter dem Doppelpunkt jeweils noch ein Leerzeichen.

Die Eingabe solle in einem `char` gespeichert werden. Der Character soll nun als Zahl und dann als ASCII Zeichen ausgegeben werden.

```
Number:           <zahlenwert>
ASCII Character:  <ascii-wert>
```

**Hinweis**: Hier muss der richtige [format specifier](https://codeforwin.org/2015/05/list-of-all-format-specifiers-in-c-programming.html) im `printf` verwendet werden um den Zahlenwert und den ASCII Wert darstellen zu können.

Zwischen den beiden Abfragen erfolgt zur besseren Übersicht ein Trennstrich (34x)  `----------------------------------`

### Einlesen der Ganzzahl

Nun soll das Programm den Benutzer nach einer Ganzzahl fragen:

```
Insert number: 
```

Die Eingabe solle in einem `int` gespeichert werden. Danach folgen wieder die 2 Ausgaben in Zahlen- und ASCII-Format:

```
Number:          <zahlenwert>
ASCII Character: <ascii-wert>
```



### Beispiel

In diesem Beispiel wurde beim Programm `d` und `43` eingegeben.

```
Insert character: d
Number:           100
ASCII Character:  d
----------------------------------
Insert number: 43
Number:          43
ASCII Character: +
```



### Automatisches Testen

Um das Programm mit dem Testrunner auszuführen, ist es nur notwendig `make test` im Terminal einzugeben. Anschließend werden alle Testcases ausgeführt. Die Auswertung befindet sich dann in der Datei `testreport.html`, die beispielsweise in einem Browser geöffnet werden kann. Dort sind dann die Ergebnisse aller Tests zu finden.

Mit `make clean` ist es möglich, den Ordner wieder aufzuräumen und den Testreport zu löschen, falls man dies nicht händisch machen möchte.



### Fortsetzung

Dieses Beispiel wird [hier](https://gitlab.tugraz.at/coding_tug/coding-exercises/-/tree/main/02-conditions-loops/ascii-konverter/README.md) weiterentwickelt.

