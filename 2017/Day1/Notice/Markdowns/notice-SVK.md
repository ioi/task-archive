# Nieľad
Ku každej úlohe máte, v CMS aj na svojom počítači, k dispozícii balíček súborov.

Pre úlohy, v ktorých odovzdávate iba výstup, platí:
* Priložený balíček obsahuje ostré vstupy a ukážkové vstupy a výstupy.
Každý vstup je samostatná podúloha.
* Môžete odovzdať viacero výstupov v jednom zipe. V takom prípade sa výstupné súbory musia volať `??.out`, kde `??` je číslo príslušného vstupu (napr. `03.out`). Viacero súborov naraz môžete zazipovať pomocou príkazu `zip output.zip *.out`.
* Úlohy tohto typu môžete submitovať najviac 100-krát. V každom submite môžete odovzdať výstupy pre ľubovoľnú podmnožinu vstupov.

Pre ostatné úlohy platí:
* Priložený balíček obsahuje ukážkový grader, ukážkovú implementáciu, ukážkové vstupy a výstupy a kompilovacie skripty.
* Musíte odovzdať práve jeden súbor. Môžete urobiť najviac 50 submitov.
* Vaše riešenia nesmú čítať zo štandardného vstupu (stdin), písať na štandardný výstup (stdout) ani interagovať so žiadnym iným súborom. Môžete však vypisovať na štandardný chybový výstup (stderr).
* Meno súboru, ktorý máte odovzdať, je v hlavičke zadania danej úlohy. Súbor má implementovať funkcie popísané v zadaní používajúc signatúry z ukážkovej implementácie.
* Môžete implementovať aj ďalšie pomocné funkcie.
* Keď testujete svoje programy pomocou ukážkového gradera, váš vstup musí dodržiavať formát a obmedzenia zo zadania, inak sa môže grader správať nešpecifikovane (nesťažujte sa, ak vám z počítača začnú liezť zelené príšery).

## Konvencie

V zadaniach sú signatúry funkcií popísané pomocou generických typov  `bool`, `integer`, `int64`, a `int[]` (pole).

V každom z podporovaných programovacích jazykov používa grader vhodné dátové typy a implementácie. Tie nájdete v nasledovnej tabuľke:

Jazyk | `bool` | `integer` | `int64` |  `int[]` | dĺžka poľa `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limity

Úloha | Časový limit | Pamäťový limit
--- | --- | ---
nowruz | iba výstup | iba výstup
wiring | 1 s | 256 MB
train | 2 s | 256 MB
