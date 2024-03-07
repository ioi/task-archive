 # Vláčik

Anička a jej brat Bob dostali na Vianoce magnificentnú súpravu hračkárskych vláčikov.
Hneď sa pustili do stavania a postavili železničnú sieť s $n$ stanicami a $m$ *jednosmernými* úsekmi koľajníc. Stanice si očíslovali od $0$ po $n-1$. Každý úsek koľajnice vychádza z nejakej stanice a končí v nejakej (možno tej istej) stanici. Z každej stanice vychádza aspoň jeden úsek.

Niektoré stanice sú *nabíjacie*. Vždy, keď vláčik príde na nabíjaciu stanicu, nabije sa na maximum. Plne nabitý vláčik má dosť energie na to, aby prešiel $n$ po sebe idúcich úsekov trate. V momente, keď vstúpi do $(n+1)$-vého úseku od posledného nabíjania, dôjde mu baterka a zastaví.

Pri východe z každej stanice je výhybka, ktorá sa dá nastaviť na ľubovoľný úsek koľajníc vychádzajúci z tejto stanice. Vláčik odcházajúci zo stanice odíde po koľaji, na ktorú je výhybka práve nastavená.

Po dostavaní železničnej siete si deti medzi sebou rozdelili jednotlivé stanice: každá stanica je teraz buď Aničkina alebo Bobova. Následne sa rozhodli zahrať si s vláčikom nasledovnú hru:

Počas celej hry je na železnici jediný vláčik. Vláčik začína plne nabitý na stanici $s$.
Na začiatku hry vlastník stanice $s$ nastaví výhybku na tejto stanici. Následne zapnú vláčik a ten sa začne hýbať po koľajniciach.

Vždy, keď vláčik navštívi nejakú stanicu prvýkrát, majiteľ tejto stanice v nej nastaví výhybku. Od tohto momentu sa už touto výhybkou až do konca hry nehýbe.
To znamená, že ak vlak znovu navštívi túto stanicu, odíde z nej po rovnakej koľaji ako minule.

Keďže počet staníc je konečný, vlak sa po nejakom čase dostane do *cyklu*. Cyklus je postupnosť rôznych staníc $c[0], c[1], \cdots, c[k-1]$ taká, že zo stanice $c[i]$ (pre $0 \leq i < k-1$) odíde vlak po koľaji vedúcej do stanice $c[i+1]$ a zo stanice $c[k-1]$ odíde do stanice $c[0]$. Počet staníc $k$ v cykle môže byť aj $1$, ak vlak odchádza zo stanice $c[0]$ po koľaji vedúcej späť do stanice $c[0]$.

Anička vyhrá, ak bude vláčik chodiť po železnici donekonečna. Bob vyhrá, ak sa vláčik vybije a zastane. Inými slovami, keď vláčik zacyklia, zaujíma nás, či sa v cykle nachádza nejaká nabíjacia stanica. Ak áno, vyhrá Anička, lebo každým prechodom stanice sa vláčik dostatočne nabije. Ak nie, vyhrá Bob, lebo časom (možno po niekoľkých prechodoch celým cyklom) sa vláčik určite vybije.

Dostanete popis železnice. Anička a Bob budú hrať $n$ samostatných hier. V $s$-tej z nich (pre $0 \leq s \leq n-1$) bude vláčik začínať v stanici $s$. Vašou úlohou bude pre každú hru zistiť, či pre Aničku existuje stratégia, pomocou ktorej zaručene vyhrá (bez ohľadu na to, ako hrá Bob).

## Implementačné detaily

Implementujte nasledovnú funkciu:

```
int[] who_wins(int[] a, int[] r, int[] u, int[] v)
```

* $a$: pole dĺžky $n$. Ak stanica číslo $i$ patrí Aničke, $a[i] = 1$. Ak patrí Bobovi, $a[i] = 0$.
* $r$: pole dĺžky $n$. Ak je stanica $i$ nabíjacia, $r[i] =1$, inak $r[i] = 0$.
* $u$ a $v$: polia dĺžky $m$.
Pre všetky $0 \leq i \leq m-1$ existuje jednosmerný úsek koľajníc idúci zo stanice $u[i]$ do stanice $v[i]$.
* Táto funkcia má vrátiť pole $w$ dĺžky $n$.
Pre každé $0 \leq i \leq n-1$, hodnota $w[i]$ má byť:
  * $1$ ak v hre začínajúcej na stanici $i$ existuje víťazná stratégia pre Aničku
  * $0$ v opačnom prípade

## Príklad

```
who_wins([0, 1], [1, 0], [0, 0, 1, 1], [0, 1, 0, 1])
```

![Train](train.png)

* V železničnej sieti sú $2$ stanice. Bob vlastní stanicu $0$, ktorá je nabíjacia. Anička má stanicu $1$, ktorá nie je nabíjacia.
* V sieti sú $4$ úseky koľajníc $(0, 0)$, $(0, 1)$, $(1, 0)$ a $(1, 1)$, kde $(i, j)$ znamená úsek vedúci zo stanice $i$ do
stanice $j$.
* V nultej hre vláčik začína na stanici $0$. Ak Bob nastaví výhybku na úsek $(0, 0)$, vlak sa bude donekonečna cykliť na tomto úseku. Všimnite si, že stanica $0$ je nabíjacia, takže mu nikdy nedôjde šťava, a teda Anička vyhrá. Ak Bob nastaví výhybku na úsek $(0, 1)$, Anička môže
nastaviť výhybku v stanici $1$ na úsek $(1, 0)$. Vláčik sa potom bude donekonečna cykliť cez obe stanice, keďže v stanici $0$ sa bude nabíjať. Aj v tomto prípade teda vyhrá Anička. Ukázali sme teda, že Anička dôkáže vyhrať bez ohľadu na to, ako hrá Bob.
* V prvej hre vláčik začína na stanici $1$. Aj túto hru dokáže Anička za každých okolností vyhrať (analýza prípadov vyzerá podobne). To znamená,
že funkcia má vrátiť pole $[1, 1]$.

## Obmedzenia
* $1 \leq n \leq 5000$.
* $n \leq m \leq 20\,000$.
* Existuje aspoň jedna nabíjacia stanica.
* Z každej stanice vychádza aspoň jeden úsek trate.
* Môžu existovať úseky, ktoré vedú do tej istej stanice, z ktorej vychádzajú (t. j. $u[i] = v[i]$).
* Každý úsek trate je iný, t. j. neexistujú dva indexy $i, j$ ($0 \leq i < j \leq m-1$) také, že $u[i] = u[j]$ a $v[i] = v[j]$.
* $0 \leq u[i], v[i] \leq n-1$ (pre všetky $0 \leq i \leq m-1$).

## Podúlohy

1. (5 bodov) Pre všetky $0 \leq i \leq m-1$ platí buď $v[i] = u[i]$, alebo $v[i] = u[i] + 1$.
2. (10 bodov) $n \leq 15$.
3. (11 bodov) Anička vlastní všetky stanice.
4. (11 bodov) Bob vlastní všetky stanice.
5. (12 bodov) Existuje práve jedna nabíjacia stanica.
6. (51 bodov) Žiadne ďalšie obmedzenia.

## Ukážkový grader

Ukážkový grader číta vstup v nasledovnom formáte:
* riadok $1$: $\;\; n \;\; m$
* riadok $2$: $\;\; a[0] \;\; a[1] \; \ldots\; a[n-1]$
* riadok $3$: $\;\; r[0] \;\; r[1] \; \ldots\; r[n-1]$
* riadok $4 + i$ (pre $0 \leq i \leq m-1$): $\;\; u[i] \;\; v[i]$

Ukážkový grader vypíše pole vrátené funkciou `who_wins` v nasledovnom formáte:
* riadok $1$: $\;\; w[0] \;\; w[1] \; \ldots\; w[n-1]$

