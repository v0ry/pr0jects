# `static` Members

Dieses Beispiel ist unbewertet. Wenn du es löst, bekommst du keine zusätzlichen Punkte für die KU, aber du kannst ein tieferes Verständnis der behandelten Themen erlangen und dein Wissen festigen.

## Lernziele

Ziel dieses Übungsbeispiels ist es, die Verwendung von `static` Membern zu üben.

## Das Problem

Die `Pet`-Klasse in der Datei `pets.cpp` entspricht der Lösung der vorherigen Aufgabe. Der einzige Unterschied zu [../pets_6_more_constructors/solution.cpp](../pets_6_more_constructors/solution.cpp) ist die `main`-Funktion. In der `main`-Funktion wird an zwei Stellen versucht, die Anzahl der erstellten Haustier-Objekte auszugeben. Leider bietet die `Pet`-Klasse keine Member, die uns bei der Ermittlung der bisher erstellten Haustier-Objekte helfen. 🙁️

## Deine Aufgabe

### 1. Vervollständige die Klasse `Pet`
Erstelle eine Methode namens `getNumberOfPets`. Sie soll die Anzahl der bisher erstellten `Pet`-Objekte zurückgeben.

Die Methode benötigt keinen Zugriff auf Membervariablen eines Haustierobjekts (weder die Tierart noch das Alter). Daher kann und soll sie als *Klassen*methode (`static`) implementiert werden.

<details>
<summary>Woher weiß nun die Methode, wie viele Haustier-Objekte es gibt? 🤔️ Du kannst selbst versuchen, dir eine Lösung zu überlegen oder du blendest mit einem Klick hier weitere Details ein und liest einfach weiter 😉️</summary>

Die Lösung ist, die Anzahl der bisher erstellten `Pet`-Objekte in einer Variablen zu speichern. Diese Variable soll beim Erstellen eines Haustier-Objekts – also im Konstruktor – um eins erhöht werden. Da mit einer solchen Variable Haustiere gezählt werden, sollte sie auch Teil der `Pet`-Klasse sein.

Achtung, diese Variable kann nicht einfach eine herkömmliche Membervariable wie das Alter (`age_`) sein! Grund: Jedes Tier hat ein **eigenes** Alter aber _kein_ Tier hat eine **eigene** Anzahl an bisher erstellten Haustier-Objekten.

Die Anzahl der bisher erstellten Haustier-Objekte ist also eine **Eigenschaft der `Pet`-Klasse**. Daher speichern wir die Anzahl der bisher erstellten Haustier-Objekte in einer _Klassenvariable_, für welche wir das Schlüsselwort `static` verwenden.

Erstelle also eine private `static` Membervariable (vom Typ `unsigned`) namens `number_of_pets_`, welche im Konstruktor um eins erhöht wird. Der Wert dieser Variable soll von der zu schreibenden Methode `getNumberOfPets` zurückgegeben werden.

<table>
  <thead>
    <tr>
      <td align="left" style="font-weight: bold; vertical-align: top;">
        Hinweis:
      </td>
      <td>
        Wir bezeichnen nicht-<code>static</code> Membervariablen – also solche, deren Wert sich von Objekt zu Objekt unterscheiden kann – auch als <em>Instanzvariablen</em>, um hervorzuheben, dass es sich um keine Klassenvariablen (<code>static</code>) handelt. Die Membervariable <code>age_</code> ist zum Beispiel eine Instanzvariable. Die Membervariable <code>number_of_pets_</code> soll eine Klassenvariable sein. 
      </td>
    </tr>
  </thead>

  <tbody>
  </tbody>
</table>


</details>


### 2. Ändere zwei Zeilen in `main`
In der `main`-Funktion werden einige Haustier-Objekte erstellt. Dieser Teil ist bereits implementiert.

Um zu testen, ob unsere neue Version der `Pet`-Klasse funktioniert, soll am Anfang und am Ende der `main`-Funktion ausgegeben werden, wie viele `Pet`-Objekte bis zum jeweiligen Zeitpunkt erstellt wurden. Die zwei Stellen, an denen diese Ausgabe erfolgen soll, sind mit einem `TODO`-Kommentar markiert. Nutze an beiden zu bearbeitenden Stellen die neue Methode `getNumberOfPets`.


## Lösung

Ändere die Datei `pets.cpp`, um die oben beschriebene Aufgabe zu lösen. Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird eine Datei namens `testreport.html` erstellt. Sie enthält einen Bericht, der dir zeigt, welche Ausgabe dein Programm produzieren sollte und welche Ausgabe dein Programm produziert. Du erhältst auf diese Weise sofortiges Feedback zu deiner überarbeiteten `pets.cpp`-Datei.

Solltest du Probleme haben, das Übungsbeispiel zu lösen, so kannst du dir eine mögliche Lösung in `solution.cpp` ansehen. Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

## Mitwirkende an diesem Übungsbeispiel
Aleksandar Karakaš