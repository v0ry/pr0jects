# Objekt als Funktionsparameter

Dieses Beispiel ist unbewertet. Wenn du es löst, bekommst du keine zusätzlichen Punkte für die KU, aber du kannst ein tieferes Verständnis der behandelten Themen erlangen und dein Wissen festigen.

## Lernziele

Ziel dieses Übungsbeispiels ist es, Access Specifier einzusetzen.

## Das Problem

Die Datei `pets.cpp` entspricht der [Lösung der vorherigen Aufgabe](Semester%2002/OOP1/pr0jects/cpp-exercises/week_2/pets_4_object_as_parameter/solution.cpp). Der Code in `pets.cpp` besteht den Test Case bereits aber er bedarf dennoch einer Überarbeitung. Alle Member Variablen der Klasse `Pet` sind von außen zugänglich und die Funktion `happy_birthday` macht von der Möglichkeit Gebrauch, auf das Attribut `age_` zuzugreifen. Wir haben in der VO jedoch gehört, dass es eine gute Praxis ist, Membervariablen von außerhalb der Klasse nicht direkt zugänglich zu machen.

## Deine Aufgabe
### Access Specifier
Mache die Attribute der `Pet`-Klasse `private`. Alle Methoden sollen weiterhin `public` sein. Welche Änderungen an der Klasse werden durch die privaten Attribute noch notwendig?

### Funktion in Methode umwandeln
Dadurch kann die Funktion `happy_birthday` nicht mehr auf die Membervariable `age_` zugreifen. Dieses Problem könntest du umgehen, indem du für `age_` einen Getter und einen Setter implementierst. In diesem Übungsbeispiel sollst du einen anderen Lösungsansatz wählen: Da `happy_birthday` das Verhalten eines Haustiers repräsentiert (in diesem Fall das Altern), sollte diese Funktion Teil der `Pet`-Klasse sein. Wandle daher `happy_birthday` in eine Methode um. Dadurch erhält sie auch Zugriff auf private Membervariablen.

Derzeit gibt `happy_birthday` den Text

```
Happy birthday! This pet is <AGE> years old now.\n
```

aus, wobei `<AGE>` durch den neuen Wert des `age_`-Attributs ersetzt wird. Da Methoden das Verhalten eines Objekts widerspiegeln, sollte der Text zu

```
Happy birthday to me :D I am now <AGE> years old.\n
```

geändert werden. Auch in dieser Ausgabe ist `<AGE>` durch den neuen Wert des `age_`-Attributs zu ersetzen.

### Änderungen in `main`
Schreibe danach die `main`-Funktion so um, dass statt der alten `happy_birthday`-Funktion die neue `happy_birthday`-Methode aufgerufen wird.


## Lösung

Ändere die Datei `pets.cpp`, um die oben beschriebene Aufgabe zu lösen. Du kannst deine Lösung jederzeit testen, indem du in diesem Verzeichnis `make test` aufrufst. Dadurch wird eine Datei namens `testreport.html` erstellt. Sie enthält einen Bericht, der dir zeigt, welche Ausgabe dein Programm produzieren sollte und welche Ausgabe dein Programm produziert. Du erhältst auf diese Weise sofortiges Feedback zu deiner überarbeiteten `pets.cpp`-Datei.

Solltest du Probleme haben, das Übungsbeispiel zu lösen, so kannst du dir eine mögliche Lösung in `solution.cpp` ansehen. Bedenke jedoch, dass du den größtmöglichen Lerneffekt nur dann erzielst, wenn du wirklich versuchst, das Übungsbeispiel selbst zu lösen.

## Mitwirkende an diesem Übungsbeispiel
Aleksandar Karakaš

