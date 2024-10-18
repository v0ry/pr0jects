# Berechnungen in einem Rechteck

In diesem Übungsbeispiel soll die Fläche, der Umfang und das Verhältnis zwischen Länge und Breite eines Rechtecks berechnet werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen
  - arithmetische Operatoren
  - Ein- und Ausgabe

Lines of Code der Musterlösung: 24

---

## Anleitung

Das Programm soll zu Beginn den Benutzer nach der Länge und der Breite eines Rechtecks fragen. Anschließend soll sowohl die Fläche und der Umfang, als auch das Verhältnis zwischen der Länge und der Breite des Rechtecks berechnet werden. Diese werden schließlich dem Benutzer wieder ausgegeben.

### Vorbereitung

Um beginnen zu können, müssen wir zu Beginn eine neue C-Datei erstellen. Natürlich kann man das direkt im Editor oder in der IDE machen, aber wir möchten es uns zumindest einmal im Terminal anschauen. Wir öffnen also ein neues Terminalfenster und navigieren solange mit dem Befehl `cd <Ordnername>` bis wir uns im Ordner `rectangle` befinden. Anschließend können wir mit `touch main.c` eine neue C-Datei mit dem Namen `main` erstellen. In das neu erstellte File können wir nun beispielsweise mit einem Hello-World beginnen.

Jetzt können wir auch noch sofort versuchen unser Programm zu kompilieren. Mit dem Befehl `clang -Wall -std=c17 -g -o main main.c` können wir unser Hello-World kompilieren und anschließend mit `./main` ausführen. Übrigends: Damit wir nicht immer zum Kompilieren den kompletten Befehl ins Terminal eingeben müssen, können wir einfach mit Pfeiltaste nach oben im Terminal zu bereits vorher eingegeben Befehlen gehen. 

Wenn das nun alles erledigt ist, können wir mit dem eigentlichen Programm beginnen.

### Einlesen der Seiten

Zu Beginn des Programm sollen wir also die Länge und Breite des Rechtecks vom Benutzer einlesen. Wir gehen an der Stelle davon aus, dass vom Benutzer nur positive ganzzahlige Seitenlängen eingegeben werden. Um diese zu speichern, benötigen wir zwei entsprechende Variable - wir wählen diese vom Typ `unsigned int` - und initialisieren beide zu Beginn mit `0`:

Anschließend wollen wir den User dazu aufforden, die Länge einzugeben. Dazu geben wir den Text

```
Insert length: 
```

aus. Anschließend soll die Länge eingelesen werden und in der entsprechend vorher erstellen Variable gespeichert werden. Analog verfahren wir mit der Breite, wozu wir den Text

```
Insert width: 
```

ausgeben. **Wichtig:** Bei beiden Ausgaben ist hinter dem Doppelpunkt jeweils noch ein Leerzeichen.

### Berechnung

Nach der Eingabe können wir jetzt mit den Berechnungen starten. Zuerst legen wir noch für Fläche, Umfang und das Seitenverhältnis Variable an, damit wir die Ergebnisse abspeichern können. Für die ersten beiden können wir wieder den Datentyp `unsigned int` verwenden. Das Seitenverhältnis wird hingegen im Allgemeinen nicht ganzzahlig sein, weswegen wir hierzu eine Variable vom Typ `float` anlegen wollen.

Nun können wir die Werte berechnen, die Formeln dafür sollten bekannt sein. Wir betrachten nur das Seitenverhältnis etwas genauer. Grundsätzlich ist dafür die Länge durch die Breite zu dividieren. Da aber beide Variable Ganzzahlen sind, ist dies eine Integer-Division und wir bekommen als Ergebnis wieder nur eine Ganzzahl. Damit wir tatsächlich eine Gleitkommazahl aus der Divison bekommen, müssen wir zuvor die Länge oder Breite in einen `float` casten.

### Ausgabe

Abschließend möchten wir nun noch dem Benutzer die errechneten Ergebnisse wieder ausgeben. Dies machen wir in folgendem Format:

```
Area: <wert>
Perimeter: <wert>
Aspect ratio: <wert>
```

Die spitzen Klammern sind mit den jeweiligen Werten zu ersetzen. (Damit die automatischen Tests funktionieren, müssen bei Gleitkommazahlen genau zwei Stellen nach dem Dezimalpunkt ausgegeben werden.)

---

## Testen

Jetzt müssen wir unser Programm auch noch testen, damit wir sicherstellen können, dass wir keinen Fehler gemacht haben. Dazu sollten auf jeden Fall einige Testfälle selbstständig ausprobiert werden. Als Anreiz hier noch zwei Beispiele:

Länge: 6, Breite: 3 -> Fläche: 18, Umfang: 18, Seitenverhältnis: 2.00

Länge: 150, Breite 40 -> Fläche: 6000, Umfang: 380, Seitenverhältnis: 3.75

Für diese beiden Testcases sind auch automatische Tests verfügbar:

### Automatisches Testen

Um das Programm mit dem Testrunner auszuführen, ist es nur notwendig `make test` im Terminal einzugeben. Anschließend werden alle Testcases ausgeführt. Die Auswertung befindet sich dann in der Datei `testreport.html`, die beispielsweise in einem Browser geöffnet werden kann. Dort sind dann die Ergebnisse aller Tests zu finden.

Mit `make clean` ist es möglich, den Ordner wieder aufzuräumen und den Testreport zu löschen, falls man dies nicht händisch machen möchte.
