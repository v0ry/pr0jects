# IDs und besseres Zählen

Dieses Beispiel ist unbewertet. Wenn du es löst, bekommst du keine zusätzlichen Punkte für die KU, aber du kannst ein tieferes Verständnis der behandelten Themen erlangen und dein Wissen festigen.

## Lernziele

Ziel dieses Übungsbeispiels ist es, die Verwendung des Destruktors zu üben. Außerdem wird noch einmal der Unterschied zwischen Instanzvariablen (nicht `static`) und Klassenvariablen (`static`) unterstrichen.

## Das Problem

Unsere `Pet`-Klasse kann seit dem letzten Übungsbeispiel zuverlässig Haustiere zählen. Es scheint als könnte sich die Klasse zu einem wichtigen Bestandteil eines größeren Programms entwickeln. Ein solches Programm könnte z. B. der Verwaltung eines Tierheimes dienen oder es könnte ein Spiel mit Tieren sein.

Bis es so weit ist, müssen wir unsere `Pet`-Klasse allerdings noch weiter verbessern. Unserer Klasse fehlen unter anderem noch folgende Features:

1. Für die Verwaltung eines Tierheimes wäre es wichtig, dass jedes Tier eine eigene ID hat.
2. Wir können uns vorstellen, dass ein Tierheim ein `Pet`-Objekt nicht mehr benötigt, wenn das entsprechende Tier an eine\*n neue\*n Besitzer\*in übergeben wird. In einem solchen Fall sollte also die Anzahl der Tiere wieder verringert werden.

Die [Lösung des letzten Übungsbeispiels](../pets_8_copy_constructor/solution.cpp) stellt in `pets.cpp` auch den Ausgangspunkt für dieses Beispiel dar. Lediglich die `main`-Funktion hat sich geändert und verwendet bereits die hier zu implementierenden Features der `Pet`-Klasse.

## Deine Aufgabe

Behebe die zwei oben genannten Probleme. Die Details dazu kannst du der folgenden Liste entnehmen.

1. <details>
   <summary>ID für Tiere</summary>

   Gib jedem Tier eine eindeutige ID. Diese soll ein privates `unsigned` Attribut sein, welches du `id_` nennen kannst. Das erste erzeugte Haustier soll die ID 0 bekommen, das zweite Haustier soll die ID 1 bekommen, und so weiter.

   **Beachte:** Diese Membervariable ist eine _Instanzvariable_ (nicht `static`), weil jedes Haustier-Objekt seine eigene ID hat.

   Für die ID soll es eine öffentliche Getter-Methode namens `getId` geben.

   **Beachte:** Eine bestimmte ID soll höchstens ein Mal verwendet werden. Die ID eines Haustiers soll auch im Falle des Destruktoraufrufs nicht später an ein anderes `Pet`-Objekt vergeben werden.

   **Beachte:** Wir machen uns in diesem Beispiel keine Gedanken darüber, dass so viele `Pet`-Objekte erstellt werden könnten, dass deren Anzahl die Anzahl unterschiedlicher `unsigned`-Werte übersteigt.
   </details>
2. <details>
   <summary>Verbessertes Zählen</summary>

   Bisher haben wir bei der Erzeugung eines Haustiers die Klassenvariable `number_of_pets_` um eins erhöht. Damit haben wir stets die Anzahl der bisher erstellten `Pet`-Objekte gekannt.

   Wir möchten allerdings nicht nur wissen, wie viele Haustiere erzeugt wurden, sondern auch, wie viele `Pet`-Objekte es *aktuell* gibt. Diese Zahl soll gleich wie `number_of_pets_` bei der Haustier-Erzeugung um eins erhöht werden. Allerdings soll dieser Wert beim Destruktoraufruf eines `Pet`-Objekts um eins verringert werden. Erstelle dazu eine zweite Klassenvariable namens `current_number_of_pets`, welche in Konstruktoren um eins erhöht und im Destruktor um eins verringert wird.

   **Beachte:** Diese Membervariable ist eine _Klassenvariable_ (`static`), weil sie für die gesamte `Pet`-Klasse gilt und sich nicht von Objekt zu Objekt unterscheiden soll.

   Erstelle auch eine Klassenmethode namens `getCurrentNumberOfPets`, welche den Wert von <code>current_number_of_pets</code> zurückgibt.

   Damit die Nutzer\*innen der Haustier-Klasse `number_of_pets_` nicht mit `current_number_of_pets` verwechseln, benennen wir `number_of_pets_` in `cumulative_number_of_pets_` um. Der entsprechende Getter soll analog dazu nun `getCumulativeNumberOfPets` heißen.

   **Tipp:** Um besser zu erkennen, wann der Destruktor eines Haustier-Objekts aufgerufen wird, kannst du im Destruktor eine Ausgabe veranlassen. Zum Beispiel könntest du im Destruktor die Zeile

   ```cpp
   cout << "bye bye" << endl;
   ```

   einfügen. Kommentiere diese Zeile jedoch wieder aus, bevor du wie [unten](#lösung) beschrieben testest, denn im Referenzoutput fehlt diese Ausgabe.
   </details>

## Lösung

Ändere die Datei `pets.cpp`, um die oben beschriebene Aufgabe zu lösen. Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird eine Datei namens `testreport.html` erstellt. Sie enthält einen Bericht, der dir zeigt, welche Ausgabe dein Programm produzieren sollte und welche Ausgabe dein Programm produziert. Du erhältst auf diese Weise sofortiges Feedback zu deiner überarbeiteten `pets.cpp`-Datei.

Solltest du Probleme haben, das Übungsbeispiel zu lösen, so kannst du dir eine mögliche Lösung in `solution.cpp` ansehen. Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

## Mitwirkende an diesem Übungsbeispiel

Aleksandar Karakaš
