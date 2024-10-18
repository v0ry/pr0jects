# Geometrische Formen

> **Hinweis:** Für diese Aufgabe dürfen Sie eine Online-IDE verwenden, auf die Sie mit folgendem Link zugriffen haben: <https://www.onlinegdb.com/>

> **Hinweis:** In diesem Beispiel sollen alle Attribute privat sein und alle in der Angabe geforderten Methoden sollen öffentlich sein. Falls Sie Member hinzufügen möchten, die nicht in der Angabe beschrieben wurden, können Sie das gerne tun. (Das könnte sogar notwendig sein.)

> **Hinweis:** Es ist darauf zu achten, dass bei der Verwendung der hier zu schreibenden Klassen keine Memory Leaks auftreten können.

> **Hinweis:** Bei mathematischen Operationen muss die Möglichkeit eines Overflows nicht berücksichtigt werden.

## a) Basisklasse für geometrische Formen: `Shape` (5 Punkte)

Schreiben Sie eine Klasse für geometrische Formen. Diese Klasse soll Shape heißen.

### Attribute

- `id_`: Attribut vom Typ `size_t`.

### Methoden

- Konstruktor: Nimmt keine Parameter und setzt das Attribut `id_` eines `Shape`-Objekts. Das erste erstellte `Shape`-Objekt soll die ID 1 haben. Jedes weitere `Shape`-Objekt soll eine ID haben, die um 1 größer ist als jene des zuletzt erstellten `Shape`-Objekts.
- Copy-Konstruktor: Soll die ID eines zu kopierenden `Shape`-Objekts nicht kopieren, sondern so wie der Konstruktor eine neue ID vergeben.
- Zuweisungsoperator: Soll nicht verfügbar sein.
- `area`: Rein virtuelle, öffentliche Methode ohne Parameter und Rückgabetyp double. Sie soll den Flächeninhalt einer geometrischen Form zurückgeben.
- `print`: Öffentliche Methode ohne Rückgabewert und Parameter. Gibt den Text `Shape with ID <ID> is <AREA> units large.\n` aus. Dabei soll `<ID>` durch den im Attribut `id_` gespeicherten Wert ersetzt werden und `<AREA>` soll durch den Rückgabewert der Methode area ersetzt werden.
- Operator `+`: Wenn zwei `Shape`-Objekte mit `+` addiert werden, soll die Summe der beiden Flächeninhalte zurückgegeben werden.

## b) Subklasse `Rectangle` (2 Punkte)

`Rectangle` ist eine Subklasse von `Shape`.

### Attribute

- `width_`: Attribut vom Typ `double`, welches die Breite eines Rechtecks angibt.
- `length_`: Attribut vom Typ `double`, welches die Länge eines Rechtecks angibt.

### Methoden

- Konstruktor: Nimmt zwei Parameter. Setzt das `width_`-Attribut auf den Wert des ersten Parameters und das `length_`-Attribut auf den Wert des zweiten Parameters.
- Copy-Konstruktor: Kopiert die Werte der Attribute `width_` und `length_`.
- Zuweisungsoperator: Soll nicht verfügbar sein.
- `area`: Gibt den Flächeninhalt eines Rechtecks zurück. Dieser beträgt *w &sdot; l*, wobei *w* für die Breite und *l* für die Länge des Rechtecks steht.
- `print`: Wie die gleichnamige Methode in der Basisklasse. Der einzige Unterschied zur Methode der Basisklasse ist, dass das erste Wort der Ausgabe nicht `Shape` sondern `Rectangle` lautet. Bei dieser Methode soll Polymorphie unterstützt werden. Wenn also z. B. ein Pointer auf ein `Rectangle`-Objekt in einer Variable vom Typ `Shape*` gespeichert ist, und auf dieser Variablen die `print`-Methode aufgerufen wird, soll die Methode der Subklasse (und nicht jene der Basisklasse) aufgerufen werden.
