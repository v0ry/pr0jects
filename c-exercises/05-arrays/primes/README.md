# Primzahlen

Das Arbeiten mit Arrays soll geübt werden. Eine Funktion soll nach einer detaillierten Vorgabe implementiert werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Arrays, (Pointer)

Lines of Code der Musterlösung: 58 inkl. Main-Funktion

---

## Anleitung

Es ist eine Funktion `countPrimes` zu erstellen, welche die Anzahl der Primzahlen in einem Array aus Ganzzahlen ermittelt.

### Funktionsspezifikation

Signatur der Funktion:

```
unsigned int countPrimes(uint32_t element_list[], unsigned int elements);
```

Der erste Parameter ist ein Array aus nicht-vorzeichenbehafteten 32-Bit Ganzzahlen. Der zweite Parameter ist eine nicht-vorzeichenbehaftete Ganzahl - die Anzahl der Elemente im Array.

Als Rückgabewert soll die Funktion die Anzahl der Primzahlen im Array retournieren.

### Funktionsweise

Primzahlen sind natürliche Zahlen, welche größer als 1 und nur durch sich selbst (und 1) ohne Rest teilbar sind. Die Funktion überprüft für jedes Element des Arrays, ob es sich hierbei um eine solche handelt und zählt die identifizierten Primzahlen.

---

## Testen

Zum Testen stehen automatische Tests zur Verfügung, welche mit `make test` ausgeführt werden können. Zum händischen Testen müssen einfach alle Zahlen eingegeben werden, die in das Array gefüllt werden. Nach Eingabe der letzten Zahl wird `EOF` (=End of File) erwartet, welches mittels `CTRL + D` eingeben werden kann.
