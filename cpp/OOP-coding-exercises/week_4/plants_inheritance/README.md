# Übungsbeispiel Plants
## Das Problem

Um noch etwas mehr Übung im Bereich der Vererbung zu bekommen, soll in diesem Beispiel ein kleiner Garten bestehend aus verschiedenen Pflanzen erstellt werden. Hierfür wird bereits die Datei `main.cpp` mit der `main`-Funktion zur Verfügung gestellt. Sie übernimmt die Ausführung des Programms. Die in `main.cpp` verwendeten Klassen müssen jedoch erst erstellt werden.

## Deine Lösung

Erstelle die fehlenden Klassen

- `Plant`,
- `Flower`,
- `Cactus` und
- `Tree`,

welche unten beschrieben werden. Die dabei geschriebenen Dateien sollen nach den jeweiligen Klassen bennant werden. So soll etwa der Code für die Klasse `Plant` in den Datei `Plant.hpp` und `Plant.cpp` stehen. Die `.hpp`-Endung ist erforderlich, weil `.hpp`-Dateien in `main.cpp` inkludiert werden.

Im Folgenden werden die Attribute und Methoden aller zu schreibenden Klassen beschrieben.

**TIPP:** Überlege dabei selbst, welche Methoden virtuell sein müssen.


### Klasse Plant

Erstelle die Klasse `Plant`. Diese Klasse beschreibt beliebige Pflanzen und dient sie als Basisklasse für die Klassen `Flower`, `Cactus` und `Tree`.

#### Attribute

- `water_level_`
    - `int`, welcher den aktuellen Wasserstand der Pflanze beschreibt
- `NEEDED_WATER_`
    - konstanter `int` welcher den täglichen Wasserbedarf der Pflanze beschreibt

#### Methoden


- `Plant(int needed_water);`
    - ein Konstruktor mit einem Parameter
    - Soll das Attribut `NEEDED_WATER_` auf den Wert des Parameters `needed_water` setzen und das Attribut `water_level_` auf `0`.
- `Plant();`
    - ein Konstruktor ohne Parameter
    - Soll das Attribut `NEEDED_WATER_` auf den Wert `10` setzen und das Attribut `water_level_` auf `0`.
- `waterPlant(int amount_of_water)`
    - Methode, welche den `water_level_` um `amount_of_water` erhöht
    - Sollte der `water_level_` größer als `NEEDED_WATER_` sein, so soll folgender Text ausgegeben werden (*beachte die Leerzeichen am Anfang Ausgabe!*):
    ```
      Thank you for watering me.\n
    ```
    - Rückgabewert: `void`



### Klasse Flower

Die Klasse `Flower` stellt eine Blume dar. Sie wird von `Plant` abgeleitet.

#### Attribute

- `blossom_`
    - `bool`, welcher angibt, ob die Blume blüht

#### Methoden
- `Flower()`
    - ein Konstruktor ohne Parameter
    - ruft den parameterlosen Konstruktor der Basisklasse auf und setzt `blossom_` auf `false` 
- `getBlossom()`
    - Getter für `blossom_`
- `setBlossom(bool blossom)`
    - Setter für `blossom_`


### Klasse Cactus

Die Klasse `Cactus` stellt einen Kaktus dar. Sie wird von `Plant` abgeleitet.

#### Attribute

- `ALLOWED_WATER_LEVEL_`
    - konstanter `int`, welcher den maximalen Wasserlevel der Pflanze beschreibt - dieser soll für alle Instanzen `1` sein.

#### Methoden
- `Cactus()`
    - ein Konstruktor ohne Parameter
    - ruft den Konstruktor der Basisklasse auf, welcher `NEEDED_WATER_` auf `0` setzt

- `waterPlant(int amount_of_water)`
    - überschreibt die gleichnamige Methode der Basis Klasse
    - Sollte `water_level_` größer als `ALLOWED_WATER_LEVEL_` sein, so soll folgender Text ausgegeben werden (*beachte die Leerzeichen am Anfang Ausgabe!*): 
    ```
      Help I am drowning.\n
    ```
    - Rückgabewert: `void`


### Klasse Tree

Die Klasse `Tree` stellt einen Baum dar. Sie wird von `Plant` abgeleitet.

#### Attribute

- `full_grown_`
    - `bool`, welcher angibt, ob der Baum seine volle Größe erreicht hat

#### Methoden
- `Tree()`
    - ein Konstruktor ohne Parameter
    - ruft den parameterlosen Konstruktor der Basisklasse auf und setzt `full_grown_` auf `false` 
- `getFullGrown()`
    - Getter für `full_grown_`
- `setFullGrown()`
    - Setter für `full_grown_` - Dieser kann das Attribut `full_grown_` lediglich auf `true` setzen (da ein Baum ja nicht kleiner werden kann).



### Programmablauf

Der Programmablauf ist bereits in `main.cpp` festgelegt und soll nicht verändert werden.


## Testen

Bei diesem Beispiel gibt es automatische Tests, die mit `make test` gestartet werden können.

## Lösung

Eine Lösung unserer Tutor\*innen befindet sich im Ordner `solution`. Im Ordner `solution` gibt es auch ein Makefile. Das heißt, dass du im Ordner `solution` ebenfalls `make test` ausführen kannst. Damit wird die Lösung unserer Tutor\*innen getestet.

