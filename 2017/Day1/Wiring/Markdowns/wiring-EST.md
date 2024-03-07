# Juhtmestik

Marjam on elektriinsener. Ta kavandab kommunikatsioonitorni juhtmestikku. Tornil on mitu erinevatel kõrgustel asuvat ühenduspunkti. Iga kaks punkti võib ühendada juhtmega ning iga punkti küljes võib olla suvaline arv juhtmeid. On kahte tüüpi ühenduspunkte: punased ja sinised.

Selles ülesandes võime vaadelda torni kui sirgjoont ning ühenduspunkte kui punaseid ja siniseid mittenegatiivsete täisarvuliste koordinaatidega punkte sellel joonel. Juhtme pikkus on seega kahe tema poolt ühendatud punkti koordinaatide vahe.

Sinu ülesanne on aidata Marjamil planeerida juhtmestikku sellisena, et:

1. Iga ühenduspunkt on ühendatud vähemalt ühe teist värvi punktiga.
2. Kõikide juhtmete kogupikkus on võimalikest minimaalne.

## Tehnilised detailid

Lahendusena tuleb realiseerida järgmine funktsioon:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: massiiv pikkusega $n$, milles on antud punaste ühenduspunktide koordinaadid kasvavas järjekorras.
* $b$: massiiv pikkusega $m$, milles on antud siniste ühenduspunktide koordinaadid kasvavas järjekorras.
* Funktsioon peab tagastama minimaalse võimaliku korrektse juhtmestiku kogupikkuse.
* Pane tähele, et tagastatava väärtuse tüüp on `int64`.

## Näide

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Alltoodud pilt illustreerib näidet:
![Wiring](wiring.png)

* Torn on skemaatiliselt näidatud horisontaalsena.
* Mustvalges väljatrükis on punased ühenduspunktid tumedat värvi ning sinised - heledat.
* Joonisel on $4$ punast punkti. Nende asukohtade koordinaadid on $1$, $2$, $3$ ja $7$.
* Joonisel on $5$ sinist punkti. Nende asukohtade koordinaadid on $0$, $4$, $5$, $9$ ja $10$.
* Pildil on näidatud üks võimalik optimaalne lahendus.
* Selles lahenduses on kõikide juhtmete kogupikkus $1 + 2 + 2 + 2 + 3 = 10$. Kuna lahendus on optimaalne, peabki funktsioon  tagastama vastusena $10$.
* Pane tähele, et ühenduspunktiga positsioonil $7$ on ühendatud kaks juhet.

## Piirangud

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (iga $0 \leq i \leq n-1$ jaoks),
* $0 \leq b[i] \leq 10^9$ (iga $0 \leq i \leq m-1$ jaoks),
* Sisendmassiivid $r$ ja $b$ on sorteeritud kasvavas järjekorras.
* Kõik $n+m$ väärtust massiivides $r$ ja $b$ on erinevad.

## Alamülesanded

1. (7 punkti) $n, m \leq 200$,
2. (13 punkti) Kõik punaste ühenduspunktide koordinaadid on väiksemad kõikidest siniste punktide koordinaatidest.
3. (10 punkti) iga 7 järjestikuse punkti seas leidub vähemalt üks punane ühenduspunkt ja üks sinine ühenduspunkt.
4. (25 punkti) Ühenduspunktide koordinaadid on kõik erinevad arvud vahemikus [1, n+m]
5. (45 punkti) Lisapiirangud puuduvad.

## Näidistester

Näidistester loeb sisendit järgmises formaadis:
* rida $1$: $\;\; n \;\; m$
* rida $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* rida $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Näidistester trükib ainsal real funktsiooni `min_total_length` poolt tagastatud väärtuse.
