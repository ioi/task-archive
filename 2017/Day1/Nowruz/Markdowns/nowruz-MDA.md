  # Nowruz

Au rămas doar câteva zile până la Nowruz (Anul Nou persan) și bunicul a invitat întreaga familie la o petrecere în grădina sa.
Printre invitați sunt și $k$ copii.
Pentru a face petrecerea mai distractivă pentru copii bunicul vrea să organizeze o joacă de-a v-ați ascunselea.

Grădina este reprezentată printr-o matrice $m \times n$ de celule unitare.
Unele celule (posibil nici una) sunt blocate de pietre, iar celelalte celule se numesc *libere*.
Două celule se numesc *vecine* dacă au o latură comună.
Astfel, fiecare celulă poate avea până la patru vecini: doi pe orizontală și doi pe verticală.
Bunicul dorește să transforme grădina într-un labirint.
În acest scop el poate bloca unele celule libere plantând în ele arbuști.
Celulele în care au fost plantați arbuști nu mai sunt libere.

Labirintul trebuie să posede următoarea proprietate: pentru fiecare pereche de celule libere $a$ și $b$ în labirint va exista un *drum simplu* unic, care să le unească.
Un drum simplu între celulele $a$ și $b$ este o secvență de celule libere în care prima celulă este $a$, ultima - $b$, toate celulele sunt distincte și  fiecare două celule consecutive sunt vecine.

Un copil se poate ascunde într-o celulă dacă și numai dacă celula este liberă și are *exact* un vecin liber. Nu se pot ascunde doi sau mai mulți copii în aceeași celulă.

Se dă harta grădinii. Se cere ajutarea bunicului în realizarea unui labirint în care să se ascundă cât mai mulți copii.

## Particularități de implementare

Aceasta este o problemă tip output-only cu scoruri parțiale.
Primiți $10$ fișiere de intrare, fiecare dintre ele descriind o grădină a bunicului.
Pentru fiecare fișier de intrare trebuie să submitați un fișier de ieșire, care să conțină o hartă a labirintului. Pentru fiecare fișier de ieșire veți primi puncte în funcție de numărul de copii, care se pot ascunde în labirintul vostru.

Nu trebuie să submitați nici o sursă pentru această problemă.

## Format Input

Fiecare fișier de intrare va descrie o matrice reprezentând grădina și numărul de copii $k$ invitați de bunic. Formatul fișierului este următorul:
* linia $1$: $\;\; m \;\; n \;\; k$
* linia $1+i$ (pentru $1 \leq i \leq m$): linia $i$ a matricei, formată dintr-un șir de caractere de lungime $n$, format din următoarele caractere (fără spații):
  - '`.`': o celulă liberă,
  - '`#`': piatră.

## Format Output 

* linia $i$ (pentru $1 \leq i \leq m$): linia $i$ a labirintului (grădinii, după plantarea arbuștilor). Este un șir de caractere de lungime $n$,  format din următoarele caractere (fără spații):
  -  '`.`': o celulă liberă,
  -  '`#`': piatră,
  -  '`X`': arbust. (De remarcat că litera X trebuie să fie majusculă.)

## Restricții

* $1 \leq m, n \leq 1024$

## Punctaje

Fișierul output se consideră a fi *valid* dacă respectă toate condițiile următoare:
* Harta de ieșire va coincide cu harta de intrare cu unica excepție că un număr arbitrar de caractere '`.`' din harta de intrare pot fi transformate în caractere '`X`' (celule blocate cu arbuști).
* Harta de ieșire va avea proprietatea de labirint, după cum acesta a fost definit în enunțul problemei.

Dacă fișierul output pentru un test nu va fi valid, scorul acordat pentru acest test va fi  $0$.
În caz contrar, scorul va fi calculat ca $\min(10, 10 \cdot l/k)$ puncte, trunchiat până la două cifre zecimale după virgulă.
Aici, $l$ este numărul copiilor care se pot ascunde în labirintul submitat, $k$ fiind numărul dat în fișierul de intrare.
Veți primi câte $10$ puncte doar pentru acele teste în care harta de ieșire le va permite să se ascundă la  $k$ sau mai mulți copii.
Pentru fiecare test există o soluție care permite acordarea a $10$ puncte.

De menționat, că în cazul în care aveți o soluție validă dar care acumulează puncte $0$ conform formulei de mai sus, mesajul evaluatorului afișat în CMS va fi 'Wrong Answer'.

## Exemplu

Considerăm următorul input:

```
4 5 5
....#
.#..#
...#.
....#
```

Mai jos este prezentat un posibil output valid:

```
.X.X#
.#..#
...#X
XX..#
```

Deoarece $l=4$ copii se pot ascunde în acest labirint, soluția va primi $10 \cdot 4 / 5 = 8$ puncte. Celulele în care se ascund copiii sunt marcate mai jos cu `O` :


```
OXOX#
.#.O#
...#X
XX.O#
```

Următoarele trei output-uri nu sunt valide:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

În output-ul din stânga nu există un drum simplu între celula liberă din colțul stâng-sus și celula liberă din cea mai de dreapta coloană.
În celelalte două output-uri, pentru fiecare pereche de celule libere distincte există exact câte două drumuri simple diferite, care le unesc.