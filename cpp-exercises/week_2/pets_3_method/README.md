# Funktion vs. Methode

Dieses Beispiel ist unbewertet. Wenn du es löst, bekommst du keine zusätzlichen Punkte für die KU, aber du kannst ein tieferes Verständnis der behandelten Themen erlangen und dein Wissen festigen.

## Lernziele

Ziel dieses Übungsbeispiels ist es, den grundlegenden Umgang mit Methoden zu üben.

## Das Problem

Die Datei `pets.cpp` entspricht der [Lösung der vorherigen Aufgabe](../pets_2_struct/solution.cpp). Der Code in `pets.cpp` besteht in diesem Übungsbeispiel auch bereits den Test Case. Dennoch sollte der Code überarbeitet werden.

Im Programm gibt es einen eigenen Datentyp für Haustiere, welcher über zwei Membervariablen (`species_` und `age_`) verfügt. Es fällt auf, dass die Funktion `greet` das Verhalten einer Klasse beschreibt. In der VO haben wir jedoch gehört, dass das Verhalten von Objekten mit Hilfe von Methoden ausgedrückt werden soll. Auf diese Weise werden die Daten einer Klasse mit der dazugehörigen Programmlogik vereint.

## Deine Aufgabe
### Funktion in Methode umwandeln
Wandle die Funktion `greet` in eine Methode der Klasse `Pet` um.

### Anpassungen in der `main`-Funktion
Schreibe danach die `main`-Funktion so um, dass statt der alten `greet`-Funktion die neue `greet`-Methode aufgerufen wird.


## Lösung

Ändere die Datei `pets.cpp`, um die oben beschriebene Aufgabe zu lösen. Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird eine Datei namens `testreport.html` erstellt. Sie enthält einen Bericht, der dir zeigt, welche Ausgabe dein Programm produzieren sollte und welche Ausgabe dein Programm produziert. Du erhältst auf diese Weise sofortiges Feedback zu deiner überarbeiteten `pets.cpp`-Datei.

Solltest du Probleme haben, das Übungsbeispiel zu lösen, so kannst du dir eine mögliche Lösung in `solution.cpp` ansehen. Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

## Mitwirkende an diesem Übungsbeispiel
Aleksandar Karakaš

