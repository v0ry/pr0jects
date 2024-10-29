# Übungsbeispiel: Bruch

## Lernziele

Ziel dieses Übungsbeispiels ist es, Operator-Overloading und Exception-Handling in einem Programm zu implementieren. Auch das Schreiben einer eigenen Exception-Klasse soll geübt werden.

## Aber worum geht es denn?

In den Dateien `Fraction.hpp` und `Fraction.cpp` soll eine Klasse `Fraction`, die einen Bruch - also eine rationale Zahl - darstellt, erstellt werden. Nach fertiger Implementierung soll mit dieser Klasse wie mit gewöhnlichen `int` oder `double` mit den Operatoren `+`, `*`, `==` ... gerechnet werden können.

Beim Rechnen mit Brüchen ist außerdem zu beachten, dass der Nenner nie `0` werden darf. Insbesondere beim Erstellen eines neuen Bruchs, aber auch beispielsweise beim Dividieren könnte es hier zu einem Problem kommen. Dafür soll eine eigene Exception `DivideByZeroException` implementiert werden.

---

## Klasse `Fraction`

Die Klasse `Fraction` soll einen Bruch darstellen. Dafür werden zwei Attribute benötigt, nämlich ein Zähler (`nominator_`) und ein Nenner (`denominator_`).

Ein Bruch soll intern nach jeder Operation (z. B. addieren oder multiplizieren) immer in gekürzter Form gespeichert sein und der Nenner soll immer positiv sein. Beispielsweise soll `5/-15` als `-1/3` gespeichert werden. Falls der Bruch den Wert `0` annimmt, soll der Nenner den Wert `1` besitzen.

### Konstruktoren

Ein Bruch soll auf drei Arten erstellt werden können:

| Parameter | Beschreibung |
| --------- | ------------ |
| keiner | Der Bruch soll den Wert `0` besitzen. |
| `int` | Der Bruch soll den Wert der Ganzzahl besitzen. |
| `int`, `int` | Erster Paramter ist der Zähler, zweiter der Nenner. |

Im letzten Fall ist außerdem zu überprüfen, dass es zu keiner Division durch `0` kommt, ansonsten soll eine `DivideByZeroException` geworfen werden mit dem Text `0 in the denominator invalid!\n`. Außerdem ist zu beachten, dass der Bruch in oben beschriebener Form (gekürzt und mit nicht-negativem Nenner) gespeichert werden soll.

> **Tipp:** Es ist nicht notwendig drei unterschiedliche Konstruktoren zu erstellen. Wenn man es geschickt löst, kommt man mit einem aus.

Copy-Konstruktor bzw. Copy-Assignment-Operator sollen als Übung explizit implementiert werden. Wichtig beim Copy-Assignment-Operator ist es, dass auch folgendes möglich sein soll: `b1 = b2 = b3`.

> **Tipp:** Überlege, ob es hier auch zu einer Division durch `0` kommen kann bzw. ob der Bruch gekürzt werden muss.

### Methoden

- `getNominator()`
  - Getter für den Zähler
- `getDenominator()`
  - Getter für den Nenner
- `value()`
  - gibt den Wert des Bruchs als `double` zurück
- `reduce()`
  - private Methode, um den Bruch zu kürzen und den Nenner positiv zu machen

> **Tipp:** [Euklidischer Algorithmus](https://de.wikipedia.org/wiki/Euklidischer_Algorithmus). Alternativ kann man auch alle möglichen Teiler durchprobieren; das ist zwar nicht besonders effizient, aber es funktioniert auch.

### Ausgabeoperator

Es soll ein Ausgabeoperator implementiert werden, wobei `b1` im folgenden Beispiel ein Objekt der Klasse `Fraction` ist.

- `std::cout << b1`
  - `b1` soll in der Form: `<nominator> / <denominator>\n` ausgegeben werden, wobei `<nominator>` durch den Zähler und `<denominator>` durch den Nenner von `b1` zu ersetzen sind.

### Arithmetische Operatoren

Folgende Operationen sollten auf jeden Fall implementiert werden, wobei der Copy-Assignment-Operator bereits implementiert sein sollte. In den folgenden Beispielen sind `b1`, `b2` und `b3` Brüche, während `a` ein `int` ist.

> **Tipp:** Manche Operatoren sind einfacher als Methode zu implementieren, andere wiederum müssen sogar unbedingt als Funktion implementiert werden.

- `b1 = b2 + b3`
  - `b2` und `b3` werden zusammenaddiert, ändern sich aber nicht
- `b1 = b2 += b3`
  - `b3` wird direkt auf `b2` addiert
  - das Ergebnis kann an `b1` zugewiesen werden
- `b1 = b2 + a`
  - `b2` und `a` werden zusammenaddiert, ändern sich aber nicht (`a` ist ein `int`!)
- `b1 = a + b3`
  - `a` und `b3` werden zusammenaddiert, ändern sich aber nicht (`a` ist ein `int`!)
- `b1 = b2++`
  - post-increment
  - in `b1` wird der alte Wert von `b2` geschrieben
  - anschließend wird `b2` um den Wert `1` erhöht
- `b1 = ++b2`
  - pre-increment
  - `b2` wird um den Wert `1` erhöht
  - das Ergebnis wird in `b1` geschrieben
- `b1 = -b2`
  - `b1` wird das Negative von `b2` zugewiesen
  - `b2` bleibt unverändert
- `b1 = ~b2` (eigentlich ein bitweiser Operator, hier aber mit anderer Bedeutung)
  - `b1` wird der Kehrwert von `b2` zugewiesen
    - der Nenner soll weiterhin positiv sein
    - `DivideByZeroException` falls der Nenner `0` ist
  - `b2` bleibt unverändert
- `b1 = b2 /= b3`
  - `b2` wird durch `b3` durchdividiert
  - `DivideByZeroException` falls durch `0` dividiert wird
    - in diesem Fall soll der `DivideByZeroException` der Text `Dividing by 0 not valid!\n` übergeben werden
  - das Ergebnis kann an `b1` zugewiesen werden

Alle weiteren arithmetischen Operatoren, wie beispielsweise `-`, `-=`, `--`, `*`, `/`... können analog implementiert werden.

### Logische Operatoren und Vergleichsoperatoren

Folgende Operatoren sollten auf jeden Fall implementiert werden. `b1`, `b2` sind wiederum Brüche.

- `b1`
  - ist genau dann `false`, wenn der Bruch den Wert `0` besitzt
  - **Wichtig!** `int a = b1;` darf nicht gültig sein bzw. kompilieren. Daher ist das Schlüsselwort `explicit` (nicht in VO behandelt) zu verwenden.
- `!b1`
  - ist genau dann `true`, wenn der Bruch den Wert `0` besitzt
- `b1 == b2`
  - ist genau dann `true`, wenn `b1` und `b2` denselben Wert besitzen
- `b1 != b2`
  - ist genau dann `true`, wenn `b1` und `b2` verschiedene Werte besitzen
- `b1 < b2`
  - ist genau dann `true`, wenn `b1` echt kleiner als `b2` ist
- `b1 <= b2`
  - ist genau dann `true`, wenn `b1 < b2` oder `b1 == b2`

Alle weiteren Vergleichsoperatoren können analog implementiert werden.

---

## Klasse `DivideByZeroException`

Diese Klasse stellt eine Exception dar und soll eine Fehlermeldung liefern, wenn in einem Bruch der Nenner `0` werden würde oder durch `0` dividiert wird. Daher soll diese Klasse auch von `std::exception` abgeleitet werden. Innerhalb der Klasse soll es genau ein Attribut gegeben, nämlich die Fehlermeldung `message_`, als `const char*`. (Wir können an dieser Stelle leider keinen C++-String verwenden, da die Möglichkeit besteht, dass dieser selbst eine Exception auflöst. Damit würden aber gleichzeitig zwei Exception behandelt werden müssen, was nicht möglich ist.)

### Konstruktor

Die Klasse soll einen Konstruktor besitzen. Dieser erhält als einzigen Parameter einen C-String (`const char*`) und initialisiert mit diesem das Attribut `message_`.

Der Copy-Konstruktor soll ebenfalls implementiert werden (default), da dies abhängig von der C++ Version notwendig ist. Der Copy-Assignment-Operator kann hingegen gelöscht werden.

### Methoden

Außerdem soll in der Klasse genau eine Methode implementiert werden, nämlich die `what()`-Methode aus der Basisklasse. Diese Methode liefert als Rückgabewert einen `const char*`, ist selbst `const`, darf selbst keine Exception werfen (`noexcept`) und überschreibt die Methode aus der Basisklasse (`override`). Hier soll das Attribut `message_` zurückgegeben werden.

---

## Testen

Ein kurzes Testprogramm, das die wesentlichen Funktionalitäten überprüft, steht zur Verfügung (`test.cpp`). Am Beginn des Testprogramms gibt es mehrere `#define` Statements. Über diese ist es möglich Testcases ein- bzw. auszuschalten. Zu Beginn empfiehlt es sich daher nur den ersten Testcase auf `1` zu lassen und allen weiteren Testcases den Wert `0` zuzuweisen. Dadurch werden die entsprechenden Programmteile nicht mitkompiliert und es ist kein Problem, wenn noch nicht alle Methoden der Klasse `Fraction` implementiert worden sind.

In den Testcases selbst werden die Werte von den Brüchen immer mithilfe von `assert`s überprüft. Falls ein Wert nicht der Vorgabe entsprechen sollte, wird das Programm an dieser Stelle abgebrochen.

Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird das Testprogramm gestartet und du erhältst auf diese Weise sofortiges Feedback zu deiner Lösung.

Natürlich kannst du zum Testen auch eigene kurze Programme schreiben, in denen Instanzen von Brüchen erstellt und mit diesen dann die einzelnen Operatoren überprüft werden.

## Lösung

Eine Lösung unserer Tutor\*innen befindet sich im Ordner `solution`. Solltest du Probleme haben, das Übungsbeispiel zu lösen, dann könnte dir diese von uns bereitgestellte Lösung helfen. Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

Im Ordner `solution` gibt es auch ein Makefile. Das heißt, dass du im Ordner `solution` ebenfalls `make test` ausführen kannst. Damit wird die Lösung unserer Tutor\*innen getestet.

## Mitwirkende an diesem Übungsbeispiel
### Autor\*innen

- Michael Guttmann

### Lektorat

 - Aleksandar Karakaš
 
