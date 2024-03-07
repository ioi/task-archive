# Wiring

Maryam este inginer.
Ea vrea să contruiască un turn de comunicație. Turnul conține multe puncte de conectare plasate la diferite inaltimi. Un cablu poate fi folosit pentru a conecta oricare două puncte de conectare. Toate punctele de conetare pot fi conectate cu un număr arbitrar de cabluri. Sunt doua tipuri de cabluri: roșii si albastre.

In corcondanta cu scopul acestei probleme, turnul poate fi văzut ca o linie, iar punctele de conetare albastre si roșii ca puncte pe aceasta linie având coordonate intregi ne-negative. Lungimea unui cablu este distanța dintre cele doua puncte pe care le unește.

Scopul vostru este de a o ajuta pe Maryam pentru a găsi o schema de cablare astfel încât:
1. Fiecare punct de conetare are cel puțin un cablu către o culoare diferită.
1. Lungimea totala a cablurilor este minima.

## Detalii de Implementare

Se cere implementarea următoarei proceduri:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: șir de lungime $n$ conținând pozițiile punctelor de conectare roșii in ordine crescătoare.
* $b$: șir de lungime $m$ conținând pozițiile punctelor de conectare albastre in ordine crescătoare.
* Aceasta procedura va returna valoarea minima a lungimii totale a cablurilor, dintre toate schemele valide de cablare.
* Observați ca numărul ce se va returna prin aceasta procedura este de tip `int64`.

## Exemplu

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

In imaginea care urmează aveți un exemplu.
![Wiring](wiring.png)

* Turnul este reprezentat pe orizontală.
* Pe versiunea printată in alb-negru punctele închise la culoare reprezinta punctele de conectare roșii, iar cele deschise reprezintă punctele de conectare albastre.
* Avem $4$ puncte de conectare de culoare roșie localizate pe pozițiile $1, 2, 3,$ și $7$.
* Avem $5$ puncte de conectare de culoare albastra localizate pe pozițiile $0, 4, 5, 9,$ și $10$.
* O soluție optima este arătată in imaginea de mai sus.
* In aceasta soluție lungimea totala a cablurilor este $1 + 2 + 2 + 2 + 3 = 10$, ceea ce este optim. Deci procedura va returna $10$.
* Observați, că două cabluri sunt conectate la punctul de conectare în poziția $7$.

## Restricții și precizări

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (pentru $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (pentru $0 \leq i \leq m-1$),
* fiecare din șirurile $r$ și $b$ este sortat în ordine crescătoare.
* Toate cele $n+m$ valori din șirurile $r$ și $b$ sunt distincte.

## Subtask-uri
1. (7 puncte) $n, m \leq 200$,
1. (13 puncte) Toate punctele de conectare de culoare roșie au poziții mai mici decât toate punctele de conectare de culoare albastră.
1. (10 puncte) Există cel puțin un punct de conectare de culoare roșie și cel puțin un punct de conectare de culoare albastră printre oricare $7$ puncte de conectare consecutive.
1. (25 puncte) Toate punctele de conectare au poziții distincte în intervalul $[1, n+m]$.
1. (45 puncte) Fără restricții suplimentare.

## Evaluator local

Evaluatorul local citește datele din input în următorul  format:
* linia $1$: $\;\; n \;\; m$
* linia $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* linia $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Evaluatorul afișează o singură linie, care conține  valoarea returnată de  `min_total_length`.
