# Vorlesungsverwaltung von Studenten

In diesem Beispiel soll das Arbeiten mit Arrays und Pointer geübt werden. Lernziel ist es zu verstehen, dass für diese Art der Anwendung Pointer notwendig sind.

---

## Lernziele

Folgende Inhalte werden bei der Umsetzung benötigt:
  - Datentypen, Operatoren
  - Verzweigungen, Schleifen, Funktionen
  - Arrays
  - Pointer

Lines of Code der Musterlösung: 150 inkl. Main-Funktion (Framework 100 Zeilen)

---

## Anleitung

Es soll ein einfaches Verwaltungsprogramm erweitert werden, indem Studenten zu Vorlesungen zugewiesen werden. Ein Student hat eine `studentID` (Matrikelnummer) und kann mit dieser mehrere Vorlesungen besuchen. Um das Beispiel einfach zu halten sind 2 Vorlesungen vorgegeben: `ESP` und `Analysis`.  Im Programm soll es möglich sein

- Studenten zu Vorlesungen hinzuzufügen,
- alle Studenten sowie alle aktuellen Anmeldungen für beide Vorlesungen auszugeben,
- die `studentID` eines Studenten zu ändern und
- das Programm zu beenden

Zu Beginn haben beide Vorlesungen keine Studenten inkludiert, diese soll im Programmverlauf hinzugefügt werden können. 

**Wichtig:** Wurde ein Student zu einer Vorlesung hinzugefügt und es ändert sich danach seine `studentID`, so soll diese automatisch bei allen angemeldeten Vorlesungen geändert aufscheinen. Das bedeutet es soll eine Referenz auf die `studentID` bei den Vorlesungen gespeichert werden, nicht die `studentID` selbst. 



### Framework

Im Framework enthalten sind bereits Teile der `main`-Funktion sowie die Ausgabefunktionen. Die Variablen `esp_students` und `analysis_students` sind  Arrays aus Integer-Pointer mit einer Größe von 6. In diesen Arrays sollen die Referenzen zu den Matrikelnummern der Studenten gespeichert werden, die diese Vorlesung besuchen. Die eigentlichen Matrikelnummern liegen nur in der bereits vorgegebenen Variable `students` (ein Array aus Integers - den Matrikelnummern) 



### Programmablauf

Nach Programmstart soll zunächst mittels Aufruf der bereits vorhandenen Funktion `printMenuAndGetSelection()` das Menü ausgegeben werden. Diese  Funktion gibt die eingegebene Zahl des Benutzers zurück und muss nur noch aufgerufen werden. Für die Ausgabe der `StudentID`'s ist auch bereits die Funktion `printStudents()` gegeben, welche noch aufgerufen werden. 

Nach beenden eines Befehls soll erneut dass Menü erscheinen. Dies geschieht solange bis der Benutzer 0 (=Quit) eingibt, dann soll das Programm mit dem Rückgabewert 0 beenden. 

Selbst zu implementieren ist das Hinzufügen von Studenten zu Vorlesungen und das Ändern von `StudentID`'s.

#### Hinzufügen eines Studenten

Für das Hinzufügen eines Studenten gibt es auch bereits 2 Hilfsfunktionen `getStudendId()` und `getLectureId()` welche die Eingaben des Benutzers zurückgeben. 

Zuerst soll die Ausgabe `Select the Student by the ID (not the studentID itself): ` ausgegeben werden, welche von der Funktion `getStudendId()` bereits vorgegeben ist. Diese Funktion gibt auch die Eingabe des Benutzers zurück.

Danach soll die Ausgabe `Select Lecture: ESP == 1, Analysis == 2: ` ausgegeben werden, welche von der Funktion `getLectureId()` bereits vorgegeben ist. Diese Funktion gibt wieder die Eingabe des Benutzers zurück. 

Mithilfe dieser Daten soll nun der Student zu einer Vorlesung **als Referenz** hinzugefügt werden. 

Ist ein Student bereits für eine Vorlesung angemeldet und wird er erneut hinzugefügt, so soll stattessen die Meldung `Student already in this lecture\n` ausgegeben werden. Gibt es keinen Platz mehr in einer Vorlesung soll die Meldung `lecture full\n` ausgegeben werden. Nach diesen Meldungen erscheint wieder das Menü. 

#### Ändern eines Studenten

Wurde Option 3 (Ändern eines Studenten) ausgewählt, soll zunächst die Stelle des Studenten in der Liste aller Studenten ausgewählt werden können (nicht die `StudentID`, sondern 0 oder 1 oder 2, ....)

Dann soll dieser Student geändert werden können. Zuerst soll die Ausgabe `Enter new student ID of Student Nr %d: ` erfolgen, wobei in `%d` die zuvor gewählte Stelle des Studenten einzusetzen ist. Danach kann vom User eine neue `StudentID` eingegeben werden. Diese soll dann **NUR** im Array `students` geändert werden. Da die anderen beiden Vorlesungs-Arrays Referenzen auf die `StudentID` haben, werden diese automatisch auch aktualisiert. 



## Beispielausgaben

#### Beispiel 1

```
----- MAIN MENU -----
:: 0 Quit
:: 1 Print StudentIDs
:: 2 Add StudentID to lecture
:: 3 change StudentID
> 1
All Students: 0: 999999999     1: 4444444     2: 7777777     3: 65455654     4: 11111111     5: 23232323     
---------------------------------------------------------------------------------------------------------
ESP Students: 
---------------------------------------------------------------------------------------------------------
Analysis Students: 
---------------------------------------------------------------------------------------------------------
----- MAIN MENU -----
:: 0 Quit
:: 1 Print StudentIDs
:: 2 Add StudentID to lecture
:: 3 change StudentID
> 2
Select the Student by the ID (not the studentID itself): 0
Select Lecture: ESP == 1, Analysis == 2: 1
----- MAIN MENU -----
:: 0 Quit
:: 1 Print StudentIDs
:: 2 Add StudentID to lecture
:: 3 change StudentID
> 1
All Students: 0: 999999999     1: 4444444     2: 7777777     3: 65455654     4: 11111111     5: 23232323     
---------------------------------------------------------------------------------------------------------
ESP Students:  999999999     
---------------------------------------------------------------------------------------------------------
Analysis Students: 
---------------------------------------------------------------------------------------------------------
----- MAIN MENU -----
:: 0 Quit
:: 1 Print StudentIDs
:: 2 Add StudentID to lecture
:: 3 change StudentID
> 0
```

#### Beispiel 2

```
----- MAIN MENU -----
:: 0 Quit
:: 1 Print StudentIDs
:: 2 Add StudentID to lecture
:: 3 change StudentID
> 1
All Students: 0: 999999999     1: 4444444     2: 7777777     3: 65455654     4: 11111111     5: 23232323     
---------------------------------------------------------------------------------------------------------
ESP Students: 
---------------------------------------------------------------------------------------------------------
Analysis Students: 
---------------------------------------------------------------------------------------------------------
----- MAIN MENU -----
:: 0 Quit
:: 1 Print StudentIDs
:: 2 Add StudentID to lecture
:: 3 change StudentID
> 2
Select the Student by the ID (not the studentID itself): 1
Select Lecture: ESP == 1, Analysis == 2: 2
----- MAIN MENU -----
:: 0 Quit
:: 1 Print StudentIDs
:: 2 Add StudentID to lecture
:: 3 change StudentID
> 2
Select the Student by the ID (not the studentID itself): 1
Select Lecture: ESP == 1, Analysis == 2: 1
----- MAIN MENU -----
:: 0 Quit
:: 1 Print StudentIDs
:: 2 Add StudentID to lecture
:: 3 change StudentID
> 1
All Students: 0: 999999999     1: 4444444     2: 7777777     3: 65455654     4: 11111111     5: 23232323     
---------------------------------------------------------------------------------------------------------
ESP Students:  4444444     
---------------------------------------------------------------------------------------------------------
Analysis Students:  4444444     
---------------------------------------------------------------------------------------------------------
----- MAIN MENU -----
:: 0 Quit
:: 1 Print StudentIDs
:: 2 Add StudentID to lecture
:: 3 change StudentID
> 3
Select the Student by the ID (not the studentID itself): 1
Enter new student ID of Student Nr 1: 55555555
----- MAIN MENU -----
:: 0 Quit
:: 1 Print StudentIDs
:: 2 Add StudentID to lecture
:: 3 change StudentID
> 1
All Students: 0: 999999999     1: 55555555     2: 7777777     3: 65455654     4: 11111111     5: 23232323     
---------------------------------------------------------------------------------------------------------
ESP Students:  55555555     
---------------------------------------------------------------------------------------------------------
Analysis Students:  55555555     
---------------------------------------------------------------------------------------------------------
----- MAIN MENU -----
:: 0 Quit
:: 1 Print StudentIDs
:: 2 Add StudentID to lecture
:: 3 change StudentID
> 0
```



---

## Testen

Bei diesem Beispiel gibt es wieder automatische Tests, die mit `make test` gestartet werden können. 
