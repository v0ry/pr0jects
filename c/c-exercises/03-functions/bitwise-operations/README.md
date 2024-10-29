# Bitoperationen (Ausgabe + Addition)

In diesem Übungsbeispiel soll der Umgang mit bitweisen Operatoren geübt werden. Zum einen ist eine Funktion zu schreiben, die die Bits einer Ganzzahl ausgibt, zum anderen soll eine Addition von zwei Ganzzahl implementiert werden, die fast ausschließlich Bitoperationen verwendet.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen
  - arithmetische, logische, insbesondere bitweise Operatoren
  - Verzweigungen
  - Schleifen
  - Funktionen
  - Ein- und Ausgabe

Lines of Code der Musterlösung: 76

---

## Anleitung

Zu Beginn sollen zwei nichtvorzeichenbehaftete 32-bit große Ganzzahlen (mit anderen Worten `uint32_t`) vom Benutzer eingelesen. Dabei wird folgende Eingabeaufforderung ausgegeben, 

```
Insert first number:  <input> // Zwei Leerzeichen nach dem Doppelpunkt!
Insert second number: <input>
```

wobei `<input>` jeweils die Eingabe des Benutzers darstellen soll. Anschließend soll die Bitdarstellung beider Zahlen ausgegeben werden, 

```
\n
Bits of first number:  0000 0000 | 0000 0000 | 0000 0000 | 0110 0000\n
Bits of second number: 0000 0000 | 0000 0000 | 0000 0000 | 0100 0001\n
```

wobei das natürlich die Bits der eingelesenen Zahlen sein sollen. In diesem Ausgabebeispiel sind die erste Zahl `96` und die zweite Zahl `65`. Im nächsten Schritt sollen die beiden Zahlen addiert werden. Danach wird das Ergebnis in Bitdarstellung ausgegeben,

```
\n
Bits of result number: 0000 0000 | 0000 0000 | 0000 0000 | 1010 0001\n
```

in unserem Beispiel ist das `161`.

Zuletzt gibt es noch zwei Möglichkeiten. Sollte es bei der Addition zu einem Overflow gekommen sein, soll `An overflow occured!\n` ausgegeben werden. Andernfalls soll zusätzlicher zur Binärdarstellung auch die Dezimaldarstellung des Ergebnisses ausgegeben werden `Decimal value of the result number: <result>\n`.

### Ausgabe der Binärdarstellung

Hierzu soll eine Funktion geschrieben werden, da dieser Codeteil im Programm mehrmals aufgerufen wird. Signatur der Funktion:

```
void printNumber(uint32_t number);
```

Es sind alle Operatoren (arithmetische, logische, bitweise) sowie Schleifen und Verzweigungen erlaubt, mit der einzigen Ausnahme, dass auf die Bits von `number` nur mittels Bitoperationen (+ Konstante, Bitmasken etc.) zugegriffen werden darf.

### Bitweise Addition

Bei der bitweisen Addition sollen die beiden eingegeben Zahlen zusammenaddiert werden. Ein guter Start ist hierbei die "Schulmethode", also die schriftliche Addition zu verwenden - natürlich angepasst auf Binärzahlen.

Hierbei sind nur Bitoperationen (+ Konstante, Bitmasken etc.) und Schleifen erlaubt. (Falls eine Laufvariable in der Schleife vorkommt, darf diese wie üblich mittels `++` und `<` oder ähnlichem verwendet werden. Es ist aber auch rein mittels Bitoperationen in der Schleife möglich.) Zur Bestimmung, ob es einen Overflow gegeben hat, darf auch eine Verzweigung verwendet werden. 

Am besten ist es, sich jetzt Gedanken darüber zu machen und zu versuchen einen Algorithmus zu finden. Somit bekommt man den besten Lerneffekt. Falls es aber etwas zu kompliziert ist, gibt es hier noch ein Beispiel und ein paar Überlegungen.

Wir betrachten in dem Beispiel zwei 4-bit Zahlen, nämlich `1011` und `1011`. Anschließend fahren wir wie mit der schriftlichen Addition fort und addieren die beiden letzten Stellen `1` und `1`. Als Ergebnis erhalten wir `2`, was aber binär dargestellt `10` ist. Damit ist die letzte Stelle des Ergebnisses `0` und wir nehmen `1` für die vorletzte Stelle mit. Dort wird dann `1`, `1` und `1` von der vorherigen Addition zusammengezählt. Das Ergebnis ist diesmal `11`, womit `1` die vorletzte Stelle des Ergebnisses ist und wir wieder `1` für die nächste Addition mitnehmen. Die nächste Addition ist `0 + 0 + 1 = 1`, womit die zweite Stelle `1` ist und wir nichts mitnehmen. Schließlich bleibt noch `1 + 1 + 0 = 10`, damit ist die erste Stelle `0`, aber wir haben noch eine `1` übrig. Da es aber keine weitere Stelle vorne gibt, fällt diese `1` einfach weg, ein Overflow.

Bei welchen Kombinationen wird jetzt also eine `0` bzw. `1` an die Stelle im Ergebnis geschrieben? Welche (wiederholt angewandte) Bitoperation eignet sich dafür?

Bei welchen Kombinationen wird eine `0` bzw. `1` in die nächste Addition mitgenommen? Welche Bitoperation(en) eignen sich dafür?

---

## Testen

Bei diesem Beispiel gibt es wieder automatische Tests, die mit `make test` gestartet werden können.
