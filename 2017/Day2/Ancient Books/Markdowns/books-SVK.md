
# Kopa starého papiera

V Teheráne je Iránska národná knižnica.  Najväčšia pýcha tejto knižnice sa
nachádza v dlhočiznej hale, v ktorej je dlhočizný rad $n$ stolov očíslovaných (zľava
doprava) od $0$ po $n-1$. Na každom stole je vystavená vzácna prastará kniha. Knihy sú momentálne zoradené podľa veku, čo však nie je najpraktickejšie, keďže väčšina návštevníkov hľadá knihy podľa názvu. Riaditeľ knižnice sa preto rozhodol, že nechá knihy usporiadať abecedne podľa názvu.

Denis pracuje v tejto knižnici ako knihovník. Keďže vo svojom životopise uviedol, že ovláda základné triediace algoritmy, riaditeľ pridelil túto úlohu práve jemu. Denis si vytvoril zoznam $p$ dĺžky $n$, obsahujúci všetky celé čísla od $0$ po $n-1$, každé práve raz. Tento zoznam popisuje zmeny potrebné na preusporiadanie kníh do abecedného poradia. Presnejšie,
pre každé $0 \leq i < n$, treba knihu, ktorá je momentálne na stole $i$, presunúť na stôl $p[i]$.

Denis začína pri stole číslo $s$. Keďže si tu nechal svoj batoh, chce pri tomto stole aj skončiť. Knihy sú veľmi vzácne, preto môže Denis niesť v jednom momente najviac jednu knihu.
Denisova práca teda bude vyzerať ako postupnosť akcií nasledovných typov:

* Ak práve nenesie žiadnu knihu a stojí pri stole s knihou, môže túto knihu zobrať.
* Ak nesie knihu a je pri stole s ďalšou knihou, môže vymeniť knihu, ktorú nesie, za knihu na stole.
* Ak nesie knihu a je pri prázdnom stole, môže túto knihu položiť na stôl.
* Môže sa presunúť ku ktorémukoľvek stolu. Počas presunu môže niesť najviac jednu knihu.

Pre každé $0 \leq i, j \leq n - 1$ je vzdialenosť medzi stolmi $i$ a $j$ presne $|j-i|$ metrov. Denis, súc špičkový lenivec, má vyvinutý výnimočný šiesty zmysel. Vďaka nemu celú prácu zaručene vykoná tak, aby sa čo najmenej nachodil. Zaujíma ho, akú vzdialenosť pri tom prejde (lebo chce vedieť, či sa mu oplatí obúvať si turistické topánky). Keďže jemu sa nechce, zistite mu to vy!

## Implementačné detaily

Implementujte nasledovnú funkciu:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ je pole dĺžky $n$.
Kniha, ktorá začína na stole $i$ má skončiť na stole $p[i]$ (pre všetky $0 \leq i < n$).
* $s$ je číslo stola, pri ktorom Denis začína a pri ktorom má aj skončiť.
* Funkcia má vrátiť minimálnu vzdialenosť (v metroch), ktorú musí Denis prejsť.

## Príklad

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

V tomto príklade $n=4$ a Denis začína pri stole $0$.
Knihy zoradí nasledovným spôsobom:
* Príde k stolu číslo $1$ a zoberie z neho knihu. Táto kniha patrí na stôl číslo $2$.
* Následne príde k stolu $2$ a vymení knihu, ktorú nesie, za knihu na stole. Kniha, ktorú práve zdvihol, patrí na stôl číslo $3$.
* Príde k stolu číslo $3$ a vymení túto knihu za knihu zo stola číslo $3$. Kniha, ktorú zobral, patrí na stôl číslo $1$.
* Ďalej príde k stolu $1$ a položí naň knihu, ktorú má v rukách. V tomto momente sú už všetky knihy na správnych miestach.
* Nakoniec sa ešte Denis musí vrátiť k stolu číslo $0$.

Všimnite si, že kniha na stole číslo $0$ je od začiatku na správnom mieste, takže tejto knihy sa Denis nepotrebuje ani dotknúť. Vzdialenosť, ktorú Denis prejde, je $6$ metrov. Toto riešenie je optimálne, funkcia má teda vrátiť číslo $6$.

## Obmedzenia

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* Pole $p$ obsahuje $n$ rôznych celých čísel z rozsahu $0$ až $n-1$ vrátane.

## Podúlohy

1. (12 bodov) $n \le 4$ a $s = 0$
1. (10 bodov) $n \le 1000$ a $s = 0$
1. (28 bodov) $s = 0$
1. (20 bodov) $n \le 1000$
1. (30 bodov) žiadne ďalšie obmedzenia

## Ukážkový grader

Ukážkový grader číta vstup v nasledujúcom formáte:

- riadok $1$: $\;\; n \;\; s$
- riadok $2$: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

Grader vypíše jediný riadok obsahujúci hodnotu vrátenú funkciou `minimum_walk`.
