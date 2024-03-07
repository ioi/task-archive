# Perzsa újév

A perzsa újév alkalmából a nagypapa $k$ gyereket hívott meg bújócskát játszani a kertben.
A kert egy $n \times m$-es rácshálózat, amiben egyes cellákban lehetnek blokkoló kövek, a többi szabad.

Két cella szomszédos, ha valamelyik oldalukkal érintkeznek, azaz mindenkinek legfeljebb 4 szomszédja lehet.

A nagypapa labirintust szeretne készíteni úgy, hogy szabad cellákba bokrokat ültet, ezek nem lesznek szabadok.
A labirintusnak olyannak kell lennie, hogy bármely két szabad cella között pontosan egy egyszerű út legyen,
 amely különböző, egymással szomszédos szabad cellákon vezet keresztül.
 
A gyerekek olyan szabad cellákban bújhatnak el, amelyeknek egyetlen szabad szomszédjuk van. 
Egy cellába csak egy gyerek bújhat el.

Minden feladatban megkapod egy kert térképét, amelynek alapján el kell készítened a labirintust,
 ahol a legtöbb gyerek elbújhat.

## Megvalósítás

Ez egy output-only feladat, kapsz 10 kert leírást, és mindegyikhez készítened kell egy-egy labirintus leírást.

 Az alapján kapsz mindegyikre pontot, hogy hány gyerek tud elbújni bennük.

## Bemenet

Minden bemenet egy kert leírását és a meghívott gyerekek $k$ számát tartalmazza az alábbi formában:
* Az $1$. sor: $\;\; m \;\; n \;\; k$
* A $1+i$. sor ( $1 \leq i \leq m$): a kert $i$. sora, $n$ karakterből álló szöveg, amely az alábbi kétféle karaktert tartalmazhatja, szóközök nélkül:
  - '`.`': szabad cella,
  - '`#`': kő.

## Kimenet

* Az $i$. sor (for $1 \leq i \leq m$): a labirintus $i$ . sora (a kert a bokrok ültetése után). Ez is $n$ karakteres szöveg, háromféle karaktert tartalmazhat, szóközök nélkül:
  -  '`.`': szabad cella,
  -  '`#`': kő,
  -  '`X`': bokor. (nagy X)

## Korlátok

* $1 \leq m, n \leq 1024$

## Pontozás

A kimenet helyes, ha az alábbi két feltétel teljesül:
* A kimenet csak a  '`.`' karakterek helyére tett  '`X`' karakterekben térhet el a bemenettől.
* A kimenetnek olyan labirintusnak kell lenni, ami a feladat leírásában szerepel.

Ha a kimenet nem helyes, $0$ pontot kapsz.
Egyébként a pontszámod $\min(10, 10 \cdot l/k)$, két tizedesre lefelé kerekítve, ahol $l$ a gyerekek száma, akik elbújhatnak a labirintusban, a $k$ a bemenetben szereplő gyerekek száma.
Pontosan akkor kapsz $10$ pontot, ha legalább $k$ gyerek el tud bújni.
Minden tesztesetre van $10$ pontos megoldás.

Helyes, de $0$ pontos megoldásra a 'Wrong Answer' értékelést kapod.

## Példa

Bemenet:

```
4 5 5
....#
.#..#
...#.
....#
```

Lehetséges helyes kimenet:

```
.X.X#
.#..#
...#X
XX..#
```

Itt $l=4$ gyerek tud elbújni, ezért $10 \cdot 4 / 5 = 8$ pontot kapsz. Az alábbi ábrán a `O` karakter jelzi a helyeket, ahol gyerek el tud bújni:


```
OXOX#
.#.O#
...#X
XX.O#
```

A következő 3 kimenet nem helyes:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

A baloldaliban nincs út a bal felső és a legjobboldalibb oszlop szabad cellája között.
A másik két esetben bármely két pontpár között pontosan két út van.

