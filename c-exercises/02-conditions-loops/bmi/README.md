# Body-Mass-Index

In diesem Übungsbeispiel soll ein einfaches, sequentielles Programm geschrieben werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen
  - arithmetische und logische Operatoren
  - Ein- und Ausgabe
  - Verzweigungen

Lines of Code der Musterlösung: 36

---

## Anleitung

Es soll ein Programm geschrieben werden, welches den [BMI](https://de.wikipedia.org/wiki/Body-Mass-Index) (Bodymassindex) eines Benutzers berechnet und das Ergebnis dieser Berechnung kategorisiert.

### Berechnung vom BMI

```
BMI = (Körpergewicht in kg) / (Körpergröße in m)²
```

### Kategorisierung des BMI

| Kategorie	              | BMI (kg/m²) 	|
| ----------------------- | :-----------: |
| Starkes Untergewicht  	| < 16.0 	      |
| Mäßiges Untergewicht  	| 16.0 - < 17.0	|
| Leichtes Untergewicht 	| 17.0 - < 18.5	|
| Normalgewicht	          | 18.5 - < 25.0	|
| Präadipositas	          | 25.0 - < 30.0	|
| Adipositas Grad I	      | 30.0 - < 35.0	|
| Adipositas Grad II	    | 35.0 - < 40.0	|
| Adipositas Grad III	    | ≥ 40    	    |

### Programmablauf

1. Das Programm gibt den Text `Bitte geben Sie Ihr Gewicht in kg ein:\n` aus.
2. Das Programm liest den vom Benutzer eingegebenen Wert ein. Es ist davon auszugehen, dass nur gültige Eingaben erfolgen.
3. Das Programm gibt den Text `Bitte geben Sie Ihre Körpergröße in cm ein:\n` aus.
4. Das Programm liest den vom Benutzer eingegebenen Wert ein.
5. Das Programm berechnet den BMI.
6. Das Programm gibt den BMI mit folgendem Text aus: `BMI: <wert>\n`, wobei `<wert>` durch den errechneten Wert, auf eine Nachkommastelle genau, zu ersetzen ist.
7. Das Programm gibt außerdem noch folgenden Text aus: `Kategorie: <category>\n`, wobei `<category>` abhängig vom Wert des BMI durch den entsprechenden Text in der Spalte "Kategorie" aus oben stehender Tabelle zu ersetzen ist. Dabei sollten maximal sieben Vergleiche notwendig sein.

---

## Beispielausgabe inkl. Eingaben

```
Bitte geben Sie Ihr Gewicht in kg ein:
30
Bitte geben Sie Ihre Körpergröße in cm ein:
89
BMI: 37.9
Kategorie: Adipositas Grad II
```
