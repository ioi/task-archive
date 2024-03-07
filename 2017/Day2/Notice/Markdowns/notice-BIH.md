# Napomene

Svaki zadatak ima priložen paket koji je dostupan u CMS-u i na vašoj radnoj površini.

* Priložen paket sadrži primjere grejdera, primjere implementacija, primjere test primjera i skripte za kompajliranje.
* Treba da pošaljete tačno jedan fajl i smijete slati najviše 50 puta.
* Vaša rješenja ne smiju čitati sa standardnog ulaza, niti smiju ispisivati na standardni izlaz. Takođe ne smiju ni na koji način pristupati drugim fajlovima. Uprkos tome, smijete ispisivati na stderr.
* Ime datoteke koju treba poslati nalazi se u zaglavlju svakog zadatka. U tom fajlu implementirajte sve funkcije koje su opisane u zadatku koristeći definicije iz primjera implementacije.
* Smijete implementirati druge funkcije/procedure.
* Kad testirate vaše programe primjerom grejdera potrebno je da su ulazni podaci validni (prema formatu ulaza iz teksta zadatka). U suprotnom može doći do nedefinisanog ponašanja grejdera.

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
prize | 1 sec | 1024 MB
simurgh | 3 sec | 1024 MB
books | 2 sec | 1024 MB

<div style="margin-top:-1em"></div>

