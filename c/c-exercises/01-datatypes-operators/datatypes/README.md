# Unterschiede zwischen Datentypen

In diesem ersten Übungsbeispiel sollen die verschiedenen Datentypen und deren Unterschiede verinnerlicht werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen

Lines of Code der Musterlösung: 29 (nur für den Datentyp `char`)

---

## Anleitung

Das Programm benötigt keine Eingabe und dient nur zur Veranschaulichung der Datentypen. 

### Datentypen in C (64-bit Architekturen)

#### Ganzzahlen

| Datentyp                           | Größe in byte              | darstellbarer Wertebereich                                                                     |
| ---------------------------------- | -------------------------- | ---------------------------------------------------------------------------------------------- |
| signed char<br />unsigned char     | 1 byte                     | -128 bis 127<br />0 bis 255                                                                    |
| (signed) short<br />unsigned short | 2 byte                     | -32.768 bis 32.767<br />0 bis 65.535                                                           |
| (signed) int<br />unsigned int     | 4 byte                     | -2.147.483.648 bis 2.147.483.647<br />4.294.967.295                                            |
| (signed) long<br />unsigned long   | 8 byte (bei Linux und Mac) | -9.223.372.036.854.775.808 bis 9.223.372.036.854.775.807<br />0 bis 18.446.744.073.709.551.615 |

#### Gleitkommazahlen

| Datentyp    | Größe in byte | Genauigkeit           |
| ----------- | ------------- | --------------------- |
| float       | 4 byte        | ca. 6 Dezimalstellen  |
| double      | 8 byte        | ca. 15 Dezimalstellen |
| long double | 10 byte       | ca. 19 Dezimalstellen |

### Aufgabe

Erstelle von jedem Ganzzahl-Datentyp eine Variable (signed und unsigned extra) und initialisiere die Variable mit 0. Dekrementiere dann jede Variable mithilfe des `--` Operators und gebe das Ergebnis der Variablen mittels `printf` aus. bei den signed-Datentypen sollte das Ergebnis -1 sein, bei den unsigned-Datentypen sollte die höchstmögliche Zahl des darstellbaren Wertebereichs ausgegeben werden. 

Versuche danach die Variablen mit dem höchstmöglichen Wert des jeweiligen Wertebereichs zu initialisieren und zähle dann mittels des `++` Operators eins dazu und gib das Ergebnis erneut mit `printf` aus. 

Was passiert wenn du zB. in einen `signed char` den Wert -130 zuweisen möchtest? Hinweis: Diese Zahl liegt auserhalb des darstellen Wertebereichs. 

### Beispiel

Ein Beispielprogramm für den Datentyp `signed char` und `unsigned char` findest du in der `main.c`-Datei.
