# Klassen für Strings

## (a) 1 Punkt

Erstellen Sie eine eigene Klasse für Strings. Die zu schreibende Klasse muss `String` heißen. Die Klasse hat ein Attribut, welches den Zugriff auf die einzelnen Zeichen erlaubt. Das Attribut muss `string_` heißen. Sie dürfen selbst einen passenden Datentyp für das Attribut wählen, wobei jedoch die Klasse `std::string` nicht als Datentyp erlaubt ist.

## (b) 1 Punkt

Erstellen Sie für die Klasse einen einparametrigen Konstruktor. Der Parameter ist vom Typ `char*` und zeigt auf einen C-String. Der Konstruktor muss dafür sorgen, dass der Inhalt des C-Strings (die einzelnen Zeichen) kopiert werden. Ob auch das abschließende 0-Byte kopiert wird, dürfen Sie selbst entscheiden. Die kopierten Inhalte müssen nach dem Konstruktor über das Attribut `string_` verfügbar sein. Es soll auch ein Copy-Konstruktor implementiert werden, der Copy-Assignment-Operator wird allerdings nicht gefordert.

## (c) 2 Punkte

Die Zeichen eines `String`-Objekts können auf zwei verschiedene Arten ausgegeben werden. (Am Ende des Strings soll dabei nie ein 0-Byte ausgegeben werden.)

- Die erste Möglichkeit ist die Verwendung einer Methode namens `print`. Diese Methode hat keinen Rückgabewert und soll die Zeichen des Strings mithilfe von `std::cout` ausgeben.
- Die zweite Möglichkeit ist die Verwendung des `<<`-Operators. Überladen Sie den `<<`-Operator, um die Zeichen des Strings auszugeben.

## (d) 1 Punkt

Leiten Sie eine Klasse namens `SecretString` von `String` ab. Der Konstruktor der Subklasse hat zwei Parameter. Der erste Parameter des Konstruktors ist ein C-String (wie in der Basisklasse). Der zweite Parameter des Konstruktors ist ein `char`, welcher in einem Attribut namens `symbol_` gespeichert wird. Es soll auch ein Copy-Konstruktor implementiert werden, der Copy-Assignment-Operator wird allerdings nicht gefordert.

## (e) 2 Punkte

Die Klasse `SecretString` soll – wie die Basisklasse – die Ausgabe mit einer `print`-Methode und dem `<<`-Operator anbieten. Bei der Ausgabe soll hier jedoch jedes Zeichen durch das Zeichen ersetzt werden, welches in `symbol_` gespeichert ist.

Im Zusammenhang mit der `print` Methode soll Polymorphie unterstützt werden. (Im Zusammenhang mit dem `<<`-Operator wird das nicht gefordert und auch nicht überprüft.) Das bedeutet zum Beispiel, dass der Aufruf der `print`-Methode auf einer Referenz zu einem `SecretString`-Objekt zur Ausgabe gemäß der `SecretString`-Implementierung der `print`-Methode führen muss – auch wenn die Variable, auf der die `print`-Methode aufgerufen wird, vom Typ der Basisklassen-Referenz ist.

---

> **Hinweis:** Für die Bearbeitung der Aufgabe dürfen Sie die Online-IDE verwenden, auf die Sie mit folgendem Link zugriffen haben: <https://www.onlinegdb.com/>

> **Hinweis:** Es dürfen neben den in der Angabe angeführten Methoden auch weitere Methoden geschrieben werden. Das kann unter Umständen sogar notwendig sein.

> **Hinweis:** Es ist darauf zu achten, dass bei der Verwendung der beiden String-Klassen keine Memory Leaks auftreten können.
