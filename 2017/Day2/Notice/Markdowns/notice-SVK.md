# Nieľad
Ku každej úlohe máte, v CMS aj na svojom počítači, k dispozícii balíček súborov.

* Priložený balíček obsahuje ukážkový grader, ukážkovú implementáciu, ukážkové vstupy a výstupy a kompilovacie skripty.
* Odovzdávajte práve jeden súbor. Môžete urobiť najviac 50 submitov.
* Vaše riešenia nesmú čítať zo štandardného vstupu (stdin), písať na štandardný výstup (stdout) ani interagovať s akýmkoľvek iným súborom. Môžete však vypisovať na štandardný chybový výstup (stderr).
* Meno súboru, ktorý máte odovzdať, je v hlavičke zadania danej úlohy. Súbor má implementovať funkcie popísané v zadaní používajúc signatúry z ukážkovej implementácie.
* Môžete implementovať aj ďalšie, pomocné, funkcie.
* Keď testujete svoje programy pomocou ukážkového gradera, váš vstup musí dodržiavať formát a obmedzenia zo zadania, inak sa môže grader správať nešpecifikovane (nesťažujte sa, ak vám z počítača začnú liezť zelené príšery).

## Konvencie

V zadaniach sú signatúry funkcií popísané pomocou generických typov  `bool`, `int`, `int64`, a `int[]` (pole).

V každom z podporovaných programovacích jazykov používa grader vhodné dátové typy a implementácie. Tie nájdete v nasledovnej tabuľke:

Language | `bool` | `int` | `int64` |  `int[]` | length of array `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limity

Úloha | Časový limit | Pamäťový limit
--- | --- | ---
prize | 1 s | 1024 MB
simurgh | 3 s | 1024 MB
books | 2 s | 1024 MB

<div style="margin-top:-1em"></div>