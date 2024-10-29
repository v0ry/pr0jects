# Einfacher Taschenrechner

In diesem Übungsbeispiel soll eine Version von einem simplen Taschenrechner geschrieben werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Ein- und Ausgabe
  - Verzweigungen

Lines of Code der Musterlösung: 68

---

## Anleitung

Zu Beginn des Programms soll der Benutzer dazu aufgefordert werden, eine (Gleitkomma-)Zahl einzugeben. Dazu wird der Text `First number: ` im Terminal ausgegeben. Anschließend wird mit `Operation: ` nach der auszuführenden Rechenart gefragt. Welche Rechenarten möglich sind, werden nachfolgend beschrieben. Im nächsten Schritt wird vom Programm mit `Second number: ` noch nach einer zweiten (Gleitkomma-)Zahl gefragt.

In diesem Beispiel wird davon ausgegangen, dass nur Gleitkommazahlen eingegeben werden. Daher ist hierzu keine weitere Überprüfung notwendig. Hingegen ist bei einigen Operationen zu überprüfen, ob die Gleitkommazahlen in einem bestimmten Wertebereich liegen, mehr dazu nachfolgend.

Außerdem muss überprüft werden, ob eine gültige Operation eingegeben wurde. Ansonsten soll die Fehermeldung `Invalid operation!\n` ausgegeben werden. Auch hier kann davon ausgegangen werden, dass genau ein Zeichen eingegeben wird, welches zu überprüfen ist.

Nachdem die Eingabe abgeschlossen ist, soll nun das Ergebnis berechnet werden. Dieses soll danach dem Benutzer ausgegeben werden mit dem Text `Result: <result>\n`, wobei `<result>` durch das Ergebnis auf 2 Nachkommastellen genau gerundet sein soll. Zuletzt terminiert das Programm mit Rückgabewert `0`. Sollte es zu irgendeiner Fehlermeldung gekommen sein, wird die entsprechende Fehlermeldung aber kein Ergebnis ausgegeben. Anschließend soll das Programm mit Rückgabewert `1` terminieren.

### Rechenoperationen

Folgende Rechenoperationen sind zulässig, wobei `a` bzw. `b` hierbei für die erste bzw. zweite Zahl stehen.

| Rechenoperation | Zeichen | Berechnung |
| :-------------: | :-----: | :--------: |
| Addition | `+` | `a + b` |
| Subtraktion | `-` | `a - b` |
| Multiplikation | `*` | `a * b` |
| Division (**nicht** Integer-Division) | `/` | `a / b` |
| Potenz | `p` | `pow(a, b)` |
| Qudratwurzel | `s` | `sqrt(a)` |
| Exponentialfunktion | `e` | `exp(a)` |

Die letzten drei Operationen können **nicht** direkt in C umgesetzt werden. Um diese Berechnung machen zu können ist die Bibliothek `math.h` analog zu `stdio.h` einzubinden. Außerdem kann es nötig sein, dass beim Kompilieren zusätzlich noch `-lm` angegeben werden muss. Damit können nun die in der Tabelle genannten Funktionen `pow`, `sqrt` und `exp` direkt verwendet werden. Beispiel für `pow`:

```
float result = pow(a, b);
```

Bei den letzten beiden in der Tabelle angeführt Operationen wird zwar auch die zweite Zahl vom Benutzer eingelesen, diese ist aber nicht für die Berechnung relevant und wird daher nicht weiter beachtet.

### Überprüfungen

Falls eine der folgenden Bedingungen auftritt, soll die entsprechende Fehlermeldung, aber kein Ergebnis der Berechnung ausgegeben werden. Außerdem soll das Programm mit Rückgabewert `1` beenden.

Bei der Division ist es nicht erlaubt, durch `0` zu dividieren. Falls dies dennoch versucht wird, soll die Fehlermeldung `Division through 0 not allowed!\n` ausgegeben werden. Da es sich bei den Eingaben um Gleitkommazahlen handelt, ist es nicht ausreichend die Zahl einfach auf 0 zu überprüfen, da dies im Allgemeinen nicht das gewünschte Ergebnis liefert.

Das Potenzieren soll es in diesem Programm nur erlaubt sein, falls sowohl die Basis `a` als auch der Exponent `b` größer gleich `0` sind. Ansonsten soll die Fehlermeldung `Base and exponent have to be at least 0!\n` ausgegeben werden.

Die Quadratwurzel ist nur für Zahlen `a >= 0` (im Reellen) definiert. Daher soll bei kleineren Zahlen die Fehlermeldung `Square root only defined for numbers at least 0!\n` ausgegeben werden.

---

## Beispielprogramm

```
First number: 100
Operation: *
Second number: 5
Result: 500
```

---

## Testen

Zum Testen des Programms stehen wieder automatische Tests zur Verfügung, welche mit `make test` ausgeführt werden können.
