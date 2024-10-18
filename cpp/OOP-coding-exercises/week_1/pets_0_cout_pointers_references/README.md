# Fehlende Funktionen

Dieses Beispiel ist unbewertet. Wenn du es löst, bekommst du keine zusätzlichen Punkte für die KU, aber du kannst ein tieferes Verständnis der behandelten Themen erlangen und dein Wissen festigen.

## Lernziele

Ziel dieses Übungsbeispiels ist es, den Umgang mit Pointern und References zu üben. References sind neu in C++ und der sichere Umgang mit References ist eine Grundvoraussetzung für das Programmieren C++. Auch die bereits aus C bekannten Pointer sind in C++ nach wie vor unerlässlich.

Außerdem wird empfohlen, in diesem Beispiel `cout` einzusetzen, um auch diese Neuerung in C++ kennenzulernen. Du kannst gerne auch eine Lösung mit `printf` schreiben, um diese mit der `cout`-Lösung zu vergleichen. Welcher der beiden Ansätze gefällt dir besser?

## Das Problem

In der Datei `pets.cpp` existiert bereits eine `main`-Funktion. Darin werden Variablen angelegt und Funktionen aufgerufen, jedoch gibt es diese Funktionen noch nicht.

## Deine Aufgabe

Deine Aufgabe ist es, die in `pets.cpp` fehlenden Funktionen zu schreiben. Diese heißen

 - `printPetInfo`,
 - `happyBirthdayWithPointer` und
 - `happyBirthdayWithReference`.

### `printPetInfo`

Die einzige Aufgabe der Funktion `printPetInfo` ist es, Informationen über ein Haustier auszugeben. Die Funktion hat daher keinen Rückgabewert. Die Parameter der Funktion sind ein `char*`, welcher die Tierart angibt, und ein `unsigned`, welcher das Alter des Tiers repräsentiert. Der auszugebende Text soll wie folgt aussehen.

```
That's a <AGE>-year-old <SPECIES>.\n
```

Dabei ist `<AGE>` durch den an die Funktion übergebenen `unsigned` zu ersetzen. `<SPECIES>` soll durch den C-String ersetzt werden, dessen Adresse, der Funktion übergeben wurde.

### `happyBirthdayWithPointer`

Die einzige Aufgabe der Funktion `happyBirthdayWithPointer` ist es, einen `unsigned` um eins zu erhöhen. Die Funktion hat daher keinen Rückgabewert. Die Funktion erhält die Adresse des zu erhöhenden `unsigned` – also einen Pointer auf den zu erhöhenden `unsigned` – als Parameter.

### `happyBirthdayWithReference`

Die einzige Aufgabe der Funktion `happyBirthdayWithReference` ist es, einen `unsigned` um eins zu erhöhen. Die Funktion hat daher keinen Rückgabewert. Die Funktion hat eine Referenz des zu erhöhenden `unsigned` als Parameter. Was würde passieren, wenn der Parameter keine Referenz wäre sondern einfach ein `unsigned`?

## Lösung

Ändere die Datei `pets.cpp`, um die oben beschriebene Aufgabe zu lösen. Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird eine Datei namens `testreport.html` erstellt. Sie enthält einen Bericht, der dir zeigt, welche Ausgabe dein Programm produzieren sollte und welche Ausgabe dein Programm produziert. Du erhältst auf diese Weise sofortiges Feedback zu deiner überarbeiteten `pets.cpp`-Datei.

Solltest du Probleme haben, das Übungsbeispiel zu lösen, so kannst du dir eine mögliche Lösung in `solution.cpp` ansehen. Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

## Mitwirkende an diesem Übungsbeispiel
Aleksandar Karakaš

