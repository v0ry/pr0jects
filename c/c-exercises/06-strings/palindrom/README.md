# Palindrom Check

Das Arbeiten mit Strings in C soll in diesem Beispiel geübt werden. Eine Funktion soll nach einer detaillierten Vorgabe implementiert werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Arrays
  - Strings

Lines of Code der Musterlösung: 56 inkl. Main-Funktion

---

## Anleitung

In diesem Beispiel ist eine Funktion zu schreiben, welche überprüft ob ein eingegebener String ein Palindrom ist (gespeichert in einem C-String). Palindrome sind Wörter die von vorne nach hinten und von hinten nach vorne das selbe Wort ergeben. Die groß und Kleinschreibung ist dabei irrelevant (case insensitive).

Beispiele für Palindrome: Anna, Otto, Rentner, xYyxZxYyx

Die Main-Funktion ist bereits schon vorgegeben und sollte nicht mehr verändert werden. Außerdem soll die Bibliothek `string.h` nicht verwendet werden.

### Funktionsspezifikation

Signatur der Funktion:

```
int isPalindrome(char string[100]);
```

Es ist dabei anzunehmen, dass das eingebene Wort nicht mehr als 100 Zeichen hat. 

Der Parameter `string` ist ein C-String. Die Funktion wird bereits in der main-Funktion aufgerufen. 

Als Rückgabewert soll ein Fehlerwert retourniert werden:

| Wert | Bedeutung   |
| :--: | ----------- |
| 0  | Kein Palindrom |
| 1    | Palindrom |

### Funktionsweise

Die Funktion soll überprüfen ob das eingegebene Wort von vorne und von hinten gelesen das selbe Wort ergibt. Falls dies der Fall ist, soll der Rückgabewert 1 zurückgegeben werden, andernfalls 0. 

---

## Testen

Bei diesem Beispiel gibt es wieder automatische Tests, die mit `make test` gestartet werden können. 
