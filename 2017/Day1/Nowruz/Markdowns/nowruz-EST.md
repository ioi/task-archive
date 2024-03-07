# Nowruz

Mõne päeva pärast tuleb Nowruz (Pärsia uus aasta) ning vanaisa kutsus kogu perekonda endale külla. Külaliste seas on $k$ last. Selleks et laste jaoks kokkutulek lõbusam oleks, soovib vanaisa korraldada neile peitusemängu oma aias.

Vanaisa aeda võib vaadelda $m \times n$ ruudustikuna. Mõned (võib-olla ka mitte ükski) ruudud on blokeeritud kividega. Ülejäänud ruutusid nimetame *vabadeks*. Kaks ruutu nimetame naabriks, kui nendel on ühine serv (seega igal ruudul võib olla kuni neli naabrit: kaks horisontaalselt ning kaks vertikaalselt).

Vanaisa tahab oma aia teisendada labürindiks. Selleks tuleb tal blokeerida mõned vabad ruudud, istutades sinna põõsad. Põõsaga ruut poleks enam vaba.

Lõpus peab saadud labürint rahuldama järgmist omadust: iga kahe vaba ruudu $a$ ja $b$ vahel peab leiduma täpselt üks *lihttee*. *Lihttee* $a$ ja $b$ vahel on selline vabade ruutude jada, kus esimene ruut on $a$, viimane $b$, kõik ruudud on erinevad ning iga kaks järjestikust ruutu on naabrid.

Laps võib peituda ruudus siis ja ainult siis, kui see ruut on vaba ning omab *täpselt üht* vaba naabrit. Kaks last ei saa peituda ühes ja samas ruudus.

Sul on antud sisendina aia kaart. Ülesandeks on aidata vanaisal luua labürint, milles saaks ennast peita võimalikult palju lapsi.

## Tehnilised detailid

See on ainult väljundi-põhine (output-only) ülesanne osalise hindamisega.
Antud on $10$ sisendfaili, igaüks kirjeldab vanaisa aeda kaardina. Iga sisendfaili jaoks tuleb esitada väljundfail vastava labürindi kaardiga. Iga väljundfaili jaoks antakse punkte vastavalt sellele, mitu last saavad ennast esitatud labürindis peita.

Lähtekoodi selles ülesandes esitama ei pea.

## Sisend

Iga sisendfail kirjeldab ühte ruudustiku (mis esitab aeda), ning annab ette ka külla kutsutud laste arvu $k$. Faili formaat on järgmine:
* rida $1$: $\;\; m \;\; n \;\; k$
* rida $1+i$ (kus $1 \leq i \leq m$): ruudustiku $i$-s rida, antud $n$-tähelise sõnena ilma tühikuteta. Sõnes võivad olla kasutatud järgnevad tähed:
  - '`.`': vaba ruut,
  - '`#`': kiviga ruut.

## Väljund

* rida $i$ (kus $1 \leq i \leq m$): vastava labürindi $i$-s rida, antud $n$-tähelise sõnena ilma tühikuteta. Sõnes võivad olla kasutatud järgnevad tähed:
  -  '`.`': vaba ruut,
  -  '`#`': kiviga ruut,
  -  '`X`': põõsas. (Pange tähele et X on suur täht.)

## Piirangud

* $1 \leq m, n \leq 1024$

## Hindamine

Väljundfail loetakse *korrektseks*, kui kõik järgmised tingimused on täidetud:
* Väljastatud kaart peab olema sisendkaardiga sama, kui välja arvata see, et mõni (suvaline) hulk '`.`' -tähega ruutusid sisendkaardis võivad olla teisendatud täheks '`X`' (need on põõsadega blokeeritud ruudud).
* Väljastatud kaart peab rahuldama püstituses kirjeldatud *labürindi* omadust.

Juhul kui mõne testi jaoks ei ole väljund korrektne, on vastava testi skooriks $0$. Muidu on testi skoor $\min(10, 10 \cdot l/k)$ punkti, ümardatud alla kahe komakohani.
Siin $l$ tähistab laste arvu, kes ennast pakutud labürindis peita saavad, ning $k$ on sisendis antud laste arv.
Test saab seega maksimumskoori ($10$ punkti) siis ja ainult siis kui väljastatud labürindis saavad ennast peita vähemalt $k$ last.
Iga testi jaoks eksisteerib vähemalt üks $10$-punktine lahendus.

Pane tähele, et kui lahendus on korrektne kuid saab $0$ punkti ülaltoodud valemi järgi, siis väljastab CMS vastava tulemuse kirjelduseks ikkagi teksti 'Wrong Answer'.

## Näide

Vaatleme järgmist näidet:

```
4 5 5
....#
.#..#
...#.
....#
```

All on üks võimalik korrektne vastus:

```
.X.X#
.#..#
...#X
XX..#
```

Kuna selles labürindis saab ennast peita $l=4$ last, on lahenduse skooriks $10 \cdot 4 / 5 = 8$ punkti. Ruudud, kus lapsed saavad ennast peita, on märgistatud tähega `O` all:


```
OXOX#
.#.O#
...#X
XX.O#
```

Järgnevad kolm väljundit pole korrektsed:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

Vasakpoolses ruudustikus ei eksisteeri lihtteed paremas veerus asuva ruudu ja suvalise teise vaba ruudu vahel. Kahes teises ruudustikus leidub iga kahe erineva vaba ruudu vahel täpselt kaks erinevat lihtteed.