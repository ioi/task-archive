# Bludisko
Pri príprave posledného sústredenia dostal Emo nápad na dokonalú hru na dnu. Zoberie všetkých $k$ účastníkov a nechá ich schovávať sa v obrovskom bludisku. Len nejak nedomyslel, že vytvoriť vhodné bludisko vôbec nie je také jednoduché.

Emo sa rozhodol postaviť bludisko v spoločenskej miestnosti. V nej sa však na rôznych miestach nachádzajú stĺpy, čo stavbu bludiska výrazne sťažuje. Spoločenskú si môžete predstaviť ako mriežku veľkosti $m \times n$. Každé políčko tejto mriežky je buď voľné alebo zatarasené stĺpom. Na zatarasené políčko sa pochopiteľne nedá postaviť. Dve políčka sú susedné ak majú spoločnú stranu. Každé políčko má teda najviac štyroch susedov -- dvoch vodorovne a dvoch zvisle.

Emo sa rozhodol vyrobiť bludisko tak, že zatarasí niektoré ďalšie políčka stoličkami. Avšak na to, aby jeho hra fungovala, potrebuje bludisko so špeciálnou vlastnosťou: Pre každú dvojicu políčok $a$ a $b$, ktoré ostanú voľné, musí platiť, že v bludisku existuje práve jedna *cesta*, ktorá ich spája. Pod pojmom cesta samozrejme chápeme postupnosť voľných políčok začínajúcu na políčku $a$ a končiacu na políčku $b$, v ktorej sa políčka neopakujú a každé dve za sebou idúce políčka spolu susedia.

Na začiatku hry chce Emo umiestniť každého účastníka na políčko, ktoré je voľné a má **práve** jedného voľného suseda. Samozrejme, na každé políčko môže dať najviac jedného účastníka.

Pomôžte Emovi rozmiestniť stoličky v spoločenskej tak, aby vytvoril platné bludisko, do ktorého vie dať čo najviac účastníkov. Počet stoličiek v chate je neobmedzený.

## Implementačné detaily
V tejto úlohe odovdzávate iba výstupy. Za každý výstup môžete získať aj čiastočné body.

Dostanete $10$ vstupných súborov, každý popisuje pôvodný vzhľad spoločenskej. Vašou úlohou je pre každý vstup vytvoriť výstup obsahujúci vzniknuté bludisko. Za každý výstup získavate body samostatne. Tento počet bodov závisí od toho, koľko účastníkov bude vedieť Emo umiestniť do vášho bludiska.

V tejto úlohe neodovzdávajte zdrojový kód svojho programu.

## Vstup
Každý vstupný súbor obsahuje popis spoločenskej, v ktorej Emo stavia svoje bludisko a tiež počet účastníkov sústredenia -- číslo $k$. Formát vstupu je nasledovný:
* prvý riadok vstupu: $\;\; m \;\; n \;\; k$
* $(1+i)$-ty riadok vstupu (pre $1 \leq i \leq m$): popis $i$-teho riadku mriežky, čiže reťazec dĺžky $n$, ktorý obsahuje nasledovné znaky:
  - '`.`': voľné políčko,
  - '`#`': políčko zatarasené stĺpom.

## Výstup
* $i$-ty riadok výstupu (pre $1 \leq i \leq m$): popis $i$-teho riadku bludiska, čiže reťazec dĺžky $n$, ktorý obsahuje nasledovné znaky:
  -  '`.`': voľné políčko,
  -  '`#`': políčko zatarasené stĺpom,
  -  '`X`': políčko, ktoré Emo zatarasil stoličkou. (Vypisujte veľké písmeno X.)

## Limity
* $1 \leq m, n \leq 1024$

## Bodovanie

Výstup považujeme za *správny* ak spĺňa nasledovné podmienky:
* Mapa na výstupe sa zhoduje s mapou na vstupe, akurát ľubovoľne veľa znakov '`.`' vstupnej mapy (možno aj nula) bolo nahradených znakmi '`X`' (políčka so stoličkami).
* Výstupná mapa spĺňa podmienku bludiska zo zadania.

Ak je váš výstup nesprávny, výsledný počet bodov za daný test bude $0$. V opačnom prípade získate $\min(10, 10 \cdot l/k)$ bodov, tieto body budú zaokrúhlené nadol na dve desatinné miesta. Hodnota $l$ je počet účastníkov, ktorých môže Emo do vami vytvoreného bludiska umiestniť a $k$ je počet účastníkov sústredenia. Za daný vstup získate 10 bodov vtedy, keď vytvoríte bludisko, v ktorom vie Emo umiestniť aspoň $k$ účastníkov. Pre každý vstup existuje riešenie, ktoré získa 10 bodov.

V prípade, že je váš výstup správny, ale vypočítaný počet bodov je $0$, výsledok testovania v CMS bude 'Wrong Answer'.

## Príklad

Zoberme si nasledovný vstup:

```
4 5 5
....#
.#..#
...#.
....#
```

Jeden z možných výstupov môže vyzerať nasledovne:

```
.X.X#
.#..#
...#X
XX..#
```

Keďže Emo vie do bludiska umiestniť $l=4$ deti, takéto riešenie by získalo $10 \cdot 4 / 5 = 8$ bodov. Miesta, na ktoré vie Emo dať účastníkov sú v nasledovnom obrázku označené znakom `O`:


```
OXOX#
.#.O#
...#X
XX.O#
```

Nasledujúce tri výstupy **nie sú** správne:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

V ľavom výstupe neexistuje cesta medzi ľavým horným políčkom a voľným políčkom v najpravšom stĺpci. V nasledovných dvoch výstupoch zase existujú medzi každými dvoma voľnými políčkami práve dve cesty.