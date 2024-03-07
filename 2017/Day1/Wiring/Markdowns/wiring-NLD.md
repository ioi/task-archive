IOI 2017 Translation

    NLD
# Wiring
Maryam is een electricien.
Ze maakt een ontwerp voor de bedrading van een communicatietoren.
Op de toren bevinden zich contacten, geplaatst op verschillende hoogtes.
Een draad kan twee contacten met elkaar verbinden. Elk contact kan met een willekeurig aantal draden verbonden zijn. Er zijn twee soorten contacten: rood en blauw.

In deze opgave beschouwen we de toren als een lijn, en zijn de rode en blauwe contacten niet-negatieve integer coördinaten op deze lijn.
De lengte van een draad is de afstand tussen de twee contacten die de draad verbindt.

Help Maryam een aansluitingsschema te bepalen waarbij: 
1. Elk contact minimaal één draad heeft die het contact verbindt met een contact van een andere kleur
2. De totale lengte van de draden minimaal is.

## Implementatiedetails
Implementeer de volgende functie:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: een array van lengte $n$ met de posities van de rode contacten, in oplopende volgorde.
* $b$: een array van lengte $m$ met de posities van de blauwe contacten, in oplopende volgorde.
* De functie moet de minimale totale lengte van de draden retourneren van alle geldige aansluitschema's.
* Let op dat een `int64` moet worden geretourneerd.

## Voorbeeld

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Bekijk de afbeelding hieronder.
![Wiring](wiring.png)

* De toren wordt horizontaal weergegeven.
* In de zwart-wit afgedrukte versie van de opdracht zijn de rode contacten donker, en de blauwe contacten licht gekleurd.
* Er zijn $4$ rode contacten, op coördinaten $1, 2, 3,$ en $7$.
* Er zijn $5$ blauwe contacten, op coördinaten $0, 4, 5, 9,$ en $10$.
* Een optimale oplossing zie je in het plaatje hierboven.
* Bij deze oplossing is de totale lengte van de draden  $1 + 2 + 2 + 2 + 3 = 10$, en dat is optimaal. Dus de functie moet $10$ retourneren.
* Let op dat twee draden zijn verbonden met het contact op positie $7$.

## Randvoorwaarden

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (voor alle $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (voor alle $0 \leq i \leq m-1$),
* Beide arrays $r$ en $b$ zijn gesorteerd in oplopende volgorde.
* Alle $n+m$ waarden in de arrays $r$ en $b$ zijn verschillend.

## Subtasks

1. (7 punten) $n, m \leq 200$,
1. (13 punten) Alle rode contacten hebben posities kleiner dan elk van de blauwe contacten.
1. (10 punten) Er is minstens een rood contact en een blauw contact onder elke $7$ opeenvolgende aansluitpunten.
1. (25 punten) Alle contacten hebben een unieke coördinaat in het domein $[1, n+m]$.
1. (45 punten) Geen verdere beperkingen.

## Voorbeeldgrader

De voorbeeldgrader leest de input op de volgende manier:
* regel $1$: $\;\; n \;\; m$
* regel $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* regel $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

De voorbeeldgrader drukt een enkele regel af met de geretourneerde waarde van `min_total_length`.
