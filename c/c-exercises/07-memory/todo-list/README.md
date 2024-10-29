# TODO List

In diesem Übungsbeispiel soll das Arbeiten mit Pointer, Arrays und dynamischen Speicher geübt werden. 

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Arrays
  - Pointer
  - dynammischer Speicher (Heap)
  - Strings

Lines of Code der Musterlösung: 103 inkl. Main-Funktion

---

## Anleitung

In diesem Beispiel soll eine einfache ToDo-Liste erstellt werden. Bei Programmstart kann der Benutzer neue Items zur ToDo-Liste hinzufügen. Nach jedem Hinzufügen wird die gesamte ToDo-Liste ausgegeben.

### Programmablauf

 Die main-Funktion enhält bereits ein paar wenige Zeilen Code, welche nicht verändert werden sollen. Die Variable `list` ist ein Array aus 50 Character-Pointer. In dieses Array sollen die Pointer der Strings der ToDo-Liste abgelegt werden. Die Strings (Text der Aufgabe) sollen am Heap angelegt werden.

Für jede Aufgabe/Item soll zunächste folgender Text ausgegeben werden:

```
Enter item: 
```

Danach kann der User die Aufgabe/ das Item eingeben. Nach und Nach soll der Benutzer nun Aufgaben/Items zu seiner ToDo-Liste hinzufügen können. Nach jeder Eingabe wird die aktuelle gesamte Liste ausgegeben - siehe [Beispiel](#Beispiel).

### Allokieren von Speicher am Heap

Jede Aufgabe / jedes Item soll am Heap gespeichert werden. Es ist ausreichend eine maximale Stringlänge von 64 vorzugeben - ein "define" `MAX_INPUT_SIZE` ist bereits vorhanden. Die Pointer zu diesen Strings sollen dann in das Array `list` gespeichert werden. 



### Ausgabe der aktuellen Liste

Schreibe eine eigene Funktion `printList()` welche die Liste und die Länge der aktuellen Liste als Parameter erhält und diese ausgibt. Zu Beginn der Ausgabe soll `Current ToDo List:\n` ausgegeben werden. Dann folgt die Liste im Format `<item_id>: <name>`.  Nach der Ausgabe der gesamte aktuellen Liste soll `----------------------\n` ausgegeben werden. Siehe [Beispiel](#Beispiel). 

### Programmende

Es gibt 2 Möglichkeiten das Programm zu beenden:

- Hat der Benutzer alle 50 Items/Aufgaben eingetragen soll das Programm die Meldung `Maximum Number of Items reached\n` ausgeben und mit dem Rückgabewert 0 beenden. (Es soll keine Möglichkeit geben, dass der User nach der Meldung noch eine Eingabe tätigt)

- Hat der Benutzer den Befehl "quit" eingegeben, soll das Programm mit Rückgabewert 0 beenden. Dieser Befehl ist case insensitive ("QUiT", "qUiT", ... sind gültige Befehle)

In allen Fällen ist zu beachten, dass der angeforderte Speicher am Heap wieder freigegeben werden muss. 



---

## Beispiel

```
---- Starting ToDo List ----
Enter item: item1
Current ToDo List:
0: item1
----------------------
Enter item: item2
Current ToDo List:
0: item1
1: item2
----------------------
Enter item: item3
Current ToDo List:
0: item1
1: item2
2: item3
----------------------
Enter item: imte4
Current ToDo List:
0: item1
1: item2
2: item3
3: imte4
----------------------
Enter item: item5
Current ToDo List:
0: item1
1: item2
2: item3
3: imte4
4: item5
----------------------
Enter item: qUiT
```



---

## Testen

Bei diesem Beispiel gibt es wieder automatische Tests, die mit `make test` gestartet werden können. 
