# Statistische Berechnungen

In diesem Übungsbeispiel soll die Berechnung von statistischen Werten (Mittelwert, Minimum, Maximum) geübt werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen
  - arithmetische und logische Operatoren
  - ternärer Operator
  - Ein- und Ausgabe

Lines of Code der Musterlösung: 31

---

## Anleitung

Das Programm soll zu Beginn den Benutzer dazu auffordern, drei Zahlen einzugeben. Anschließenden wird davon der Mittelwert berechnet und Minimum bzw. Maximum bestimmt und schließlich dem Benutzer ausgegeben.

### Einlesen der Seiten

Zu Beginn des Programm sollen drei Zahlen vom Typ `double` vom Benutzer eingelesen werden. Es kann wieder davon ausgegangen werden, dass nur gültige Eingaben erfolgen. Folgender Text soll für die Eingabeaufforderung verwendet werden, 

```
Insert first number: 
Insert second number: 
Insert third number: 
```

wobei nach jeder Zeile auf die Eingabe gewartet wird. **Wichtig:** Hinter dem Doppelpunkt befindet sich noch ein Leerzeichen.

### Berechnung

Nach der Eingabe sollen nun die statistischen Werte berechnet werden. Zur Berechnung des Mittelwert werden alle Zahlen addiert und in diesem Fall durch `3` dividiert. 

Für die Bestimmung von Minimum und Maximum würde man üblicherweise Verzweigungen im Code verwenden. In diesem Beispiel soll dies aber ausschließlich mit dem ternären Operator umgesetzt werden. 

Ein Tipp für den Start: Es ist sicher hilfreich zuerst zu versuchen Minimum und Maximum von zwei Zahlen festzustellen. Logische Operatoren können sicherlich auch die Sache etwas erleichtern.

### Ausgabe

Abschließend sollen nun noch dem Benutzer die errechneten Ergebnisse in nachstehenden Format wieder ausgeben werden

```
Mean: <wert>
Min: <wert>
Max: <wert>
```

Die spitzen Klammern sind mit den jeweiligen Werten zu ersetzen. Bei dieser Ausgabe sollen außerdem alle Werte auf zwei Nachkommastellen gerundet ausgeben werden. Anstelle des üblichen Format-Strings für `double` muss dieser hierfür noch leicht modifziert werden.

Tipp: Im Internet nach `printf double precision` suchen.

---

## Testen

Es ist möglich dieses Programm automatisch zu testen. Dies ersetzt aber **nie**, dass man sich selbst Gedanken über mögliche Testcases, insbesondere Edge-Cases, macht und diese auch selbstständig austestet und überprüft.

### Automatisches Testen

Um das Programm mit dem Testrunner auszuführen, ist es nur notwendig `make test` im Terminal einzugeben. Anschließend werden alle Testcases ausgeführt. Die Auswertung befindet sich dann in der Datei `testreport.html`, die beispielsweise in einem Browser geöffnet werden kann. Dort sind dann die Ergebnisse aller Tests zu finden.

Mit `make clean` ist es möglich, den Ordner wieder aufzuräumen und den Testreport zu löschen, falls man dies nicht händisch machen möchte.
