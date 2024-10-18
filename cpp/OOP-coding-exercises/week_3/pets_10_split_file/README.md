# Wir räumen auf

Dieses Beispiel ist unbewertet. Wenn du es löst, bekommst du keine zusätzlichen Punkte für die KU, aber du kannst ein tieferes Verständnis der behandelten Themen erlangen und dein Wissen festigen.

## Lernziele

Ziel dieses Übungsbeispiels ist es, die Aufteilung von Klassen in zwei Dateien (`.hpp` und `.cpp`) zu üben.

## Das Problem

Ausgangspunkt dieses Übungsbeispiels ist wieder die [Lösung des vorangegangenen Übungsbeispiels](Semester%2002/OOP1/Projects/OOP-coding-exercises/week_3/pets_9_id_and_better_counting/solution.cpp). Im Vergleich dazu unterscheidet sich die Datei `pets.cpp` nur in ihrer `main`-Funktion. In dieser Funktion wird versucht auf die Attribute `species_` und `age_` zuzugreifen, jedoch ist das nicht möglich, da diese `private` sind. Wir möchten lesenden Zugriff von außen auf diese Attribute erlauben aber schreibenden Zugriff weiterhin verhindern.

Außerdem fällt uns auf, dass die `Pet`-Klasse mit der Zeit ganz schön unübersichtlich geworden ist. Es wäre viel übersichtlicher, wenn die Implementierung der längeren Methoden – vor allem der `greet`-Methode – in einer eigenen Datei stehen würde.

Auch die Definition der `Pet`-Klasse sollte nicht zusammen mit der `main`-Funktion in einer Datei stehen, damit wir sie unabhängig von der `main`-Funktion in beliebigen anderen Projekten einsetzen können.

## Deine Aufgabe

1. Erstelle öffentliche Getter für die privaten Membervariablen `species_` und `age_`.
   Diese Getter sollen `getSpecies` bzw. `getAge` heißen. Verwende diese Methoden in der `main`-Funktion anstelle des versuchten direkten Zugriffs auf die zwei Attribute.
1. <details>
   <summary>Teile die Datei <code>pets.cpp</code> in drei Dateien auf.</summary>

   - In der Datei `Pet.hpp` soll die Definition der Klasse `Pet` stehen. Auch die Definition des benutzerdefinierten Datentyps `Species` soll in diese Datei verschoben werden.
   - In der Datei `Pet.cpp` sollen Methoden implementiert werden, außer sie haben einen sehr kurzen (einzeiligen) Methodenkörper. In dieser Datei soll auch die Klassenvariable `number_of_pets_` definiert werden (außer es wird von einem C++17-Feature mit dem Schlüsselwort `inline` Gebrauch gemacht).

     In dieser Datei wird die Datei `Pet.hpp` eingebunden, weil der Compiler hier den Scope `Pet` kennen muss.
   - In der Datei `pets.cpp` steht nur noch die `main`-Funktion (und notwendige `#include`s).

     In dieser Datei wird die Datei `Pet.hpp` eingebunden, weil der Compiler den Datentyp `Pet` in der `main`-Funktion kennen muss.
   </details>

## Lösung

Führe die geforderten Änderungen durch, um die oben beschriebene Aufgabe zu lösen. Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird eine Datei namens `testreport.html` erstellt. Sie enthält einen Bericht, der dir zeigt, welche Ausgabe dein Programm produzieren sollte und welche Ausgabe dein Programm produziert. Du erhältst auf diese Weise sofortiges Feedback zu deiner Lösung.

Solltest du Probleme haben, das Übungsbeispiel zu lösen, so kannst du dir eine mögliche Lösung im Ordner `solution` ansehen. Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

Im Ordner `solution` gibt es auch ein Makefile. Das heißt, dass du im Ordner `solution` ebenfalls `make test` ausführen kannst. Damit wird die bereitgestellte Lösung getestet.

## Mitwirkende an diesem Übungsbeispiel

Aleksandar Karakaš
