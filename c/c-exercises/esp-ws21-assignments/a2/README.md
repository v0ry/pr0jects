# Assignment 2 : Tanz der Zeichenketten

<span style="color:red">
Achtung: Dies ist ein Assignment aus dem *Wintersemester 2021*, welches nun als freiwilliges Übungsbeispiel implementiert werden kann. Die Assignments des aktuellen Semesters sind auf Gitlab in eigenen Repositories zu finden.
</span>
<p>

## Lernziele
Strings, Pointer, Dynamische Speicherverwaltung

Lines of Code der Musterlösung

**Achtung:** *<string.h>* darf zur Lösung dieser Aufgabe **nicht** verwendet werden! *(Zumindest im WS21 war es nicht erlaubt.)*

## Aufgabenstellung - Übersicht
Das Programm erhält über `stdin` mehrere Sätze. Wird ein `\n` gelesen, hört das Programm auf, Sätze einzulesen.

Nun wird ein Auswahlmenü angezeigt:
```
Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze verketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: 
```
---
Die Funktionen der Optionen werden anhand der folgenden Eingabe erklärt:
```
Das ist ein unnoetiger Satz. C ist so schwer.
```
---

Wenn die\*der Benutzer\*in `t` eingibt:
```
Text Statistik:
2 Sätze, 37 Zeichen
35 Buchstaben (3 Großbuchstaben, 32 Kleinbuchstaben)
```

Wenn die\*der Benutzer\*in `s` eingibt:
```
Nummer des ersten Satzes: 1 [Anmerkung: 1 wurde eingegeben]
Nummer des zweiten Satzes: 2 [Anmerkung: 2 wurde eingegeben]
```
Nun wird der Satz 1 mit dem Satz 2 vertauscht (Ergebnis: `C ist so schwer. Das ist ein unnoetiger Satz.`).


Wenn die\*der Benutzer\*in `c` eingibt:
```
Nummer des ersten Satzes: 1 [Anmerkung: 1 wurde eingegeben]
Nummer des zweiten Satzes: 2 [Anmerkung: 2 wurde eingegeben]
```
Nun wird der Satz 1 mit dem Satz 2 mit einem `und` verbunden (Ergebnis: `Das ist ein unnoetiger Satz und C ist so schwer.`).

Wenn die\*der Benutzer\*in `p` eingibt:
```
 Nr. | Satz
-----+----------------------------------------
   1 | Das ist ein unnoetiger Satz.
   2 | C ist so schwer.
```

Wenn die\*der Benutzer\*in `o` eingibt:
```
Text:
Das ist ein unnoetiger Satz. C ist so schwer.
```

Wenn die\*der Benutzer\*in `e` eingibt:
```
Programmende!
```
Danach wird das Programm mit dem Rückgabewert `0` beendet.

Bei allen Operationen (außer bei `e` - Programmende) wird danach wieder das Auswahlmenü angezeigt.

---

## Aufgabenstellung - Detailliert

**Hinweis:** Jede ausgegebene Zeile wird mit einem `\n` abgeschlossen. Die Ausnahme bilden Eingaben durch Benutzer\*innen, denn es wird *nur bei der [ersten Eingabe](#einlesen-der-sätze)* (bei `Bitte Text eingeben:`) ein `\n` ausgegeben.

### Einlesen der Sätze

Das Programm startet mit der Ausgabe von:
```
Bitte Text eingeben:
```

Danach kann die\*der Benutzer\*in eine **beliebige Anzahl** von Sätzen eingeben. Ein Satz wird mit eiem Punkt (`.`), Fragezeichen (`?`) oder Rufzeichen (`!`) abgeschlossen. Wird ein `\n` (Enter gedrückt) gelesen, hört das Programm auf, Sätze einzulesen.

---
**Tipp:** Es macht keinen Sinn, bei jedem einzelnen gelesenen Zeichen immer `realloc()` aufzurufen. Reservieren Sie also z.B. immer Platz für 100 Zeichen, wenn dieser Platz nicht mehr ausreicht, wieder für 100 Zeichen usw. (Hinweis: `fgets()`).
Speichern Sie danach die Sätze intern als einzelne Strings (ohne Leerzeichen vor oder nach dem Text)! Das heißt pro Satz verwenden Sie einen String und somit ein Mal `malloc()`.

---

**Fehlermeldungen:**
 - Wird in der Eingabe kein Zeichen gefunden, das einen Satz abschließt (`.`, `?`, `!`), so kommt es zu der folgenden Ausgabe
      ```
      Kein Satz gefunden!
      ```
      und das Programm wird mit dem Rückgabewert `1` beendet.


 - Sollte sich am Ende des letzten Satzes kein Punkt (`.`), Fragezeichen (`?`) oder Rufzeichen (`!`) befinden, so wird
      ```
      Der Text endet ohne Satzzeichen!
      ```
      ausgegeben und das Programm mit dem Rückgabewert `2` beendet.


 - Sollte nicht genügend Speicher vorhanden sein, so lautet die Fehlermeldung
      ```
      Zu wenig Speicher vorhanden!
      ```
      und das Programm wird mit dem Rückgabewert `3` beendet.

---

### Auswahlmenü

Nach erfolgreicher Eingabe der Sätze wird eine leere Zeile ausgegeben und danach wird ein Auswahlmenü angezeigt:
```
Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze verketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: <Eingabe>
```

die\*der Benutzer\*in tätigt nun eine Eingabe, um eine Option auszuwählen. Falls die Eingabe ungültig ist (ungleich `t`, `s`, `c`, `p`, `o` oder `e`), wird wieder `Ihre Wahl: ` ausgegeben (*Hinweis:* `getchar()`). Wird ein Leerzeichen vor dem Buchstaben eingegeben, ist die Eingabe ungültig.

---

### Text ohne Zeilennummer ausgeben

Wurde die Auswahl `o` durch die\*den Benutzer\*in getroffen, wird der gespeicherte Text ausgegeben. Zwischen den einzelnen Sätzen wird genau ein Leerzeichen ausgegeben. Beachten Sie, dass sich der Text während der Laufzeit des Programms verändern kann (z.B. durch die Option `s` - *Zwei Sätze vertauschen*)!

Beispiel-Eingabe:
```
Das ist ein unnoetiger Satz.                     C ist so schwer.
```

Ausgabe durch Option `o`:
```
Text:
Das ist ein unnoetiger Satz. C ist so schwer.
```

Weitere Beispiel-Ausgabe nach dem Vertauschen von Satz 1 und Satz 2 (Option `s`, danach Option `o`):
```
Text:
C ist so schwer. Das ist ein unnoetiger Satz.
```

---

### Text mit Zeilennummer ausgeben

Wurde die Auswahl `p` durch die\*den Benutzer\*in getroffen, wird der gespeicherte Text mit Satznummer (der erste Satz hat die Nummer 1) ausgegeben. Beachten Sie, dass sich der Text während der Laufzeit des Programms verändern kann (z.B. durch die Option `s` - *Zwei Sätze vertauschen*)!

Beispiel-Eingabe:
```
Das ist ein unnoetiger Satz.                     C ist so schwer.
```

Ausgabe durch Option `p`:
```
 Nr. | Satz
-----+----------------------------------------
   1 | Das ist ein unnoetiger Satz.
   2 | C ist so schwer.
```

Weitere Beispiel-Ausgabe nach dem Vertauschen von Satz 1 und Satz 2 (Option `s`, danach Option `p`):
```
 Nr. | Satz
-----+----------------------------------------
   1 | C ist so schwer.
   2 | Das ist ein unnoetiger Satz.

```

---

### Programm beenden

Wurde die Auswahl `e` durch die\*den Benutzer\*in getroffen, wird
```
Programmende!
```
ausgegeben und das Programm mit dem Rückgabewert `0` beendet.

---

### Text-Statistik

Wurde die Auswahl `t` durch die\*den Benutzer\*in getroffen, wird eine Statistik zu den Sätzen angezeigt. Es wird die Anzahl der Sätze, die Anzahl der Zeichen (ohne Leerzeichen), sowie die Anzahl der Groß- und die Anzahl der Kleinbuchstaben ausgegeben. Die Ausgabe sieht so aus (`x` ist dabei jeweils durch die entsprechende Anzahl zu ersetzen):
```
Text Statistik:
x Sätze, x Zeichen
x Buchstaben (x Großbuchstaben, x Kleinbuchstaben)
```

---
**ACHTUNG!**

Wurde zuvor die Option `c` ("Zwei Sätze verketten") gewählt, hat sich die Anzahl der Sätze und auch die Anzahl der Zeichen im Vergleich zu den eingegebenen Sätzen verändert!

---

### Zwei Sätze vertauschen

Wurde die Auswahl `s` durch die\*den Benutzer\*in getroffen, wird zuerst die Anzahl der Sätze überprüft. Sollte der Text nur mehr aus einem Satz bestehen, wird `Nur noch ein Satz vorhanden!` 
ausgegeben und danach wieder das Auswahlmenü angezeigt. Anderenfalls werden zuerst die Satznummern der Sätze abgefragt, die vertauscht werden sollen:

```
Nummer des ersten Satzes: <Eingabe>
Nummer des zweiten Satzes: <Eingabe>
```

Wird eine ungültige Zahl oder keine Zahl eingegeben, wird nocheinmal `Nummer des ersten Satzes: ` oder `Nummer des zweiten Satzes: ` ausgegeben.
Die Nummern des ersten und des zweiten Satzes müssen sich unterscheiden. Daher ist bei der Abfrage der zweiten Satznummer die nochmalige Eingabe der ersten Satznummer ungültig! Beispiel:
```
Nummer des ersten Satzes: 2
Nummer des zweiten Satzes: 2
Nummer des zweiten Satzes: 1
```

Nach der Eingabe der Satznummern werden die Sätze in der internen Datenstruktur vertauscht.

---

### Zwei Sätze verketten

Wurde die Auswahl `c` durch die\*den Benutzer\*in getroffen, werden zuerst die Satznummern der Sätze abgefragt, die zusammengefügt werden sollen:

```
Nummer des ersten Satzes: <Eingabe>
Nummer des zweiten Satzes: <Eingabe>
```

Die Eingabe soll exakt so wie bei der Option `s` erfolgen. Denken Sie auch an die Überprüfung, ob noch mindestens 2 Sätze vorhanden sind!

Nach der Eingabe der Satznummern werden die Sätze in der internen Datenstruktur zusammengefügt. Dabei wird das Satzzeichen, das den ersten Satz abgeschlossen hat, durch ein ` und ` ersetzt. (Satzaufbau: Satz mit der Nummer `Nummer des ersten Satzes` (ohne abschließendes Satzzeichen) + ` und ` + Satz mit der Nummer `Nummer des zweiten Satzes`.) Bedenken Sie, dass zwischen den beiden Sätzen mehrere Sätze stehen können z.B. Satz 6 mit Satz 2 verbinden.

Auf die Groß- und Kleinschreibung (Satzanfang) ist keine Rücksicht zu nehmen. In der [Beispielausgabe](#beispielausgabe) sehen sie weitere Beispiele, in welchen Sätze verkettet werden. Diese verdeutlichen auch das Verketten von Sätzen, die nicht aufeinanderfolgen.

---


## Beispielausgabe
```
Bitte Text eingeben:
Das ist ein Text. Hier kommt der zweite Satz. Ich bin der dritte Satz. Ein vierter Satz geht auch noch!

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: u
Ihre Wahl:    t
Ihre Wahl:  t
Ihre Wahl: t
Text Statistik:
4 Sätze, 84 Zeichen
80 Buchstaben (8 Großbuchstaben, 72 Kleinbuchstaben)

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: o
Text:
Das ist ein Text. Hier kommt der zweite Satz. Ich bin der dritte Satz. Ein vierter Satz geht auch noch! 

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: p
 Nr. | Satz
-----+----------------------------------------
   1 | Das ist ein Text.
   2 | Hier kommt der zweite Satz.
   3 | Ich bin der dritte Satz.
   4 | Ein vierter Satz geht auch noch!

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: s
Nummer des ersten Satzes: 100
Nummer des ersten Satzes: 2
Nummer des zweiten Satzes: 4

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: o
Text:
Das ist ein Text. Ein vierter Satz geht auch noch! Ich bin der dritte Satz. Hier kommt der zweite Satz. 

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: p
 Nr. | Satz
-----+----------------------------------------
   1 | Das ist ein Text.
   2 | Ein vierter Satz geht auch noch!
   3 | Ich bin der dritte Satz.
   4 | Hier kommt der zweite Satz.

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: t
Text Statistik:
4 Sätze, 84 Zeichen
80 Buchstaben (8 Großbuchstaben, 72 Kleinbuchstaben)

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: c
Nummer des ersten Satzes: 4
Nummer des zweiten Satzes: 1

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: p
 Nr. | Satz
-----+----------------------------------------
   1 | Ein vierter Satz geht auch noch!
   2 | Ich bin der dritte Satz.
   3 | Hier kommt der zweite Satz und Das ist ein Text.

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: o
Text:
Ein vierter Satz geht auch noch! Ich bin der dritte Satz. Hier kommt der zweite Satz und Das ist ein Text. 

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: t
Text Statistik:
3 Sätze, 86 Zeichen
83 Buchstaben (8 Großbuchstaben, 75 Kleinbuchstaben)

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: c
Nummer des ersten Satzes: 3
Nummer des zweiten Satzes: 2

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: p
 Nr. | Satz
-----+----------------------------------------
   1 | Ein vierter Satz geht auch noch!
   2 | Hier kommt der zweite Satz und Das ist ein Text und Ich bin der dritte Satz.

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: c
Nummer des ersten Satzes: 2
Nummer des zweiten Satzes: 1

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: p
 Nr. | Satz
-----+----------------------------------------
   1 | Hier kommt der zweite Satz und Das ist ein Text und Ich bin der dritte Satz und Ein vierter Satz geht auch noch!

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: o
Text:
Hier kommt der zweite Satz und Das ist ein Text und Ich bin der dritte Satz und Ein vierter Satz geht auch noch! 

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: t
Text Statistik:
1 Sätze, 90 Zeichen
89 Buchstaben (8 Großbuchstaben, 81 Kleinbuchstaben)

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: s
Nur noch ein Satz vorhanden!

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: c
Nur noch ein Satz vorhanden!

Wählen Sie eine Option:
  t: Text-Statistik
  s: Zwei Sätze vertauschen
  c: Zwei Sätze zusammenketten
  p: Text mit Zeilennummer ausgeben
  o: Text ohne Zeilennummer ausgeben
  e: Programm beenden

Ihre Wahl: e
Programmende!

```
