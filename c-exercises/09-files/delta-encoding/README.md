# Kompressionsverfahren (Delta-Encoding)

In diesem Übungsbeispiel soll das Arbeiten mit Files in C geübt werden. Dazu soll ein einfaches Kompressionverfahren implementiert werden, sodass es möglich ist aus einer Textdatei eine komprimierte Binärdatei zu erstellen bzw. aus einer komprimierten Datei wieder die ursprüngliche Textdatei zu machen.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Arrays, Strings, Pointer
  - Files

Lines of Code der Musterlösung: 140

---

## Anleitung

### Aufruf des Programms

Das Programm ist mit genau 4 Kommandozeilenparametern in genau dieser Reihenfolge aufzurufen:

| Parameter | Bedeutung |
| :-------: | :-------: |
| 1.         | Programmname |
| 2.         | Option |
| 3.         | neu zu erstellende Datei |
| 4.         | zu (de)komprimierende Datei |

Der Option-Parameter kann entweder die Werte `-c` (zum Komprimieren) oder `-d` (zum Dekomprimieren) haben.

### Fehlermeldungen

Folgende Fehlermeldungen sind zu implementieren. Anschließend ist das Programm mit dem entsprechenden Rückgabewert zu beenden. Die Reihenfolge der Fehlermeldungen ist nach Priorität sortiert, dh. sollten möglicherweise mehrere Fehler auftreten ist die oberst gereihte Fehlermeldung aus der Tabelle zu auszugeben.

| Fehlerart | Fehlermeldung | Rückgabewert |
| :-------: | :-----------: | :----------: |
| Falsche Parameteranzahl | USAGE | 1 |
| Option ist weder `-c` noch `-d` | USAGE | 1 |
| Die zu (de)komprimierende Datei kann nicht geöffnet werden | `The file <filename> may not exist.\n` | 2 |
| Die neue Datei kann nicht geöffnet werden | `The file <filename> cannot be created.\n` | 3 |
| Progamm beendet erfolgreich | `Completed successfully.\n` | 0 |

Aus Platzgründen in der Tabelle ist USAGE hier angeführt:
```
"Compression:   <binary> -c 'compressed_file' 'uncompressed_file'\n"
"Decompression: <binary> -d 'uncompressed_file' 'compressed_file'\n"
```

Sobald eine Datei geöffnet worden ist, darf in diesem Programm angenommen werden, dass sie das richtige Format besitzt. Weitere Überprüfungen sind daher nicht unbedingt erforderlich (aber natürlich steht es frei, diese als zusätzliche Übung zu implementieren.)

### Format der Dateien

Die (unkomprimierte) Textdatei ist so aufgebaut, dass in jeder Zeile der Datei genau eine Ganzzahl (int32_t) mit anschließendem `\n` steht.

Die (komprimierte) Binärdatei ist wie folgt aufgebaut. Die ersten 4 Byte entsprechen der ersten Zahl aus der Textdatei. Solange die Differenz der nächsten Zahl der Textdatei zur vorangegangenen Zahl im Intervall `[-127, 127]` liegt, soll das nächste Byte nur diese Differenz speichern. Falls die Differenz außerhalb des Intervalls liegt, soll das nächste Byte den Wert `-128` besitzen und in den anschließenden 4 Byte steht die nächste Zahl wieder "voll ausgeschrieben".

### Beispiel

Textdatei
```
255
256
100
150
```

Binärdatei (alle Bytes liegen natürlich ohne Whitespaces und Kommentare nebeneinander, dies dient nur zur Übersichtlichkeit)
```
FF 00 00 00 // 255
01          // +1 für 256
80          // Platzhalter "-128", da Differenz nicht im Intervall
64 00 00 00 // 100
32          // +50 für 150
```

Tipp: Wie im Beispiel angeführt werden Ganzzahlen zuerst mit dem Least Significant Byte, dann aufsteigenden bis zum Most Significant Byte gespeichert. Dies entspricht auch der Speicherung von Zahlen in C (zumindest in der VM / Linux). Es gibt aber auch Systeme bzw. Protokolle, in denen die Bytes genau umgekehrt gespeichert werden.

---

## Testen

Zum Testen stehen wieder automatische Tests zur Verfügung, welche mit `make test` ausgeführt werden können. Zusätzlich zum Output des Programms auf `stdout` werden im Testreport auch die umgewandelten Dateien verglichen.

Zum händischen Testen stehen die Dateien `uncompressed_1.txt` bzw. `compressed_2` zur Verfügung, welche (de)komprimiert werden können. Beide beinhalten dieselben Werte, damit ein Vergleich möglich ist. Mittels `make runc` bzw. `make rund` besteht auch Support zum Ausführen des Programms mit dem `Makefile`.
