# Notice

Svaki zadatak ima paket privitak koji je dostupan i u CMS-u i na tvojem računalu.


* Paket privitak sadrži sempl grejdere, sempl implementejšne, lutke test primjere, i skripte za kompajliranje.
* Trebaš podčiniti točno jedan fajl i smiješ napraviti najviše 50 podčinjenja.
* Tvoja podčinjenja ne smiju čitati sa standardnog ulaza, pisati na standardni izlaz, niti drkati po ikojem drugom fajlu. 
* Međutim, smiju ispisivati na stderr.
* Ime fajla koji trebaš podčiniti dan je u zaglavlju opisa zadatka. On treba implementirati funkciju opisanu u tekstu zadatka koristeći definicije dane u sempl implementejšnima.
* Smiješ implementirati druge funkcije.
* Kada testiraš svoj program koristeći sempl grejder, ulaz mora odgovarati formatu i ograničenjima danim u opisu zadatka. U protivnom, ni sam Teetough ne zna što će se desiti.

## Konvenšni

Opisi zadataka koriste degenerične tipove podataka `bool`, `int`, `int64`, i `int[]` (niz).

U svakom od podržanih jezika, grejderi koriste prikladne tipove podataka ili njihove implementacije, izlistane ispod:

Jezik | `bool` | `int` | `int64` |  `int[]` | duljina niza `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `niz longint-a` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Ograničenja

Zadatak | Tajm limit | Memori limit
--- | --- | ---
prize | 1 sec | 1024 MB
simurgh | 3 sec | 1024 MB
books | 2 sec | 1024 MB

<div style="margin-top:-1em"></div>