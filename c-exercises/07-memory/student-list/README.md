# Studentenliste am Heap

In diesem Übungsbeispiel soll vor allem das Arbeiten mit dem Heap geübt werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Funktionen
  - Strings
  - Arrays
  - Pointer
  - dynamischer Speicher (Heap)

Lines of Code der Musterlösung: 90 inkl. Main-Funktion

---

## Anleitung

In diesem Übungsbeispiel soll eine kleine Liste von Studenten angelegt werden. Die `main`-Funktion ist bereits vorgegeben. Es sind noch die Funktionen `readAndGetNames()` und `freeList()` zu implementieren, welche bereits in der `main`-Funktion aufgerufen werden. Die `main`-Funktion soll (aufgrund des Lerneffekts) nicht mehr verändert werden. 

In der `main`-Funktion wird bereits die Anzahl der Studenten abgefragt.

### Funktion `readAndGetNames()`

Die Funktion erhält bereits die Anzahl der Studenten als Parameter. Es soll nun eine Liste erstellt werden, in die dann die Namen mit `stdin` eingefügt werden können. 

#### Eingabe der Namen

Vor der Eingabe jedes Names soll folgender Text ausgegeben werden: `Enter <nr> name:  `  *(beachte das Leerzeichen nach dem Doppelpunkt)*
Wobei `<nr>` die aktuelle Aufzählungszahl dieser Person ist.  Beispiele: ``Enter 1st name:  `, `Enter 2nd name:  `, `Enter 3rd name:  `, `Enter 4th name:  `, `Enter 5th name:  ` , ....

Nach dieser Ausgabe soll der Name eingegeben werden können. Dieser Name soll mit einer maximalen Länge von 32 beschränkt sein und mit `\n` bestätigt werden können. Ist der Name länger sollen nur die ersten 31 Zeichen eingelesen werden (31 Zeichen + Nullbyte = 32 Zeichenlänge des Strings) Siehe [Beispielausgabe](#Beispielausgabe).

**Tipp:** es reicht nicht aus nur für jeden String Speicher zu allokieren.



Diese Eingabe der Name soll nur 1x geschehen, die Liste wird dann von der `main`-Funktion ausgegeben und die Funktion `freeList()` wird aufgerufen. 

### Funktion `freeList()`

In der Funktion `readAndGetNames()` muss das Array am Heap angelegt werden, damit es in der `main`-Funktion ausgegeben werden kann. In der Funktion `freeList()` soll nun der angefordeter Speicher wieder freigegeben werden. 



## Beispielausgabe



```
How many students are in class? 4
Enter 1st name: David K
Enter 2nd name: Michael G
Enter 3rd name: Alex S
Enter 4th name: Aleks K
Student list:
--------------------------------------
|1: David K                          |
|2: Michael G                        |
|3: Alex S                           |
|4: Aleks K                          |
--------------------------------------
```



---

## Testen

Bei diesem Beispiel gibt es wieder automatische Tests, die mit `make test` gestartet werden können.