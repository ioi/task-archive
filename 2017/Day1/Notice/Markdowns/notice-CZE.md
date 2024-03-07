# Poznámky k implementaci

Každá úloha má přiložený balíček, který je dostupný v CMS i na vašem počítači.

Pro úlohy typu "Output-only" (odevzdává se pouze výstup):
* Přiložený balíček obsahuje vstupní testovací případy a vzorové testovací případy.
Každý testovací případ je samostatná podúloha.
* Můžete odevzdat více výstupních souborů najednou v zip souboru. V tomto případě pojmenujte výstupní soubory `??.out`, kde `??` je číslo testovacího případu (např. `03.out`). Výstupní soubory můžete sloučit do zip souboru tímto příkazem: `zip output.zip *.out`
* Máte až 100 pokusů na odevzdání úlohy typu "Output-only". Při každém odevzdání můžete odevzdat výstupní soubory pro libovolnou podmnožinu testovacích případů.

Pro ostatní úlohy:
* Přiložený balíček obsahuje ukázkové vyhodnocovače, vzorové implementace, příklady testovacích případů a kompilační skripty.
* Musíte odevzdat právě jeden soubor a máte až 50 pokusů na odevzdání.
* Vaše řešení nesmí nic číst ze standardního vstupu, ani nic vypisovat na standardní výstup nebo interagovat s jakýmkoli jiným souborem.
Do standardního chybového proudu však můžete zapisovat cokoliv.
* Název souboru, který máte odevzdat, je uveden v záhlaví zadání úlohy.
Soubor musí implementovat procedury popsané v zadání úlohy se signaturami dodanými ve vzorové implementaci.
* Můžete implementovat i jiné procedury.
* Při testování programu ukázkovým vyhodnocovačem musíte dodržet formát vstupu a omezení uvedená v zadání. V opačném případě není chování programu definované.

## Konvence

Zadání úloh popisují signatury pomocí obecných názvů typů `bool`, `integer`, `int64` a `int[]` (pole).

V každém z podporovaných programovacích jazyků používají vyhodnocovače vhodné datové typy nebo implementace, jak je popsáno níže:

Jazyk | `bool` | `integer` | `int64` |  `int[]` | délka pole `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limity

Úloha | Časový limit | Paměťový limit
--- | --- | ---
nowruz | Output-only | Output-only
wiring | 1 sekunda | 256 MB
train | 2 sekunda | 256 MB
