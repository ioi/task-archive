# Novrūzs

Ir atlikušas dažas dienas līdz Novrūzam (Persiešu jaunajam gadam), un vectēvs ir ielūdzis ģimeni uz savu dārzu.
Viesu starpā ir $k$ bērni.
Lai kopā sanākšanu bērniem padarītu vēl interesantāku, vectēvs plāno dārzā organizēt paslēpes.

Dārzu var uztvert kā $m \times n$ rūtiņu laukumu.
Dažas (iespējams nevienu) rūtiņu aizņem klints bluķi, bet atlikušās rūtiņas ir *tukšas*.
Divas rūtiņas sauc par *kaimiņiem*, ja tām ir kopīga mala. Tas nozīmē, ka katrai rūtiņai ir ne vairāk kā 4 kaimiņi: divi horizontālā virzienā un divi - vertikālā. Vectēvs vēlas dārzā izveidot labirintu. Lai to paveiktu, viņš dažās brīvās rūtiņās var iestādīt krūmus. Rūtiņas, kurās ir iestādīti krūmi, vairs nav tukšas.

Labirintam jāpiemīt noteiktām īpašībām. Katram labirinta tukšo rūtiņu pārim $a$ un $b$ ir jābūt tieši vienam *vienkāršam ceļam* starp tām.
Vienkāršs ceļš starp rūtiņām $a$ un $b$ ir secīgu tukšo rūtiņu virkne, kurā 1. rūtiņa ir $a$, un pēdējā rūtiņa ir $b$. Ceļā visas rūtiņas ir atšķirīgas, un katras divas secīgas rūtiņas ir kaimiņi.

Bērns var paslēpties rūtiņā tad un tikai tad, ja rūtiņa ir tukša, un tai ir *tieši* viena tukša kaimiņu rūtiņa. Katrā rūtiņā var paslēpties ne vairāk kā viens bērns.

Tev tiek dota dārza karte. Tavs uzdevums ir palīdzēt vectēvam izveidot labirintu, kurā var paslēpties daudzi bērni.

## Realizācijas noteikumi

Šis ir "tikai izvaddatu" uzdevums ar daļēju vērtēšanu. Tev tiek doti $10$ ieejas datu faili. Katrs fails apraksta vectēva dārzu. Katram ieejas failam ir jāiesniedz atbilstošs izejas fails ar labirinta karti. Par katru izvaddatu failu tu saņemsi punktus atkarībā no tā, cik bērni var paslēpties tavā labirintā.

Šim uzdevumam programmas kods nav jāiesniedz.

## Ievaddatu formāts

Katrā ievaddatu failā ir dots viena dārza laukuma apraksts un vectēva uzaicināto bērnu skaits $k$. Datu formāts ir šāds:
* $1$. rinda: $\;\; m \;\; n \;\; k$
* $1+i$-tā rinda ($1 \leq i \leq m$): laukuma $i$ rinda, kas ir simbolu virkne garumā $n$, kas satur šādus simbolus bez atstarpēm:
  - '`.`': tukša rūtiņa,
  - '`#`': klints bluķis.

## Izvaddatu formāts

* Izvaddatu $i$-tā rinda ($1 \leq i \leq m$) ir labirinta $i$-tā rinda pēc krūmu sastādīšanas. Tā ir simbolu virkne garumā $n$,kas satur šādus simbolus bez atstarpēm:
  -  '`.`': tukša rūtiņa,
  -  '`#`': klints bluķis,
  -  '`X`': krūmi. (Ņem vērā, ka simbols X ir lielais burts X.)

## Ierobežojumi

* $1 \leq m, n \leq 1024$

## Vērtēšana

Izejas fails tiek uzskatītas par *derīgu*, ja visi šie nosacījumi ir spēkā:
* Izvaddatu kartei jāatbilst ievaddatu kartei ar vienu vienīgu izņēmumu, kad nenoteikts daudzums simbolu '`.`' ievaddatu kartē ir aizstāti ar simboliem '`X`' (rūtiņas ir aizņemtas ar krūmiem).
* Izvaddatu kartei ir jāatbilst tādam labirintam, kāds ir definēts uzdevuma aprakstā.

Ja tavi testa izvaddati nebūs derīgi, rezultāts par šo testa piemēru būs $0$.
Citādi rezultāts būs $\min(10, 10 \cdot l/k)$ punkti, noapaļots uz leju līdz 2 cipariem pēc komata.
Šeit $l$ ir bērnu skaits, kas var paslēpties tevis izveidotajā labirintā, un $k$ ir ievaddatos dotais bērnu skaits.
Tu iegūsi $10$ punktus par testu tad un tikai tad, ja tavi izvaddati atbildīs labirintam, kurā var paslēpties $k$ vai vairāk bērni.
Katram testam eksistē risinājums, kurā var iegūt $10$ punktus.

Ņem vērā, ka, ja tavs risinājums būs derīgs, bet, balstoties uz augstākminēto formulu, tu iegūsi $0$ punktus, CMS tu redzēsi rezultātu 'Wrong Answer'.

## Piemērs

Aplūkosim šādus ievaddatus:

```
4 5 5
....#
.#..#
...#.
....#
```

Viens derīgs izvaddatu piemērs:

```
.X.X#
.#..#
...#X
XX..#
```

Tā kā šajā labirintā var paslēpties $l=4$ bērni, šis risinājums saņems $10 \cdot 4 / 5 = 8$ punktus. Nākamajā piemērā rūtiņas, kurās var paslēpties bērni, ir apzīmētas ar `O`:


```
OXOX#
.#.O#
...#X
XX.O#
```

Trīs nākamie izvaddatu piemēri nav derīgi:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

Pa kreisi esošajā piemērā nav vienkārša ceļa starp tukšo rūtiņu augšējā kreisajā stūrī un tukšo rūtiņu pašā labējā kolonnā.
Abos pārējos piemēros katram tukšo rūtiņu pārim ir divi vienkārši ceļi starp tām.