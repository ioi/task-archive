# Wiring

Azur obično provodi večeri razmjenjujući nježnosti sa svojom djevojkom u dugim telefonskim razgovorima, ali večeras je taj ritual doveden pod znak pitanja! Naime, Vladan je zapeo za papuču koju je Azur nehotice ostavio pored telefonskog stuba, te je u pokušaju da održi ravnotežu počupao sve žice na stubu. Muamer je, kao najstasitiji od svih, odlučio da se popne na stub i postavi nove žice, dok je Nikola cijeli ovaj čin posmatrao kroz svoje kul naočale.

Vaš zadatak je da pomognete Muameru da pomogne Azuru da se i večeras čuje sa devojkom. Vladan će pomoći sam sebi, dok će Nikola nastaviti kulirati.

Na stubu se nalazi više pinčika (tj. andraka, andrmoljaca, nešto što štrči ili viri), svaka dva na različitoj visini. Dva pinčika se spajaju žicom. Svaki pinčik može biti na kraju proizvoljnog broja žica. Postoje dvije vrste pinčika: crveni i plavi.

Za potrebe ovog problema, telefonski stub ćemo posmatrati kao pravu, a pinčike kao crvene i plave tačke koje se nalaze na nenegativnim cjelobrojnim koordinatama na toj pravi. Dužina žice je rastojanje između dva pinčika koje ta žica povezuje.

Povezivanje pinčika žicama mora da zadovoljava sljedeće uslove:

1. Svaki pinčik je povezan žicom sa barem jednim pinčikom druge boje.
2. Ukupna dužina svih žica je najmanja moguća.

## Detalji implementacije

Potrebno je da implementirate sljedeću funkciju:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: niz dužine $n$ koji sadrži pozicije crvenih pinčika u rastućem redoslijedu.
* $b$ niz dužine $m$ koji sadrži pozicije plavih pinčika u rastućem redoslijedu.
* Ova funkcija treba da vrati najmanju ukupnu dužinu žica, među svim mogućim ispravnim povezivanjima.
* Primjetite da je tip rezultata ove funkcije `int64`.

## Example

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Ovaj primjer je ilustrovan na slici ispod.
![Wiring](wiring.png)

* Stub je prikazan horizontalno.
* U crno-bijeloj štampanoj verziji teksta problema, crveni pinčici su tamni, a plavi su svetli.
* Postoji $4$ crvena pinčika, na pozicijama $1, 2, 3$ i $7$.
* Postoji $5$ plavih pinčika, na pozicijama $0, 4, 5, 9$ i $10$.
* Jedno optimalno rešenje je prikazano na gornjoj slici.
* Ukupna dužina žica u ovom rješenju je $1 + 2 + 2 + 2 + 3 = 10$, što je optimalno. Dakle, funkcija treba da vraća $10$.
* Primjetite da su dvije žice povezane na pinčik na poziciji $7$.

## Ograničenja

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (za sve $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (za sve $0 \leq i \leq m-1$),
* Svaki od nizova $r$ i $b$ je sortiran u rastućem redoslijedu.
* Svih $n+m$ vrijednosti iz nizova $r$ i $b$ su različite.

## Podzadaci

1. (7 bodova) $n, m \leq 200$,
1. (13 bodova) Svaki crveni pinčik je na manjoj poziciji od svakog plavog pinčika.
1. (10 points) Postoji bar jedan pinčik od svake boje među svakih $7$ uzastopnih pinčika.
1. (25 points) Svi pinčici imaju različite pozicije u opsegu $[1, n+m]$.
1. (45 points) Nema dodatnih ograničenja.

## Primer grejdera

Grejder čita ulazne podatke u sljedećem formatu:
* linija $1$: $\;\; n \;\; m$
* linija $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* linija $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Grejder štampa jednu liniju koja sadrži vrednost koju vraća funkcija `min_total_length`.
