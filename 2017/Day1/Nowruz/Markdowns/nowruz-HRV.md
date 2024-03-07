# Nowruz

Moj dida i ja...

Za par dana je Nowruz (Perzijska nova godina) pa deda zove ekipu u vrt. Među gostima se našlo $k$ djece. Kako bi cijela zabava bila, jel, zabavnija, deda će s djecom odigrati partiju skrivača.

Vrt zamišljamo kao matricu dimenzija $m \times n$ koja se sastoji od jediničnih kvadratića (polja). Na nekim se poljima može nalaziti kamenje pa takva polja smatramo neprohodnim, dok su sva ostala polja *slobodna*. Dva su polja *susjedna* ako dijele stranicu. Preciznije, svako polje ima najviše 4 susjeda: dva u horizontalnom i dva u vertikalnom smjeru. Deda želi vrt pretvoriti u labirint gdje će s djecom igrati skrivača. U te svrhe, odlučio je blokirati neka slobodna polja tako što će na njih posaditi vinovu lozu. Nakon sadnje loze, ta polja više nisu slobodna. 

Labirint mora imati sljedeće svojstvo. Za svaki par slobodnih polja $a$ i $b$ mora postojati točno jedan *jednostavan put* između njih. Jenostavan put između polja $a$ i $b$ je slijed slobodnih polja takav da je prvo polje $a$, zadnje polje $b$, sva su polja različita te su svaka dva uzastopna polja susjedna. 

Dijete se može sakriti na nekom polju ako i samo ako je ono slobodno i ima *točno* jednog slobodnog susjeda. Također, na nekom se polju može sakriti najviše jedno dijete. 

Na ulazu ćete dobiti izgled vrta, a vaš je zadatak pomoći dedi posaditi lozu tako da je broj djece koja se istovremeno mogu sakriti najveći mogući.

## Implementacijski detalji

Ovo je output-only zadatak sa parcijalnim bodovanjem.
Dobili ste $10$ ulaznih datoteka, a svaka od njih opisuje jednu inačicu dedina vrta.
Za svaku ulaznu datoteku trebate na sustav poslati izlaznu datoteku s mapom labirinta nakon sadnje loze. Za svaku poslanu izlaznu datoteku osvojit ćete broj bodova ovisan o broju djece koja se istovremeno mogu sakriti u vašem labirintu.

Nije potrebno poslati izvorni kod vašeg rješenja za ovaj zadatak.

## Ulazni podaci

Svaka ulazna datoteka sadrži opis vrta i broj djece $k$ koju je pozvao deda. Slijedi format datoteke:
* redak $1$: $\;\; m \;\; n \;\; k$
* redak $1+i$ (za $1 \leq i \leq m$): $i$-ti redak matrice, odnosno riječ duljine $n$ koja se sastoji od sljedećih znakova (bez bjelina):
  - '`.`': slobodno polje,
  - '`#`': kamenje.

## Izlazni podaci

* redak $i$ (za $1 \leq i \leq m$): $i$-ti redak matrice (vrt nakon sadnje vinove loze), odnosno riječ duljine $n$ koja se sastoji od sljedećih znakova (bez bjelina):
  -  '`.`': slobodno polje,
  -  '`#`': kamenje,
  -  '`X`': grm vinove loze. (Primijetite VELIKO slovo X.)

## Ograničenja

* $1 \leq m, n \leq 1024$

## Bodovanje

Izlazna se datoteka smatra *valjanom* ako su zadovoljeni sljedeći uvjeti:
* Izlazna matrica mora se slagati sa ulaznom matricom uz iznimku da je proizvoljan broj prohodnih polja  '`.`' promijenjen u '`X`' (loza).
* Izlazna matrica mora imati svojsta labirinta kao što je objašnjeno u tekstu zadatka.

U slučaju da vaša izlazna datoteka nije valjana, osvojit ćete impresivnih (Kurtzovih) $0$ bodova. U protivnom, osvojit ćete $\min(10, 10 \cdot l/k)$ bodova zaokruženih (nadolje) na dvije znamenke nakon decimalne točke.

Broj $l$ iz formule predstavlja broj djece koja se istovremeno mogu sakriti u vašem labirintu, dok je $k$ broj djece koju je deda pozvao na zabavu (iz ulaza). Možete pretpostaviti da su primjeri takvi da je na svakom moguće osvojiti svih $10$ bodova.

Primijetite da, prema gornjoj formuli, vaše rješenje može osvojiti $0$ bodova čak i ako je ispisana matrica valjana. U tom će slučaju poruka na CMS sustavu biti 'Wrong Answer'.

## Primjer

Ulaz:

```
4 5 5
....#
.#..#
...#.
....#
```

Mogući izlaz:

```
.X.X#
.#..#
...#X
XX..#
```

Budući da se $l=4$ djece može sakriti u labirintu, ovo će rješenje osvojiti $10 \cdot 4 / 5 = 8$ bodova. Polja na kojima se djeca mogu sakriti prikazana su slovom `O`:


```
OXOX#
.#.O#
...#X
XX.O#
```

Sljedeća tri izlaza nisu valjana:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

Lijevi izlaz ne sadrži jednostavan put između gornjeg lijevog slobodnog polja i slobodnog polja u najdesnijoj koloni. U preostalim izlazima, za svaki par slobodnih polja postoje točno dva različita jednostavna puta između njih.
