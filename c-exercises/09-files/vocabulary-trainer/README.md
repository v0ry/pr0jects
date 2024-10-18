# Vokabeltrainer

Es ist ein Programm zu schreiben, welches Vokabelpaare (ein Wort und dessen Übersetzung in eine andere Sprache) aus einer Datei liest. Im Anschluss wird dem Benutzer jeweils ein Element eines Paares ausgegeben und die richtige Übersetzung muss durch den Benutzer eingegeben werden. Zum Abschluss wird dem Benutzer angezeigt, wie viele richtige Antworten gegeben wurden.

---

## Lernziel

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Arrays, Strings, Pointer
  - Dynamisches Speichermanagement (Übungsbeispiel Dynamisches Array hilfreich)
  - Structs
  - Files

Lines of Code der Musterlösung: 208 (ohne Funktionen für Dynamisches Array)

---

## Anleitung

Das dynamische Array aus dem entsprechenden Übungsbeispiel kann hilfreich sein und hier verwendet werden. Eine eigene Implementierung nur für diese Beispiel ist aber auch nicht schwer umzusetzen und erfordert kaum Mehraufwand. Daher ist das dynamische Array nicht als Voraussetzung zu sehen.

### Datentyp

Zu Beginn ist ein Datentyp für die Vokabelpaare. Die entsprechende Struktur soll zwei C-Strings mit fixer Länge 32 als Elemente beinhalten. (Falls nötig, dürfen auch noch andere Elemente hinzugefügt werden.)

### Dateiformat

Die Vokabelpaare werden in einer Textdatei gespeichert, wobei jeweils pro Zeile ein Vokabelpaar gespeichert wird. Die beiden Elemente des Vokabelpaares werden durch mindestens ein Leerzeichen getrennt.

Einzelne Zeilen sind mit einem Zeilenumbruch (\n) abgeschlossen. Es dürfen zu Zeilenbeginn und Zeilenende beliebig viele Leerzeichen vorliegen.

Sollte eine Zeile nicht genau zwei Elemente enthalten oder nicht mit einem Zeilenumbruch abgeschlossen sein, ist die Vokabeldatei ungültig (siehe Fehlermeldungen).

### Programmablauf

Das Programm wird mit einem Kommandozeilenparameter aufgerufen. Dieser gibt den Dateinamen der zu öffnenden Vokabeldatei an. Sollte das Programm ohne Kommandozeilenparameter aufgerufen werden kommt es zu einer Fehlermeldung. Sollte das Programm mit mehr als einem Kommandozeilenparameter aufgerufen werden, so werden alle Parameter nach dem ersten ignoriert.

Im ersten Schritt liest das Programm die Vokabeldatei ein. Für jedes Vokabel, dass sich in der Datei befindet, soll am Heap eine wie oben definierte Struktur erstellt werden, in welche dann das Ausgangswort und die Übersetzung gespeichert werden. Da zu Beginn nicht bekannt ist, wie viele Vokabeln sich in der Datei befinden, macht es Sinn, die Pointer auf die Strukturen oder sogar die Strukturen selbst in einem dynamischen Array zu speichern (möglicherweise hilfreich, Übungsbeispiel: Dynamisches Array).

Im zweiten Schritt wird das erste Element des ersten Vokabelpaares gefolgt von der Zeichenfolge ` - ` ausgegeben und auf eine Benutzereingabe gewartet.

Die vom Benutzer eingegebene Zeichenkette wird mit dem zweiten Element des Vokabelpaares verglichen. Stimmen die beiden Zeichenketten überein wird "correct\n" ausgegeben, ansonsten "incorrect\n".

Anschließend wird mit dem nächsten Vokabelpaar fortgesetzt, wobei in diesem Fall das zweite Element ausgegeben wird und die Eingabe mit dem ersten Element verglichen wird.

Für jedes gerade Vokabelpaar (0., 2., 4., ...) wird das erste Element des Paares ausgegeben und die Eingabe mit dem zweiten Element verglichen. Für jedes ungerade Vokabelpaar (1., 3., 5., ...) wird das zweite Element des Paares ausgegeben und die Eingabe mit dem ersten verglichen.

Abschließend wird eine Statistik ausgegeben: `[correct] / [pairs]\n` wobei [correct] durch die Anzahl der richtig beantworteten Vokabeln und [pairs] durch die Anzahl der Vokabelpaare ersetzt wird.

### Rückgabewerte und Fehlermeldungen

| Wert | Bedeutung   | Fehlermeldung   |
| :--: | ----------- | ----------- |
| 0    | Erfolgsfall | |
| 1    | keine Kommandozeilenparameter | `usage: [executable] filename\n` |
| 2    | Vokabeldatei kann nicht geöffnet werden | `ERROR: cannot open file [filename]\n` |
| 3    | Vokabeldatei ungültig | `ERROR: file [filename] invalid\n` |
| 4    | kein Speicher kann mehr angefordert werden | `ERROR: Out of Memory\n` |

[executable] wird durch den Namen des kompilierten Programms ersetzt.

[filename] wird durch den Namen der Vokabeldatei ersetzt.

---

## Testen

Zum Testen stehen wieder automatische Tests bereits, welche mittels `make test` ausgeführt werden können. Außerdem befindet sich im Ordner eine Datei `test.txt`, welche fünf Vokabeln enthält. Diese kann zum händischen Testen verwendet werden.
