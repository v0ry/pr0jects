# Verstreute Haustiervariablen

Dieses Beispiel ist unbewertet. Wenn du es löst, bekommst du keine zusätzlichen Punkte für die KU, aber du kannst ein tieferes Verständnis der behandelten Themen erlangen und dein Wissen festigen.

## Lernziele

Ziel dieses Übungsbeispiels ist es, den grundlegenden Umgang mit `struct` zu üben.

## Das Problem

Die Datei `pets.cpp` entspricht der Lösung der vorherigen Aufgabe. Der einzige Unterschied zur Datei [`../pets_1_enum/solution.cpp`](Semester%2002/OOP1/pr0jects/cpp-exercises/week_2/pets_1_enum/solution.cpp) besteht darin, dass in `pets.cpp` für jedes Tier neben der Tierart noch eine weitere Eigenschaft (Alter) einer Variable zugewiesen wird. Somit gibt es in der `main`-Funktion zehn lokale Variablen (zwei für jedes Tier).

Das Programm besteht zwar den Test Case, allerdings mit Warnings, denn ein Teil der zehn Variablen in der `main`-Funktion wird nicht verwendet. Die zehn lokalen Variablen machen das Programm auch etwas unübersichtlich. Gäbe es für jedes Tier noch weitere Eigenschaften (z. B. den Namen und das Gewicht) in jeweils eigenen Variablen, dann wäre das Programm noch schwerer überblickbar.

## Deine Aufgabe
### Ein neuer Datentyp für Haustiere
Erstelle mit Hilfe des Schlüsselworts `struct` einen Datentyp für ein Haustier, welcher öffentliche Member für

 - die Tierart (Typ: `Species`) und
 - das Alter (Typ: `unsigned`)

eines Haustiers enthält.

### Änderungen in der `greet`-Funktion
Bisher bekam die `greet`-Funktion lediglich eine Tierart übergeben. Nun soll die Funktion stattdessen ein Haustier als Parameter haben. Diese Änderung macht auch Anpassungen im Funktionskörper erforderlich.

### Aufräumen in der `main`-Funktion
Schreibe danach die `main`-Funktion so um, dass nicht mehr zehn lokale Variablen angelegt werden, sondern nur fünf (also für jedes Tiere eine). Passe die Aufrufe der `greet`-Funktion entsprechend an (genauer gesagt, das Argument).


## Lösung

Ändere die Datei `pets.cpp`, um die oben beschriebene Aufgabe zu lösen. Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird eine Datei namens `testreport.html` erstellt. Sie enthält einen Bericht, der dir zeigt, welche Ausgabe dein Programm produzieren sollte und welche Ausgabe dein Programm produziert. Du erhältst auf diese Weise sofortiges Feedback zu deiner überarbeiteten `pets.cpp`-Datei.

Solltest du Probleme haben, das Übungsbeispiel zu lösen, so kannst du dir eine mögliche Lösung in `solution.cpp` ansehen. Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

## Mitwirkende an diesem Übungsbeispiel
Aleksandar Karakaš

