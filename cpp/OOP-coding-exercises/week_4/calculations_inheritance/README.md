# Übungsbeispiel Calculations
## Das Problem

In diesem Beispiel soll ein einfacher Taschenrechner programmiert werden, der mit vorgegebenen Ganzzahlen vom Typ `int` 
Additionen und Subtraktionen durchführt. Hierfür wird bereits die Datei `main.cpp` mit der `main`-Funktion zur Verfügung gestellt. Sie
übernimmt die Ausführung des Programms. Die in `main.cpp` verwendeten Klassen müssen jedoch erst erstellt werden.


## Deine Lösung

Erstelle die fehlenden Klassen

 - `Calculation`,
 - `Addition` und
 - `Subtraction`,

welche unten beschrieben sind. Jede Klasse ist in einer entsprechenden Datei mit der Endung `.hpp` zu schreiben, da diese Dateien in `main.cpp` mit `#include` eingefügt werden. So ist z. B. eine Klasse namens `Addition` in eine Datei namens `Addition.hpp` zu schreiben.

### Klasse Calculation

Erstelle die Klasse `Calculation`. Diese Klasse ist eine abstrakte Klasse, die als Basisklasse für die 
beiden Klassen `Addition` und `Subtraction` verwendet wird.

#### Attribute

- `a_`
    - erster Integer für die Berechnung
- `b_`
    - zweiter Integer für die Berechnung
- `operator_symbol_`
    - `char`, der in der Ausgabe verwendet wird, um den Operator darzustellen (`'+'` oder `'-'`)

#### Methoden

- `Calculation(int a, int b, char operator_symbol_)`
    - Ein Konstruktor mit 3 Parametern
    - Soll das Attribut `a_` auf den Wert des Parameters `a` setzen, das Attribut `b_` auf den Wert von `b` und 
      das Attribut `operator_symbol_` auf den Wert des Parameters `operator_symbol`
- `calculate()`
    - rein virtuelle (pure virtual) Methode für die Berechnung in den Subklassen
    - Rückgabewert: `int`
- `getOperatorSymbol()`
    - Soll das Attribut `operator_symbol_` zurückgeben
    - Rückgabewert: `char`
- `getA()`
    - Soll das Attribut `a_` zurückgeben
    - Rückgabewert: `int`
- `getB()`
  - Soll das Attribut `b_` zurückgeben
  - Rückgabewert: `int`



### Klasse Addition

Die Klasse `Addition` stellt eine Addition dar. Sie wird von `Calculation` abgeleitet.

#### Attribute

Diese Klasse hat keine zusätzlichen Attribute.

#### Methoden
- `Addition(int a, int b)`
    - ein Konstruktor mit zwei Parametern
    - ruft den Konstruktor der Basisklasse auf, sodass die beiden Attribute `a_` und `b_` die Werte von `a` bzw. `b` erhalten und 
  `operator_symbol_` auf `'+'` gesetzt wird.
- `calculate()`
    - implementiert die pure virtual Methode aus der Basisklasse
    - gibt das Ergebnis der Addition zurück
    - Rückgabewert: `int`


### Klasse Subtraction

Die Klasse `Subtraction` stellt eine Subtraktion dar. Sie wird von `Calculation` abgeleitet.

#### Attribute

Diese Klasse hat keine zusätzlichen Attribute.

#### Methoden
- `Subtraction(int a, int b)`
  - ein Konstruktor mit zwei Parametern
  - ruft den Konstruktor der Basisklasse auf, sodass die beiden Attribute `a_` und `b_` die Werte von `a` bzw. `b` erhalten und 
  `operator_symbol_` auf `'-'` gesetzt wird.
- `calculate()`
  - implementiert die pure virtual Methode aus der Basisklasse
  - gibt das Ergebnis der Subtraktion zurück
  - Rückgabewert: `int`


### Programmablauf

Der Programmablauf ist bereits in `main.cpp` festgelegt und soll nicht verändert werden.


## Testen

Bei diesem Beispiel gibt es automatische Tests, die mit `make test` gestartet werden können.

## Lösung

Eine Lösung unserer Tutor\*innen befindet sich im Ordner `solution`. Im Ordner `solution` gibt es auch ein Makefile. Das heißt, dass du im Ordner `solution` ebenfalls `make test` ausführen kannst. Damit wird die Lösung unserer Tutor\*innen getestet.

> **Tipp:** Sobald du die drei fehlenden `.hpp`-Dateien erfolgreich geschrieben und getestet hast, kannst du versuchen, die Klassen in jeweils eine `.hpp`- und eine `.cpp`- Datei aufzuteilen. Diese Aufteilung wirst du auch in den Assignments machen. Deshalb ist es eine gute Übung, es bei einem kleinen Beispiel wie diesem auszuprobieren. Dabei kannst du z. B. die Getter von `Calculation` in eine `.cpp`-Datei auslagern. Außerdem kannst du die Implementierungen von `calculate()` in die Dateien `Addition.cpp` bzw. `Subtraction.cpp` schreiben. (Die Aufteilung in `.hpp`- und `.cpp`-Dateien erfordert keine Änderungen in `main.cpp`. Auch die Kompilierbefehle im Makefile funktionieren nach der Aufteilung weiterhin.)

