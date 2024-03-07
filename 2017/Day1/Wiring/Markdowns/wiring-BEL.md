# Bedrading (Wiring)

Maryam is electrotechnica.
Ze werkt aan een ontwerp voor de bedrading van een communicatietoren.
Op de toren bevinden zich een aantal contacten, geplaatst op verschillende hoogtes.
Een draad kan twee contacten met elkaar verbinden.
Elk contact kan met een willekeurig aantal draden verbonden zijn.
Er zijn twee soorten contacten: rood en blauw.

Voor dit probleem bekijken we de toren als een lijn en de contacten als blauwe en rode integer coördinaten ($\geq 0$) op deze lijn.
De lengte van een draad is de afstand tussen de twee contacten die hij verbindt.

Help Maryam een bedradingsschema te ontwerpen zodat: 
1. Elk contact minimaal één draad heeft die het contact verbindt met een contact van een andere kleur.
2. De totale lengte van de draden minimaal is.

## Implementatiedetails

Je moet de volgende functie implementeren:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: een array van lengte $n$ met de posities van de rode contacten, in oplopende volgorde.
* $b$: een array van lengte $m$ met de posities van de blauwe contacten, in oplopende volgorde.
* Deze functie moet de minimale totale lengte van de draden over alle mogelijke geldige bedradingsschema's teruggeven.
* Merk op dat de terugkeerwaarde van deze functie `int64` is.

## Voorbeeld

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Onderstaande afbeelding verduidelijkt dit voorbeeld.
![Wiring](wiring.png)

* De toren wordt horizontaal weergegeven.
* In de zwart-wit afgedrukte versie van de opdracht zijn de rode contacten donker en de blauwe contacten licht gekleurd.
* Er zijn $4$ rode contacten, op coördinaten $1, 2, 3,$ en $7$.
* Er zijn $5$ blauwe contacten, op coördinaten $0, 4, 5, 9,$ en $10$.
* Een optimale oplossing zie je in bovenstaande afbeelding.
* Bij deze oplossing is de totale lengte van de draden  $1 + 2 + 2 + 2 + 3 = 10$, en dat is optimaal. De functie moet dus $10$ teruggeven.
* Merk op dat twee draden zijn verbonden met het contact op positie $7$.

## Beperkingen

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (voor alle $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (voor alle $0 \leq i \leq m-1$),
* Beide arrays $r$ en $b$ zijn gesorteerd in oplopende volgorde.
* Alle $n+m$ waarden in de arrays $r$ en $b$ zijn verschillend.

## Subtaken

1. (7 punten) $n, m \leq 200$,
1. (13 punten) Alle rode contacten hebben posities kleiner dan elk van de blauwe contacten.
1. (10 punten) Er is minstens één rood contact en één blauw contact voor elke $7$ opeenvolgende contacten.
1. (25 punten) Alle contacten hebben een unieke positie in het interval $[1, n+m]$.
1. (45 punten) Geen verdere beperkingen.

## Voorbeeldgrader

The voorbeeldgrader leest de input in het volgende formaat:
* Lijn $1$: $\;\; n \;\; m$
* Lijn $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* Lijn $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

De voorbeeldgrader schrijft een enkele lijn uit met het resultaat van `min_total_length`.

