# Römische Zahlen

In diesem Übungsbeispiel soll ein C-String, der eine römische Zahl enthält in eine Ganzzahl umgewandelt werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Arrays
  - Strings
  - Ein- und Ausgabe

Lines of Code der Musterlösung: 168

---

## Anleitung

Zu Beginn des Programm soll der Benutzer dazu aufgefordert werden eine römische Zahl als Zeichenkette einzugeben. Dazu soll `Enter roman number: ` ausgegeben werden. Anschließend wird versucht den String in eine Ganzzahl umzuwandeln. Falls dies erfolgreich ist, wird `Decimal number: <number>\n` ausgegeben, wobei `<number>` durch das Ergebnis zu ersetzen ist. Andernfalls soll eine der unten angeführten Fehlermeldungen ausgegeben werden und die gesamte Eingabe wiederholt werden.

### Römische Zahlen

Im römischen Zahlensystem gibt es folgende Zeichen:

| Zeichen | Dezimalwert |
| :-----: | :---------: |
| I       |    1        |
| V       |    5        |
| X       |   10        |
| L       |   50        |
| C       |  100        |
| D       |  500        |
| M       | 1000        |

Hintereinanderstehende absteigende Zeichen werden adddiert, beispielweise `MCCXVIII` entspricht `1 * 1000 + 2 * 100 + 1 * 10 + 1 * 5 + 3 * 1 = 1218`. Mit Ausnahme von `M` darf aber das gleiche Zeichen nur maximal dreimal hintereinander stehen. Beispielsweise die Zeichenkette `IIII` für `4` ist nicht erlaubt. 

Hierbei kommt eine Subtraktionsregel ins Spiel: Falls `I`, `X` und `C` **vor** dem erst- oder zweithöheren Zeichen stehen, so wird deren Wert von diesem Zeichen abgezogen. Somit ist für `4` die korrekt Schreibweise `IV`, für `9` ist sie `IX`, aber für `49` ist sie **nicht** `IL`, da ja `L` nicht erst- oder zweithöheres Zeichen von `I` ist. Die korrekt Schreibweise für `49` ist somit `XLIX`. 

Einen Spezialfall bildet noch die `0`. Für diese Zahl gibt es kein Zeichen innnerhalb der römischen Zahlen.

### Umwandlung der Eingabe

Nach folgenden Regeln soll nun die Eingabe evaluiert werden:

1. Die eingegebene Zeichenkette darf eine maximale Länge von 30 Zeichen haben (mit abschließendem `\n` sind das dann 31). Ansonsten wird die Fehlermeldung `Input too long!\n` ausgegeben.
2. Der String muss folgendes Format erfüllen. Zuerst dürfen belieblig viele Leerzeichen stehen, anschließend dürfen nur oben genannte Zeichen der römischen Zahlen stehen (nur Großbuchstaben). Diese dürfen **nicht** durch andere Zeichen, Leerzeichen etc. unterbrochen werden. Zuletzt dürfen wieder beliebig viele Leerzeichen im String enthalten sein. Falls dieses Format nicht erfüllt ist, soll die Fehlermeldung `No roman number could be found!\n` ausgegeben werden. Erinnerung: Eine leere Zeichenkette bzw. eine die nur aus Leerzeichen besteht, ist eine gültig Zahl - nämlich die `0`.
3. Nun soll der String in eine römische Zahl umgewandelt werden mithilfe der oben genannten Regeln. Falls eine der Regeln nicht erfüllt ist und somit keine gültige römische Zahl eingegeben wurde, ist `Invalid roman number!\n` auszugeben.
4. Falls eine Fehlermeldung aufgetreten ist, soll wie bereits oben erklärt, die Eingabe wiederholt werden. Ansonsten ist `Decimal number: <number>\n` auszugeben.

---

## Testen

Bei diesem Beispiel stehen wieder automatische Tests zur Verfügung, die mit `make test` ausgeführt werden können.
