# Notice

Elke opdracht heeft een bijlage die beschikbaar is in zowel CMS als op je eigen computer.

* De bijlage bevat een voorbeeldgrader, een voorbeeldimplementatie, de voorbeeldtests en
compilatiescripts.
* Je moet precies een bestand inzenden, en je mag maximaal 50 inzendingen doen.
* Je inzending mag niet van standard input lezen, mag niet naar standard output schrijven en ook niet met andere bestanden interacteren. Je mag wel uitvoer schrijven naar standard error.
* De naam van het bestand dat je moet insturen is gegeven in de kopregel van de opdracht. Je moet de procedures implementeren die in de opdrachtomschrijving staan, conform de signaturen die in de voorbeeld implementatie staan.
* Je mag ook andere functies implementeren.
* Als je test met de voorbeeldgrader dan moet je programma zich exact houden aan het formaat en de voorwaarden uit de opdrachtomschrijving, anders kan deze ongedefinieerd gedrag vertonen.

## Conventions

De opdrachtbeschrijving kan de generieke namen `bool`, `integer`, `int64`, and `int[]` (array) bevatten.

Voor elk van de toegestane programmeertalen zijn de relevante datatypes en implementaties gegeven in de volgende tabel:

Language | `bool` | `int` | `int64` |  `int[]` | length van array `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limits

Opdracht | Tijdslimit | Geheugenlimit
--- | --- | ---
prize | 1 sec | 1024 MB
simurgh | 3 sec | 1024 MB
books | 2 sec | 1024 MB

<div style="margin-top:-1em"></div>