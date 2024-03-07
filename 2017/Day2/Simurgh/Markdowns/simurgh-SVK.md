# Kapitán sa ponáhľa
"Okamžite sa potrebujem dostať na letisko, inak tú vojenskú prehliadku nestihnem!" zrúkol Kapitán Absurdistanu.

"Pane, ale lietanie je príliš drahé. Musíte použiť auto." oponoval mu nesmelo jeho Podriadený.

"Toľká drzosť! Ale dobre teda, ak pôjdeme iba po diaľniciach, tak sa to ešte stihne. Naplánujte cestu, o 3 sekundy vyrážame."

V Absurdistane je $n$ miest, ktoré sú očíslované od $0$ po $n-1$. Medzi týmito mestami vedie $m$ obojsmerných ciest, ktoré sú očíslované od $0$ po $m-1$. Každá takáto cesta spája dve rôzne mestá a žiadna dvojica miest nie je spojená viac ako jednou cestou. Niektoré z týchto ciest sú diaľnice. Podriadený však nevie, ktoré z nich to sú. Ak teda chce naplánovať Kapitánovu púť, bude to musieť najskôr zistiť.

Množinu ciest nazveme *rýchlostná*, ak obsahuje **práve** $n-1$ ciest a platí, že pre každú dvojicu miest existuje postupnosť ciest z tejto množiny, ktorá dané mestá spája. Podriadený vie, že množina diaľníc v Absurdistane je rýchlostná. Naviac má k dispozícii Kataster Stavebných Prác (KSP), ktorého sa môže pýtať otázky špeciálneho tvaru. Tie fungujú nasledovne: 

* Podriadený vyberie rýchlostnú množinu ciest.
* Následne mu KSP povie, koľko ciest z tejto rýchlostnej množiny sú diaľnice.

Pomôžte Podriadenému nájsť všetky diaľnice v Absurdistane, pričom sa KSP spýta najviac $q$ otázok.

## Implementačné detaily

Implementujte nasledovnú funkciu:

```
int[] find_roads(int n, int[] u, int[] v)
```

* $n$: počet miest Absurdistanu
* $u$ a $v$: polia dĺžky $m$. Pre všetky $0 \leq i \leq m-1$ sú hodnoty $u[i]$ a $v[i]$ čísla miest spojených cestou $i$.
* Táto funkcia má vrátiť pole dĺžky $n-1$, ktoré obsahuje čísla ciest (v ľubovoľnom poradí), ktoré sú diaľnicami.

Vaše riešenie môže najviac $q$ krát zavolať nasledujúcu funkciu testovača:

```
int count_common_roads(int[] r)
```

* $r$: pole dĺžky $n-1$ obsahujúce čísla $n-1$ ciest, ktoré tvoria rýchlostnú množinu.
* Táto funkcia vracia počet diaľníc medzi cestami danými poľom $r$.

## Príklad

```
find_roads(4, [0, 0, 0, 1, 1, 2], [1, 2, 3, 2, 3, 3])
```

![Simurgh](simurgh.png)

V tomto príklade máme $4$ mestá a $6$ ciest, ktoré ich spájajú. Počet diaľníc v Absurdistane je teda $n-1 = 3$. Cestu medzi mestami $a$ a $b$ označme $(a,b)$. Cesty Absurdistanu sú očíslované od $0$ po $5$ v nasledovnom poradí: $(0, 1)$, $(0, 2)$, $(0, 3)$, $(1, 2)$, $(1, 3)$, a $(2, 3)$.

Predpokladajme, že diaľnice sú cesty $0$, $1$ a $5$, teda cesty $(0,1)$, $(0,2)$ a $(2,3)$. Potom:
* `count_common_roads([0, 1, 2])` vráti hodnotu $2$. V tejto otázke sa pýtame na cesty číslo $0, 1$, a $2$, teda cesty $(0, 1)$, $(0, 2)$ a $(0,3)$. Dve z týchto ciest (0 a 1) sú diaľnice.
* `count_common_roads([5, 1, 0])` vráti hodnotu $3$. V tejto otázke sa pýtame na všetky diaľnice v Absurdistane.

Funkcia `find_roads` by teda mala vrátiť pole `[5, 1, 0]`, poprípade akúkoľvek inú permutáciu týchto troch čísel.

Všimnite si, že nasledovné volania funkcie `count_common_roads` nie sú povolené:
* `count_common_roads([0, 1])`: pole $r$ nemá dĺžku $3$.
* `count_common_roads([0, 1, 3])`: cesty v poli $r$ netvoria rýchlostnú množinu. Presnejšie, je nemožné prejsť z mesta $0$ do mesta $3$ iba s použitím ciest $(0,1)$, $(0,2)$ a $(1,2)$.

## Obmedzenia

* $2 \leq n\leq 500$
* $n - 1 \leq m \leq n (n-1) / 2$
* $0 \leq u[i], v[i] \leq n-1$ (pre všetky $0 \leq i \leq m-1$)
* Pre všetky $0 \leq i \leq m-1$, cesta $i$ spája dve rôzne mestá, teda $u[i] \neq v[i]$.
* Medzi každou dvojicou miest vedie najviac jedna priama cesta.
* Je možné dostať sa z každého mesta do každého iného.
*  Diaľnice tvoria rýchlostnú množinu.
* `find_roads` by mal zavolať funkciu `count_common_roads` najviac $q$ krát.
* Pri každom volaní funkcie `count_common_roads` musí byť množina ciest definovaná poľom $r$ rýchlostná.

## Podúlohy

1. (13 bodov) $n \leq 7$, $q = 30\,000$
1. (17 bodov) $n \leq 50$, $q = 30\,000$
1. (21 bodov) $n \leq 240$, $q = 30\,000$
1. (19 bodov) $q = 12\,000$ a medzi každou dvojicou miest vedie cesta.
1. (30 bodov) $q = 8000$

## Ukážkový grader

Ukážkový grader načítava vstup v nasledujúcom formáte:
* riadok $1$: $\;\; n \;\; m$
* riadok $2 + i$ (pre všetky $0 \leq i \leq m-1$): $\;\; u[i] \;\; v[i]$
* riadok $2 + m$: $\;\; s[0] \;\; s[1] \; \ldots\; s[n-2]$

Pričom $s[0], s[1], \ldots, s[n-2]$ sú čísla diaľníc.

Ukážkový testovač vypíše `YES` ak `find_roads` zavolá funkciu `count_common_roads` najviac $30\,000$ krát a vráti správnu množinu diaľníc. V opačnom prípade vypíše `NO`.

Dajte si pozor na to, že `count_common_roads` v ukážkovom testovači nekontroluje, či majú cesty v poli $r$ všetky požadované vlastnosti. Iba spočíta a vráti počet diaľníc spomedzi ciest v $r$.

Ak však váš program, ktorý odovzdáte, zavolá funkciu `count_common_roads` s množinou ciest, ktorá nespĺňa požadované podmienky, ostrý testovač vráti výstup 'Wrong Answer'.

## Technická poznámka

Funkcia `count_common_roads` in C++ a Pascal používa kvôli efektivite *volanie referenciou*. Stále však môžete funkciu použiť obvyklým spôsobom. Testovač hodnotu poľa $r$ meniť **nebude**.