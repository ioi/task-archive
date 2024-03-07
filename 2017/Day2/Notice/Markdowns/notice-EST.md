# Teade

Igal ülesandel on manus, mis on nii CMSis kui ka sinu töölaual.

* Manuses on näidistesterid, näidislahendused, näidistestid ja kompileerimiseks vajalikud skriptid.
* Esitada tuleb täpselt üks fail, lahendust saab esitada kuni 50 korda.
* Lahendus ei tohi lugeda midagi standardsisendist, kirjutada midagi standardväljundisse ega suhelda ühegi muu failiga.
Standardveavoogu kirjutamine on lubatud.
* Esitatava faili nimi on antud ülesande kirjelduse päises.
Lahendus peab realiseerima tekstis kirjeldatud protseduurid, kasutades näidislahendustes toodud signatuure.
* Teiste protseduuride realiseerimine on lubatud.
* Näidistestriga testides peab sinu esitataesitatud sisend sobima ülesande tekstis toodud formaadileformaadi ja piirangutelepiirangutega, vastasel korral võib juhtuda ettearvamatuid asju.

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
prize | 1 sek | 1024 MB
simurgh | 3 sek | 1024 MB
books | 2 sek | 1024 MB

<div style="margin-top:-1em"></div>