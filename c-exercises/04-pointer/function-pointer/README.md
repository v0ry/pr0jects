# Funktionspointer

In diesem Übungsbeispiel soll der Umgang mit einem Funktionspointer veranschaulicht werden. Als Vorausetzung muss das Beispiel "Abgesicherte Eingabe von einzelnen Zeichen" zuerst absolviert worden sein, da dieses an der Stelle nun verbessert wird.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Funktionen
  - Ein- und Ausgabe (Übungsbeispiel "Abgesicherte Eingabe von einzelnen Zeichen" erforderlich)
  - (Funktions)pointer

Lines of Code der Musterlösung: 114 inkl. Main-Funktion und bereits vorhandener Implementierung

---

## Anleitung

In diesem Beispiel soll nun die Funktion `safeInput` aus einem vorangegangenen Übungsbeispiel verbessert werden, damit diese flexibler einsetzbar ist. Am besten ist es, wenn ihr direkt eure eigene Implementierung dazu verwendet.

### Voraussetzungen

Die aktuelle Version eurer Funktion `safeInput` ist momentan speziell auf das Spiel Schere-Stein-Papier eingerichtet. Wenn die Funktion nun aber für eine andere Eingabe verwendet werden soll (möglicherweise sogar im selben Programm), müsste jedesmal die Funktion selbst auf die möglichen Eingaben angepasst werden (oder sogar öfters im Programm vorkommen). Um dies zu vermeiden, ist es notwendig der Funktion als Parameter alle erlaubten Eingaben mitzugeben. Dies könnte beispielsweise über ein Array umgesetzt werden. Eine besonders elegante Lösung bieten hier allerdings Funktionspointer.

### Anpassungen

Zu Beginn möchten wir zwei Funktion schreiben, die jeweils als Parameter ein Zeichen als Input bekommen und anschließend als Wahrheitswert zurückgeben, ob dieses Zeichen gültig war oder nicht. Eine Funktion können wir beispielsweise `charsRockPaperScissors` nennen, welche für die bereits bekannten Zeichen (`p`, `P`, `q`, `Q`, `r`, `R`, `s`, `S`) wahr zurückgibt. Die zweite Funktion könnten wir schon als Vorbereitung das Übungsbeispiel "Vier gewinnt" implementieren, in dem die Zeichen `1` bis `7` sowie `q` und `Q` gültig sind. Wichtig ist, dass beide Funktionen dieselbe Parameteranzahl, dieselben Parametertypen und denselben Rückgabetyp besitzen. 

Nun passen wir die Funktion `safeInput` an. Als Parameter soll die Funktion einen Funktionspointer übergeben bekommen. Dieser soll genau vom Typ der oben beschriebenen Funktionen sein. Damit können wir `safeInput` nun mitgeben, welche Inputs gültig sind. Anschließend muss noch die "hardcoded" Überprüfung in `safeInput` durch einen Aufruf der übergebenen Funktion ersetzt werden.

---

## Testen

Da die Hauptfunktionalität bereits in einem anderen Beispiel überprüft wurde, müssen nur mehr die Anpassungen selbstständig getestet werden. Daher stehen hier keine automatischen Tests bereit.
