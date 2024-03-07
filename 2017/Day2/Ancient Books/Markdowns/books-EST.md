# Vanad raamatud

Teheranis asub Iraani Rahvusraamatukogu.
Raamatukogu peamine kogu on pikas saalis, kus on $n$ lauast koosnev rida, laudadel on sildid $0$ kuni $n-1$ vasakult paremale.
Igal laual on üks vanaaegne käsitsi kirjutatud raamat.
Raamatud on vanuse järjekorras, mis tähendab, et neid on pealkirja alusel raske otsida.
Seega otsustab raamatukogu juhataja sorteerida raamatud hoopis pealkirjade järgi.

Raamatukoguhoidja Aryan peab selle töö ära tegema.
Ta on loonud nimekirja $p$ pikkusega $n$, milles on erinevad täisarvud $0$ kuni $n-1$.
Nimekirjas on muudatused, mida tuleb teha, et raamatud tähestiku järjekorda seada:
iga $0 \leq i < n$ jaoks tuleb raamat, mis on praegu laual $i$, viia lauale $p[i]$.

Aryan alustab raamatute sorteerimist laua $s$ juures.
Pärast kõigi raamatute sorteerimist tahab ta sama laua juurde tagasi tulla.
Kuna raamatud on väga väärtuslikud, ei saa ta korraga kätte võtta rohkem kui ühe raamatu.
Raamatute sorteerimisel teeb Aryan hulga liigutusi.
Iga liigutus on üks järgmistest:
* Kui tal ei ole raamatut käes ja tema juures oleval laual on raamat, võib ta selle raamatu üles võtta.
* Kui tal on raamat käes ja tema juures oleval laual on teine raamat, võib ta vahetada enda käes oleva raamatu laual oleva raamatu vastu.
* Kui tal on raamat käes ja tema juures olev laud on tühi, võib ta raamatu sellele lauale panna.
* Ta võib kõndida suvalise laua juurde. Kõndimise ajal võib tal üks raamat kaasas olla.

Iga $0 \leq i, j \leq n - 1$ puhul on laudade $i$ ja $j$ vaheline kaugus täpselt $|j-i|$ meetrit. Sinu ülesandeks on arvutada välja minimaalne vahemaa mida Aryan kõndima peaks selleks et raamatud niiviisi ära sorteerida.

## Tehnilised detailid

Sul tuleb kirjutada järgmine protseduur:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ on massiiv pikkusega $n$.
Aryan peab viima raamatu, mis on alguses laual $i$, lauale $p[i]$ (iga $0 \leq i < n$ puhul).
* $s$ on laud, mille ääres Aryan alguses on, ja kus ta peab töö lõpuks viibima.
* Protseduur peab tagastama minimaalse vahemaa (meetrites), mille Aryan peab raamatuid sorteerides maha kõndima.

## Näide

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

Selles näites on $n=4$ ja Aryan on alguses laua $0$ juures.
Ta sorteerib raamatuid järgmiselt:
* Läheb laua $1$ juurde ja võtab sealt raamatu. Raamat tuleb viia lauale $2$.
* Siis läheb ta laua $2$ juurde ja vahetab käes oleva raamatu laual oleva raamatu vastu.
Uus raamat tuleb viia lauale $3$.
* Siis läheb ta laua $3$ juurde ja vahetab käes oleva raamatu laual oleva raamatu vastu.
Uus raamat tuleb viia lauale $1$.
* Siis läheb ta laua $1$ juurde ja paneb käes oleva raamatu lauale.
* Lõpuks läheb ta tagasi laua $0$ juurde.

Pane tähele, et raamat laual $0$ on juba õiges kohas, laual $0$, nii et Aryan ei pea seda üles võtma.
Kogu vahemaa, mis tal tuleb kõndida, on $6$ meetrit.
See on optimaalne lahendus, seega peab protseduur tagastama $6$.

## Piirangud

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* Massiiv $p$ sisaldab $n$ erinevat täisarvu lõigust $0$ ja $n-1$.

## Alamülesanded

1. (12 punkti) $n \le 4$ and $s = 0$
1. (10 punkti) $n \le 1000$ and $s = 0$
1. (28 punkti) $s = 0$
1. (20 punkti) $n \le 1000$
1. (30 punkti) täiendavad piirangud puuduvad

## Näidistester

Näidistester loeb sisendit järgmises formaadis:

- rida $1$: $\;\; n \;\; s$
- rida $2$: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

Näidistester väljastab ühe täisarvu, mis on protseduuri `minimum_walk` tagastatud väärtus.
