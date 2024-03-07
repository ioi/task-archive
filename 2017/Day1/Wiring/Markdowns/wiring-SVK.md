# Kabeláž
Miriam, pracujúca u nemenovaného mobilného operátora, ktorý určite nesponzoruje OI, má navrhnúť novú kabeláž na jednom z GSM vysielačov. Na tomto vysielači je niekoľko konektorov, ktoré sú umiestnené v rôznych výškach. Konektory sú dvoch farieb: červené a modré. Miriam má k dispozícii káble, ktorými vie spájať dvojice týchto konektorov. Z jedného konektoru môže vychádzať ľubovoľné množstvo káblov.

Pre jednoduchosť si môžeme vysielač predstaviť ako polpriamku a konektory ako červené a modré body ležiace na tejto polpriamke, v celočíselných vzdialenostiach od jej začiatku. Dĺžka kábla spájajúceho dva konektory je rovná dĺžke úsečky medzi týmito dvoma bodmi.

Pomôžte Miriam navrhnúť pospájanie konektorov káblami tak, aby platilo:
1. Každý konektor bude spojený (priamo, jedným káblom) s aspoň jedným konektorom opačnej farby.
2. Celková dĺžka použítých káblov bude najmenšia možná.

## Implementačné detaily

Implementujte nasledovnú funkciu:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: pole veľkosti $n$, obsahujúce súradnice červených konektorov v rastúcom poradí.
* $b$: pole veľkosti $m$, obsahujúce súradnice modrých konektorov v rastúcom poradí.
* Táto funkcia vracia minimálnu celkovú dĺžku káblov, ktoré Miriam musí použiť.
* Všimnite si, že návratová hodnota tejto funkcie je `int64`.

## Príklad

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Nasledujúci obrázok ilustruje daný vstup.
![Wiring](wiring.png)

* Vysielač je zobrazený horizontálne.
* V čierno-bielej tlačenej verzii tohto zadania sú červené konektory tmavé a modré konektory svetlé.
* Na obrázku sú $4$ červené konektory, ktoré sú na pozíciach $1, 2, 3,$ a $7$.
* Na obrázku je $5$ modrých konektorov, ktoré sú na pozíciách $0, 4, 5, 9$, a $10$.
* Okrem toho je na obrázku znázornené aj jedno optimálne riešenie.
* Celková dĺžka káblov použitá v tomto riešení je $1 + 2 + 2 + 2 + 3 = 10$. Toto riešenie je optimálne.
Funkcia teda má vrátiť hodnotu $10$.
* Všimnite si, že z konektoru na pozícii $7$ vedú dva káble.

## Limity

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (pre všetky $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (pre všetky $0 \leq i \leq m-1$),
* Obe polia $r$ a $b$ sú usporiadané v rastúcom poradí.
* Všetkých $n+m$ hodnôt v poliach $r$ a $b$ je rôznych.

## Podúlohy

1. (7 bodov) $n, m \leq 200$,
1. (13 bodov) Všetky červené konektory majú súradnice menšie ako všetky modré konektory.
1. (10 bodov) Medzi ľubovolnými $7$-imi po sebe idúcimi konektormi sa nachádza aspoň jeden červený a aspoň jeden modrý konektor.
1. (25 bodov) Všetky konektory majú rôzne súradnice z rozsahu $[1, n+m]$.
1. (45 bodov) Žiadne dodatočné obmedzenia.

## Ukážkový grader

Ukážkový grader načíta vstup v nasledovnom formáte:
* riadok $1$: $\;\; n \;\; m$
* riadok $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* riadok $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Ukážkový grader vypíše jediný riadok obsahujúci návratovú hodnotu funkcie `min_total_length`.