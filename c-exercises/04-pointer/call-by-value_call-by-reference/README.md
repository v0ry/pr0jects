# Call-by-value / Call-by-reference

In diesem Übungsbeispiel sollen die Funktionsaufrufe "by value" und "by reference" geübt werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Funktionen
  - Pointer

Lines of Code der Musterlösung: 60 inkl. Main-Funktion

---

## Anleitung

Dieses Übungsbeispiel ist in 2 Teile unterteilt. Teil 1 zeigt den Unterschied zwischen Call-By-Reference und Call-By-Value anhand einer Invertierungsfunktion (Änderung des Vorzeichens) auf, im 2. Teil wir der Funktionsaufruf "by reference" nochmal geübt. 

### Teil 1

Zu schreiben sind 2 Funktionen die aus der Main funktion am markierten **TODO** aufgerufen werden sollen. Beide Funktionen sollen die Zahl, welche als Parameter mitgegeben wird, invertieren.

##### Call-By-Value:

```
int invertByValue(int number)
```

Hier soll die Zahl invertiert und das Ergebnis zurückgegeben werden.

##### Call-By-Reference:

```
void invertByRef(int* number)
```

Hier soll die Zahl direkt über den Zeiger geändert werden, deshalb ist auch kein Rückgabewert notwendig.

### Teil 2

In zweiten Teil ist eine weitere Funktion zu schreiben, welche 2 Zahlen per Reference erhält und die Werte austauscht. Hierfür werden zuerst 2 Werte eingelesen (Die Anzahl der Kühe die Michael und David besitzen), danach soll die zu schreibende Funktion `swapNumbers()` aufgerufen werden. Da diese Funktion keinen Rückgabewert benötigt ist dieser `void`.
Auch diese Funktion soll in der main-Funktion am vorgegebenen **TODO** aufgerufen werden.

```
void swapNumbers(int* number1, int* number2)
```



### Teil 3

In dritten Teil soll nochmal verdeutlich werden, dass manche Ideen nur mit Pointer umsetzbar sind. Die Aufgabe lautet: Schreibe eine Funktion names `editReferences`, welche 2 Zahlen im gleichen Funktionsaufruf bearbeitet. Die erste Zahl soll invertiert werden, die zweite Zahl soll durch die (bereits invertierte) erste Zahl dividiert werden. Da es nicht möglich ist 2 Rückgabewerte zu definieren, sollen die mitgegebenen Pointer-Variablen verändert werden.  

```
void editReferences(int* number1, int* number2)
```



---

## Testen

Bei diesem Beispiel gibt es keine Testcases. Es dient hauptsächlich als Grundlage für weitere Versuche die man ausführen kann um das Konzept von **Call-by-value / Call-by-reference** zu verstehen. 
