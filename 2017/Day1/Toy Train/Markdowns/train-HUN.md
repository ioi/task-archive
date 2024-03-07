# Játékvasút

Arezuo és Borzou $n$ állomást és $m$ egyirányú vágányszakaszt tartalmazó vasútmodellt kaptak.
Minden vágányszakasz egy állomásról indul és vagy ugyanarra az állomásra, vagy egy másik állomásra vezet.
Minden állomásról indul legalább egy vágányszakasz.
Vannak töltőállomások, amelyen úgy lehet feltölteni a mozdonyt, hogy $n$ szakaszt tud megtenni vele.

Minden állomáson van egy váltókapcsoló, amellyel azt lehet beállítani, hogy a mozdony melyik csatlakozó
vágányszakaszon menjen tovább. Ha egyszer beállítottuk, többet nem lehet változtatni rajta.

Az állomások egy része Arezou-é, a többi pedig Borzou-é.
Egy, kezdetben teljesen feltöltött mozdony van.
A játék során, ha a vonat először fut be egy állomásra, akkor a tulajdonosa beállítja a váltókapcsolót.
A mozdony előbb-utóbb egy állomásokból álló körbe jut. (A kör egyetlen állomásból is állhat.)

Arezou nyer, ha a mozdony olyan körbe jut, ahol van töltőállomás és ezáltal akármeddig mehet.
Borzou nyer, ha a mozdony olyan körbe jut, ahol nincs töltőállomás, és így a mozdony lemerül.

Minden vasút leírásra $n$ játékot játszanak, az $s$. játékban az $0 \leq s \leq n-1$. állomásról indul a mozdony.

Írj programot, amely minden játékra megadja, hogy Arezou-nak van-e nyerő stratégiája, bárhogy is játszik Borzou!


## Megvalósítás

Az alábbi függvényt kell megírnod:

```
int[] who_wins(int[] a, int[] r, int[] u, int[] v)
```

* $a$: $n$ elemű tömb. Az $i$ állomás Arezou-é, ha $a[i] = 1$, illetve Borzou-é, ha $a[i] = 0$.
* $r$: $n$  elemű tömb. Ha az $i$. állomás töltőállomás, akkor $r[i] =1$, egyébként $r[i] = 0$.
* $u$ és $v$: $m$  elemű tömbök.
Minden $0 \leq i \leq m-1$, van egyirányú vágányszakasz $u[i]$-ből $v[i]$-be.
* A függvény értéke egy $n$ elemű $w$ tömb legyen!
Minden $0 \leq i \leq n-1$-re a $w[i]$ legyen $1$, ha Arezou megnyerheti a játékot
az $i$. állomásról indulva, bárhogy is játszik Borzou! Egyébként $w[i]$ legyen $0$!

## Példa

```
who_wins([0, 1], [1, 0], [0, 0, 1, 1], [0, 1, 0, 1])
```

![Train](train.png)


* Itt $2$ állomás van.
Borzou-é a $0$., ami töltőállomás.
Arezou-é az $1$., ami nem töltőállomás.
* Van $4$ vágányszakasz $(0, 0), (0, 1), (1, 0)$, és $(1, 1)$, ahol $(i, j)$ az $i$. állomásról a $j$. állomásra vezető egyirányú vágányszakaszt jelöl.
* Ha a mozdony a $0$. állomásról indul, akkor:
Ha Borzou a $0$. állomás vágánykapcsolóját $(0, 0)$ irányba állítja, akkor végig ott marad, azaz Arezou nyer.
Ha $(0, 1)$-re állítja, akkor Arezou az $1$. állomás vágánykapcsolóját $(1, 0)$-ra állítja és ezzel visszaküldi a $0$. állomásra. Ismét Arezou győz.
* Hasonló a megoldás, ha a mozdony az $1$. állomásról indul. Ekkor is Arezou nyer. Így a függvény értéke $[1, 1]$ értékű tömb legyen!

## Korlátok

* $1 \leq n \leq 5000$.
* $n \leq m \leq 20\,000$.
* Van legalább egy töltőállomás.
* Minden állomásból indul legalább egy vágányszakasz.
* Lehet ugyanaz egy vágányszakasz kezdő és végpontja (azaz $u[i] = v[i]$).
* Minden vágányszakasz különböző, tehát nincs két $i$ és $j$ index ($0 \leq i < j \leq m-1$), hogy $u[i]=u[j]$ és $v[i]=v[j]$.
* $0 \leq u[i], v[i] \leq n-1$ ($0 \leq i \leq m-1$).

## Részfeladatok

1. (5 pont) Minden $0 \leq i \leq m-1$-re vagy $v[i] = u[i]$, vagy $v[i] = u[i] + 1$.
1. (10 pont) $n \leq 15$.
1. (11 pont) Minden állomás Arezou-é.
1. (11 pont) Minden állomás Borzou-é.
1. (12 pont) Pontosan egy töltőállomás van.
1. (51 pont) Nincs további korlát.

## Minta értékelő

Bemenet:
* Az $1$. sor: $\;\; n \;\; m$
* A $2$. sor: $\;\; a[0] \;\; a[1] \; \ldots\; a[n-1]$
* A $3$. sor: $\;\; r[0] \;\; r[1] \; \ldots\; r[n-1]$
* A $4 + i$. sor ($0 \leq i \leq m-1$): $\;\; u[i] \;\; v[i]$

Az értékelő a `who_wins` eredményét írja ki az alábbi formátumban:
* Az $1$. sor: $\;\; w[0] \;\; w[1] \; \ldots\; w[n-1]$

