# Opomba k implementaciji

Vsaka naloga ima priponko dostopno v CMS in na vašem namizju.

Za naloge "Zgolj-izhod":
* Priponka vsebuje vhodne testne primere in vzočni testni primer.
Vsak tesni primer je ločena podnaloga.
* Lahko oddate več izhodnih datotek kot zip datoteko. Za ta namen naj bodo izhodne datoteke poimenovane  `??.out`, kjer je `??` številka testnega primera (npr., `03.out`). Več datotek lahko shranite v zip datoteko z ukazom: `zip output.zip *.out`
* Lahko ustvarite do 100 oddaj za te naloge. V vsaki oddaji lahko oddate izhodne datoteke za poljubno podmnožico testnih primerov.

Za ostale naloge:
* Priponka vsebuje vzorčni ocenjevalnik, vzorčne implementacije, vzorčne testne primere in prevajalne skripte.
* Oddati moraš natanko eno datoteko in opraviš lahko do vključno 50 oddaj.
* Tvoje oddaje nesmejo brati s standarnega vhoda, pisati na standardni izhod ali komunicirati z drugimi datotekami.
Vseeno pa lahko oddaje uporabljajo standarni tok za napake.
* Ime datoteke katero oddajate je podana v glavi naloge.
Implementira naj funkcije opisane v nalogi, s podpisi podanimi v vzorčni implementaciji.
* Lahko implementiraš druge funkcije.
* Pri testiranju svojih programov z vzorčnim ocenjevalnikom, mora tvoj vhod slediti obliki in omejitvam podanih v nalogi, sicer lahko pride do nedoločenega vedenja.

## Dogovori

Naloge določajo podpise z uporabo generičnih tipov  `bool`, `integer`, `int64`, in `int[]` (polje).

V vsakem izmed podprtih programskih jezikov uporabljajo ocenjevalniki primerne podatkovne tipe ali implementacije, kot je navedeno spodaj:

Jezik | `bool` | `integer` | `int64` |  `int[]` | dolžina polja `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Omejitve

Naloga | Omejitev časa | Omejitev pomnilnika
--- | --- | ---
nowruz | Zgolj-izhod | Zgolj-izhod
wiring | 1 sekunda | 256 MB
train | 2 sekundi | 256 MB