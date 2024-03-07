# Velika nagrada

Velika nagrada je slavna TV oddaja.
Si srečni tekmovalec, ki se je prebil v finale.
Stojiš pred $n$ škatlami, označenimi s števili od $0$ do $n-1$ v naraščajočem vrstnem redu od leve proti desni.
Vsaka škatla ima v sebi skrito nagrado, ki pa je ne poznamo, dokler je ne odpremo.
Obstaja $v \geq 2$ različnih *tipov* nagrad.
Tipi nagrad so označeni s števili od $1$ do $v$ v padajočem vrstnem redu, ki predstavljajo vrednost nagrade.

Nagrada tipa $1$ je najbolj vredna - diamant.
Samo v eni izmed škatel je diamant.
Nagrada tipa $v$ je vredna najmanj - lizika.
Da bi popestrili igro, je število manj vrednih nagrad večje od števila bolj vrednih nagrad.
Natančneje: za vse $t$, za katere velja $2 \leq t \leq v$, vemo sledeče:
Če je $k$ nagrad tipa $t-1$, je število nagrad tipa $t$ strogo večje od $k^2$.

Tvoja naloga je osvojiti diamant.
Na koncu igre boš moral odpreti škatlo in dobil boš njeno vsebino.
Preden izbereš škatlo, smeš vprašati Rambod, voditelja oddaje, nekaj vprašanj.
Pri vsakem vprašanju izbereš škatlo $i$.
Rambod ti odgovori s poljem $a$ dveh celih števil.
Njuna pomena sta sledeča:
* Med vsemi škatlami levo od škatle $i$ je natanko $a[0]$ škatel, ki vsebujejo bolj vredne nagrade od nagrade v škatli $i$.
* Med vsemi škatlami desno od škatle $i$ je natanko $a[1]$ škatel, ki vsebujejo bolj vredne nagrade od nagrade v škatli $i$.

Denimo, da $n=8$. Za vprašanje izbereš škatlo $i=2$.
Za odgovor prejmeš $a=[1,2]$.
Odgovor pomeni, da je:
* Natanko ena od škatel $0$ in $1$ vsebuje bolj vredno nagrado od nagrade v škatli $2$.
* Natanko dve škatli izmed škatel $3, 4, \ldots, 7$ vsebuje nagrado vrednejšo od nagrade v škatli $2$.

Tvoja naloga je, da najdeš škatlo z diamantom s pomočjo čim manjšega števila vprašanj.

## Podrobnosti implementacije

Implementirati moraš naslednjo funkcijo:

```
int find_best(int n)
```

* Ocenjevalnik to funkcijo pokliče le enkrat.
* $n$: število škatel.
* Funkcija naj vrne oznako škatlo škatle v kateri je diamant, t.j. edinstveno število<br> $d$ ($0 \leq d \leq n-1$), tako da škatla $d$ vsebuje nagrado tipa $1$.

Zgornja funkcija naj kliče naslednjo funkcijo:

```
int[] ask(int i)
```

* $i$: označuje škatlo, ki si jo izbral za vprašanje. Vrednost $i$ mora biti med vključno $0$ in $n-1$.
* Funkcija vrne polje $a$ dolžine $2$, kjer $a[0]$ predstavlja število bolj vrednih nagrad v škatlah levo od škatle $i$ in $a[1]$ predstavlja število bolj vrednih nagrad v škatlah desno od škatle $i$.


## Primer

Ocenjevalnik naredi sledeče klice:

```
find_best(8)
```

Imamo $n=8$ škatel. Denimo, da so tipi nagrad razporejeni kot $[3,2,3,1,3,3,2,3]$.
Vsi možni klici funkcije `ask` in njihove vrednosti so označene spodaj.

- `ask(0)` vrne $[0, 3]$
- `ask(1)` vrne $[0, 1]$
- `ask(2)` vrne $[1, 2]$
- `ask(3)` vrne $[0, 0]$
- `ask(4)` vrne $[2, 1]$
- `ask(5)` vrne $[2, 1]$
- `ask(6)` vrne $[1, 0]$
- `ask(7)` vrne $[3, 0]$

V tem primeru je diamant v škatli $3$. Torej naj funckija `find_best` vrne $3$.

![Prize1](prize.png "600") 

Zgornja skica prikazuje dan primer.
Zgornji del prikazuje tipe nagrad v vsaki škatli.
Spodnji del skice prikazuje poizvedbo `ask(2)`.
Označene škatle vsebujejo nagrade večje vrednosti od nagrade v škatli $2$.

## Omejitve

* $3 \leq n \leq 200\,000$.
* Tipi nagrad v škatlah so vključno med števili $1$ in $v$.
* Vedno je natanko ena nagrada tipa $1$.
* Za vse $2 \leq t \leq v$ velja, da če je $k$ nagrad tipa $t-1$, je nagrad tipa $t$ *strogo* več od $k^2$.

## Podnaloge in ocenjevanje

V nekaterih testnih primerih se ocenjevalnik sproti prilagaja.
To pomeni, da v teh testnih primerih ocenjevalnik nima vnaprej določenega zaporedja nagrad.
Namesto tega lahko odgovor ocenjevalnika zavisi od zastavljenih vprašanj tvoje rešitve.
Zagotovljeno je, da ocenjevalnik odgovarja tako, da vsaj eno zaporedje nagrad zadostuje prejšnjim odgovorom.

1. (20 točk) Obstaja natanko $1$ diamant in $n-1$ lizik (torej $v=2$).
Funkcijo `ask` lahko kličeš največ $10000$ krat.
1. (80 točk) Ni dodatnih omejitev.

V podnalogi 2 lahko dosežeš delne točke.
Denimo, da je $q$ največje možno število klicev funkcije `ask` med vsemi testnimi primeri pri tej podnalogi.
Točke so potlej izračunane po sledeči tabeli.

Vprašanja | Točke
--- | ---
$10\,000 < q$ | $0$ (CMS vrne 'Wrong Answer')
$6000 < q \leq 10\,000$ | $70$
$5000 < q \leq 6000$ | $80 - (q-5000)/100$
$q \leq 5000$ | $80$

## Vzorčni ocenjevalnik

Vzorčni ocenjevalnik se ne prilagaja vprašanjem tvoje rešitve.
Namesto tega le bere in uporablja vnaprej določeno polje $p$, ki predstavlja vrednosti nagrad. Za vse $0 \leq b \leq n-1$ je vrednost nagrade v škatli $b$ podana kot $p[b]$.
Vzorčni ocenjevalni bere vhod sledeče oblike:

- $1.$ vrstica: $\;\; n$
- $2.$ vrstica: $\;\; p[0] \;\; p[1]  \; \ldots \; p[n-1]$

Vzorčni ocenjevalnik izpiše eno samo vrstico, ki predstavlja vrnejno vrednost funkcije `find_best` in število klicev funkcije `ask`.