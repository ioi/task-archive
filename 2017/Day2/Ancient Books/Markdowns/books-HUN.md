# Könyvek

Az Iráni Nemzeti Könyvtárban egy sorban $n$ asztalon van kiállítva asztalonként egy-egy régi könyv. Az asztalok $0$-tól $n-1$-ig vannak sorszámozva.

A koruk szerint vannak sorbarakva, de címük szerinti sorrendbe kell őket rendezni.

Aryan, a könyvtáros készített egy $n$ elemű $p$ sorozatot,  amely $0$ és $n-1$ közötti értékeket tartalmaz.
Ebben $p[i]$ azt jelenti, hogy az $i$. asztalon levő könyvnek a kívánt sorrendben a $p[i]$. asztalon van a helye.

Aryan az $s$. asztaltól indulva rendezi át a könyveket, és a végén ide kell visszajönnie. Egyszerre egy könyvet vihet a kezében.
Rendezés közben a következőket teheti:
* Ha nincs nála könyv, de az asztalon van, ahol áll, akkor azt a könyvet felveheti (de nem kötelező felvennie).
* Ha van nála könyv és az asztalon is van, akkor kicserélheti őket.
* Ha van nála könyv és az asztal üres, akkor a könyvet leteheti az asztalra.
* Átmehet másik asztalhoz (legfeljebb egy könyvvel a kezében).


Az $i$. és a $j$. asztal távolsága pontosan $|j-i|$ méter ($0 \leq i, j \leq n - 1$). 

Írj programot, amely kiszámítja, hogy minimum mennyi az Aryan által megteendő össz távolság a rendezés során!

## Megvalósítás

Az alábbi függvényt kell megírnod:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ $n$ elemű tömb.
A kezdetben az $i$. asztalon levő könyvet Aryannak a $p[i]$. asztalra kell átvinnie ($0 \leq i < n$).
* $s$ annak az asztalnak a sorszáma, ahonnan Aryan indul, és ahova a rendezés végén visszatér.
* A függvény eredménye, hogy minimum mennyi az Aryan által megteendő össz távolság a rendezés során.

## Példa

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

$n=4$ és Aryan kezdetben a $0$. asztalnál áll.
A következőképpen rendezi a könyveket:
* Az $1$. asztalhoz megy és felveszi az ott levő könyvet, amit a $2$. asztalra kell raknia.
* A $2$. asztalhoz megy, kicseréli a könyvet az asztalon levővel.
A most kezében levőt a $3$. asztalra kell vinnie.
* Elmegy a $3$. asztalhoz és kicseréli a könyvet az asztalon levővel.
A most kezében levőt az $1$. asztalra kell vinnie.
* Elmegy az $1$. asztalhoz és leteszi a kezében levő könyvet.
* Végül visszamegy a $0$. asztalhoz.

Megjegyezzük, hogy a $0$. asztalon levő könyv már a kívánt helyen van, azt nem kellett mozgatnia.
Összesen $6$ métert kellett megtennie a rendezés során, a függvényed eredméyne így $6$.

## Korlátok

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* A $p$ tömb $n$ darab különböző egész számot tartalmaz $0$ és $n-1$ között.

## Részfeladatok

1. (12 pont) $n \le 4$ és $s = 0$
1. (10 pont) $n \le 1000$ és $s = 0$
1. (28 pont) $s = 0$
1. (20 pont) $n \le 1000$
1. (30 pont) nincs további korlát

## Minta értékelő

A bemenet formátuma:

- Az $1$. sor: $\;\; n \;\; s$
- A $2$. sor: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

Egyetlen számot ír ki, a `minimum_walk` értékét.