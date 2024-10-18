# Objekt als Funktionsparameter

Dieses Beispiel ist unbewertet. Wenn du es löst, bekommst du keine zusätzlichen Punkte für die KU, aber du kannst ein tieferes Verständnis der behandelten Themen erlangen und dein Wissen festigen.

## Lernziele

Ziel dieses Übungsbeispiels ist es, Funktionen mit Objekten als Parameter zu verstehen.

## Das Problem

Die Datei `pets.cpp` entspricht der Lösung der vorherigen Aufgabe. Der einzige Unterschied zur Datei [`../pets_3_method/solution.cpp`](../pets_3_method/solution.cpp) besteht darin, dass es eine zusätzliche Funktion im Programm gibt. Diese Funktion heißt `happy_birthday` und sie wird in der `main`-Funktion für jedes Tier zwei Mal aufgerufen. Die Aufgabe von `happy_birthday` ist es, das Alter eines Haustiers um eins zu erhöhen und einen entsprechenden Text auszugeben. Wenn du `make test` ausführst, wirst du allerdings bemerken, dass die Erhöhung des Alters nicht (oder nicht immer?) funktioniert. Woran kann das liegen?

## Deine Aufgabe

Finde den Fehler und ändere den Code, sodass das Alter eines Haustiers durch `happy_birthday` um eins erhöht wird. Der Fehler muss sich entweder in der Funktion `happy_birthday` oder im Aufruf der Funktion in der `main`-Funktion befinden.


## Lösung

Ändere die Datei `pets.cpp`, um die oben beschriebene Aufgabe zu lösen. Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird eine Datei namens `testreport.html` erstellt. Sie enthält einen Bericht, der dir zeigt, welche Ausgabe dein Programm produzieren sollte und welche Ausgabe dein Programm produziert. Du erhältst auf diese Weise sofortiges Feedback zu deiner überarbeiteten `pets.cpp`-Datei.

Solltest du Probleme haben, das Übungsbeispiel zu lösen, so kannst du dir eine mögliche Lösung in `solution.cpp` ansehen. Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

## Mitwirkende an diesem Übungsbeispiel
Aleksandar Karakaš

