# Caeser Cipher

In diesem Übungsbeispiel soll der Umgang mit (Character-)Pointern bzw. Strings in C geübt werden. Es ist hierbei eine vorgegebene Funktion zu implementieren.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Pointer, Arrays
  - Strings

Lines of Code der Musterlösung: 66 inkl. Main-Funktion

---

## Anleitung

Es ist eine Funktion zu schreiben, welche eine Variante des [Caesar Cipher](https://en.wikipedia.org/wiki/Caesar_cipher) auf einen String anwendet. Hierbei wird anstatt eines vorgegebenen Betrages und einer vorgegebenen Richtung für die Chiffrierung der Schlüssel für jeden Buchstaben des Klartextes neu berechnet. Die Main-Funktion ist bereits schon vorgegeben und sollte nicht mehr verändert werden. Außerdem soll die Bibliothek `string.h` nicht verwendet werden.

### Funktionsspezifikation

Signatur der Funktion:

```
unsigned int cipher(char* cipher_str, int start_key);
```

Der erste Parameter ist ein C-String nämlich die zu chiffriernde Zeichenkette. Diese wird per Reference übergeben, sodass nach Abschluss der Chiffrierung die verschlüsselte Zeichenkette in `cipher_str` enthalten ist. Im zweiten Parameter wird der Startschlüssel übergeben.

Als Rückgabewert soll die Anzahl der Zeichen retourniert werden, auf welche die Chiffrierung angewandt wurde.

### Funktionsweise

Jede Verschiebung erfolgt abhängig vom Schlüssel. Ist der Schlüssel für das aktuelle Zeichen eine gerade Zahl, so wird das aktuelle Zeichen um diesen Betrag im Alphabet nach rechts verschoben (z.B. beim Schlüssel 2 wird aus einem A ein C). Ist der Schlüssel ungerade, so erfolgt eine Verschiebung nach links (z.B. beim Schlüssel 3 wird aus einem D ein A).

Würde eine Verschiebung über das Ende des Alphabets hinaus erfolgen, so wird die Zählung bei Beginn des Alphabets fortgesetzt. Beim Schlüssel 2 wird aus einem Z also ein B bzw. beim Schlüssel 3 aus einem A ein X.

Es werden nur Buchstaben des englischen Alphabets (A-Z und a-z) chiffriert. Alle anderen Zeichen bleiben unverändert.

Der Startschlüssel wird nur auf das erste Zeichen angewendet. Danach wird der Schlüssel nach jeder Anwendung neu berechnet, indem der Zahlenwert des zuletzt veränderten Klartext-Zeichens (also 1 für A und a, 2 für B und b, bis 26 für Z und z) durch den zuletzt verwendeten Schlüssel dividiert wird. Der neue Schlüssel für das nächste Zeichen ist der ganzzahlige Rest dieser Division. Falls es hierbei zu einer Division durch Null kommen würde (weil der zuletzt verwendete Schlüssel 0 war) wird der neue Schlüssel wieder auf den Wert des Startschlüssels gesetzt.

---

## Testen

Es stehen automatische Tests zur Verfügung, welche mit `make test` gestartet werden können. Zum besseren Verständnis der Übungsaufgabe ist es empfehlenswert mindestens einen eigenen Testcase selbst zu entwerfen und den Output händisch auszurechnen.
