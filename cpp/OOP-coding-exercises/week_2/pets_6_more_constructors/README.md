# Mehrere Konstruktoren

Dieses Beispiel ist unbewertet. Wenn du es löst, bekommst du keine zusätzlichen Punkte für die KU, aber du kannst ein tieferes Verständnis der behandelten Themen erlangen und dein Wissen festigen.

## Lernziele

Ziel dieses Übungsbeispiels ist es, die Verwendung von Konstruktoren zu üben.

## Das Problem

Die Datei `pets.cpp` entspricht der Lösung der vorherigen Aufgabe. Der einzige Unterschied zu [Semester 02/OOP1/Projects/OOP-coding-exercises/week_2/pets_5_access_specifier/solution.cpp](Semester%2002/OOP1/Projects/OOP-coding-exercises/week_2/pets_5_access_specifier/solution.cpp) ist, dass zwei weitere `Pet`-Objekte am Ende der `main`-Funktion angelegt werden. Das erste dieser zwei Objekte soll dabei ohne Parameter für den Konstruktor erzeugt werden. Beim zweiten Objekt wird dem Konstruktor lediglich die Tierart mitgeteilt.

Der Konstruktor der Klasse `Pet` erwartet zwei Parameter. Das heißt, dass es für die zwei neuen `Pet`-Objekte keinen passenden Konstruktor gibt.

## Deine Aufgabe
Erstelle die fehlenden Konstruktoren, damit der Code fehlerfrei kompiliert.

### Konstruktor ohne Parameter
Erstelle einen Konstruktor in der `Pet`-Klasse, der keinen Parameter erwartet. Wird dieser Konstruktor aufgerufen, so soll das `species_`-Attribut mit dem Wert `Species::UNKNOWN` und das `age_`-Attribut mit `0` initialisiert werden.

### Konstruktor mit einem Parameter
Erstelle einen Konstruktor in der `Pet`-Klasse, der einen Parameter vom Typ `Species` erwartet. Wird dieser Konstruktor aufgerufen, so soll das `species_`-Attribut mit dem übergebenen Wert und das `age_`-Attribut mit `0` initialisiert werden.

## Lösung

Ändere die Datei `pets.cpp`, um die oben beschriebene Aufgabe zu lösen. Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird eine Datei namens `testreport.html` erstellt. Sie enthält einen Bericht, der dir zeigt, welche Ausgabe dein Programm produzieren sollte und welche Ausgabe dein Programm produziert. Du erhältst auf diese Weise sofortiges Feedback zu deiner überarbeiteten `pets.cpp`-Datei.

Solltest du Probleme haben, das Übungsbeispiel zu lösen, so kannst du dir eine mögliche Lösung in `solution.cpp` ansehen. Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

## Mitwirkende an diesem Übungsbeispiel
Aleksandar Karakaš

