# Napomene 
Svaki zadatak ima priložen paket koji je dostupan u CMS-u i na vašoj radnoj površini.

Za "Output-only" zadatak:

* Priložen paket sadrži ulazne podatke i primere uz tekst zadatka. Svaki test primer je poseban podzadatak.
* Možete poslati više izlaznih fajlova odjednom kao .zip fajl. Kako biste to uradili, potrebno je vaše izlazne fajlove nazvati `??.out`, gde je `??` broj test primera (npr., `03.out`). Više fajlova možete upakovati u zip koristeći naredbu: `zip output.zip *.out`
* Output-only zadatke smete poslati najviše 100 puta. Prilikom svakog slanja možete poslati bilo koji podskup izlaznih fajlova.

Za sve ostale zadatke:
* Priložen paket sadrži primere grejdera, primere implementacija, primere test primera i skripte za kompajliranje.
* Treba da pošaljete tačno jedan fajl i smete slati najviše 50 puta.
* Vaša rešenja ne smeju čitati sa standardnog ulaza, niti smeju ispisivati na standardni izlaz. Takođe ne smeju ni na koji način pristupati drugim fajlovima. Uprkos tome, smete ispisivati na stderr.
* Ime datoteke koju treba poslati nalazi se u zaglavlju svakog zadatka. U tom fajlu implementirajte sve funkcije koje su opisane u zadatku koristeći definicije iz primera implementacije.
* Smete implementirati druge funkcije/procedure.
* Kad testirate vaše programe primerom grejdera potrebno je da su ulazni podaci validni (prema formatu ulaza iz teksta zadatka). U suprotnom može doći do nedefinisanog ponašanja grejdera.

## Konvencije

U tekstovima zadataka se koriste definicije funkcija sa generičkim tipovima podataka: `bool`, `integer`, `int64` i `int[]` (polje).

U svakom od podržanih programskih jezika grejderi koriste odgovarajuće tipove podataka kao što je prikazano u sledećoj tabeli:

Jezik | `bool` | `integer` | `int64` |  `int[]` | duljina niza `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Ograničenja

Zadatak | Vremensko ograničenje | Memorijsko ograničenje
--- | --- | ---
nowruz (Persivaldan) | Output-only | Output-only
wiring (Papuča) | 1 s | 256 MB
train (Železnice Avalona) | 2 s | 256 MB