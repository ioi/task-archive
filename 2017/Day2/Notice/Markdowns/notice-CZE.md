# Poznámky k implementaci

Každá úloha má přiložený balíček, který je dostupný v CMS i na vašem počítači.

* Přiložený balíček obsahuje ukázkové vyhodnocovače, ukázkové implementace, příklady testovacích případů a kompilační skripty.
* Musíte odevzdat právě jeden soubor a máte až 50 pokusů na odevzdání.
* Vaše řešení nesmí nic číst ze standardního vstupu, ani nic vypisovat na standardní výstup nebo interagovat s jakýmkoli jiným souborem.
Do standardního chybového proudu však můžete zapisovat cokoliv.
* Název souboru, který máte odevzdat, je uveden v záhlaví zadání úlohy.
Soubor musí implementovat procedury popsané v zadání úlohy se signaturami dodanými v ukázkové implementaci.
* Můžete implementovat i jiné procedury.
* Při testování programu ukázkovým vyhodnocovačem musíte dodržet formát vstupu a omezení uvedená v zadání. V opačném případě není chování programu definované.

## Konvence

Zadání úloh popisují signatury pomocí obecných názvů typů `bool`, `int`, `int64` a `int[]` (pole).

V každém z podporovaných programovacích jazyků používají vyhodnocovače vhodné datové typy nebo implementace, jak je popsáno níže:

Jazyk | `bool` | `int` | `int64` |  `int[]` | délka pole `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limity

Úloha | Časový limit | Paměťový limit
--- | --- | ---
prize | 1 sekunda | 1024 MB
simurgh | 3 sekundy | 1024 MB
books | 2 sekundy | 1024 MB

<div style="margin-top:-1em"></div>