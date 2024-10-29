# Array-Algorithmen

In diesem Übungsbeispiel sollen ein Sortier- sowie ein Suchalgorithmus zu einem Array implementiert werden. Es können entweder eigene Algorithmen dazu überlegt werden oder zwei beschriebene implementiert werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Ein- und Ausgabe
  - Arrays, (Pointer)

Lines of Code der Musterlösung: 90

---

## Anleitung

Zu Beginn des Programms soll der Benutzer nach der Größe des Arrays gefragt werden mittels `Length of the array: `. Anschließend soll mit der eingegebenen Länge ein Ganzzahlarray erstellt werden. (Es ist hierzu nicht notwendig das Array speziell am Heap anzulegen, da C Variable-Length-Arrays unterstützt.) Im nächsten Schritt soll der Text `Numbers:\n` ausgegeben werden und danach soll der Benutzer solange Zahlen eingeben können, bis das Array gefüllt ist. Zwischen den Eingaben ist kein weiterer Text auszugeben.

Es kann in diesem Beispiel davon ausgegangen werden, dass der Benutzer nur gültige Eingaben tätigt.

### Sortier-Algorithmus

Nachdem das Array gefüllt worden ist, soll dieses nun aufsteigend sortiert werden. Anschließend sollen `Sorted Array:\n` und alle Werte des Arrays mit einem Leerzeichen getrennt ausgegeben werden. Abschließend noch ein Zeilenumbruch.

Zum Sortieren des Arrays kann ein beliebiger Algorithmus implementiert werden. Es ist sicherlich nicht verkehrt, sich selbst einen Algorithmus zu überlegen und diesen hier auszuprobieren. 

Beispiele für einfache Sortierverfahren sind Insertion-Sort (nähere Details können im Internet nachgelesen werden) oder auch Bubble-Sort, welcher nachfolgend erklärt wird:

### Bubble-Sort

Der Name Bubble-Sort kommt daher, dass bei diesem Algorithmus immer nur eine Bubble von zwei Elementen betrachtet wird. Zu Beginn umfasst die Bubble die ersten beiden Elemente im Array. Falls das zweite Element kleiner als das erste ist, werden die beiden vertauscht, sonst nicht. Danach verschiebt sich die Bubble um eins nach rechts, sodass nun das zweite und dritte Element darin enthalten sind. Falls das dritte Element kleiner als das zweite ist, werden die beiden vertauscht. Dies wird über die gesamte Länge des Array wiederholt, bis die letzten beiden Elemente betrachtet wurden. Nach dieser ersten Iteration befindet sich jetzt das größte Element des Arrays an letzter Stelle, da ja alle kleinere Elemente innerhalb der Bubble nach links vertauscht wurden.

Wenn diese Iteration ein zweites Mal ausgeführt wird, dann wird das zweitgrößte Element des Arrays irgendwann in der Bubble stehen und immer weiter vertauscht werden, bis es eine Position vor dem größten Element steht. Damit sind also schon zwei Elemente am richtigen Ort. Wenn diese Iteration nun so oft wiederholt wird wie das Array lang ist, befinden sich am Ende alle Elemente des Arrays am richtigen Platz und es ist sortiert.

Verbesserungspotenzial gibt es, in dem man berücksichtigt, dass die letzten Stellen schon korrekt sortiert sind, und man daher einen Durchlauf abbrechen kann, sobald auf die bereits sortierten Elemente getroffen wird.

### Such-Algorithmus

Nachdem die Sortier-Phase abgeschlossen ist, geht es im Folgenden nun um das Suchen im Array. Der Benutzer soll mittels `Enter number: ` dazu aufgefordert werden, eine Zahl einzugeben. Falls keine Zahl sondern `EOF` eingegeben wird, soll aus ästhetischen Gründen noch ein `\n` ausgegeben und das Programm beendet werden (Rückgabewert von `scanf` überprüfen).

Für jede eingegebene Zahl soll nun das Array durchsucht werden und danach ausgesagt werden, ob sich die Zahl im Array befindet `<number> was found.\n` oder nicht `<number> was not found.\n`. Hierzu kann wieder ein eigener Algorithmus überlegt und implementiert werden. Ein Beispiel für ein einfaches Suchverfahren ist die Binärsuche, welche nachfolgend erklärt wird.

Es ist **nicht** ausreichend als eigenen Algorithmus einfach nur jedes Element im sortierten Array durchzugehen und zu überprüfen. Dazu hätte das Array vorher nicht sortiert werden müssen und dieser Vorteil geht somit verloren.

### Binary-Search

Bei der Binärsuche wird das Element, das sich in der Mitte des Arrays befindet, betrachtet. (Bei gerader Anzahl an Elementen im Array kann entweder das Element vor oder nach der Hälfte betrachtet werden.) Falls dieses Element das Gesuchte ist, kann die Suche beendet werden, falls es kleiner als das Gesuchte ist, muss rechts davon weitergesucht werden, ansonsten links davon. Damit hat sich nun der Suchbereich um die Hälfte verkleinert.

In der nächsten Iteration wird nun nur mehr in der relevanten Hälfte des Arrays weitergesucht. Es wird wieder das Element in der Mitte bestimmt und nach dem gleichen Muster nur mehr im entsprechenden Viertel weitergesucht.

Dies wird solange fortgesetzt, bis entweder das gesuchte Elemente gefunden wurde, oder der Suchbereich keine weiteren Elemente mehr umfasst.

---

## Testen

Zum Testen stehen wieder automatische Tests zur Verfügung, die mittels `make test` ausgeführt werden können. Je ein Test bezieht sich auf einen der beiden Algorithmen, ein Test testet beide kombiniert.
