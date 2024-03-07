# Rotaļu dzelzceļš

Arzo un viņas brālis Borzo ir dvīņi. Dzimšanas dienā dvīņiem ir uzdāvināts rotaļu dzelzceļš, kuru izmantojot, viņi ir izveidojuši dzelzceļa sistēmu, kas satāv no $n$ stacijām un $m$ *vienvirziena* sliežu ceļiem.
Stacijas ir numurētas ar skaitļiem no $0$ līdz $n-1$.
Katrs sliežu ceļš sākas un beidzas kādā stacijā. Iespējams, ka sliežu ceļš beidzas tajā pašā stacijā, kurā sākas.
Katrā stacijā sākas vismaz viens sliežu ceļš.

Dažas no stacijām ir *uzlādes stacijas*. Kad vilciens ierodas uzlādes stacijā, tas tiek pilnībā uzlādēts - tā enerģijas pietiek $n$ secīgu sliežu ceļu veikšanai. Tas ir, pēc pēdējās uzlādes vilciens pilnībā izlādējas tad, kad iebrauc pēc kārtas $(n+1)$-ajā sliežu ceļā.

Katrā stacijā ir pārmijas, kuras var pārslēgt uz jebkuru sliežu ceļu, kas sākas šajā stacijā. Kad vilciens atrodas kādā stacijā un brauc prom no tās, tas izmanto sliežu ceļu, uz kuru ir pārslēgtas šīs stacijas pārmijas.

Dvīņi ir nolēmuši spēlēt spēli, izmantojot vienu vilcienu. Spēles sākumā tiek noteikti visu staciju īpašnieki - katra stacija pieder vai nu Arzo vai Borzo.
Spēles sākumā vilciens atrodas stacijā $s$ un ir pilnībā uzlādēts. Lai sāktu spēli, stacijas $s$ īpašnieks pārslēdz stacijas $s$ pārmijas uz kādu no sliežu ceļiem, kas sākas stacijā $s$. Pēc tam dvīņi ieslēdz vilcienu, un tas sāk kustību pa sliežu ceļiem.

Kad vilciens kādā stacijā ierodas pirmoreiz, stacijas īpašnieks pārslēdz šīs stacijas pārmijas. Kad pārmijas ir pārslēgtas, to stāvoklis saglabājas līdz spēles beigām. Tādejādi, ja vilciens iebrauks stacijā kurā jau kādreiz ir bijis, tas no šīs stacijas izbrauks pa to pašu sliežu ceļu kā iepriekš.

Tā kā staciju skaits ir galīgs, vilciens nonāks *ciklā*.
Cikls ir *atšķirīgu* staciju $c[0], c[1], \cdots, c[k-1]$ virkne, kurā vilciens no stacijas $c[i]$ (visiem $0 \leq i < k-1$) dodas pa sliežu ceļu uz staciju $c[i+1]$, un no stacijas $c[k-1]$ - uz staciju $c[0]$.
Ievērojiet, ka ciklu var veidot arī viena pati stacija (t.i., ja $k=1$) ja vilciens no stacijas $c[0]$ pa sliežu ceļu dodas uz to pašu $c[0]$.

Arzo spēlē uzvar, ja vilciens kustību turpina bezgalīgi, bet Borzo - ja vilciens pilnībā izlādējas.
Citiem vārdiem, ja starp stacijām $c[0], c[1], \cdots, c[k-1]$ ir kāda uzlādes stacija, tad vilciens var uzlādēties un cikloties bezgalīgi ilgi, un Arzo uzvar.
Pretējā gadījumā vilciens kādā brīdī pilnībā izlādēsies (iespējams pēc vairāku ciklu veikšanas), un uzvarēs Borzo.

Jums ir dots dzelzceļa sistēmas apraksts. Arzo un Borzo spēlēs spēli $n$ reizes.
$s$-tajā reizē (kur $0 \leq s \leq n-1$) vilciens spēles sākumā atradīsies stacijā $s$.

Jums katrai spēlēšanas reizei nepieciešams noteikt, vai Arzo eksistē stratēģija, kas garantē viņas uzvaru neatkarīgi no tā, kā spēlēs Borzo.

## Realizācijas noteikumi

Jums jārealizē procedūra

```
int[] who_wins(int[] a, int[] r, int[] u, int[] v)
```

* $a$: masīvs garumā $n$. Ja stacija $i$ pieder Arzo, tad $a[i] = 1$, bet, ja stacija $i$ pieder Borzo, tad $a[i] = 0$.
* $r$: masīvs garumā $n$. Ja stacija $i$ ir uzlādes stacija, $r[i] =1$. Pretējā gadījumā, $r[i] = 0$.
* $u$ un $v$: masīvi garumā $m$.
Visiem $i$ ($0 \leq i \leq m-1$) ir vienvirziena sliežu ceļš, kas sākas stacijā $u[i]$ un beidzas stacijā $v[i]$.
* Procedūrai jāatgriež masīvs $w$ garumā $n$.
$w[i]$ vērtībai visiem $i$ ($0 \leq i \leq n-1$) jābūt $1$, ja Arzo var uzvarēt spēli, kas sākas stacijā $i$, neatkarīgi no tā, kā spēlēs Borzo. Pretējā gadījumā $w[i]$ vērtībai jābūt $0$.

## Piemērs

```
who_wins([0, 1], [1, 0], [0, 0, 1, 1], [0, 1, 0, 1])
```

![Train](train.png)

* Ir $2$ stacijas.
Borzo pieder stacija $0$, kas ir uzlādes stacija.
Arzo pieder stacija $1$, kas nav uzlādes stacija.
* Ir $4$ sliežu ceļi $(0, 0), (0, 1), (1, 0)$, un $(1, 1)$, kur $(i, j)$ apzīmē vienvirziena sliežu ceļu no stacijas $i$ uz staciju $j$.
* Aplūkosim spēli, kurā vilciens sākumā atrodas stacijā $0$.
Ja Borzo stacijā $0$ pārslēdz pārmijas uz sliežu ceļu $(0, 0)$, vilciens bezgalīgi ilgi brauks pa šo ciklu (ievērojiet, ka $0$ ir uzlādes stacija).
Šajā gadījumā Arzo uzvar.
Bet, ja Borzo stacijā $0$ pārslēdz pārmijas uz sliežu ceļu $(0, 1)$, tad Arzo var pārslēgt pārmijas stacijā $1$ uz sliežu ceļu $(1, 0)$. Tad vilciens bezgalīgi ilgi brauks pa ciklu cauri abām stacijām, un atkal uzvarēs Arzo, jo $0$ ir uzlādes stacija un vilciens neapstāsies. Tādejādi, Arzo var spēli uzvarēt neatkarīgi no tā, ko darīs Borzo.
* Spriežot līdzīgi, ja spēle sāksies stacijā $1$, Arzo varēs uzvarēt neatkarīgi no tā, kā spēlēs Borzo. Tāpēc procedūrai jāatgriež $[1, 1]$.

## Ierobežojumi

* $1 \leq n \leq 5000$.
* $n \leq m \leq 20\,000$.
* Ir vismaz viena uzlādes stacija.
* Katrā stacijā sākas vismaz viens sliežu ceļš.
* Var būt sliežu ceļš, kas sākas un beidzas tajā pašā stacijā (t.i., $u[i] = v[i]$).
* Visi sliežu ceļi ir atšķirīgi.
Citiem vārdiem, nav divu tādu indeksu $i$ un $j$ ($0 \leq i < j \leq m-1$), ka $u[i]=u[j]$ un $v[i]=v[j]$.
* $0 \leq u[i], v[i] \leq n-1$ (visiem $0 \leq i \leq m-1$).

## Apakšuzdevumi

1. (5 punkti) Visiem $i$($0 \leq i \leq m-1$), vai nu $v[i] = u[i]$, vai arī $v[i] = u[i] + 1$.
1. (10 punkti) $n \leq 15$.
1. (11 punkti) Arzo pieder visas stacijas.
1. (11 punkti) Borzo pieder visas stacijas.
1. (12 punkti) Ir tieši viena uzlādes stacija.
1. (51 punkts) Bez papildus ierobežojumiem.

## Paraugtestētājs

Paraugtestētājs lasa šāda formāta ievaddatus:
* $1$. rinda: $\;\; n \;\; m$
* $2$. rinda: $\;\; a[0] \;\; a[1] \; \ldots\; a[n-1]$
* $3$. rinda: $\;\; r[0] \;\; r[1] \; \ldots\; r[n-1]$
* $4 + i$-tā rinda (for $0 \leq i \leq m-1$): $\;\; u[i] \;\; v[i]$

Paraugtestētājs izdrukā `who_wins` atgriežamo vērtību šādā formātā:
* $1$. rinda: $\;\; w[0] \;\; w[1] \; \ldots\; w[n-1]$
