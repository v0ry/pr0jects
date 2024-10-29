# Schere-Stein-Papier

In diesem Übungsbeispiel soll das Spiel Schere-Stein-Papier implementiert werden. Es soll dabei möglich sein gegen einen Computerspieler anzutreten.

**Achtung:** Es empfiehlt sich zuvor das Übungsbeispiel "Abgesicherte Eingabe von einzelnen Zeichen" zu erarbeiten. Zwingend erforderlich ist es aber nicht.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen
  - Funktionen
  - Ein- und Ausgabe (Übungsbeispiel: "Abgesicherte Eingabe von einzelnen Zeichen" hilfreich)
  - Zufallszahlen

Lines of Code der Musterlösung: 158 inkl. Funktionen für die abgesicherte Eingabe

---

## Anleitung

Für unser Spiel benötigen wir zum einen eine Eingabe vom Spieler und zum anderen brauchen wir vom Computerspieler eine möglichst zufällige Auswahl. Schließlich muss noch ausgewertet werden, wer der beiden gewonnen hat. Damit das Programm nicht sofort nach einer Runde vorbei ist, hat derjenige gewonnen, der drei einzelnen Runden gewinnen konnte.

### Eingabe des Spielers

Zu Beginn jeder Runde soll ausgegeben werden, um die wievielte es sich handelt mit dem Text `\nRound <round>: You: <you> vs. Computer: <computer>\n`, wobei `<round>` durch die aktuelle Runde, `<you>` durch die Rundensiege vom Spieler und `<computer>` durch die Rundensiege vom Computer ersetzt werden sollen.

Anschließend soll der CommandPrompt `> ` ausgegeben werden und der Spieler kann seine Eingabe tätigen. Damit klar ist, welche Eingabeoptionen möglich sind, ist es eine gute Idee zu Beginn des Programm oder vor jeder Eingabe die Möglichkeiten auszugeben, beispielweise mit `Options: Rock (R,r), Paper (P,p), Scissors (S,s), Quit (Q,q)\n`. An dieser Stelle kann eins zu eins die Funktion `safeInput` aus dem Übungsbeispiel "Abgesicherte Eingabe von einzelnen Zeichen" verwendet werden. (Natürlich ist das Beispiel aber auch ohne diese Funktion lösbar.) Bei Eingabe von `Q`, `q` oder `EOF` soll wie bekannt an der Stelle das Programm beenden. Andernfalls ist nun der Computerspieler an der Reihe.

### Auswahl des Computerspielers

Für den Computerspieler möchten wir eine Zufallsauswahl umsetzen. Dazu werden wir zwei Funktionen aus der Bibliothek `stdlib.h` verwenden und eine Funktion aus `time.h`, die somit neben `stdio.h` in unser File einzubinden sind. 

Mit der Funktion `int rand(void)` bekommen wir eine Zufallszahl im Zahlenbereich `[0, RAND_MAX]` zurückgegeben. Diese Funktion ist jede Runde für den Computerspieler aufzurufen. Die erhaltene Ganzzahl können wir anschließend durch `3` dividieren. An dieser Stelle interessiert uns dann der Rest dieser Division, dieser ist nämlich entweder `0`, `1` oder `2` - es sind also genau drei Möglichkeiten. Diese Zahlen können wir dann genau für das Schere-Stein-Papier verwenden. Beispielsweise können wir `0` auf Rock, `1` auf Paper und `2` auf Scissors mappen, womit wir eine zufällige Auswahl des Computers umgesetzt haben. Anschließend können wir die Auswahl auch ausgeben mit `Computer: <letter>\n`, wobei `<letter>` mit `R`, `P` oder `S` zu ersetzen ist. 

Ein Problem gibt es aber dabei noch. Aktuell wird immer die gleiche Folge von Zufallszahlen generiert. Das hängt damit zusammen, dass wir keinen speziellen Seed (=Startwert) setzen. Mit der Funktion `void srand(unsigned int seed)` ist es möglich einen Seed zu setzen, womit jetzt eine andere Folge von Zufallszahlen generiert werden sollte. Damit sich der Seed dynamisch bei jedem Programmstart ändert, können wir die Funktion `time_t time(time_t *tloc)` verwenden. Die Signatur schaut etwas komplexer als die der anderen Zahlen, aber im wesentlichen gibt uns diese Funktion die Systemzeit in Sekunden zurück. Als Argument übergeben wir jetzt einmal einfach `NULL` ohne weitere Erklärungen. Warum das notwendig ist, wird wahrscheinlich nach dem Kapitel über Pointer klarer. Damit sieht also der ganze Aufruf zu `srand` folgendermaßen aus

```
srand(time(NULL));
```

**Wichtig:** Dieser Startwert muss nur **genau einmal** zu Beginn des Programms gesetzt werden. Anschließend ist nur mehr mittels `rand` zu arbeiten.

Eine Anmerkung für Interessierte: Die Modulo-Berechnung von oben kann Einfluss darauf haben, ob die Zahlen danach noch immer zufällig sind. Angenommen wir würden von `rand` die Zahlen 0 bis 15 bekommen und anschließend Modulo 3 rechnen. Dann kommt bei den Zahlen 0, 3, 6, 9, 12, 15 Rest 0 heraus (das sind 6 Möglichkeiten), Rest 1 kommt hingegeben aber nur bei den Zahlen 1, 4, 7, 10, 13 heraus (das sind nur 5 Möglichkeiten). Damit ist die Wahrscheinlichkeit höher eine 0 zu bekommen als eine 1. Natürlich ist `RAND_MAX` wesentlich größer als 15 und damit fällt dieser Effekt weniger stark ins Gewicht, besonders jetzt bei unserem kleinen Spiel. Dieses Problem sollte aber auf jeden Fall in anderen Projekten nicht einfach ignoriert werden, insbesondere wenn eine gute Zufallszahlenverteilung dringend erforderlich ist.

### Auswertung des Ergebnisses

Im letzten Schritt müssen wir uns nun ansehen, ob der Spieler oder der Computer gewonnen hat. Dazu brauchen wir nur die möglichen Fälle durchzugehen und zu überprüfen, wer gewonnen hat oder ob es einen Gleichstand gibt. Anschließend beginnt die nächste Runde. Falls einer der beiden Spieler die dritte Runde gewonnen hat, ist das Spiel vorbei. Folgende Texte sollen ausgegeben werden:

| Ausgang                | Text                                 |
| ---------------------- | :----------------------------------: |
| Spieler gewinnt Runde  | `You won!\n`                         |
| Spieler verliert Runde | `You lost!\n`                        |
| Spieler gewinnt Spiel  | `Congratulations! You won!\n`        |
| Spieler verliert Spiel | `You lost! Better luck next time!\n` |

---

## Beispielausgabe

Da es keine Testcases gibt, kann die Ausgabe auch etwas anders gestaltet werden.

```
Welcome to Rock-Paper-Scissors!
Options: Rock (R,r), Paper (P,p), Scissors (S,s), Quit (Q,q)

Round 1: You: 0 vs. Computer: 0
> r
Computer: P
You lost!

Round 2: You: 0 vs. Computer: 1
> p
Computer: P
Draw!

Round 3: You: 0 vs. Computer: 1
> p
Computer: R
You won!

Round 4: You: 1 vs. Computer: 1
> p
Computer: S
You lost!

Round 5: You: 1 vs. Computer: 2
> s
Computer: P
You won!

Round 6: You: 2 vs. Computer: 2
> p
Computer: P
Draw!

Round 7: You: 2 vs. Computer: 2
> s
Computer: S
Draw!

Round 8: You: 2 vs. Computer: 2
> p
Computer: P
Draw!

Round 9: You: 2 vs. Computer: 2
> *p
Invalid input!
> p
Computer: R
You won!

Results: You: 3 vs. Computer: 2
Congratulations! You won!
```

---

## Testen

In diesem Fall stehen keine automatischen Tests bereit. Für die Eingabefunktion gibt es bereits Tests, die restliche Logik ist leicht überprüfbar, in dem eine paar Runden gespielt werden.
