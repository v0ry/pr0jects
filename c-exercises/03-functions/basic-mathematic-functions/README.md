# Mathematik-Funktionen

In diesem Übungsbeispiel soll der Umgang mit Funktionen geübt werden. Es sollen einige mathematische Operationen als Funktionen implementiert werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen
  - Operatoren
  - Funktionen
  - Ein- und Ausgabe

Lines of Code der Musterlösung: 60

---

## Anleitung

In diesem Beispiel sind ein paar kleine mathematische Funktionen zu programmieren.

### add-Funktion

Es soll eine Funktion geschrieben werden, die 2 Ganzzahlen als Argumente annimmt, diese addiert und das Ergebnis als Ganzzahl zurückgibt. 

```
int add(int number1, int number2);
```

### min/max-Funktionen

Es sollen Funktionen geschrieben werden, die 2 Ganzzahlen als Argumente annehmen und die kleinere/größere der beiden Zahlen zurückgiben.

```
int min(int number1, int number2);
```

```
int max(int number1, int number2);
```

### abs-Funktion

Es soll eine Funktion geschrieben werden, die 1 Ganzzahl als Argument annimmt und den absoluten Wert zurückgibt.

```
int abs(int number);
```

### mean-Funktion

Es soll eine Funktion geschrieben werden, die 2 Gleitkommazahl als Argument annimmt und den Mittelwert der beiden Zahlen zurückgibt.

```
float mean(float number1, float number2);
```



### Ein- und Ausgabe

Um die Funktionen zu testen sollen diese in der main-Funktion aufgerufen werden und das Ergebnis ausgegeben werden. 

Zunächst sollen 2 Zahlen eingelesen werden können. 

```
First number: 
```

```
Second number: 
```

Danach folgen 6 Ausgaben (2x Absolut für beide Zahlen) mittels `printf` wo sowohl die eingebenen Zahlen als auch das Ergebnis durch den Funktionsaufruf ausgegeben werden soll. Für die genaue Formatierung (Anzahl der Leerzeichen) siehe [Beispiel](#Beispiel).

Beispiel Addition:

```
Addition of <number1> and <number2> is <result_of_add_function>
```



### Beispiel

```
First number: 4
Second number: -3
Addition of 4 and -3 is 1
Min      of 4 and -3 is -3
Max      of 4 and -3 is 4
Absolute of 4 is 4
Absolute of -3 is 3
Mean     of 4 and -3 is 0.500000
```



---

## Testen

Bei diesem Beispiel gibt es wieder automatische Tests, die mit `make test` gestartet werden können.
