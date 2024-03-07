# Pastabos
Kievienas uždavinys turi prikabintą paketą, kurį rasite ir CMS, ir savo darbalaukyje.

* Prikabintame pakete yra pavyzdiniai vertintojai, pavyzdinės procedūros, pavyzdiniai testai ir kompiliavimo skriptai.
* Jūs turite pateikti lygiai vieną failą, ir galite pateikti iki 50 sprendimų.
* Jūsų sprendimai neturi skaityti iš standartinės įvesties, rašyti į standartinę išvestį ar dirbti su bet kokiu kitu failu. Išvedimas į standartinės klaidos srautą yra leidžiamas.
* Failo, kurį turite pateikti, pavadinimas pateiktas užduoties antraštėje. Jame turi būti pateiktos užduotyje nurodytos procedūros naudojant pavyzdinėse procedūrose pateiktus parametrus.
* Galite parašyti ir kitas procedūras.
* Testuojant jūsų programas su pavyzdiniu vertintoju, jūsų pradinių duomenų formatas turi atitikti užduotyje nurodytą formatą ir ribojimus, kitu atveju galimas neapribėžtas veikimas.

## Žymėjimai

Uždavinių sąlygose aprašyti procedūrų parametrai, naudojant apibendrintus duomenų tipų pavadinimus  `bool`, `integer`, `int64`, ir `int[]` (masyvai).

Kiekvienoje palaikomoje kalboje vertintojai naudoja atitinkamus duomenų tipus ar realizacijas, išvardintus žemiau:

Kalba | `bool` | `integer` | `int64` |  `int[]` | masyvo ilgis `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Ribojimai

Užduotis | Laiko limitai | Atminties limitai
--- | --- | ---
prize | 1 sek | 1024 MB
simurgh | 3 sek | 1024 MB
books | 2 sek | 1024 MB

<div style="margin-top:-1em"></div>