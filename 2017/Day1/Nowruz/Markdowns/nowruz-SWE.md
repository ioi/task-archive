# Nouruz

Det är några dagar till Nouruz (det persiska nyåret), och farfar har bjudit in släkten till sin trädgård.
Det finns $k$ barn bland gästerna.
För att göra tillställningen roligare före barnen, tänke farfar arrangera kurragömma.

Trädgården representeras av ett $m \times n$ rutnät av enhetsrutor. Några (möjligtvis inga) rutor är blockerade av stenar, och de kvarvarande rutorna kallas *fria*.
Två rutor är *grannar* om de delar en kant. 
D.v.s., varje ruta har upp till 4 grannar: två i horisontell riktning, och två i vertikal riktning.
Farfar vill göra om trädgården till en labyrint.
För att göra detta kan han blockera vissa fria rutor genom att plantera buskar i dem.
Rutorna som han planterar buskar i är inte längre fria.

En labyrint måste ha följande egenskap.
Mellan varje par av fria rutor $a$ och $b$ i labyrinten måste det finnas exakt en *enkel väg*.
En enkel väg mellan rutorna $a$ och $b$ är en sekvens av fria rutor som börjar med $a$, slutar med $b$, där alla rutor är olika och där rutor som kommer efter varandra är grannar.

Ett barn kan gömma sig i en ruta om och endast om rutan är fri och har *exakt* en fri granne.
Två barn kan inte gömma sig i samma ruta.

Du får en karta över trädgården som indata.
Din uppgift är att hjälpa farfar att skapa en labyrint som många barn kan gömma sig i.

## Intrikat implementationsinformation

Det här är en *uteslutande utdata*-uppgift med partiell poängsättning.
Du får $10$ indatafiler som vardera beskriver farfars trädgård.
För varje indatafil ska du skicka in en utdatafil med en karta över en labyrint.
För varje utdatafil får du poäng baserat på antalet barn som kan gömma sig i din labyrint.

Du förväntas inte skicka in någon källkod på det här problemet.

## Indatainläsning

Varje indatafil beskriver ett rutnät som beskriver en trädgård samt ger antal barn, $k$, som farfar har bjudit in. Formatet är:
* rad $1$: $\;\; m \;\; n \;\; k$
* rad $1+i$ (för $1 \leq i \leq m$): rad $i$ i rutnätet, en sträng av längd $n$ som består av följande tecken (utan något whitespace):
  - '`.`': en fri ruta,
  - '`#`': en sten.

## Utdatautskrift

* rad $i$ (för $1 \leq i \leq m$): rad $i$ i labyrinten (trädgården efter att buskar har planterats), n sträng av längd $n$ som består av följande tecken (utan något whitespace):
  -  '`.`': en fri ruta,
  -  '`#`': en sten,
  -  '`X`': en buske. (Notera att bokstaven X måste vara versal.)

## Gränser

* $1 \leq m, n \leq 1024$

## Poängsättning

En utdatafil är *giltig* om alla följande villkor möts:
* Utdatakartan matchar indatakartan med den enda skillnaden att godtyckligt många '`.`'-tecken i indatakartan kan ändras till '`X`'-tecken (rutor som blockeras av buskar).
* Utdatakartan måste beskriva en labyrint som definierad i problemlydelsen.

Om din utdatafil för ett testfall inte är giltig får du $0$ poäng för det testfallet.
Annars får du $\min(10, 10 \cdot l/k)$ poäng, avrundat nedåt till två decimaler.
Här är $l$ antalet barn som kan gömma sig i din labyrint och $k$ antalet inbjudna barn enligt indata.
Du får $10$ poäng för ett testfall endast om din utdata beskriver en labyrint där minst $k$ barn kan gömma sig.
För varje testfall finns en lösning som ger $10$ poäng.

Notera att om din lösningr är giltig men ändå ger $0$ poäng enligt formeln ovan kommer domslutet du ser i CMS att vara 'Wrong Answer'.

## Exempelexekvering

Betrakta följande indata:

```
4 5 5
....#
.#..#
...#.
....#
```

Nedan är en möjlig giltig utdata:

```
.X.X#
.#..#
...#X
XX..#
```

Eftersom $l=4$ barn kan gömma sig i den här labyrinten får den här lösningen $10 \cdot 4 / 5 = 8$ poäng. De rutor som barn kan gömma sig i är markerade med `O` nedan:

```
OXOX#
.#.O#
...#X
XX.O#
```

Följande tre utdata är inte giltiga:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#
```

I den vänstra utdatan finns ingen enkel väg mellan den fria rutan i det övre vänsta hörnet och den fria rutan i den högraste kolumnen.
I de två andra utdataexemplena finns det exakt två olika enkla vägar mellan varje par av olika fria rutor.
