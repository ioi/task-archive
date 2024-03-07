# Persivaldan (nowruz)

Ostalo je još nekoliko dana do Persivaldana (Persivalovog rođendana), i njegov deda Merlin je pozvao njegovu porodicu u svoj zamak. Poznato je da Persival ima $k$ sinova i ćerki i da je svima dao ime Filip ili Filipinka, pošto se zna da jedino dete sa imenom koje počinje sa Filip može da nasledi celokupno znanje svog oca. Da bi okupljanje bilo što zabavnije za Filipe i Filipinke, Merlin je odlučio da organizuje žmurke.

Ceo zamak se može predstaviti uz pomoć matrice dimenzija $m \times n$. Na nekim (moguće ni na jednom) poljima matrice se nalazi kamenje, te su ta polja neprohodna, dok su sva ostala polja *prohodna*. Dva polja su *susedna* ukoliko dele stranicu, tj. svako polje ima najviše 4 susedna polja: dva polja u redu i dva polja u koloni.
Merlin hoće da pretvori svoj zamak u lavirint. Da bi to uradio, on može da blokira neka prohodna polja tako što će postaviti svoje lojalne sluge na ta polja. Polja na koje Merlin postavi svoje lojalne sluge postaju neprohodna.

Lavirint mora da imati sledeću osobinu. Za svaki par $a$ i $b$ prohodnih polja u lavirintu mora da postoji tačno jedan *prost put* između njih. Prost put između polja $a$ i $b$ je niz prohodnih polja u kome je prvo polje baš polje $a$, poslednje je polje $b$, sva polja u nizu su različita, i svaka dva uzastopna polja u nizu su susedna polja u matrici.

Svako dete može da se sakrije na polje ako i samo ako je to polje prohodno i ima *tačno* jedno prohodno susedno polje. Nemoguće je da se dva deteta sakriju na isto polje.

Data vam je mapa zamka na ulazu. Vaš zadatak je da pomognete Merlinu da napravi lavirint u kome može da se sakrije što više Filipa i Filipinki.

## Detalji implementacije

Ovo je output-only problem sa parcijalnim bodovanjem.
Dato vam je $10$ ulaznih fajlova, gde je u svakom fajlu opisan Merlinov zamak.
Za svaki ulazni fajl koji vam je dat možete da pošaljete po jedan izlazni fajl sa mapom lavirinta.
Za svaki poslat izlazni fajl ćete dobiti bodove u zavisnosti od broja dece koja mogu da se sakriju u lavirintu.

Ne treba da posaljete nikakav izvorni kod (source code) za ovaj zadatak.

## Format ulaza

Svaki ulazni fajl opisuje matricu koja predstavlja zamak i uz matricu je dat i broj Persivalove dece. Format ulaznog fajla je sledeći:
* linija $1$: $\;\; m \;\; n \;\; k$
* linija $1+i$ (za $1 \leq i \leq m$): $i$-ti red matrice, koji je predstavljen stringom dužine $n$, koji sadrži sledeće znakove (bez razmaka):
  - '`.`': prohodno polje,
  - '`#`': polje sa kamenjem (neprohodno polje).

## Format izlaza

* linija $i$ (za $1 \leq i \leq m$): $i$-ti red lavirinta (zamak nakon  postavljanja lojalnih sluga). $i$-ti red je string dužine $n$, koji sadrži sledeće znakove (bez razmaka):
  -  '`.`': prohodno polje,
  -  '`#`': polje sa kamenjem (neprohodno polje),
  -  '`X`': polje sa lojalnim slugom (neprohodno polje). (Primetiti da znak X mora biti veliko slovo.)

## Ograničenja

* $1 \leq m, n \leq 1024$

## Bodovanje

Fajl koji se šalje će biti označen kao *validan* ukoliko su zadovoljeni svi sledeći uslovi:
* Izlazna mapa mora da se slaže sa datom mapom zamka svuda osim što proizvoljno mnogo '`.`' znakova iz ulazne mape zamka može biti promenjeno u '`X`' znakove (polja sa lojalnim slugama).
* Izlazna mapa mora imati osobine lavirinta, kao što je opisano u tekstu zadatka.

Ukoliko Vaš izlazni fajl nije validan dobićete $0$ bodova za taj test primer.
U suprotnom, broj bodova će biti $\min(10, 10 \cdot l/k)$, zaokruženo na dole, na dve decimale.
U datoj formuli, $l$ je broj dece koja mogu da se sakriju u lavirintu, a $k$ je broj Persivalove dece dat u ulaznom fajlu.
Dobićete $10$ bodova za test primer ako i samo ako se u lavirintu koji ste ispisali u izlazni fajl može sakriti $k$ ili više dece.
Za svaki test primer postoji lavirint za koji se dobija $10$ bodova.

Primetite da ukoliko je vaš izlazni fajl validan i ostvaruje $0$ bodova prema navedenoj formuli, poruka servera na CMS-u će biti 'Wrong Answer'.

## Primer

Primer ulaznog fajla (mapa zamka):

```
4 5 5
....#
.#..#
...#.
....#
```

Moguće validno rešenje (lavirint):

```
.X.X#
.#..#
...#X
XX..#
```

Pošto $l=4$ dece može da se sakrije u lavirintu, ovo rešenje dobija $10 \cdot 4 / 5 = 8$ bodova. Polja na kojima se deca mogu sakriti su označena sa `O` u matrici ispod:

```
OXOX#
.#.O#
...#X
XX.O#
```

Sledeće tri matrice nisu validni lavirinti:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#
```

U matrici sa leve strane ne postoji prost put izmedju prohodnog polja u gornjem levom uglu i prohodnog polja u poslednjoj koloni.
U preostale dve matrice, za svaki par različitih prohodnih polja postoji tačno dva različita prosta puta između njih.