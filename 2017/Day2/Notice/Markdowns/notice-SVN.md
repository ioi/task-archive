# Opomba k implementaciji

Vsaka naloga ima priponko dostopno v CMS in na vašem namizju.

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

Jezik | `bool` | `int` | `int64` |  `int[]` | dolžina polja `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Omejitve

Naloga | Omejitev časa | Omejitev pomnilnika
--- | --- | ---
prize | 1 sekunda | 1024 MB
simurgh | 3 sekunda | 1024 MB
books | 2 sekunda | 1024 MB

<div style="margin-top:-1em"></div>