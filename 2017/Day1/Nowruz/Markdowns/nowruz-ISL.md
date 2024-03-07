# Nowruz

Það eru nokkrir dagar í Nowruz (persnesku áramótin), og afi er búinn að bjóða
fjölskyldu sinni í garðinn sinn. Það eru $k$ krakkar á meðal gestanna. Til
að gera samkomuna skemmtilegri fyrir krakkana, þá ætlar afi að halda feluleik.

Garðinn er hægt að tákna sem $m \times n$ fylki af reitum. Sumir (mögulega
engir) reitir eru fullir af grjóti, en hinir reitirnir eru
<em>auðir</em>. Tveir reitir kallast <em>nágrannar</em> ef þeir hafa
sameiginlega hlið. Það er, hver reitur hefur allt að 4 nágranna: tvo lárétt, og
tvo lóðrétt. Afa langar að breyta garðinum sínum í völundarhús. Til að gera
það, þá getur hann gróðursett runna í einhverja af auðu reitunum. Reitirnir þar sem hann gróðursetur runna eru ekki lengur auðir.

Völundarhús verður að uppfylla eftirfarandi skilyrði.
Fyrir hvert par $a$ og $b$ af auðum reitum í völundarhúsinu þá verður að vera nákvæmlega ein *einföld leið* á milli þeirra.
Einföld leið á milli reita $a$ og $b$ er runa af auðum reitum þar sem fyrsti reiturinn er $a$, síðasti reiturinn er $b$, allir reitirnir eru mismunandi, og hverjir tveir samliggjandi reitir í rununni eru nágrannar.

Krakki getur falið sig í reit þá og því aðeins að sá reitur sé auður og hefur *nákvæmlega* einn auðan nágranna.
Engir tveir krakkar geta falið sig í sama reit.

Þú færð gefið kort af garðinum sem inntak.
Verkefnið þitt er að hjálpa afa að búa til völundarhús þar sem margir krakkar geta falið sig.

## Útfærsluatriði

Í þessu verkefni þarf einungis að skila úttaki, og verða stig gefin fyrir það.
Þú færð gefnar $10$ inntaksskrár, og hver þeirra lýsir garðinum hans afa.
Fyrir hverja inntaksskrá þarft þú að skila inn úttaksskrá með korti af völundarhúsi.
Fyrir hverja úttaksskrá færðu stig eftir því hversu margir krakkar geta falið sig í völundarhúsinu þínu.

Þú átt ekki að skila neinum kóða í þessu verkefni.

## Inntakslýsing

Hver inntaksskrá lýsir einu fylki sem táknar garð og gefur fjölda krakka $k$ sem afi bauð, á eftirfarandi formi:
* lína $1$: $\;\; m \;\; n \;\; k$
* lína $1+i$ (fyrir $1 \leq i \leq m$): röð $i$ í fylkinu, sem er strengur af lengd $n$ sem samanstendur af eftirfarandi táknum (án bila):
  - '`.`': auður reitur,
  - '`#`': grjót.

## Úttakslýsing

* lína $i$ (fyrir $1 \leq i \leq m$): lína $i$ í völundarhúsinu (þ.e. í garðinum eftir að runnarnir hafa verið gróðursettir). Það er strengur af lengd $n$ sem samanstendur af eftirfarandi táknum (án bila):
  -  '`.`': auður reitur,
  -  '`#`': grjót,
  -  '`X`': runni. (Athugaðu að stafurinn X verður að vera hástafur.)

## Takmarkanir

* $1 \leq m, n \leq 1024$

## Stigagjöf

Úttaksskrá er sögð vera *gild* ef öll af eftirfarandi skilyrðum eru uppfyllt:
* Kortið í úttakinu verður að vera eins og kortið í inntakinu fyrir utan að það má vera búið að breyta '`.`' stöfum í '`X`' stafi (reiti sem hafa runna).
*  Kortið í úttakinu verður að uppfylla það að vera völundarhús, eins og það er skilgreint í verkefnalýsingunni.

Ef úttakið þitt fyrir prófunartilvik er ekki gilt, þá færðu $0$ stig fyrir það prófunartilvik.
Annars færðu $\min(10, 10 \cdot l/k)$ stig, námundað niður að tveimur aukastöfum eftir kommu.
Hér táknar $l$ fjölda krakka sem geta falið sig í þínu völundarhúsi í úttakinu, og $k$ er talan sem gefin er í inntakinu.
Þú færð $10$ stig fyrir prófunartilvik þá og því aðeins að úttakið þitt er völundarhús þar sem $k$ eða fleiri krakkar geta falið sig.
Fyrir hvert prófunartilvik er til lausn sem gefur $10$ stig.

Athugaðu að ef lausnin þín er gild en fær samt $0$ stig samkvæmt formúlunni að ofan, þá mun dómurinn sem þú sérð í CMS vera 'Wrong Answer'.

## Sýnidæmi

Skoðaðu eftirfarandi inntak:

```
4 5 5
....#
.#..#
...#.
....#
```

Fyrir neðan er mögulegt gilt úttak:

```
.X.X#
.#..#
...#X
XX..#
```

Þar sem $l=4$ krakkar geta falið sig í þessu völundarhúsi, þá mun þessi lausn fá $10 \cdot 4 / 5 = 8$ stig. Reitirnir þar sem krakkar geta falið sig eru merktir með `O` að neðan:

```
OXOX#
.#.O#
...#X
XX.O#
```

Eftirfarandi þrjú úttök eru ekki gild:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

Í vinstra úttakinu er engin einföld leið á milli auða reitsins í efra vinstra horninu og auða reitsins í dálknum lengst til hægri.
Í hinum tveimur úttökunum eru nákvæmlega tvær mismunandi leiðir á milli hverra tveggja mismunandi auðra reita.
