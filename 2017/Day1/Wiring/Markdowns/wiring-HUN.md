# Vezetékek

Maryam huzalozást tervez egy kommunikációs tornyon.
A tornyon különböző magasságokban vannak piros és kék kapcsolási pontok.
Bármely két különböző színű kapcsolási pont összeköthető vezetékkel.
Egy kapcsolási ponthoz akarhány vezetéket lehet kötni, de legalább egyet kell.
A kapcsolási pontok egy vízszintes egyenes mentén, egész koordinátájú pontokon vannak.
A két pontot összekötő vezeték hossza a két pont távolsága.
Írj programot, amely kiszámítja a feltételt kielégítő huzalozásban a vezeték hosszak összegének minimumát!

## Megvalósítás

Az alábbi függvényt kell megírnod:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: a piros pontok pozícióit növekvő sorrendben tartalmazó $n$ elemű tömb.
* $b$: a kék pontok pozícióit növekvő sorrendben tartalmazó $m$ elemű tömb.
* A fügvény a feltételt kielégítő huzalozásban a vezeték hosszak összegének minimumát adja eredményül!
* A függvényérték `int64` típusú legyen!

## Példa

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Az ábrán ez a példa látható.
![Wiring](wiring.png)

* A torony vízszintesen látható.
* Fekete-fehér verzióban a piros pontok sötétek, a kékek pedig világosak.
* Itt $4$ piros kapcsolási pont van, az $1, 2, 3,$ és $7$ pozícióban.
* $5$ kék pont van, a $0, 4, 5, 9,$ és $10$ pozícióban.
* Egy lehetséges optimális megoldást mutat az ábra.
* Ebben a megoldásban a vezetékek összhossza $1 + 2 + 2 + 2 + 3 = 10$, ami optimális.
Tehát a helyes függvényérték $10$.
* Megjegyezzük, hogy a $7$ pozícióban levő ponthoz két vezeték is csatlakozik.

## Korlátok

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (minden $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (minden $0 \leq i \leq m-1$),
* Minden $r$ és $b$ tömb növekvő sorrendű.
* Az $n+m$ érték az $r$ és a $b$ tömbben különböző.

## Részfeladatok

1. (7 pont) $n, m \leq 200$,
1. (13 pont) Az összes piros pont kisebb pozíción van az összes kék pontnál.
1. (10 pont) Bármely $7$ egymást követő pont között van legalább egy piros és legalább egy kék.
1. (25 pont) A pontok pozíciója az $[1, n+m]$ tartományba esik.
1. (45 pont) Nincs további korlátozás.

## Minta értékelő

A bemenete az alábbi formátumú:
* Az $1$. sor: $\;\; n \;\; m$
* A $2$. sor: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* A $3$. sor: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

A `min_total_length` függvény értékét írja ki egyetlen sorba.