# Opmerkingen

Elke taak heeft een bijlage die zowel in CMS als op je bureaublad beschikbaar is.

Voor "Output-only" taken:
* De bijlage bevat de input testcases en voorbeeld testcases.
Elke testcase is een aparte subtaak.
* Je kan meerdere output bestanden indienen als een zip bestand. Hiervoor moeten je bestanden `??.out` heten waarbij `??` het nummer van de testcase is (bvb. `03.out`). Je kan meerdere bestanden met het volgende commando in een zip plaatsen: `zip output.zip *.out`
* Je mag tot 100 submissies uitvoeren voor output-only taken. In elke submissie mag je eender welke collectie van testcases indienen.

Voor andere taken:
* De bijlage bevat voorbeeldgraders, voorbeeld implementaties, voorbeeld testcases en compileer-scripts.
* Je moet exact één bestand indienen, en mag tot 50 submissies uitvoeren.
* Je programma mag niet van standard input lezen, naar standard output schrijven of interageren met enig ander bestand.
Je mag wel naar standard error schrijven.
* Je mag bijkomende functies implementeren.
* Bij het testen met de voorbeeldgrader moet je input aan het formaat en de beperkingen van de taakomschrijving voldoen, anders kan er onbepaald gedrag voorkomen.

## Conventies

De taakomschrijving specifieert functiesignaturen met de generische typenamen `bool`, `integer`, `int64` en `int[]` (array).

In elk van de ondersteunde programmeertalen gebruiken de graders het gepaste datatype of de gepaste implementatie, zoals hieronder opgelijst:

Taal | `bool` | `integer` | `int64` | `int[]` | lengte van array `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` | `int64` | `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` | `int[]` | `a.length`

## Limieten

Taak | Tijdslimiet | Geheugenlimiet
--- | --- | ---
nowruz | Output-only | Output-only
wiring | 1 sec | 256 MB
train | 2 sec | 256 MB