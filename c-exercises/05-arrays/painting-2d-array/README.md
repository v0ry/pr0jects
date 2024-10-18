# Painting 2d array

In diesem Übungsbeispiel sollen das Arbeiten mit 2 dimensionalen Arrays geübt werden. Es ist explizit so gestaltet, dass man es auch ohne Strings und Pointer programmieren kann.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Schleifen
  - Funktionen
  - Arrays
  - Ein- und Ausgabe

Lines of Code der Musterlösung: 60

---

## Anleitung

Ziel dieses Programms ist es den Userinput in ein 2 dimensionales Array zu speichern und dieses danach gespiegelt (von hinten nach vorne) auszugeben. Das 2D-Array soll eine maximale Breite von 70 Zeichen haben (hier ist bereits ein `define` sowie die Startnachricht im Framework enthalten). Die Höhe des Bildes soll bei der ersten Abfrage nach Programmstart vom User erfragt werden:

```
How many lines do you need? 
```

Nun soll das Array mit dieser Größe erstellt werden - `picture[<anzahl_der_zeilen>][MAX_WIDTH]`. Da in dieses Array nur ASCII Character geschreiben werden sollen ist ein passender Datentyp zu wählen.

### Einlesen

Sollten Strings noch nicht in der VO behandelt worden sein, kann das Einlesen auch Zeichen für Zeichen (zB mit `getchar()`) gelöst werden. Die eingegebenen Zeichen sollen direkt in das 2 dimensionale Array gespeichert werden. 

Gibt also der Benutzer an, dass er 3 Zeilen benötigt, soll 3x eine leere Eingabezeile für den Benutzer erscheinen in der man ASCII Zeichen eingeben kann. Das erste Zeichen der ersten Zeile soll dabei in `picture[0][0]` gespeichert werden, das dritte Zeichen der zweiten Zeile in `picture[1][2]`. Werden mehr als die maximale Anzahl an Zeichen pro Zeile eingegeben soll der hintere Zeil abgeschnitten werden.

### Ausgabe

Schreibe eine Funktion `printPainting()` welche 2 Parameter besitzt.

1. Das 2D-Array
2. die Anzahl der Zeilen des 2D-Arrays (die Breite ist durch MAX_WIDTH gegeben)

Diese Funktion soll das 2D-Array als gesamtes Bild **gespiegelt** (von hinten nach vorne) ausgeben und einen Rahmen um das Bild zeichnen. Die Rahmenlinien bestehen unterhalb und oberhalb des Bildes aus einem Bindestrich  `-` (ASCII 45) und links und rechts aus einem senkrechten Strich `|` (ASCII 125). Die Rahmenlinien sollen das Bild komplett umranden - siehe [Beispiel](#Beispiel).



### Beispiel

```
--- Painting Calculator (max-width 70) ---
How many lines do you need? 4
        _   ,_,   _
       / `'=) (='` \
      /.-.-.\ /.-.-.\ 
      `      "      `  PSE
------------------------------------------------------------------------
|                                                   _   ,_,   _        |
|                                                  \ `'=( )='` /       |
|                                                 \.-.-./ \.-.-./      |
|                                            ESP  `      "      `      |
------------------------------------------------------------------------
```



---

## Testen

Zum Testen stehen wieder automatische Tests zur Verfügung, die mittels `make test` ausgeführt werden können. 
