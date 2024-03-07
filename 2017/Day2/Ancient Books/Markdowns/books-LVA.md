# Senās grāmatas

 Teherāna ir Irānas Nacionālās bibliotēkas mājvieta. Bibliotēkas lielākie dārgumi ir izvietoti garā telpā uz $n$ galdiem, kas sanumurēti no $0$ līdz $n-1$ sākot no kreisās puses uz labo. Uz katra galda atrodas sena, ar roku rakstīta grāmata. Šīs grāmatas ir sakārtotas pēc vecuma. Tas apgrūtina grāmatu atrašanu pēc nosaukuma. Bibliotēkas vadītājs ir izlēmis pārkārtot  grāmatas alfabētiski pēc to nosaukumiem.

Šis darbs ir jāpaveic bibliotēkas darbiniekam Ariānam. Viņš ir izveidojis sarakstu $p$ garumā $n$, kas satur atšķirīgus veselus skaitļus no $0$ līdz $n-1$.
Šis saraksts apraksta izmaiņas, kādas nepieciešamas, lai pārkārtotu grāmatas alfabētiskā secībā $-$
visiem $i$ ($0 \leq i < n$) grāmata, kas šobrīd atrodas uz $i$-tā galda, jāpārvieto uz galdu $p[i]$.

Ariāns sāk grāmatu kārtošanu ar galdu $s$ un pēc darba pabeigšanas vēlas atgriezties pie šī galda. Tā kā grāmatas ir ļoti vērtīgas, viņš nedrīkst vienlaicīgi pārvietot vairāk kā vienu grāmatu. Grāmatu pārkārtošanas laikā Ariāns veiks viņam atļautu darbību virkni. 
Ariānam atļautās darbības ir šādas:
* Ja viņš nenes grāmatu, un uz galda, pie kura viņš atrodas, ir grāmata, viņš šo grāmatu drīkst paņemt.
* Ja viņš nes grāmatu, un uz galda, pie kura viņš atrodas, ir cita grāmata, tad viņš šīs grāmatas drīkst samainīt.
* Ja viņš nes grāmatu, un galds, pie kura viņš atrodas, ir tukšs, viņš nesto grāmatu drīkst nolikt uz galda.
* Viņš var doties pie jebkura galda. To darot, Ariāns drīkst nest vienu grāmatu. 

Visiem $i$ ($0 \leq i, j \leq n - 1$) attālums starp galdiem $i$ un $j$ ir tieši $|j-i|$ metri. Jūsu uzdevums ir aprēķināt mazāko kopējo attālumu, kāds Ariānam jānoiet, lai sakārtotu visas grāmatas.

## Realizācijas noteikumi

Jums jārealizē procedūra:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ ir masīvs garumā $n$. Grāmata, kas sākumā ir uz $i$-tā galda, Ariānam jāaiznes uz $p[i]$-to galdu visiem $i$ ($0 \leq i < n$).
* $s$ ir tā galda numurs, pie kura Ariāns atrodas sākumā, un pie tā viņam ir jāatgriežas pēc visu grāmatu sakārtošanas.
* Šai procedūrai jāatgriež mazākais kopgarums metros, kāds Ariānam ir jānoiet, lai sakārtotu visas grāmatas.

## Piemērs

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

Šajā piemērā $n=4$, un Ariāns sākumā atrodas pie $0$-tā galda.
Viņš grāmatas sakārto šādi:
* viņš dodas pie galda $1$ un paņem grāmatu, kas atrodas uz tā. Šī grāmata jānoliek uz galda $2$.
* tad viņš dodas pie galda $2$ un samaina atnesto grāmatu pret grāmatu uz galda. Paņemtā grāmata jānoliek uz galda $3$.
* tad viņš dodas pie galda $3$ and samaina atnesto grāmatu pret grāmatu uz galda. Paņemtā grāmata jānoliek uz galda $1$.
* tad viņš dodas pie galda $1$ un noliek atnesto grāmatu uz tā.
* Visbeidzot, viņš dodas atpakaļ pie galda $0$.

Ievērojiet, ka galda $0$ grāmata jau atrodas pareizā vietā $-$ uz galda $0$, tāpēc Ariānam tā nav jāaiztiek. Šajā risinājumā viņš būs nogājis $6$ metrus. Tā kā šis risinājums ir optimāls, procedūrai jāatgriež skaitlis $6$.

## Ierobežojumi

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* Masīvs $p$ satur $n$ atšķirīgus veselus skaitļus starp $0$ un $n-1$, ieskaitot.

## Apakšuzdevumi

1. (12 punkti) $n \le 4$ un $s = 0$
1. (10 punkti) $n \le 1000$ un $s = 0$
1. (28 punkti) $s = 0$
1. (20 punkti) $n \le 1000$
1. (30 punkti) bez papildu ierobežojumiem

## Paraugvērtētājs

 Paraugvērtētājs lasa ievaddatus formātā

- $1$. rinda: $\;\; n \;\; s$
- $2$. rinda: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

 Paraugvērtētājs vienīgajā rindā izdrukā  `minimum_walk` atgriežamo vērtību.
