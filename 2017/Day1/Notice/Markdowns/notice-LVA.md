# Vispārīga informācija


Katram uzdevumam ir pielikuma pakotne, kas ir pieejama gan CMS, gan uz darba virsmas.

"Tikai izvaddatu" uzdevumiem:
* Pielikuma pakotne satur ievaddatu testus un piemēru testus. Katrs tests ir atsevišķs apakšuzdevums.
* Tu vai iesūtīt vairākus izvaddatu failus vienā zip failā. Šajā gadījumā izvaddatu failu nosaukumiem jābūt `??.out`, kur `??` ir testa  numurs (piem., `03.out`). Vairākus failus var saarhivēt, izmantojot komandu `zip output.zip *.out`
* "Tikai izvaddatu" uzdevumiem drīkst veikt ne vairāk kā 100 iesūtījumus. Katrā iesūtījumā drīkst ietvert jebkuras testu apakškopas izvaddatu failus.

Citiem uzdevumiem:
* Pielikuma pakotne satur paraugtestētājus, paraugrealizāciju, paraugtestus un kompilācijas skriptus.
* Tev ir jāiesūta tieši viens fails. Tu drīksti veikt ne vairāk kā 50 iesūtījumus.
* Tavi iesūtījumi nedrīkst izmantot standarta ievadu un standarta izvadu vai mijiedarboties ar jebkuru citu failu. Tomēr tie drīkst izvadīt standarta kļūdu plūsmā.
* Iesūtāmā faila nosaukums ir norādīts uzdevuma apraksta galvenē. Tam jārealizē uzdevuma aprakstā minētās procedūras, lietojot paraugos dotās signatūras. 
* Tu drīksti realizēt arī citas procedūras.
* Testējot savas programmas ar paraugtestētāju, taviem ievaddatiem jāatbilst uzdevuma tekstā dotajam formātam un ierobežojumiem. Pretējā gadījumā programmas uzvedība nav definēta.

## Vienošanās

Uzdevumu tekstā dotās signatūras izmanto vispārīgus tipu vārdus  `bool`, `integer`, `int64`, un `int[]` (masīvs).

Katrā atbalstītajā programmēšanas valodā vērtētāji lieto atbilstošus datu tipus vai implementācijas, kā norādīts zemāk:

Valoda | `bool` | `integer` | `int64` |  `int[]` | Masīva garums `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Ierobežojumi

Uzdevums | Laika limits | Atmiņas limits
--- | --- | ---
nowruz | Tikai izvaddati | Tikai izvaddati
wiring | 1 sec | 256 MB
train | 2 sec | 256 MB
