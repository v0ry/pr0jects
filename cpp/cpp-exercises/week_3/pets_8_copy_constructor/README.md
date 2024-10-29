# Copy-Konstruktor

Dieses Beispiel ist unbewertet. Wenn du es löst, bekommst du keine zusätzlichen Punkte für die KU, aber du kannst ein tieferes Verständnis der behandelten Themen erlangen und dein Wissen festigen.

## Lernziele

Ziel dieses Übungsbeispiels ist es, die Verwendung des Copy-Konstruktors zu üben.

## Das Problem

Die `Pet`-Klasse in der Datei `pets.cpp` entspricht der Lösung der vorherigen Aufgabe. Der einzige Unterschied zu [Semester 02/OOP1/pr0jects/cpp-exercises/week_3/pets_7_static_members/solution.cpp](Semester%2002/OOP1/pr0jects/cpp-exercises/week_3/pets_7_static_members/solution.cpp) ist die `main`-Funktion. In der `main`-Funktion wird an zwei Stellen versucht, die Anzahl der erstellten Haustier-Objekte auszugeben. Allerdings scheint das nicht richtig zu funktionieren.

Nach fünf erstellten Haustieren wird richtigerweise ausgegeben, dass fünf Haustiere erstellt wurden. Aber nach der Erzeugung des sechsten Haustiers wird wieder ausgegeben, dass fünf Haustiere erstellt wurden. Woran könnte das liegen? 🤔️

## Deine Aufgabe

Es fällt auf, dass das sechste Haustier (in der Variable `dolly`) nicht mit einem herkömmlichen Konstruktor sondern mittels Copy-Konstruktor erstellt wurde. Wir haben zwar für die `Pet`-Klasse bisher keinen Copy-Konstruktor geschrieben aber dennoch gibt es einen. (Das kannst du überprüfen, indem du das Programm ausführst. Die Zeile `dolly.greet()` liefert den erwarteten Output; das heißt, dass das entsprechende Haustier-Objekt erstellt wurde.)

Der Copy-Konstruktor, der beim sechsten Haustier zum Einsatz kommt, ist der vom Compiler erstellte Default-Copy-Konstruktor. Dieser kopiert lediglich die Instanzvariablen – in diesem Fall `species_` und `age_`.

<table>
  <thead>
    <tr>
      <td align="left" style="font-weight: bold; vertical-align: top;">
        Beachte:
      </td>
      <td>
        Unter <em>Instanzvariablen</em> verstehen wir Membervariablen, welche nicht Klassenvariablen (<code>static</code>) sind. Während sich der Wert einer Instanzvariable von Objekt zu Objekt unterscheiden kann, gilt der Wert einer Klassenvariable für die gesamte Klasse.
      </td>
    </tr>
  </thead>

  <tbody>
  </tbody>
</table>

Der Compiler weiß leider nicht, dass wir unsere Haustiere mit der Klassenvariable `number_of_pets_` zählen. Deshalb kann sich der Default-Copy-Konstruktor auch nicht um die Erhöhung von `number_of_pets_` kümmern. Deine Aufgabe ist es daher, einen Copy-Konstruktor für die Klasse `Pet` zu schreiben, welcher nicht nur die Instanzvariablen `species_` und `age_` kopiert, sondern auch die Anzahl der erstellten Haustiere (`number_of_pets_`) um eins erhöht.





## Lösung

Ändere die Datei `pets.cpp`, um die oben beschriebene Aufgabe zu lösen. Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird eine Datei namens `testreport.html` erstellt. Sie enthält einen Bericht, der dir zeigt, welche Ausgabe dein Programm produzieren sollte und welche Ausgabe dein Programm produziert. Du erhältst auf diese Weise sofortiges Feedback zu deiner überarbeiteten `pets.cpp`-Datei.

Solltest du Probleme haben, das Übungsbeispiel zu lösen, so kannst du dir eine mögliche Lösung in `solution.cpp` ansehen. Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

## Mitwirkende an diesem Übungsbeispiel
Aleksandar Karakaš