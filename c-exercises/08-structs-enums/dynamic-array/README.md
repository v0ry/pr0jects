# Dynamisches Array

In diesem Übungsbeispiel soll ein dynamisches Array implementiert werden, welches nicht nur speziell für dieses Übungsbeispiel funktionsfähig ist, sondern sehr allgemein in verschiedenen Anwendungen verwendet werden kann.

---

## Lernziele 

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Funktionen
  - Arrays, Pointer
  - Dynamisches Speichermanagement
  - Structs

Lines of Code der Musterlösung: 94 (nur die Funktionen gezählt, ohne Testcases)

---

## Anleitung

Mit dem dynamischen Speichermangement ist es nun möglich geworden, dass zur Laufzeit des Programms Speicher in beliebigen Größen angefordert und freigegeben werden können. Damit ist es nun auch machbar, ein Array zu implementieren, dass keine fixe Größe von Beginn an hat, sondern sich dynamisch während des Programmablaufs vergrößern und verkleinern kann.

### Datentyp

Die Struktur ist bereits vorgeben, falls nötig können aber noch zusätzliche Elemente ergänzt werden.

1. `start_` soll ein Pointer auf die Speicherstelle sein, an der das dynamische Array tatsächlich im Speicher beginnt.
2. `element_size_` gibt an, wie viele Bytes ein Element im Array groß ist. Beispielweise wäre das für einen Charakter die Größe 1, für einen Integer 4 usw.
3. `length_` gibt an, wie viele Elemente das Array groß ist.
4. `capacity_` gibt an, wie viele Elemente im Array Platz haben. Mit der Konstante `CAPACITY_STEP` ist angegeben, in welchen Schritten die Kapazität wachsen soll. Beispielsweise falls, das Array eine Länge von 4 hat, soll die tatäschliche Kapazität 8 sein. Falls das Array nun um 5 Elemente wächst (insgesamt 9), soll die Kapazität 16 sein usw.

Es ist nicht beabsichtig, dass auf diese Attribute außerhalb der bereits vordefinierten Funktionen zugegriffen wird. Die einzige Ausnahme davon sind die Testcases.

### Funktionen

Es sind bereits fünf Funktionen vordefiniert, welche implementiert werden sollen. Alle Funktionen besitzen bereits eine Beschreibung in `main.c`, trotzdem werden sie hier nochmals kurz erklärt.

```
void dynArray_init(DynArray* array, size_t element_size);
```
In dieser Funktion sollen alle Werte des Arrays auf die Startwerte gesetzt werden. Außerdem soll die Größe pro Element entsprechend gesetzt werden.

```
void dynArray_destroy(DynArray* array);
```
In dieser Funktion soll das Array zerstört werden und die Größe pro Element auf 0 zurückgesetzt werden. Falls sich noch Elemente im Array befinden, soll deren Speicher freigegeben werden.

```
int dynArray_push_back(DynArray* array, void* object);
```
In dieser Funktion wird das Element, das sich hinter `object` verbirgt, am Ende des Arrays angehängt. Falls nötig, muss dazu die Kapazität vergrößert und mehr Speicher angefordert werden. Fehlermeldungen beachten!

```
int dynArray_pop_back(DynArray* array);
```
In dieser Funktion wird das letztstehende Element aus dem Array gelöscht. Falls damit acht Plätze im Array wieder frei sind, soll deren Speicher wieder freigegeben werden. Fehlermeldungen beachten!

```
void* dynArray_at(DynArray* array, size_t position);
```
In dieser Funktion wird ein Pointer auf das Element an der gegebenen Position zurückgegeben. Falls die Position Out-of-Range ist, soll ein Nullpointer zurückgegeben werden. Es ist hierbei wichtig zu beachten, dass der Pointer nur solange gültig ist, solange die Größe des Arrays nicht verändert wird.

---

## Testen

In diesem Beispiel gibt keine automatischen Testcases, wie sie in den anderen Beispiel üblich waren. Jedoch ist schon ein Testcase direkt im Code fertig implementiert, welcher beim Ausführen von `./main` ausgeführt wird. Es ist ratsam, weitere Testcases zu implementieren und auch auf besondere Situationen / Edge-Cases zu achten.

Es kann durchaus hilfreich sein, das Programm mit dem Speicherüberprüfungstool `valgrind` auszuführen. Mittels `valgrind ./main` kann dies gemacht werden. Damit bekommt man eine Übersicht, ob der Speicher korrekt verwaltet wurde, oder ob es zu falschen Speicherzugriffen / Speicherlöchern etc. gekommen ist.

Das Makro `assert`, das im vorhandenen Testcase verwendet wird, beendet das Programm falls die Bedingung, die darin steht nicht wahr ist. Im Falle von `assert(my_array.start_ == NULL && "init: not setting nullptr");` würde das Programm beendet werden, falls `my_array.start_` nicht den Wert `NULL` hätte. Die Zeichenkette nach dem logischen UND ist immer wahr.
