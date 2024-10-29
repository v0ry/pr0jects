# Redouble Calculator - 1d array

In diesem Übungsbeispiel sollen das Arbeiten mit Arrays geübt werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Schleifen
  - Arrays
  - Ein- und Ausgabe

Lines of Code der Musterlösung: 40

---

## Anleitung

Das Framework beinhalted die erste Ausgabe des Programs. Danach folgen 2 Abfragen an den User:

1. Die Zahl die verdoppelt werden soll. Diese soll in einen `long` gespeichert werden.

```
Enter your number: 
```

2. Die Anzahl wie oft die Zahl verdoppelt werden soll (gespeichert als `int`)

```
How many times:
```

Nun soll mit den eingebenen Zahlen gerechnet werden und die Ergebnisse in ein Array aus `long` gespeichert werden. Dieses Array hat die Größe **X**, wobei **X** die Anzahl der Verdoppelungen darstellt (also die 2. Abfrage).

### Berechnung

Es soll nun die eingebene Zahl **X** mal verdoppelt werden und das Zwischenergebnis immer in das Array geschrieben werden.

### Ausgabe

Nachdem alle Zahlen in das Array eingefügt wurden, soll über das Array von vorne nach hinten iteriert werden und alle Zahlen mit einem Leerzeichen getrennt ausgegeben werden (Kein Leerzeichen am Anfang und Ende der Reihe). Am Ende folgt noch ein `\n` . Zum Schluss soll das Array noch von hinten nach vorne ausgegeben werden, wieder gefolgt von einem `\n` bevor das Programm mit dem Rückgabewert 0 beendet. 



### Beispiel

```
--- Redouble Calculator ---
Enter your number: 10
How many times: 20
10 20 40 80 160 320 640 1280 2560 5120 10240 20480 40960 81920 163840 327680 655360 1310720 2621440 5242880
5242880 2621440 1310720 655360 327680 163840 81920 40960 20480 10240 5120 2560 1280 640 320 160 80 40 20 10
```



---

## Testen

Zum Testen stehen wieder automatische Tests zur Verfügung, die mittels `make test` ausgeführt werden können. 
