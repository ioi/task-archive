# Hinweise

Jede Aufgabe hat ein Attachment-Paket, das sowohl im CMS als auch auf deinem Computer vorhanden ist.

* Das Attachment-Paket enthält Beispiel-Grader, Beispiel-Implementationen, Beispiel-Testfälle und Compile-Scripts.
* Du musst genau eine Datei einsenden und du darfst bis zu 50 Einsendungen machen.
* Dein Programm darf nicht vom Standard-Input lesen, nicht zum Standard-Output schreiben und auf keine anderen Dateien zugreifen. Es darf aber auf Standard-Error schreiben.
* Der Name der Datei, die du einsenden sollst, steht in der Kopfzeile der Aufgabenstellung. Sie sollte die Funktionen, die in der Aufgabenstellung beschrieben sind, mit den in den Beispiel-Implementationen angegebenen Signaturen implementieren.
* Du darfst auch andere Funktionen implementieren.
* Beim Testen mit dem Beispiel-Grader sollte deine Eingabe dem Format und den Beschränkungen aus der Aufgabenstellung entsprechen, sonst könnte unspezifiziertes Verhalten auftreten.

## Konventionen

Die Aufgabenstellungen geben die Signaturen mit generischen Datentypnamen `bool`, `integer`, `int64` und `int[]` (Array) an.

In jeder der unterstützten Programmiersprachen verwenden die Grader passende Datentypen, wie unten angegeben:

Sprache | `bool` | `integer` | `int64` |  `int[]` | Länge des Arrays `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limits
Aufgabe | Zeitlimit | Speicherlimit
--- | --- | ---
prize | 1 sec | 1024 MB
simurgh | 3 sec | 1024 MB
books | 2 sec | 1024 MB
