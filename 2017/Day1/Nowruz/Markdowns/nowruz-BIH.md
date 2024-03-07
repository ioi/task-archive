# Nowruz
Ostalo je još nekoliko dana do Nowruz-a (persijske nove godine) pa je djed pozvao cijelu svoju porodicu u baštu. Među gostima se nalazi i $k$ djece. Kako bi porodično okupljanje bilo zanimljivo i djeci, djed će organizovati igru sakrivanja. 

Cijela bašta se može predstaviti kao mreža jednakih ćelija dimenzija $m \times n$. Neke od ćelija (moguće je nijedna) su blokirane stijenama dok se sve druge ćelije smatraju *slobodnim*. Dvije ćelije su *susjedne* ako imaju jednu zejedničku ivicu. To znači da svaka ćelija ima najviše 4 susjeda: dva u horizontalnom i dva u vertikalnom pravcu. Djed želi da pretvori svoju baštu u labirint. U tu svrhu on može blokirati neke od slobodnih ćelija sadeći grmlje u njima. Ćelije gdje su zasađene biljke se više ne smatraju slobodnim. 

Labirint mora imati sljedeće osobine. Za svaki par $a$ i $b$ slobodnih ćelija u labirintu mora postojati tačno jedan *jednostavan put* između njih. Jedan jednostavan put između dvije ćelije $a$ i $b$ je niz slobodnih ćelija gdje je prva ćelija $a$, posljednja ćelija je $b$, sve ćelije niza su različite, i svake dvije uzastopne ćelije u nizu su susjedne i u labirintu.

Svako dijete se može sakriti u neku ćeliju ako i samo ako je to slobodna ćelija i ima tačno jednog slobodnog susjeda. Dva djeteta se ne mogu sakriti u istoj ćeliji. 

Data Vam je mapa bašte kao input. Vaš zadatak je da pomognete djedu da kreira labirint gdje se može sakriti najveći broj djece. 

## Detalji implementacije
Ovo je output-only tip zadatka u kojem je moguće dobiti djelomičan broj bodova. Imate $10$ ulaznih dadoteka, svaka opisuje djedovu baštu. Za svaku izlaznu datoteku treba da pošaljete izlaznu datoteku sa mapom labirinta. Za svaku izlaznu datoteku dobićete bodove na osnovu broja djece koja se mogu sakriti u vašem labirintu.

Za ovaj zadatak ne trebate submitati source/izvorni code. 

## Ulazni format

Svaka ulazna datoteka opisuje mrežu koja predstavlja baštu a na njoj broj $k$ djecu koju je pozvao djed. Format je sljedeći:
* linija $1$: $\;\; m \;\; n \;\; k$
* linija $1+i$ (for $1 \leq i \leq m$):  $i$-ti red mreže, je string dužine $n$, koji se sastoji od sljedećih znakova (bez praznog prostora):
  - '`.`': prazna ćelija,
  - '`#`': kamen.

## Izlazni format

* linija $i$ (for $1 \leq i \leq m$): $i$-ti red lavirinta (vrta, nakon postavljanja grmlja), je string dužine $n$, koji se sastoji od sljedećih znakova (bez praznog prostora): 
  -  '`.`': prazna ćelija,
  -  '`#`': kamen,
  -  '`X`': grm. (Imajte na umu da slovo X mora biti napisano velikim slovom)

## Ograničenja

* $1 \leq m, n \leq 1024$

## Bodovanje
Izlaza datoteka se smatra *valid* valjanom ako su ispunjeni svi sljedeći uslovi:
*	Izlazna mapa mora da odgovara ulaznoj mpai sa jednim izuzetkom koji proizvoljno ima monogo '`.`' znakova na ulaznoj mapi te se mogu promjeniti na znakove „X“ (ćelije koje blokiraju grmlje).
* Izlazna mapa mora imati osobine labirinta, kako su definisane u postavci zadatka. 

Ukoliko Vaš izlazni fajl nije validan dobićete $0$ bodova za taj test primjer. U suprotnom, broj bodova će biti $\min(10, 10 \cdot l/k)$, zaokruženo na dole na dvije cifre iza zareza. U formuli datoj iznad, $l$ je broj djece koja mogu da se sakriju u lavirintu, a $k$ je broj djece dat u ulaznom fajlu. Dobićete $10$ bodova za test primjer ako i samo ako se u lavirintu koji ste ispisali u izlazni fajl može sakriti $k$ ili više dece. Za svaki test primjer postoji lavirint za koji se dobija $10$ bodova.

Primetite da ukoliko je vaš izlazni fajl validan i ostvaruje $0$ bodova prema formuli od gore, poruka servera na CMS-u će biti 'Wrong Answer'.

## Primer

Primjer ulaznog fajla:

```
4 5 5
....#
.#..#
...#.
....#
```

Moguće validno rješenje (lavirint):

```
.X.X#
.#..#
...#X
XX..#
```

Pošto $l=4$ djece može da se sakrije u lavirintu, ovo rješenje dobija $10 \cdot 4 / 5 = 8$ bodova. Ćelije na kojima se djeca mogu sakriti su označena sa `O` u matrici ispod:

```
OXOX#
.#.O#
...#X
XX.O#
```

Sljedeće tri matrice nisu validni lavirinti:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

U matrici sa ljeve strane ne postoji prost put izmedju prohodnih ćelija u gornjem ljevom uglu i prohodnoj ćeliji u poslednjoj koloni. U preostale dvije matrice, za svaki par različitih prohodnih ćelija postoji tačno dva različita prosta puta između njih.




