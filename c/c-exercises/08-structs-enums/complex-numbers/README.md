# Komplexe Zahlen

In diesem Übungsbeispiel soll der Umgang mit eigenen Datentypen geübt werden. Hierzu soll eine Struktur für komplexe Zahlen erstellt werden und Rechenoperationen implementiert werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Funktionen
  - Pointer, Parameterübergabe
  - Structs

Lines of Code der Musterlösung: 84 inkl. Main-Funktion

---

## Anleitung

### Datentyp

Es soll ein eigener Datentyp `Complex` erstellt werden, der eine komplexe Zahl darstellt. Als Attribute werden sowohl der Real- als auch der Imaginärteil benötigt, beide sollen vom Datentyp `double` sein.

### Programmablauf

1. Zu Beginn des Programms werden Real- und Imaginärteil von zwei komplexen Zahlen eingelesen (bereits implementiert).
Nun sollen die eingelesenen Werte tatsächlich in den vorgesehenen komplexen Zahlen `a` und `b` gespeichert werden. Hierzu soll eine Initialisierungsliste verwendet werden.

2. Im nächsten Schritt sollen die beiden Zahlen addiert werden und das Ergebnis soll in der Variable `c` gespeichert werden. Für diesen Zweck soll eine eigene Funktion `add` geschrieben werden, die als Parameter zwei komplexe Zahlen nimmt und eine komplexe Zahl als Rückgabewert zurückgibt.

3. Als nächstes soll eine Funktion geschrieben werden, die eine komplexe Zahl ausgibt. Dabei soll folgendes Format eingehalten werden: `[real] + [imag]i`, falls `[imag] >= 0` gilt, sonst `[real] - [imag]i`, wobei `[real]` durch den Realteil und `[imag]` durch den Betrag des Imaginärteils ersetzt werden soll. Beide sind auf 2 Nachkommastellen bei der Ausgabe zu runden. Mithilfe dieser Funktion soll nun das Ergebnis der Addition ausgegeben werden: `c = a + b = [cnumber]\n`

4. Zum Ergebnis `c` soll nun nochmals `a` addiert werden. Hierzu soll eine eigene Funktion `addTo` geschrieben werden. Diese Funktion soll zwei Parameter entgegeben nehmen und den Rückgabewert `void` besitzen. Anschließend soll das Ergebnis wieder ausgegeben werden `c += a = [cnumber]\n"`.

5. Nun soll eine Funktion geschrieben werden, die eine komplexe Zahl konjugiert. (Zu `x+yi` ist die konjugiert Komplexe `x-yi`.) Diese Funktion soll ebenfalls als Rückgabewert `void` besitzen. Mithilfe dieser Funktion soll nun `b` konjugiert werden. Danach soll `b` zur Zahl `c` addiert werden. Das Ergebnis soll wieder ausgegeben werden `c += ~b = [cnumber]\n`. 

6. Zuletzt soll noch `c` mit seiner konjugiert Komplexen multipliziert werden. Für die Mulitplikation ist wiederum eine neue Funktion zu schreiben. Das Ergebnis der Mulitplikation soll danach wieder `c` zugewiesen werden und ausgegeben werden `c = c * ~c = [cnumber]\n"`.

---

## Beispielausgabe / Tests

Als Testcases können folgende Beispielausgaben selbsständig ausprobiert werden. Diese sind auch als automatische Tests implementiert.

```
Real of a: -2
Imag of a: 3
Real of b: 1
Imag of b: -5
c = a + b = -1.00 - 2.00i
c += a = -3.00 + 1.00i
c += ~b = -2.00 + 6.00i
c = c * ~c = 40.00 - 0.00i
```

```
Real of a: -9
Imag of a: 0
Real of b: 6
Imag of b: 0
c = a + b = -3.00 + 0.00i
c += a = -12.00 + 0.00i
c += ~b = -6.00 + 0.00i
c = c * ~c = 36.00 + 0.00i
```

```
Real of a: 0
Imag of a: 17
Real of b: 0
Imag of b: 18
c = a + b = 0.00 + 35.00i
c += a = 0.00 + 52.00i
c += ~b = 0.00 + 34.00i
c = c * ~c = 1156.00 + 0.00i
```

```
Real of a: -67.28
Imag of a: 18.71
Real of b: 82.09
Imag of b: -20.12
c = a + b = 14.81 - 1.41i
c += a = -52.47 + 17.30i
c += ~b = 29.62 + 37.42i
c = c * ~c = 2277.60 + 0.00i
```
