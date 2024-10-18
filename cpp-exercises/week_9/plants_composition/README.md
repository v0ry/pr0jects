# Übungsbeispiel Plants mit Komposition

## Lernziele

Dieses Beispiel soll zeigen, wie Komposition als alternatives bzw. ergänzendes Konzept zu Polymorphie eingesetzt werden kann. Nach der Lösung dieses Beispiels hast du verstanden, dass Attribute nicht nur beschreibende Daten enthalten können, sondern sogar das Verhalten einer Klasse definieren können. Nach diesem Beispiel wirst du auch wissen, wie du das Verhalten einer Klasse mittels Komposition festlegen kannst.

## Das Problem

Es wird ähnlich wie [in einem anderen Übungsbeispiel](../../week_4/plants_inheritance/README.md) ein kleiner Garten erstellt. Im anderen Übungsbeispiel erlangten die Pflanzen mit Hilfe von Vererbung unterschiedliches Verhalten. In diesem Beispiel möchten wir den Pflanzen unterschiedliches (Wachstums-)Verhalten durch *Komposition* verleihen. Hierfür steht die Datei `main.cpp` mit der `main`-Funktion bereits zur Verfügung. Sie übernimmt die Ausführung des Programms. Die in `main.cpp` verwendeten Klassen müssen jedoch erst erstellt werden.

## Deine Lösung

Erstelle die in `main.cpp` verwendeten Klassen. Schreibe den dafür nötigen Code in Dateien, die nach den jeweiligen Klassen benannt sind – z. B. soll die Klasse `Plant` in den Files `Plant.hpp` und `Plant.cpp` implementiert werden.

In der Folge werden die zu schreibenden Klassen beschrieben. Alle Attribute, deren Sichtbarkeit nicht spezifiziert wurde, sollen `private` sein.

### Klasse `Plant`

Die Klasse `Plant` beschreibt beliebige Pflanzen und besteht aus drei Komponenten:

- `GrowthBehaviour` beschreibt, wie schnell die Pflanze wächst.
- `Blossom` beschreibt die Blüten einer Pflanze.
- `Fruit` beschreibt die Frucht der Pflanze.

#### Attribute

- `name_`
  - `std::string`, der Name der Pflanze
- `growth_behaviour_`
  - `GrowthBehaviour*`, Pointer auf das Wachstumsverhalten der Pflanze. Ein Pointer ist hier deswegen notwendig, damit Polymorphie funktionieren kann (abgeleitete Methode wird aufgerufen).
- `blossom_`
  - `Blossom`, beschreibt die Blüten der Pflanze
- `fruit_`
  - `Fruit`, beschreibt die Früchte der Pflanze

#### Methoden

- `Plant(std::string name, GrowthBehaviour* growth_behaviour, Blossom blossom, Fruit fruit)`
  - Konstruktor, initialisiert die Attribute der Klasse
- `waterPlant(int amount_of_water)`
  - Die Pflanze wird bewässert, indem die Methode `addWater()` der `growth_behaviour`-Komponente aufgerufen wird
  - Auch soll der Text `Watering the <name> with <amount> ml.\n` ausgegeben werden, wobei `<name>` = Name der Pflanze und `<amount>` = `amount_of_water`-Parameter der Methode
  - Rückgabewert: `void`
- `showDescription()`
  - Es soll eine Beschreibung der Pflanze durch folgenden Text angezeigt werden: `The <name> is <size> cm tall, has <growth_description> growth, <blossom> blossoms and grows <fruit>.\n`
  - `<name>` = Name der Pflanze
  - `<size>` = Rückgabewert der Methode `getSize()` der `growth_behaviour_`-Komponente
  - `<growth_description>` = Rückgabewert der Methode `getDescription()` der `growth_behaviour_`-Komponente
  - `<blossom>` = Rückgabewert der Methode `getColour()` der `blossom_`-Komponente
  - `<fruit>` = Rückgabewert der Methode `getDescription()` der `fruit_`-Komponente
  - Rückgabewert: `void`

### Klasse GrowthBehaviour

Diese abstrakte Klasse ist die Basis für verschiedene Wachstumsverhalten von Pflanzen.

#### Attribute

- `size_`
  - `int`, beschreibt die aktuelle Größe der Pflanze
  - soll `protected` sein, damit die abgeleiteten Klassen darauf zugreifen können
- `description_`
  - `std::string`, enthält die Beschreibung des Wachstumsverhaltens

#### Methoden

- `GrowthBehaviour(std::string description)`
  - Konstruktor, soll `description_` mit `description` und `size_` mit `0` initialisieren
- `~GrowthBehaviour()`
  - Destruktor, der nichts macht. Er ist `virtual`, damit beim Einsatz von Polymorphie auch der Subklassen-Destruktor aufgerufen wird.
- `getSize()`
  - Getter für das Attribut `size_`
- `getDescription()`
  - Getter für das Attribut `description_`
- `addWater(int amount_of_water)`
  - Ändert die Größe der Pflanze abhängig von der Wassermenge und dem Wachstumsverhalten
  - Rein virtuelle Methode (pure virtual member function)
  - Rückgabewert: `void`

### Klasse QuadraticGrowthBehaviour

Wird von `GrowthBehaviour` abgeleitet und beschreibt ein quadratisches Wachstum.

#### Methoden

- `QuadraticGrowthBehaviour()`
  - Konstruktor, welcher den `GrowthBehaviour`-Konstruktor mit dem String `quadratic` aufrufen soll
- `addWater(int amount_of_water)`
  - Implementierung der Basisklassen-Methode. `size_` soll um `amount_of_water`<sup>2</sup> erhöht werden

### Klasse NoGrowthBehaviour

Wird von `GrowthBehaviour` abgeleitet und beschreibt Pflanzen, die nicht wachsen.

#### Methoden

- `NoGrowthBehaviour(int fixed_size)`
  - Konstruktor, welcher den `GrowthBehaviour`-Konstruktor mit dem String `no` aufruft und das `size_`-Attribut der Basisklasse auf den übergebenen Parameter setzt
- `addWater(int amount_of_water)`
  - Implementierung der Basisklassen-Methode, welche nichts tun soll (`size_` soll nicht verändert werden)

### Klasse Blossom

Diese Klasse beschreibt die Blüten einer Pflanze.

#### Attribute

- `colour_`
  - `std::string`, beschreibt die Farbe der Blüten

#### Methoden

- `Blossom(std::string colour)`
  - Konstruktor, initialisiert das Attribut `colour_` mit dem Wert des Parameters `colour`
- `getColour()`
  - Getter für das Attribut `colour_`

### Klasse Fruit

Diese Klasse beschreibt die Früchte einer Pflanze.

#### Attribute

- `description_`
  - `std::string`, beschreibt die Eigenschaften der Früchte

#### Methoden

- `Fruit(std::string description)`
  - Konstruktor, initialisiert das Attribut `description_` mit dem Wert des Parameters `description`
- `getDescription()`
  - Getter für das Attribut `description_`

## Testen

Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird eine Datei namens `testreport.html` erstellt. Sie enthält einen Bericht, der dir zeigt, welche Ausgabe dein Programm produzieren sollte und welche Ausgabe dein Programm produziert. Damit erhältst du sofortiges Feedback zu deiner Lösung.

## Lösung

Eine Lösung unserer Tutor\*innen befindet sich im Ordner `solution`. Solltest du Probleme haben, das Übungsbeispiel zu lösen, dann könnte dir diese von uns bereitgestellte Lösung helfen. Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

Im Ordner `solution` gibt es auch ein Makefile. Das heißt, dass du im Ordner `solution` ebenfalls `make test` ausführen kannst. Damit wird die Lösung unserer Tutor\*innen getestet.

## Mitwirkende an diesem Übungsbeispiel

### Autor\*innen

- Kilian Payer
- Markus Meierhofer

### Lektorat

- Aleksandar Karakaš
