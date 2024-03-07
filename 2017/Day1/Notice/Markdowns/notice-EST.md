# Teade

Igal ülesandel on manus, mis on nii CMSis kui ka sinu töölaual.

"Output-only" ülesannetel:
* Manuses on näidistestid ja päris testid.
Iga test on eraldi alamülesanne.
* Mitu vastust võib esitada korraga zip-failina. Selleks peaks väljundfailide nimed olema kujul `??.out`, kus `??` on testi number (nt `03.out`). Mitu faili saab kokku pakkida kasutades käsku: `zip output.zip *.out`
* Output-only ülesannete lahendusi võib esitada kuni 100 korda. Igal esitamisel võib esitada lahendusi suvalisele testide alamhulgale.

Teistel ülesannetel:
* Manuses on näidistesterid, näidislahendused, näidistestid ja kompileerimiseks vajalikud skriptid.
* Esitada tuleb täpselt üks fail, lahendust saab esitada kuni 50 korda.
* Lahendus ei tohi lugeda midagi standardsisendist, kirjutada midagi standardväljundisse ega suhelda ühegi muu failiga.
Standardveavoogu kirjutamine on lubatud.
* Esitatava faili nimi on antud ülesande kirjelduse päises.
Lahendus peab realiseerima tekstis kirjeldatud protseduurid, kasutades näidislahendustes toodud signatuure.
* Teiste protseduuride realiseerimine on lubatud.
* Näidistestriga testides peab sinu esitatud sisend sobima ülesande tekstis toodud formaadi ja piirangutega, vastasel korral võib juhtuda ettearvamatuid asju.

## Ülesannetes kasutatav notatsioon

Ülesannete tekstis kasutatakse "üldistatud" tüübinimedega signatuure: `bool`, `integer`, `int64`, `int[]` (massiiv).

Kõigis toetatud programmeerimiskeeltes kasutavad testrid õigeid andmetüüpe:

Keel | `bool` | `integer` | `int64` |  `int[]` | massiivi `a` pikkus
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Piirangud

Ülesanne | Ajapiirang | Mälupiirang
--- | --- | ---
nowruz | Output-only | Output-only
wiring | 1 sec | 256 MB
train | 2 sec | 256 MB