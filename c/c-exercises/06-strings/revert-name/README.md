# Namen rückwärts ausgeben

Das Arbeiten mit Strings in C soll in diesem Beispiel geübt werden. Eine Funktion soll nach einer detaillierten Vorgabe implementiert werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Arrays
  - Strings

Lines of Code der Musterlösung: 61 inkl. Main-Funktion

---

## Anleitung

In diesem Beispiel ist eine Funktion zu schreiben, welche die einzelnen Teile eines Namens (gespeichert in einem C-String) rückwärts geschrieben ausgibt. Die Main-Funktion ist bereits schon vorgegeben und sollte nicht mehr verändert werden. Außerdem soll die Bibliothek `string.h` nicht verwendet werden.

### Funktionsspezifikation

Signatur der Funktion:

```
int reversePrint(char* name);
```

Falls in der Vorlesung noch keine Pointer behandelt worden sind, kann `char* name` auch durch `char name[]` ersetzt werden - beide Schreibweisen sind in diesem Fall äquivalent (im Allgemeinen aber nicht!).

Der Parameter `name` ist ein C-String, der aus einem oder mehreren Vornamen und einem oder mehreren Nachnamen besteht, die jeweils durch genau ein Leerzeichen getrennt sind. Es kommen nur Buchstaben und Leerzeichen vor.

Als Rückgabewert soll ein Fehlerwert retourniert werden:

| Wert | Bedeutung   |
| :--: | ----------- |
| 0    | Erfolgsfall |
| 1    | Fehlerfall: leerer Parameter   |
| 2    | Fehlerfall: nicht mindestes zwei Namensteile im Parameter |

### Funktionsweise

Die Funktion gibt die einzelnen Teile des Namens jeweils rückwärts buchstabiert aus. Hierbei ist darauf zu achten, dass jeweils das erste ausgegebene Zeichen eines Namensteils großgeschrieben wird, während der nun an letzter Stelle stehende eigentlich erste Buchstabe zu einem Kleinbuchstaben wird. Die übergebenen Namensteile in `name` folgen sicher diesem Format (erster Buchstabe groß, Rest klein). Am Ende der Ausgabe ist noch ein abschließender Zeilenumbruch auszugeben.

Falls einer der oben genannten Fehlerfälle auftritt wird **kein** Name ausgegeben.

---

## Ausgabebeispiel

Lautet der Parameter beispielsweise "John Joe Jelly" so wird der Text "Nhoj Eoj Yllej\n" ausgegeben.

---

## Testen

Bei diesem Beispiel gibt es wieder automatische Tests, die mit `make test` gestartet werden können. 

Bugs: Bei den Testcases, in denen keine Ausgabe gefordert ist, ist es je nach Testrunner-Version möglich, dass die `diff` - der Vergleichswert zwischen "Reference Output" und "Your Output" - nicht korrekt angezeigt wird. Entscheidend ist, dass beim Testcase ein grünes Häckchen dabeisteht, damit er erfolgreich geschafft wurde.
