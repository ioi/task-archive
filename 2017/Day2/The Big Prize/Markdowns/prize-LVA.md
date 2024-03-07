# Lielā balva

"Lielā balva" ir populārs TV šovs. Tu esi laimīgais dalībnieks, kurš ticis finālā un stāv $n$ kastu rindas priekšā. Kastes ir numurētas no $0$ līdz $n-1$ no kreisās uz labo pusi. Katrā kastē ir balva, kas nav redzama līdz pat kastes atvēršanai. Ir $v$ ($v \geq 2$) *veidu* balvas. Balvu veidi ir numurēti no $1$ līdz $v$ *dilstošā* balvu vērtību secībā.

Visdārgākā ir 1. veida balva – dimants. Visās kastēs kopā ir tikai viens dimants. Vislētākā ir $v$-tā veida balva – konfekte. Lai spēli padarītu aizraujošāku, lēto balvu skaits ir daudz lielāks nekā dārgo balvu skaits. Konkrētāk, par visiem $t$ ($2 \leq t \leq v$) ir zināms, ka, ja $t-1$ veida balvu skaits ir $k$, tad $t$-tā veida balvu skaits *noteikti ir vairāk* nekā $k^2$.

Tavs mērķis ir iegūt dimantu. Spēles beigās tev būs jāatver viena kaste, un tu saņemsi tajā esošo balvu. Pirms izvēles izdarīšanas, kuru kasti atvērt, tev ir iespēja televīzijas šova vadītājam Rambodam uzdot dažus jautājumus. Katru jautājumu tu uzdod par kādu kasti $i$. Kā atbildi Rambods tev dos divu veselu skaitļu masīvu $a$. Skaitļu nozīme ir šāda:
* Pa kreisi no kastes $i$ ir tieši $a[0]$ kastes, kurās balvas ir dārgākas nekā kastē $i$.
* Pa labi no kastes $i$ ir tieši $a[1]$ kastes, kurās balvas ir dārgākas nekā kastē $i$.

Piemēram, $n=8$, tu izvēlies jautāt par kasti $i=2$, un Rambods tev atbild, ka $a=[1,2]$.
Šīs atbildes nozīme ir šāda:
* Tieši vienā no 2 pirmajām kastēm ($0$. vai $1$.) atrodas par $2$. kastē esošo vērtīgāka balva.
* Tieši divās no 5 pēdējām kastēm ($3., 4., 5., 6., 7.$) atrodas par $2$. kastē esošo vērtīgāka balva.

Tavs uzdevums ir atrast kasti ar dimantu, izmantojot nelielu skaitu jautājumu.

## Realizācijas noteikumi

Tev jārealizē procedūra:

```
int find_best(int n)
```

* $n$: kastu skaits.
* Šai procedūrai jāatgriež tās kastes numurs, kurā atrodas dimants, tas ir, tāds vesels skaitlis $d$ ($0 \leq d \leq n-1$), lai $d$-tajā kastē būtu $1$. veida balva.

Iepriekš minētā procedūra spēj izsaukt procedūru:

```
int[] ask(int i)
```

* $i$: kastes numurs, par kuru tu vēlies saņemt atbildi. $i$ vērtībai jābūt robežās starp $0$ un $n-1$, ieskaitot.
* Šī procedūra atgriež divu elementu masīvu $a$, kur $a[0]$ ir dārgāku balvu skaits kastēs pa kreisi no $i$-tās kastes, un $a[1]$ ir dārgāku balvu skaits kastēs pa labi no $i$-tās kastes.


## Piemērs

Vērtētājs veic šādu procedūras izsaukumu:

```
find_best(8)
```

Ir $n=8$ kastes. Pieņemsim, balvu veidi ir $[3,2,3,1,3,3,2,3]$.
Visi iespējamie procedūras `ask` izsaukumi un atbilstošās atgriežamās vērtības ir dotas zemāk.

- `ask(0)` returns $[0, 3]$
- `ask(1)` returns $[0, 1]$
- `ask(2)` returns $[1, 2]$
- `ask(3)` returns $[0, 0]$
- `ask(4)` returns $[2, 1]$
- `ask(5)` returns $[2, 1]$
- `ask(6)` returns $[1, 0]$
- `ask(7)` returns $[3, 0]$

Šajā piemērā dimants ir $3$. kastē. Tātad procedūrai `find_best` ir jāatgriež skaitlis $3$.

![Prize1](prize.png "600") 

Šo piemēru ilustrē augstāk esošais attēls.
Augšējā daļa attēlo balvas vērtību katrā kastē.
Apakšējā daļa ilustrē vaicājumu `ask(2)`.
Ar ķeksīti atzīmētajās kastēs ir balvas, kas ir dārgākas par $2$. kastē esošo balvu.

## Ierobežojumi

* $3 \leq n \leq 200\,000$.
* Kastēs esošo balvu veidi ir robežās no $1$ līdz $v$, ieskaitot.
* Ir tieši viena $1$. veida balva.
* Visiem $t$ ($2 \leq t \leq v$), ja $t-1$ veida balvu ir $k$, tad $t$-tā veida balvu *noteikti* ir vairāk nekā $k^2$.

## Apakšuzdevumi un vērtēšana

Dažos testpiemēros vērtētājs pielāgojas – tam nav noteiktas balvu secības. Šajos testpiemēros vērtētāja sniegtās atbildes var būt atkarīgas no tava risinājuma uzdotajiem jautājumiem. Tiek garantēts, ka vērtētājs atbild tādā veidā, ka pēc katras atbildes ir vismaz viena balvu virkne, kas atbilst visām iepriekš uzdotajām atbildēm.

1. (20 punkti) Ir tieši $1$ dimants un $n-1$ konfektes (tādēļ $v = 2$). Tu drīksti izsaukt procedūru `ask` ne vairāk kā $10\,000$ reižu.
1. (80 punkti) Bez papildu ierobežojumiem.

Otrajā apakšuzdevumā tu vari iegūt daļēju vērtējumu. Ar $q$ apzīmēsim maksimālo procedūras `ask` izsaukumu skaitu kopā visos šī apakšuzdevuma testpiemēros. Tad šī apakšuzdevuma punktu skaits tev tiks rēķināts, balstoties uz šādu tabulu:

Jautājumi | Punktu skaits
--- | ---
$10\,000 < q$ | $0$ (CMS ziņojums 'Wrong Answer')
$6000 < q \leq 10\,000$ | $70$
$5000 < q \leq 6000$ | $80 - (q-5000)/100$
$q \leq 5000$ | $80$

## Paraugvērtētājs

Paraugvērtētājs nav pielāgoties spējīgs.
Tā vietā tas tikai lasa un izmanto fiksētu balvu veidu masīvu $p$. Visiem $b$ ($0 \leq b \leq n-1$) balvas veids kastē $b$ ir $p[b]$. Paraugvērtētājs ievaddatus sagaida šādā formātā:

- $1$. rinda: $\;\; n$
- $2$. rinda: $\;\; p[0] \;\; p[1]  \; \ldots \; p[n-1]$

Paraugvērtētājs izvada vienu rindu, kurā ir procedūras `find_best` rezultāts un procedūras `ask` izsaukumu skaits.