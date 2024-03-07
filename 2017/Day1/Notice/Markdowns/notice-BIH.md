# Notice 
Svaki zadatak ima prilog paket koji je dostupan u CMS-u i na vašoj radnoj površini.

Za "Output-only" taskove:

* Prilog paket sadrži ulazne podatke i primjere uz tekst zadatka. Svaki test podatak je posebni podzadatak.
* Možete poslati više izlaznih datoteka odjednom kao .zip datoteku. Kako biste to uradili, potrebno je vaše izlazne datoteke nazvati `??.out`, gdje je `??` broj test podatka (npr., `03.out`). Više datoteka možete zazipati koristeći naredbu: `zip output.zip *.out`
* Output only zadatke smijete submitati najviše 100 puta. U svakom submissionu smijete poslati bilo koji podskup izlaznih datoteka.

Za sve ostale taskove:
* Prilog paket sadrži sempl grejdere, sempl implementacije, primjere test podataka i compile skripte.
* Trebate submitati tačno jednu datoteku i smijete napraviti najviše 50 submissiona.
* Vaši submissioni ne smiju ništa čitati sa standardnog ulaza, niti smiju išta ispisivati na standardni izlaz. Također ne smiju ni na koji način komunicirati s drugim datotekama. Unatoč tome, smiju ispisivati stvari na stderr.
* Ime datoteke koju trebate submitati nalazi se u zaglavlju svakog pojedinog zadatka. U toj datoteci implementirajte sve funkcije koje su opisane u zadatku koristeći definicije iz sempl implementacija.
* Smijete implementirati druge funkcije/procedure.
* Kad testirate vaše programe sempl grejderom nužno je da su ulazi valjani (prema formatu ulaza iz teksta zadatka). U protivnom može doći do nedefiniranog ponašanja grejdera.

## Konvencije

Tekstovi zadataka specificiraju definicije funkcija sa degeneričkim tipovima podataka: `bool`, `integer`, `int64` i `int[]` (polje).

U svakom od podržanih programskih jezika grejderi koriste odgovarajuće tipove podataka kao što je prikazano u sljedećoj tablici:

Jezik | `bool` | `integer` | `int64` |  `int[]` | duljina niza `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Ograničenja

Zadatak | Vremensko ograničenje | Memorijsko ograničenje
--- | --- | ---
nowruz | Output-only | Output-only
wiring | 1 s | 256 MB
train | 2 s | 256 MB