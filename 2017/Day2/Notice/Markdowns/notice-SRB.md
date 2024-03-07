# Napomene

Svaki zadatak ima priložen paket koji je dostupan u CMS-u i na vašoj radnoj površini.

* Priložen paket sadrži primere grejdera, primere implementacija, primere test primera i skripte za kompajliranje.
* Treba da pošaljete tačno jedan fajl i smete slati najviše 50 puta.
* Vaša rešenja ne smeju čitati sa standardnog ulaza, niti smeju ispisivati na standardni izlaz. Takođe ne smeju ni na koji način pristupati drugim fajlovima. Uprkos tome, smete ispisivati na stderr.
* Ime datoteke koju treba poslati nalazi se u zaglavlju svakog zadatka. U tom fajlu implementirajte sve funkcije koje su opisane u zadatku koristeći definicije iz primera implementacije.
* Smete implementirati druge funkcije/procedure.
* Kad testirate vaše programe primerom grejdera potrebno je da su ulazni podaci validni (prema formatu ulaza iz teksta zadatka). U suprotnom može doći do nedefinisanog ponašanja grejdera.

## Konvencije

U tekstovima zadataka se koriste definicije funkcija sa generičkim tipovima podataka: `bool`, `integer`, `int64` i `int[]` (polje).

U svakom od podržanih programskih jezika grejderi koriste odgovarajuće tipove podataka kao što je prikazano u sledećoj tabeli:

Language | `bool` | `int` | `int64` |  `int[]` | length of array `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Ograničenja

Zadatak | Vremensko ograničenje | Memorijsko ograničenje
--- | --- | ---
prize (Utešna nagrada) | 1 sec | 1024 MB
simurgh (Kanalizaciona mreža) | 3 sec | 1024 MB
books (Papučarenje) | 2 sec | 1024 MB