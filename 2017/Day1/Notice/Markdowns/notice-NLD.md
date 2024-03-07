IOI 2017 Translation

    NLD
# Notice

Elke opdracht heeft een bijlage die beschikbaar is in zowel CMS als op je eigen computer.

Voor "Output-only" opdrachten:
* De bijlage bevat invoer- en voorbeeldtests. Elke test  wordt gezien als een losse subtaak.
* Je mag meerdere uitvoerbestanden tegelijk inzenden in een zip-bestand. Voor deze mogelijkheid moeten je uitvoerbestanden `??.out` worden genoemd, waar `??` het nummer is van de test (bijvoorbeeld `03.out`). Je kan meerdere bestanden zippen door het volgende commando uit te voeren: `zip output.zip *.out`.
* Je mag maximaal 100 keer inzenden voor elke output-only taak. In elke inzending mag je voor elke subset van de testcases uitvoerbestanden insturen.

Voor alle andere opdrachten:
* De bijlage bevat een voorbeeldgrader, een voorbeeldimplementatie, de voorbeeldtests en compilatiescripts.
* Je moet precies een bestand inzenden en je mag maximaal 50 keer inzenden.
* De inzendingen mogen niet lezen van standard input, schrijven naar standard output of interacteren met een willekeurig ander bestand. Je mag echter uitvoer sturen naar standard error.
* De naam van het bestand dat je instuurt is gegeven in de kop van de opdrachtomschrijving. Het moet de functies implementeren die in de opdrachtbeschrijving worden beschreven, gegeven de signatuur zoals gegeven in de voorbeeldbestanden.
* Je bent vrij om andere functies te implementeren.
* Als je test met de voorbeeldgrader dan moet je programma zich exact houden aan het formaat en de voorwaarden uit de opdrachtomschrijving, anders kan deze ongedefinieerd gedrag vertonen.

## Conventies
De opdrachtbeschrijving kan de generieke namen  `bool`, `integer`, `int64`, and `int[]` (array) bevatten. 

Voor elk van de toegestane programmeertalen zijn de relevante datatypes en implementaties gegeven in de volgende tabel:

Programmeertaal | `bool` | `integer` | `int64` |  `int[]` | lengte van de array `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limieten
Taak | Tijdlimiet | Geheugenlimiet
--- | --- | ---
nowruz | Output-only | Output-only
wiring | 1 sec | 256 MB
train | 2 sec | 256 MB