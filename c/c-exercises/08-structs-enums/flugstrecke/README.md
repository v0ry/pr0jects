# Flugstrecke

In diesem Übungsbeispiel soll das Arbeiten mit Pointer und Structs mittels einer Linked List geübt werden.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Arrays
  - Pointer
  - dynammischer Speicher (Heap)
  - Strings
  - Structs (inbesondere die Datenstruktur Linked List)
  - Kommandozeilenparamter

Lines of Code der Musterlösung: 80 inkl. Main-Funktion

---

## Anleitung

In diesem Beispiel soll eine Flugstrecke eines Piloten simuliert werden. Eine Flugstrecke besteht aus einem Startpunkt, einigen Zwischenlandungen in verschiedenen Städten und einem Endpunkt. Die Flugstrecke soll beim Programmaufruf als Kommandozeilenparameter dynamisch verändert werden können.

### Erstellung der Flughafen

Zunächst soll eine Struktur erstellt werden, welche den Flughafen einer Stadt abbildet. Ein Flughafen hat einen Namen und einen Pointer auf den Flughafen der nächsten Zwischenlandung des Piloten (also ein Pointer auf den nächsten Flughafen). Die Flughäfen müssen am Heap erstellt werden, der Name des Flughafens kann dabei mit max. 64 Zeichen begrenzt sein. 

### Programmaufruf / Erstellung der Flugrute

Die Flugstrecke soll anhand er Kommandozeilenparameter vorgegeben werden. Jeder Flughafen besitzt eine ID, welche beim Programmaufruf eingegeben wird. 

| ID   | Flughafen |
| :--- | --------- |
| 0    | Graz      |
| 1    | Wien      |
| 2    | Berlin    |
| 3    | Frankfurt |
| 4    | Miami     |
| 5    | Kapstadt  |
| 6    | Tokyo     |

Der Städte der Flugrute ergeben sich aus den eingegebenen Zahl als Kommandozeilenparamter. Danach sollen die Flughäfen anhand der eingebenen Zahlenfolge aneinander gekettet werden (Linked List). Es ist erlaubt mehrmals an einen Flughafen zureisen. Um die Aufgabe zu vereinfachen ist es in diesem Fall in Ordnung neue Objekte für den selben Flughafen zu Erstellen.

#### Beispielaufrufe des Programms: 

`./flightroute 0143` soll in Graz starten und die Flughäfen Wien, Miami und Frankfurt (in dieser Reihenfolge) bereisen. 

`./flightroute 6252` soll in Tokyo starten und Berlin, Kapstadt und erneut Berlin (in dieser Reihenfolge) bereisen. 

Es sollen nur jene Flughafen erstellt werden, die auch wirklich vom Piloten bereist werden. Das heißt zunächst muss eingelesen werden, welcher Flughafen erstellt werden soll, dieser ist dann am Heap zu erstellen und richtig zu mit dem Vorgänger zu verlinken.

### Ausgabe

Für die Ausgabe der Flugstrecke ist die Funktion `printFlightroute(Airport* start)` zu schreiben. Diese Funktion erhält als Parameter den Startflughafen des Piloten und iteriert über das `next_`-Attribut über alle bereisten Flughäfen des Piloten. 

Zu Beginn soll die Meldung `Pilot starts at %s\n` ausgegeben werden, wobei hier der String `start->name_` eingefügt werden soll. Danach sollen alle weiteren Flughäfen der Linked List mittels `Current city %s\n` ausgegeben werden. Beim letzten Flughafen soll dann die Meldung `Pilot finish travel at %s\n` ausgegeben werden. Siehe [Beispiel](#Beispiele).



### Fehlermeldungen

| Rückgabewert | Beschreibung                                                 |
| ------------ | ------------------------------------------------------------ |
| 1            | Sollten beim Programmaufruf keine oder zu viele Parameter mitgegeben werden soll die Fehlermeldung `Wrong parameter count\n` ausgegeben werden und das Programm mit dem Rückgabewert 1 beenden. |
| 2            | Sollte eine ungültige Flughafen ID eingegeben werden, so ist der Aufruf ungültig und das Programm soll sofort die Fehlermeldung `Only airport IDs from 0 to 6 are valid\n` ausgeben werden und mit dem Rückgabewert 2 beenden. |
| 3            | Eine Flugstrecke muss mindestens 2 Stationen besitzen (Start- und Endpunkt). Sollten weniger Stationen als Parameter mitgegeben werden soll die Fehlermeldung `Endpoint required\n` ausgegeben werden und das Programm mit dem Rückgabewert 3 beenden. |

**Wichtig**: Jeglicher am Heap angefordeter Speicher muss wieder freigegeben werden. Dafür ist eine Funktion `deleteAirports(Airport* start)` zu schreiben. 

---

## Beispiele

```
./flightroutes 0123456
Pilot starts at Graz
Current city Wien
Current city Berlin
Current city Frankfurt
Current city Miami
Current city Kapstadt
Pilot finish travel at Tokyo
```

```
./flightroutes 42121356
Pilot starts at Miami
Current city Berlin
Current city Wien
Current city Berlin
Current city Wien
Current city Frankfurt
Current city Kapstadt
Pilot finish travel at Tokyo
```

```
./flightroutes 458
Only airport IDs from 0 to 6 are valid
```



---

## Testen

Bei diesem Beispiel gibt es wieder automatische Tests, die mit `make test` gestartet werden können. 
