# Umständliche C-Strings vs. `enum class`

Dieses Beispiel ist unbewertet. Wenn du es löst, bekommst du keine zusätzlichen Punkte für die KU, aber du kannst ein tieferes Verständnis der behandelten Themen erlangen und dein Wissen festigen.

## Lernziele

Ziel dieses Übungsbeispiels ist es, den Umgang mit `enum class` zu üben. `enum class` ist neu in C++ und du solltest es gegenüber dem aus C bekannten `enum` bevorzugen.

## Das Problem
In der Datei `pets.cpp` existiert bereits eine `main`-Funktion. In dieser Funktion werden Variablen angelegt, welche Informationen über Tiere enthalten. Für jedes Tier wird auch die Funktion `greet` aufgerufen, welche einen Text ausgibt, der von Tierart abhängt.

Die Funktion `greet` hat einen Parameter. Dadurch wird der Funktion eine Tierart als C-String übergeben. In der Funktion wird die Tierart mit `strcmp` überprüft. Diese Überprüfung ist etwas umständlich und wird C-Neulinge verwirren, zumal im Code mit `0` verglichen werden muss.

## Deine Aufgabe
Besser wäre es, wenn die übergebene Tierart direkt mit Hilfe des `==`-Operators verglichen werden könnte. Das ist mit einem eigenen Datentyp, den du dir mit `enum class` definierst, möglich.

Definiere einen eigenen Datentyp mit `enum class`, welcher für jede der folgenden Tierarten einen Wert vorsieht.

 - Hund
 - Schwein
 - Katze
 - Kaninchen
 - unbekannte Tierart

Schreibe die Funktion `greet` so um, dass sie den neuen Datentyp nutzt – sowohl beim Parameter als auch im Funktionskörper. Schreibe auch die `main`-Funktion so um, dass anstelle von C-Strings der neue Datentyp zum Einsatz kommt. (Der C-String `"sheep"` hat keinen entsprechenden Wert im `enum class` für Tierarten. Verwende deshalb anstelle von `"sheep"` den `enum class`-Wert für ein unbekanntes Tier.)


## Lösung

Ändere die Datei `pets.cpp`, um die oben beschriebene Aufgabe zu lösen. Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird eine Datei namens `testreport.html` erstellt. Sie enthält einen Bericht, der dir zeigt, welche Ausgabe dein Programm produzieren sollte und welche Ausgabe dein Programm produziert. Du erhältst auf diese Weise sofortiges Feedback zu deiner überarbeiteten `pets.cpp`-Datei.

Solltest du Probleme haben, das Übungsbeispiel zu lösen, so kannst du dir eine mögliche Lösung in `solution.cpp` ansehen. (Eine alternative Lösung findest du in `solution_with_switch_instead_of_if.cpp`.) Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

## Mitwirkende an diesem Übungsbeispiel
Aleksandar Karakaš

