# Elektroinstalācija

Marjama ir elektroinženiere, kas projektē komunikāciju torņa elektrinstalāciju.
Tornim ir vairāki savienojuma punkti, kas izvietoti atšķirīgos augstumos.
Vads var savienot jebkurus divus savienojuma punktus.
Katrs savienojuma punkts var būt savienots ar patvaļīgu skaitu vadu.
Ir divi savienojuma punktu tipi: sarkans un zils.

Šajā uzdevumā torni var uzskatīt kā taisnes nogriezni, bet savienojuma punktus - kā sarkanus un zilus punktus ar veselām nenegatīvām koordinātām uz šī nogriežņa. Vada garums ir attālums starp punktiem, ko šis vads savieno.

Jūsu mērķis ir palīdzēt Marjamai atrast tādu elektroinstalācijas shēmu, kurā:
1. Katram savienojuma punktam ir pievienots vismaz viens vads, kura otrs gals ir savienojuma punktā ar atšķirīgu krāsu.
1. Visu vadu kopējais garums ir mazākais iespējamais.

## Realizācijas noteikumi

Jums jārealizē procedūra

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: masīvs garumā $n$, kas satur sarkano savienojuma punktu koordinātas augošā secībā.
* $b$: masīvs garumā $m$, kas satur zilo savienojuma punktu koordinātas augošā secībā.
* Procedūrai jāatgriež mazākais iespējamais vadu kopgarums derīgā elektroinstalācijas shēmā.
* Ievērojiet, ka atgriežamās vērtības tips ir `int64`.

## Piemērs

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Zīmējumā ilustrēts šis piemērs:
![Wiring](wiring.png)

* Tornis ir parādīts horizontāli.
* Melnbaltajā izdrukā sarkanie savienojuma punkti ir tumši, bet zilie - gaiši.
* Ir $4$ sarkanie savienojuma punkti, kas atrodas punktos $1, 2, 3,$ un $7$.
* Ir $5$ zilie savienojuma punkti, kas atrodas punktos $0, 4, 5, 9,$ un $10$.
* Viens no optimāliem risinājumiem ir parādīts zīmējumā.
* Šajā risinājumā vadu kopgarums ir $1 + 2 + 2 + 2 + 3 = 10$, kas ir mazākais iespējamais.
Tāpēc procedūrai jāatgriež vērtība $10$.
* Ievērojiet, ka divi vadi ir pievienoti savienojuma punktam ar koordinātu $7$.

## Ierobežojumi

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (visiem $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (visiem $0 \leq i \leq m-1$),
* Masīvi $r$ un $b$ ir sakārtoti augošā secībā.
* Visas $n+m$ masīvu $r$ un $b$ vērtības ir atšķirīgas.

## Apakšuzdevumi

1. (7 punkti) $n, m \leq 200$,
1. (13 punkti) Visu sarkano savienojuma punktu koordinātas ir mazākas par jebkura zilā savienojuma punkta koordinātām.
1. (10 punkti) Starp jebkuriem  $7$ secīgiem savienojuma punktiem ir vismaz viens sarkans un vismaz viens zils savienojuma punkts.
1. (25 punkti) Visiem savienojuma punktiem ir atšķirīgas vērtības segmentā $[1, n+m]$.
1. (45 punkti) Bez papildus ierobežojumiem.

## Paraugtestētājs

Paraugtestētājs ielasa datus šādā formātā:
* $1$. rinda: $\;\; n \;\; m$
* $2$. rinda: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* $3$. rinda: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Paraugtestētāja vienīgajā izvadītajā rindā ir `min_total_length` atgrieztā vērtība.