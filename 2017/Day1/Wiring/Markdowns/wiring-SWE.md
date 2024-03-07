# Kabeldragning
Maryam är en elingenjör.
Hon designar kabeldragning på ett kommunikationstorn.
På tornet finns det ett antal anslutningspunkter, placerade på parvis olika höjder.
En kabel kan användas för att ansluta vilka två anslutningspunkter som helst.
Varje anslutningspunkt kan ha godtyckligt många kablar anslutna.
Det finns två sorters anslutningspunkter: röda och blå.

I detta problem kan du se tornet som en tallinje, och anslutningspunkterna som röda och blå punkter på icke-negativa heltalspunkter på tallinjen.
Längden av en kabel är avståndet mellan de två anslutningspunkterna som kabeln ansluter.

Ditt mål är att hjälpa Maryam att hitta ett kopplingsschema för kablarna sådant att:
1. Varje anslutningspunkt kopplas med minst en kabel till en anslutningspunkt av  annan färg.
2. Summan av alla kablars längder är så liten som möjligt.

## Intrikat implementationsinformation
Du ska implementera följande procedur:
```
int64 min_total_length(int[] r, int[] b)
```

* $r$: array av längd $n$ innehållandes positionerna för de röda anslutningspunkterna, i ökande ordning.
* $b$: array av längd $m$ innehållandes positionerna för de blå anslutningspunkterna, i ökande ordning.
* Proceduren ska returnera den minsta möjliga summan av alla använda kablars längder, över alla giltiga kopplingsscheman.
* Notera att procedurens returtyp är `int64`.

## Exempelexekvering

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Figuren nedan illustrerar detta exempel.
![Wiring](wiring.png)

* Tallinjen som representerar tornet visas här horisontell.
* I den svart-vita utskrivna versionen av problemet är de röda anslutningspunkterna mörka, och de blå anslutningspunkterna ljusa.
* Det finns $4$ röda anslutningspunkter, placerade på positionerna $1, 2, 3,$ och $7$.
* Det finns $5$ blå anslutningspunkter, placerade på positionerna $0, 4, 5, 9,$ och $10$.
* En möjlig optimal lösning visas i figuren ovan.
* I denna lösning är den totala summan av alla kablars längder $1 + 2 + 2 + 2 + 3 = 10$, vilket är minsta möjliga.
Proceduren ska därmed returnera $10$.
* Notera att två kablar är anslutna till anslutningspunkten på position $7$.

## Gränser

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (för alla $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (för alla $0 \leq i \leq m-1$),
* Både array $r$ och $b$ är sorterad i stigande ordning.
* Alla $n+m$ värden i arrayerna $r$ och $b$ är parvis olika.

## Delproblem

1. (7 poäng) $n, m \leq 200$,
1. (13 poäng) Alla röda anslutningspunkter har positioner som är mindre än alla blå.
1. (10 poäng) I varje mängd av $7$ konsekutiva anslutningspunkter kommer det finnas minst en röd och minst en blå anslutningspunkt.
1. (25 poäng) Alla anslutningspunkter har parvis olika positioner i intervallet $[1, n+m]$.
1. (45 poäng) Inga ytterligare gränser.

## Exempeldomare
Exempeldomaren läser indata på följande format:
* rad $1$: $\;\; n \;\; m$
* rad $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* rad $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Exempeldomaren skriver ut ett enda tal innehållandes returvärdet från `min_total_length`.
<div style="margin-top:-1em"></div>