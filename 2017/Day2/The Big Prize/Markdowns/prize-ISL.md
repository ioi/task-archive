# Stóru verðlaunin

Stóru verðlaunin er frægur leikjaþáttur í sjónvarpinu.
Þú ert heppni keppandinn sem komst í síðustu umferðina.
Þú stendur fyrir framan röð af $n$ kössum, númeraðir $0$ til $n-1$ frá vinstri til hægri.
Hver kassi inniheldur verðlaun sem ekki er hægt að sjá fyrr en kassinn er opnaður.
Það eru $v \geq 2$ mismunandi *tegundir* af verðlaunum.
Tegundirnar eru númeraðar frá $1$ til $v$ í *lækkandi* röð eftir verðmæti.

Verðlaunin af tegund númer $1$ eru dýrust: demantur.
Það er nákvæmlega einn demantur í kössunum.
Verðlaunin af tegund númer $v$ eru ódýrust: sleikjó.
Til að gera leikinn meira spennandi þá eru mun fleiri ódýr verðlaun en dýr verðlaun.
Það er, fyrir öll $t$ þannig að $2 \leq t \leq v$ þá vitum við eftirfarandi:
ef það eru $k$ verðlaun af tegund $t-1$, þá eru *stranglega fleiri* en $k^2$ verðlaun af tegund $t$.

Þitt markmið er að vinna demantinn.
Í lok leiksins muntu þurfa að opna kassa og færðu verðlaunin sem eru í honum.
Áður en þú þarft að velja kassa til að opna færðu að spyrja Rambod, stjórnanda leikjaþáttarins, nokkrar spurningar.
Fyrir hverja spurningu velurðu einhvern kassa $i$.
Rambod mun þá svara þér með fylki $a$ sem inniheldur tvær heiltölur.
Þær þýða eftirfarandi:
* Á meðal kassanna vinstra megin við kassa $i$ þá eru nákvæmlega $a[0]$ kassar sem innihalda dýrari verðlaun en þau sem eru í kassa $i$.
* Á meðal kassanna hægra megin við kassa $i$ þá eru nákvæmlega $a[1]$ kassar sem innihalda dýrari verðlaun en þau sem eru í kassa $i$.

Til dæmis, segjum að $n=8$, og að þú spyrjir um kassa $i=2$.
Rambod mun þá svara þér með fylkinu $a=[1,2]$.
Þetta svar þýðir eftirfarandi:
* Nákvæmlega einn af kössunum $0$ og $1$ innihalda verðlaun sem eru dýrari en þau sem eru í kassa $2$.
* Nákvæmlega tveir af kössunum $3, 4, \ldots, 7$ innihalda verðlaun sem eru dýrari en þau sem eru í kassa $2$.

Þitt verkefni er að finna kassann sem inniheldur demantinn með því að spyrja fárra spurninga.

## Útfærsluatriði

Þú átt að útfæra eftirfarandi fall:

```
int find_best(int n)
```

* Dómarinn kallar nákvæmlega einu sinni í þetta fall.
* $n$: fjöldi kassa.
* Þetta fall á að skila númerinu á kassanum sem inniheldur demantinn, þ.e., einu heiltölunni $d$ ($0 \leq d \leq n-1$) þannig að kassi $d$ innihaldi verðlaun af tegund $1$.

Fallið að ofan getur kallað í eftirfarandi fall:

```
int[] ask(int i)
```

* $i$: númerið á kassanum sem þú ætlar að spyrja um. Gildið á $i$ þarf að vera á bilinu $0$ til $n-1$.
* Þetta fall skilar fylkinu $a$ með $2$ stökum. Hér er $a[0]$ fjöldi dýrari verðlauna í kössunum vinstra megin við kassa $i$ og $a[1]$ er fjöldi dýrari verðlauna í kössunum hægra megin við kassa $i$.


## Sýnidæmi

Dómarinn framkvæmir eftirfarandi fallakall:

```
find_best(8)
```

Það eru $n=8$ kassar. Segjum að tegundirnar á verðlaununum séu $[3,2,3,1,3,3,2,3]$.
Öll möguleg köll í fallið `ask` og samsvarandi skilagildi eru talin upp að neðan.

- `ask(0)` skilar $[0, 3]$
- `ask(1)` skilar $[0, 1]$
- `ask(2)` skilar $[1, 2]$
- `ask(3)` skilar $[0, 0]$
- `ask(4)` skilar $[2, 1]$
- `ask(5)` skilar $[2, 1]$
- `ask(6)` skilar $[1, 0]$
- `ask(7)` skilar $[3, 0]$

Í þessu sýnidæmi er demanturinn í kassa $3$. Þar af leiðandi á fallið `find_best` að skila $3$.

![Prize1](prize.png "600") 

Myndin að ofan sýnir þetta sýnidæmi.
Efri hlutinn sýnir tegundina á verðlaununum í hverjum kassa.
Neðri hlutinn sýnir fyrirspurnina `ask(2)`.
Merktu kassarnir innihalda dýrari verðlaun en þau sem eru í kassa $2$.

## Takmarkanir

* $3 \leq n \leq 200\,000$.
* Tegundin á verðlaununum í hverjum kassa er á bilinu $1$ til $v$.
* Það eru nákvæmlega ein verðlaun af tegund $1$.
* Fyrir öll $2 \leq t \leq v$, ef það eru $k$ verðlaun af tegund $t-1$, þá eru *stranglega* fleiri en $k^2$ verðlaun af tegund $t$.

## Hlutverkefni og stigagjöf

Í sumum prófunartilvikum mun dómarinn aðlaga sig eftir fyrirspurnir.
Þetta þýðir að í þessum prófunartilvikum hefur dómarinn ekki fasta runu af verðlaunum.
Í staðinn geta svörin sem dómarinn gefur farið eftir fyrirspurnum lausnarinnar.
Dómarinn mun þó alltaf svara þannig að, eftir hvert svar, þá er alltaf til að minnsta kosti ein runa af verðlaunum sem er í samræmi við svörin sem hafa verið gefin fram að því.

1. (20 stig) Það er nákvæmlega $1$ demantur og $n-1$ sleikjóar (og þar af leiðandi, $v = 2$).
Þú getur kallað í fallið `ask` í mesta lagi $10\,000$ sinnum.
1. (80 stig) Engar frekari takmarkanir.

Í hlutverkefni 2 getur þú fengið stig að hluta til.
Látum $q$ vera hæsta fjölda kalla í fallið  `ask` á meðal allra prófunartilvika í þessu hlutverkefni.
Þá munu stigin þín fyrir þetta hlutverkefni vera reiknuð samkvæmt eftirfarandi töflu:

Spurningar | Stig
--- | ---
$10\,000 < q$ | $0$ (gefið upp sem 'Wrong Answer' í CMS)
$6000 < q \leq 10\,000$ | $70$
$5000 < q \leq 6000$ | $80 - (q-5000)/100$
$q \leq 5000$ | $80$

## Sýnishorn af dómara

Sýnishorn af dómara mun ekki aðlaga sig eftir fyrirspurnir.
Í staðinn les það bara inn og notar fast fylki $p$ af verðlaunategundum. Fyrir öll $0 \leq b \leq n-1$ þá mun tegundin á verðlaununum í kassa $b$ vera gefin sem $p[b]$.
Sýnishorn af dómara les inntak á eftirfarandi formi:

- lína $1$: $\;\; n$
- lína $2$: $\;\; p[0] \;\; p[1]  \; \ldots \; p[n-1]$

Sýnishorn af dómara skrifar út eina línu sem inniheldur skilagildi fallsins `find_best` og fjölda kalla í fallið `ask`.