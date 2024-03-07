# Lastgamla böcker
Tehran huserar Irans nationalbibliotek.
Biblioteketets huvudskatt är placerad i en lång korridor med en rad bestående av $n$ bord, etiketterade $0$ till och med $n - 1$ från vänster till höger.
Varje bord innehåller en lastgammal bok.
Böckerna är ordnade efter ålder, vilket gör det svårt för besökarna att hitta boken de söker.
Nationalbibliotekschefen har beslutat att böckerna istället ska sorteras i bokstavsordning.

Bibliotikarien Aryan ska göra jobbet. Han har skapat en lista $p$ av längd $n$ som innehåller parvis olika heltal från $0$ till $n - 1$. Listan beskriver ändringarna som behövs för att arrangera böckerna i bokstavsordning:
för varje $0 \le i < n$ ska boken som just nu finns på plats $i$ flyttas till plats $p[i]$.

Aryan börjar sorteringen på bord $s$. Han vill tillbaka hit efter att ha slutfört jobbet.
Eftersom böckerna är väldigt värdefulla kan han bära högst en bok åt gången. När han sorterar böckerna utför han en sekvens av handlingar, tagna av fyra möjliga:

- om han inte bär en bok och det finns en bok på bordet han är vid kan han plocka upp boken.
- om han bär en bok och det finns en annan bok på bordet han är vid kan han plats på de två böckerna.
- om han bär en bok och är vid ett tomt bort kan han lägga boken på bordet.
- han kan gå till vilket bort som helst, möjligtvis bärandesåp en bok.

För alla $0 \le i, j \le n - 1$ är avståndet mellan bord $i$ och $j$ exakt $|j - i|$ meter. Din uppgift är att hjälpa Aryan att sortera böckerna på ett sådant sätt att det totala avståndet han går blir så litet som möjligt.

## Implementation details

You should implement the following procedure:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ is an array of length $n$.
The book that is on table $i$ at the beginning should be taken by Aryan to table $p[i]$ (for all $0 \leq i < n$).
* $s$ is the label of the table where Aryan is at the beginning, and where he should be after sorting the books.
* This procedure should return the minimum total distance (in meters) Aryan has to walk in order to sort the books.

## Example

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

In this example, $n=4$ and Aryan is at table $0$ at the beginning.
He sorts the books as follows:
* Walks to table $1$ and picks up the book lying on it. This book should be put on table $2$.
* Then, he walks to table $2$ and switches the book he is carrying with the book on the table.
The new book he is carrying should be put on table $3$.
* Then, he walks to table $3$ and switches the book he is carrying with the book on the table.
The new book he is carrying should be put on table $1$.
* Then, he walks to table $1$ and puts the book he is carrying on the table.
* Finally, he walks back to table $0$.

Note that book on table $0$ is already in the correct place, table $0$, so Aryan does not have to pick it up.
The total distance he walks in this solution is $6$ meters.
This is the optimal solution; hence, the procedure should return $6$.

## Constraints

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* Array $p$ contains $n$ distinct integers between $0$ and $n-1$, inclusive.

## Subtasks

1. (12 points) $n \le 4$ and $s = 0$
1. (10 points) $n \le 1000$ and $s = 0$
1. (28 points) $s = 0$
1. (20 points) $n \le 1000$
1. (30 points) no additional constraints

## Sample grader

The sample grader reads the input in the following format:

- line $1$: $\;\; n \;\; s$
- line $2$: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

The sample grader prints a single line containing the return value of `minimum_walk`.
