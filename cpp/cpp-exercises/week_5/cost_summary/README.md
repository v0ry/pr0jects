# WG Kostenaufstellung

Das Erstellen von Klassen sowie das Arbeiten mit Vektoren sollen in diesem Beispiel geübt werden.

------

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:

- Klassen (inkl. Konstruktoren und Destruktoren und anderen Methoden)
- Dynamischer Speicher (Heap)
- Vektoren (`std::vector`)



------

## Das Problem

In diesem Beispiel soll eine einfache Ausgabenübersicht (z.B. für eine Wohngemeinschaft) programmiert werden. Hierfür wird die Datei `main.cpp` zur Verfügung gestellt. In ihr befindet sich die `main`-Funktion, welche jedoch unvollständig ist. Auch die im Programm zu verwendenden Klassen wurden noch nicht bzw. nur teilweise geschrieben.


## Deine Lösung

Schreibe die fehlende Klasse `Cost` und vervollständige den Code für die Klasse `Person`. Überlege dabei auch, an welchen Stellen (Membervariablen, Methoden, Parameter von Methoden, ...) das Schlüsselwort `const` verwendet werden kann und soll.

### Klasse `Cost`

Diese Klasse repräsentiert eine Ausgabe einer Person. Darin werden sowohl die Kosten als auch der Verwendungszweck zusammengefasst.

#### Attribute

- `description_`
  - der Verwendungszweck (z. B. "Lebensmittelkauf") als `std::string`
- `price_`
  - die Kosten der Ausgabe als `float`

#### Methoden

- `Cost(std::string description, float price)`
  - ein Konstruktor mit zwei Parametern
  - soll das Attribut `description_` auf den Wert des Parameters `description` setzen und das Attribut `price_` auf `price`
- `print()`
  - Ausgabefunktion auf std::cout im folgenden Format: 
    `std::cout << std::fixed << std::setprecision(2) << price_ << " '" << description_ << "'" << std::endl;`
  - Die Funktion soll nur diese Ausgabe tätigen.
  - Rückgabewert: `void`
- `getPrice()`
  - soll das Attribut `price_` zurückgeben
  - Rückgabewert: `float`



### Klasse Person

Die Klasse `Person` stellt eine Person dar, die Ausgaben hat (z. B. ein\*e Mitbewohner\*in in einer Wohngemeinschaft). Diese Klasse ist bereits zum Teil erstellt.

#### Attribute

- `name_`      
  - Der Name der Person als std::string
- `costs_`    
  - ein Vektor (`std::vector`) aus `Cost*` (siehe Klasse [Cost](#klasse-cost)) 
  - Eine Person kann beliebig viele Kosten-Objekte haben. Pointer auf diese Objekte werden in diesem Vektor abgespeichert.

#### Methoden

Die folgenden Methoden könnten für das Programm nützlich sein, auch wenn – abhängig vom Lösungsansatz – evtl. nicht alle notwendig sind.

- `Person(std::string name)`
  - ein Konstruktur mit einem Parameter: der Name einer Person
  - setzt das Attribut `name_` auf den Wert des Parameters `name`
- `getName()`
  - gibt den Namen der Person als `std::string` zurück
  - Rückgabewert: `std::string`
- `getCosts()`
  - gibt den Vector von `Cost*` zurück
  - Rückgabewert: `std::vector<Cost*>`
- `addCost(Cost* new_cost)`
  - fügt ein neues Element vom Typ `Cost*` in den Vektor `costs_` ein
  - Rückgabewert: `void`
- `addCost(std::string description, float price)`
  - erstellt zuerst ein `Cost`-Objekt mit Hilfe der beiden Parameter `description` und `price` und fügt das neu erstelle Element in den Vektor `costs_` ein
  - Überladene Methode jener Methode darüber. Das bedeutet gleicher Name aber andere Parameter. Dadurch kann die Methode `addCost` auf verschiedene Arten verwendet werden:
    - Wenn man bereits über ein `Cost`-Objekt verfügt, kann man `addCost` mit einem Pointer auf dieses Objekt aufrufen.
    - Wenn man noch kein `Cost`-Objekt erzeugt hat, kann man `addCost` mit den Parametern `description` und `price` aufrufen und `addCost` wird sich um die Erzeugung eines entsprechenden `Cost`-Objekts kümmern.
  - Rückgabewert: `void`
- `readCosts()`
  - größtenteils schon imlementiert (fehlender Teil ist im Code mit `TODO` markiert)
  - liest mit `std::cin` den Verwendungszweck (`description_`) und den Preis (`price_`) von Ausgaben ein, erstellt entsprechende `Cost`-Objekt und fügt Pointer auf diese Objekte in den `cost_`-Vektor ein
- `printCosts()`
  - gibt mit `std::cout` die Kosten dieser Person aus. Diese Funktion ist bereits teilweise implementiert, um kleine Fehler bei den Testcases (z. B. ein Leerzeichen zu viel oder zu wenig) zu vermeiden. 
  - soll für jedes Element im Vektor `costs_` die `print`-Methode aufrufen
  - Rückgabewert: `void`
- `getFullCosts()`
  - berechnet die Gesamtkosten für diese Person
  - soll über den Vektor aus Kosten iterieren, alle Kosten zusammenzählen und den Gesamtwert zurückgeben
  - Rückgabewert: `float`
- `isEqual(const std::string& a, const std::string& b)`
  - bereits implementierte private `static` Methode, die in der Methode `readCosts` verwendet wird
  - vergleicht zwei Strings (case-insensitive) mit einander und gibt bei Gleichheit `true` zurück, andernfalls `false`
  - wird von `readCosts` verwendet, um festzustellen, wann mit dem Einlesen neuer Ausgaben aufgehört werden soll



### Programmablauf und `main`-Funktion

Das Programm nimmt beim Start die Namen der Personen als Kommandozeilenargumente an. Beispielprogrammaufruf:

```
./wg_costs David Michi Aleks
```

Hierbei können beliebig viele Namen als Kommandozeilenargumente angegeben werden.

In der Datei `main.cpp` sind noch folgende Teile zu implementieren (siehe auch `TODO`s in `main.cpp`):

- Die Personen sind als Objekte am Heap zu erstellen.
- Die Personen sollen in der `main`-Funktion in einer lokalen Variable namens `persons` abgespeichert werden, welche ein Vektor ist.
- Zuerst soll es möglich sein, für alle Personen die Kosten einzugeben (mittels Aufruf der zu implementierenden `Person`-Methode `readCosts()`)
  (Hat man alle Kosten einer Person eingegeben, soll (um das Beispiel einfach zu halten) `exit` bei Description eingegeben werden, um zur Kosteneingabe der nächsten Person zu gelangen.)
- Erst wenn alle Kosten aller Personen eingegeben wurden, sollen die Kosten für jede Person ausgegeben werden (mittels Aufruf der `Person`-Methode `printCosts()`).
- **Wichtig:** Bevor das Programm beendet wird, soll sämtlicher am Heap angeforderter Speicher freigegeben werden.

### Beispielprogramm

```
./wg_costs David Michi Aleks
Add new costs for David:  (type 'exit' in description if finished)
Description: Beer from 4.2.  
Price: 13.43
Description: Food 5.2.
Price: 42.02
Description: exit
Add new costs for Michi:  (type 'exit' in description if finished)
Description: Food 3.2.
Price: 11.43
Description: exit
Add new costs for Aleks:  (type 'exit' in description if finished)
Description: Friday Party      
Price: 42.82
Description: exit
----------------------------------
Costs of David
13.43 'Beer from 4.2.'
42.02 'Food 5.2.'
Total costs of David: 55.45
----------------------------------
Costs of Michi
11.43 'Food 3.2.'
Total costs of Michi: 11.43
----------------------------------
Costs of Aleks
42.82 'Friday Party'
Total costs of Aleks: 42.82
```



------

## Testen

Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird eine Datei namens `testreport.html` erstellt. Sie enthält einen Bericht, der dir zeigt, welche Ausgabe dein Programm produzieren sollte und welche Ausgabe dein Programm produziert. Du erhältst auf diese Weise sofortiges Feedback zu deiner Lösung.

## Lösung

Eine Lösung unserer Tutor\*innen befindet sich im Ordner `solution`. Solltest du Probleme haben, das Übungsbeispiel zu lösen, dann könnte dir diese von uns bereitgestellte Lösung helfen. Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

Im Ordner `solution` gibt es auch ein Makefile. Das heißt, dass du im Ordner `solution` ebenfalls `make test` ausführen kannst. Damit wird die Lösung unserer Tutor\*innen getestet.

## Mitwirkende an diesem Übungsbeispiel
### Autor\*innen

- David Kerschbaumer

### Lektorat

 - Aleksandar Karakaš
