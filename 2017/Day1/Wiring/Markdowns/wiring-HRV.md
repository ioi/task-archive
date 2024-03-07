# Wiring

Maryam je ferovka. Trenutno dizajnira komunikacijski toranj. Na njemu se, na međusobno različitim visinima, nalaze točke za spajanje. Bilo koje dvije točke za spajanje moguće je povezati žicom. Svaka točka za spajanje može biti povezana s proizvoljno mnogo žica. Postoje dvije vrste spojnih točaka: crvene i plave.

Za potrebe ovog zadatka toranj smatramo pravcem, a točke za spajanje točkama s nenegativnim cjelobrojnim koordinatama na tom pravcu. Duljina žice je udaljenost dviju spojnih točaka koje povezuje.

Vaš zadatak je pomoći Maryam sastaviti shemu spajanja takvu da:
1. Svaka spojna točka je povezana s barem jednom spojnom točkom druge boje.
2. Ukupna duljina žice je minimalna.

## Implementacijski detalji

Trebate implementirati sljedeću funkciju:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: niz duljine $n$ koji sadrži pozicije crvenih spojnih točaka u rastućem poretku
* $b$: niz duljine $m$ koji sadrži pozicije plavih spojnih točaka u rastućem poretku
* Funkcija treba vratiti minimalnu ukupnu duljinu žica, gledajući po svim validnim shemama spajanja
* Primijetite da je tip koji funkcija vraća `int64`.

## Primjer

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Sljedeća skica ilustrira ovaj primjer.
![Wiring](wiring.png)

* Toranj je prikazan vodoravno.
* U crno-bijeloj printanoj verziji teksta crvene točke su tamne, a plave su svijetle
* Postoji $4$ crvenih spojnih točaka koje se nalaze na pozicijama $1, 2, 3,$ i $7$.
* Postoji $5$ plavih spojnih točaka koje se nalaze na pozicijama $0, 4, 5, 9,$ i $10$.
* Jedno optimalno rješenje je prikazano na gornjoj slici.
* U ovom rješenju ukupna duljina žica je $1 + 2 + 2 + 2 + 3 = 10$, što je optimalno.
Dakle, funkcija treba vratiti $10$.
* Primijetite da su dvije žice spojene na točku na poziciji $7$.

## Ograničenja

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (za sve $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (za sve $0 \leq i \leq m-1$),
* Nizovi $r$ i $b$ su sortirani u rastućem poretku.
* Svih $n+m$ vrijednosti nizova $r$ i $b$ su jedinstvene.

## Podzadaci

1. (7 bodova) $n, m \leq 200$,
2. (13 bodova) Sve crvene spojne točke imaju manje pozicije od svih plavih spojnih točaka. 
3. (10 bodova) Među svakih $7$ uzastopnih spojnih točaka nalazi se barem jedna crvena i barem jedna plava.
4. (25 bodova) Sve spojne točke imaju različite pozicije u intervalu $[1, n+m]$.
5. (45 bodova) Bez dodatnih ograničenja

## Sempl grejder

Sempl grejder čita ulaz u sljedećem formatu:
* redak $1$: $\;\; n \;\; m$
* redak $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* redak $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Sempl grejder ispisuje jednu liniju koja sadrži vrijednost koju je vratila funkcija `min_total_length`.