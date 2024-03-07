# Vispārīga informācija


Katram uzdevumam ir pielikuma pakotne, kas ir pieejama gan CMS, gan uz darba virsmas.

* Pielikuma pakotne satur paraugtestētājus, paraugrealizāciju, paraugtestus un kompilācijas skriptus.
* Tev ir jāiesūta tieši viens fails. Tu drīksti veikt ne vairāk kā 50 iesūtījumus.
* Tavi iesūtījumi nedrīkst izmantot standarta ievadu un standarta izvadu vai mijiedarboties ar jebkuru citu failu. Tomēr tie drīkst izvadīt standarta kļūdu plūsmā.
* Iesūtāmā faila nosaukums ir norādīts uzdevuma apraksta galvenē. Tam jārealizē uzdevuma aprakstā minētās procedūras, lietojot paraugos dotās signatūras. 
* Tu drīksti realizēt arī citas procedūras.
* Testējot savas programmas ar paraugtestētāju, taviem ievaddatiem jāatbilst uzdevuma tekstā dotajam formātam un ierobežojumiem. Pretējā gadījumā programmas uzvedība nav definēta.

## Vienošanās

Uzdevumu tekstā dotās signatūras izmanto vispārīgus tipu vārdus  `bool`, `int`, `int64`, un `int[]` (masīvs).

Katrā atbalstītajā programmēšanas valodā vērtētāji lieto atbilstošus datu tipus vai implementācijas, kā norādīts zemāk:

Valoda | `bool` | `int` | `int64` |  `int[]` | Masīva `a` garums
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Ierobežojumi

Uzdevums | Laika ierobežojums | Atmiņas ierobežojums
--- | --- | ---
prize | 1 s | 1024 MB
simurgh | 3 s | 1024 MB
books | 2 s | 1024 MB

<div style="margin-top:-1em"></div>