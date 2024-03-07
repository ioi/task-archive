# Suur Auhind

Suur Auhind on kuulus teleshow ja sa oled pääsenud show finaali.
Sinu ees on rida $n$ karbiga, millel on sildid $0$ kuni $n-1$ vasakult paremale.
Igas karbis on auhind, mida ei saa hetkel näha, sest karbid on suletud.
Mängus on $v \geq 2$ erinevat *sorti* auhinda.
Sordid on nummerdatud $1$ kuni $v$ *kahanevas* väärtuse järjekorras.

$1$. sorti auhind on alati kõige kallim, see on teemant.
Karpides on täpselt üks teemant.
$v$-ndat sorti auhind on kõige odavam, see on pulgakomm.
Et teha mängu huvitavamaks, on odavaid auhindu palju rohkem kui kalleid auhindu.
Täpsemalt: iga $t$ ($2 \leq t \leq v$) kohta on teada, et kui meil on $k$ auhinda sordist $t-1$, siis on meil *rangelt enam* kui $k^2$ auhinda sordist $t$.

Eesmärgiks on võita teemant.
Mängu lõpus tuleb sul avada üks karpidest ja sa saad selles oleva auhinna.
Enne karbi avamist saad sa küsida mängujuht Rambodi käest küsimusi.
Iga küsimuse korral saad sa valida mõne karbi $i$.
Vastusena annab Rambod sulle massiivi $a$, milles on kaks täisarvu.
Nende tähendus on järgmine:
* Karpide seas, mis jäävad karbist $i$ vasakule, on täpselt $a[0]$ karpi, milles on kallim auhind, kui see, mis on karbis $i$.
* Karpide seas, mis jäävad karbist $i$ paremale, on täpselt $a[1]$ karpi, milles on kallim auhind, kui see, mis on karbis $i$.

Olgu näiteks $n=8$. Oma küsimusel valid sa karbi $i=2$.
Vastusena annab Rambod sulle $a=[1,2]$.
Vastuse tähendus on:
* Täpselt ühes karpidest $0$ ja $1$ on auhind, mis on kallim kui see, mis on karbis $2$.
* Täpselt kahes karpidest $3, 4, \ldots, 7$ on auhind, mis on kallim kui see, mis on karbis $2$.
Sinu ülesandeks on leida teemant võimalikult väikese küsimuste arvuga.

## Tehnilised detailid

Sul tuleb kirjutada protseduur:

```
int find_best(int n)
```

* $n$: karpide arv.
* Protseduur peab tagastama karbi numbri, milles on teemant, s.t täisarvu $d$ ($0 \leq d \leq n-1$), nii et karbis $d$ on $1$ sorti auhind.

Sinu protseduur võib välja kutsuda järgmist protseduuri:

```
int[] ask(int i)
```

* $i$: karbi silt, mille kohta küsimus käib. $i$ väärtus peab olema lõigus $0$ kuni $n-1$.
* Protseduur tagastab kahe elemendiga massiivi $a$. Siin on $a[0]$ karbist $i$ vasakul asuvates karpides olevate kallimate auhindade arv ning $a[1]$ on karbist $i$ paremal olevate kallimate auhindade arv.


## Näide

Tester teeb järgmise väljakutse:

```
find_best(8)
```

Meil on $n=8$ karpi. Olgu auhindade tüübid $[3,2,3,1,3,3,2,3]$.
Kõik võimalikud protseduuri  `ask` väljakutsumise tulemused on järgmised:

- `ask(0)` tagastab $[0, 3]$
- `ask(1)` tagastab $[0, 1]$
- `ask(2)` tagastab $[1, 2]$
- `ask(3)` tagastab $[0, 0]$
- `ask(4)` tagastab $[2, 1]$
- `ask(5)` tagastab $[2, 1]$
- `ask(6)` tagastab $[1, 0]$
- `ask(7)` tagastab $[3, 0]$

Selles näites on teemant karbis $3$. Seega peab protseduur `find_best` tagastama $3$.

![Prize1](prize.png "600") 

Ülaltoodud joonis illustreerib kirjeldatud näidet.
Ülemises osas on karpides olevate auhindade väärtused.
Alumine osa illustreerib päringut `ask(2)`.
Märgitud karpides on kallimad auhinnad kui see, mis on karbis $2$.

## Piirangud

* $3 \leq n \leq 200\,000$.
* Igas karbis on auhind sordist $1$ kuni $v$.
* $1$. sorti auhindu on täpselt üks.
* Iga $2 \leq t \leq v$ puhul, kui laual on $k$ auhinda sordist $t-1$, siis on laual ka *rangelt* enam kui $k^2$ auhinda sordist $t$.

## Alamülesanded ja hindamine

Mõnedes testides kasutatakse adaptiivset hindamist.
See tähendab, et nendes testides pole auhindade järjestus alati fikseeritud.
Selle asemel võivad vastused sõltuda sellest, milliseid küsimusi sinu lahendus küsib.
On teada, et vastused on alati sellised, et kõik vastused on kooskõlas seni esitatud küsimustega.

1. (20 punkti) Meil on täpselt $1$ teemant ja $n-1$ pulgakommi ($v = 2$).
Protseduuri `ask` võib välja kutsuda ülimalt $10\,000$ korda.
1. (80 points) Täiendavad piirangud puuduvad.

Teises alamülesandes võib saada osalise skoori.
Olgu $q$ kõigi testide seas maksimaalne arv protseduuri `ask` väljakutseid, mida su lahendus teeb.
Sel juhul saab punkte vastavalt järgmisele tabelile:

Küsimusi | Skoor
--- | ---
$10\,000 < q$ | $0$ (CMS ütleb 'Wrong Answer')
$6000 < q \leq 10\,000$ | $70$
$5000 < q \leq 6000$ | $80 - (q-5000)/100$
$q \leq 5000$ | $80$

## Näidistester

Näidistester ei ole adaptiivne.
Selle asemel kasutab see lihtsalt fikseeritud massiivi $p$ auhinnasordiga. Iga $0 \leq b \leq n-1$ puhul on auhinna sort karbis $b$ antud kui $p[b]$.
Näidistester loeb sisendit järgmises formaadis:

- line $1$: $\;\; n$
- line $2$: $\;\; p[0] \;\; p[1]  \; \ldots \; p[n-1]$

Näidistester kirjutab välja ühe rea, milles on protseduuri `find_best` tagastatud väärtus ja protseduuri `ask` väljakutsete arv.