# Hinweise

Jeder Task hat ein Attachment-Paket, das sowohl im CMS als auch auf deinem Computer vorhanden ist.
Für "Output-Only"-Tasks gilt:
* Das Attachment-Paket enthält Input-Testfälle und Beispiel-Testfälle. Jeder Testfall ist ein eigener Subtask.
* Du darfst mehere Output-Dateien als `zip`-File einsenden. Dazu müssen die Output-Dateien `??.out` heissen, wobei `??` eine Testfallnummer ist (z.B. `03.out`). Du kannst mehrere Dateien mit dem folgenen Befehl zippen: `zip output.zip *.out`
* Du darst für Output-Only-Tasks bis zu 100 Einsendungen machen. In jeder Einsendung darfst du die Output-Dateien für eine beliebige Teilmenge der Testfälle einsenden.

Für andere Tasks:

* Das Attachment-Paket enthält Beispiel-Grader, Beispiel-Implementationen, Beispiel-Testfälle und Compile-Scripts.
* Du must genau eine Datei einsenden, und du darfst bis zu 50 Einsendungen machen.
* Dein Programm darf nicht vom Standard-Input lesen, nicht zum Standard-Output schreiben, und auf keine anderen Dateien zugreifen. Es darf aber auf den Standard-Error schreiben.
* Der Name der Datei, die du einsenden sollst, steht in der Kopfzeile der Aufgabenstellung. Sie sollte die Funktionen, die in der Aufgabenstellung beschrieben sind, mit den in den Beispielimplementationen angegebenen Signaturen implementieren.
* Du darfst auch andere Funktionen implementieren.
* Beim Testen mit dem Sample-Grader sollte dein Input dem Format und den Beschränkungen aus der Aufgabenstellung entsprechen, sonst könnte unspezifiziertes Verhalten auftreten.

## Konventionen

Die Aufgabenstellungen geben die Signaturen mit generischen Datentypnamen `bool`, `integer`, `int64` und `int[]` (Array) an.

In jeder der unterstützten Programmiersprachen verwenden die Grader passende Datentypen, wie unten angegeben:

Sprache | `bool` | `integer` | `int64` |  `int[]` | Länge des Arrays `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limits

Task | Zeitlimit | Speicherlimit
--- | --- | ---
nowruz | Output-only | Output-only
wiring | 1 sec | 256 MB
train | 2 sec | 256 MB
