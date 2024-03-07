# Ancient Books
In Teheran is de nationale Bibliotheek van Iran gevestigd.
De belangrijkste stukken van deze bibliotheek bevinden zich in een lange zaal met een rij van $n$ tafels, die van links naar rechts genummerd zijn van $0$ tot en met $n - 1$.
Op iedere tafel wordt een antiek handgeschreven boek tentoongesteld.
De boeken zijn gesorteerd op volgorde van ouderdom. Dit maakt het moeilijk maakt voor de bezoekers om te zoeken op titel.
Daarom heeft de bibliothecaris besloten om de boeken te sorteren op alfabetische volgorde van titel.

Aryan, een medewerker, gaat deze opdracht uitvoeren. Hij heeft een lijst $p$ gemaakt van lengte $n$, bevattende verschillende integers van $0$ tot en met $n - 1$.
Deze lijst beschrijft de veranderingen die nodig zijn om de boeken op alfabetische volgorde te leggen: voor alle $0 \leq i < n$, geldt dat het boek dat momenteel op tafel $i$ ligt verplaatst moet worden naar tafel $p[i]$.

Aryan begint de boeken te sorteren bij tafel $s$. Als hij klaar is met de opdracht wil hij weer terugkeren naar deze tafel.
Omdat de boeken heel kostbaar zijn, kan hij niet meer dan een boek tegelijkertijd dragen.
Tijdens het sorteren van de boeken voert Aryan een reeks van acties uit.
Elke actie moet één van de volgende zijn:
* Als hij geen boek draagt en er ligt een boek op de tafel waar hij staat, kan hij dat boek oppakken.
* Als hij een boek in zijn handen heeft en er ligt een ander boek op de tafel waar hij is, kan hij het boek verwisselen met het boek dat op die tafel ligt.
* Als hij een boek draagt en hij is bij een lege tafel, dan kan hij het boek daar neerleggen.
* Hij kan naar elke tafel wandelen wanneer hij dat wil. Hij mag een boek bij zich hebben terwijl hij loopt.

Voor alle $0 \leq i, j \leq n - 1$ is de afstand tussen de tafels $i$ en $j$ precies $|j-i|$ meter.
Jouw taak is om de minimale afstand uit te rekenen die Aryan moet afleggen om alle boeken te sorteren.
## Implementatiedetails

Implementeer de volgende functie:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ is een array van lengte $n$.
Het boek dat op tafel $i$ ligt moet door Aryan naar tafel $p[i]$ worden gebracht (voor alle $0 \leq i < n$).
* $s$ is het nummer van de tafel waar Aryan begint en waar hij moet eindigen na het sorteren van de boeken.
* Deze functie moet de minimale totale afstand (in meters) teruggeven die Aryan moet lopen om de boeken te sorteren.

## Voorbeeld

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

In dit voorbeeld geldt $n=4$ en Aryan begint bij tafel $0$.
Hij sorteert de boeken als volgt:
* Hij loopt naar tafel $1$ en pak het boek dat daar ligt. Dit boek moet naar tafel $2$ gebracht worden.
* Dan loopt hij naar tafel $2$ en verwisselt hij dit boek met het boek dat daar ligt.
Het nieuwe boek dat hij draagt moet naar tafel $3$ gebracht worden.
* Dan loopt hij naar tafel $3$ en verwisselt hij het boek met het boek dat daar ligt.
Het nieuwe boek dat hij nu vast heeft moet naar tafel $1$ gebracht worden.
* Dan loopt hij naar tafel $1$ en legt het boek daar op tafel.
* Tenslotte loopt hij terug naar tafel $0$.

Merk op dat het boek dat op tafel $0$ ligt al op de goede plaats is en dat Aryan het boek dus niet hoeft op te pakken.
De totale afstand die hij loopt in deze oplossing is $6$ meter.
Dit is de optimale oplossing, dus de functie moet $6$ retourneren.

## Randvoorwaarden

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* Array $p$ bevat $n$ verschillende integers van $0$ tot en met $n-1$.

## Deeltaken

1. (12 punten) $n \le 4$ en $s = 0$
1. (10 punten) $n \le 1000$ en $s = 0$
1. (28 punten) $s = 0$
1. (20 punten) $n \le 1000$
1. (30 punten) geen verdere randvoorwaarden

## Voorbeeldgrader

De voorbeeldgrader leest de invoer in het volgende formaat:

- regel $1$: $\;\; n \;\; s$
- regel $2$: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

De voorbeeldgrader drukt een enkele regel af met de waarde die `minimum_walk` heeft teruggegeven.
