 # Leikfangalest

Arezou og bróðir hennar Borzou eru tvíburar.
Þau voru að fá glæsilegt leikfangalestarsett í afmælisgjöf, og notuðu það til að búa til lestarkerfi með $n$ stöðvum og $m$ brautum, sem hver gengur í *eina átt*.
Stöðvarnar eru númeraðar frá $0$ upp í $n-1$.
Hver braut byrjar á einni stöð og endar á sömu eða annarri stöð.
Það er að minnsta kosti ein braut sem byrjar á hverri stöð.

Sumar stöðvar eru *hleðslustöðvar*.
Þegar lest kemur á hleðslustöð, þá hleðst hún að fullu.
Fullhlaðin lest hefur næga orku til að ferðast eftir $n$ brautum í röð.
Það er, lestin klárar hleðsluna þegar hún kemur á $(n+1)$-stu brautina eftir að hún var síðast hlaðin.

Á hverri stöð er rofi sem hægt er að beina að þeim brautum sem byrja á þeirri stöð.
Þegar lest er á stöð, þá fer hún út eftir brautinni sem rofanum er beint að á þeirri stöð.

Tvíburarnir ætla að spila leik með lestinni þeirra.
Þau hafa þegar skipt upp stöðvunum á milli þeirra: hver stöð er annaðhvort í eigu Arezou eða Borzou.
Það er ein lest.
Í byrjun leiksins er lestin á stöð $s$ og er fullhlaðin.
Til að byrja leikinn, þá beinir eigandi stöðvar $s$ rofanum á stöð $s$ að einni af brautunum sem byrja á stöð $s$.
Svo kveikja þau á lestinni og lestin byrjar að ferðast eftir brautunum.

Alltaf þegar lestin kemur á stöð í fyrsta skipti, þá stillir eigandi þeirrar stöðvar rofann á þeirri stöð.
Þegar rofi hefur verið stilltur, þá er hann í sömu stöðu það sem eftir er af leiknum.
Svo ef lest kemur aftur á stöð sem hún hefur heimsótt áður, þá mun hún fara út eftir sömu braut og áður.

Þar sem það er endanlegur fjöldi af stöðvum, þá mun lestin alltaf, að lokum, byrja að ferðast eftir *rás*.
Rás er runa af *mismunandi* stöðvum $c[0], c[1], \cdots, c[k-1]$ þannig að lestin fer af stöð $c[i]$ (fyrir $0 \leq i < k-1$) með braut sem fer til stöðvar $c[i+1]$, og hún fer af stöð $c[k-1]$ með braut sem fer til stöðvar $c[0]$.
Athugaðu að rás getur verið bara ein stöð (þ.e., haft $k=1$) ef lestin fer af stöð $c[0]$ með braut sem fer aftur til $c[0]$.

Arezou vinnur leikinn ef lestin heldur endalaust áfram, og Borzou vinnur ef lestin klárar hleðsluna.
Í öðrum orðum, ef það er að minnsta kosti ein hleðslustöð á meðal $c[0], c[1], \cdots, c[k-1]$, þá getur lestin endurhlaðið sig og keyrt endalaust, og Arezou vinnur.
Annars mun lestin klára hleðsluna (mögulega eftir að hafa farið rásina nokkrum sinnum), og Borzou vinnur.

Þú færð gefna lýsingu á lestarkerfinu.
Arezou og Borzou ætla að spila $n$ leiki.
Í $s$-ta leiknum, fyrir $0 \leq s \leq n-1$, þá mun lestin byrja í stöð $s$.
Þitt verkefni er að ákvarða, fyrir hvern leik, hvort það er til leikáætlun fyrir Arezou sem mun láta hana vinna, sama hvernig Borzou leikur.

## Útfærsluatriði

Þú átt að útfæra eftirfarandi fall:

```
int[] who_wins(int[] a, int[] r, int[] u, int[] v)
```

* $a$: fylki af lengd $n$. Ef Arezou á stöð $i$, $a[i] = 1$. Annars á Borzou stöð $i$ og $a[i] = 0$.
* $r$: fylki af lengd $n$. Ef stöð $i$ er hleðslustöð, $r[i] =1$. Annars er $r[i] = 0$.
* $u$ og $v$: fylki af lengd $m$.
Fyrir öll $0 \leq i \leq m-1$, þá er braut sem byrjar á stöð $u[i]$ og endar á stöð $v[i]$.
* Þetta fall á að skila fylki $w$ af lengd $n$.
Fyrir hvert $0 \leq i \leq n-1$, þá á gildið á $w[i]$ að vera $1$ ef Arezou getur unnið leikinn sem byrjar á stöð $i$, sama hvernig Borzou leikur.
Annars á gildið á $w[i]$ að vera $0$.

## Sýnidæmi

```
who_wins([0, 1], [1, 0], [0, 0, 1, 1], [0, 1, 0, 1])
```

![Train](train.png)

* Það eru $2$ stöðvar.
Borzou er eigandi stöðvar $0$, sem er hleðslustöð.
Arezou er eigandi stöðvar $1$, sem er ekki hleðslustöð.
* Það eru $4$ brautir $(0, 0), (0, 1), (1, 0)$, og $(1, 1)$, þar sem $(i, j)$ táknar braut frá stöð $i$ til stöðvar $j$.
* Spáðu í leiknum þar sem lestin er staðsett á stöð $0$ til að byrja með.
Ef Borzou beinir rofanum á stöð $0$ að brautinni $(0, 0)$, þá mun lestin ferðast endalaust eftir þessari braut (athugaðu að stöð $0$ er hleðslustöð).
Í þessu tilfelli mun Arezou vinna.
Annars, ef Borzou beinir rofanum á stöð $0$ að brautinni $(0, 1)$, þá getur Arezou beint rofanum á stöð $1$ að brautinni $(1, 0)$.
Ef þetta gerist, þá mun lestin ferðast endalaust á milli stöðvanna tveggja. Aftur mun Arezou vinna þar sem stöð $0$ er hleðslustöð og lestin mun ekki stoppa.
Þar af leiðandi getur Arezou unnið leikinn, sama hvað Borzou gerir.
* Með svipuðum rökum þá sést að Arezou getur líka unnið leikinn þar sem lestin byrjar á stöð $1$, sama hvað Borzou gerir. Þar af leiðandi á fallið að skila $[1, 1]$.

## Takmarkanir

* $1 \leq n \leq 5000$.
* $n \leq m \leq 20\,000$.
* Það er að minnsta kosti ein hleðslustöð.
* Það er að minnsta kosti ein braut sem byrjar á hverri stöð.
* Það gætu verið brautir sem byrja og enda á sömu stöð (þ.e., $u[i] = v[i]$).
* Allar brautirnar eru mismunandi.
Í öðrum orðum, það eru ekki tvær heiltölur $i$ og $j$ ($0 \leq i < j \leq m-1$) þannig að $u[i]=u[j]$ og $v[i]=v[j]$.
* $0 \leq u[i], v[i] \leq n-1$ (fyrir öll $0 \leq i \leq m-1$).

## Hlutverkefni

1. (5 stig) Fyrir öll $0 \leq i \leq m-1$, annað hvort $v[i] = u[i]$ eða $v[i] = u[i] + 1$.
1. (10 stig) $n \leq 15$.
1. (11 stig) Arezou á allar stöðvarnar.
1. (11 stig) Borzou á allar stöðvarnar.
1. (12 stig) Það er nákvæmlega ein hleðslustöð.
1. (51 stig) Engar frekari takmarkanir.

## Sýnishorn af dómara

Sýnishorn af dómara les inntak á eftirfarandi formi:
* lína $1$: $\;\; n \;\; m$
* lína $2$: $\;\; a[0] \;\; a[1] \; \ldots\; a[n-1]$
* lína $3$: $\;\; r[0] \;\; r[1] \; \ldots\; r[n-1]$
* lína $4 + i$ (fyrir $0 \leq i \leq m-1$): $\;\; u[i] \;\; v[i]$

Sýnishorn af dómara skrifar út skilagildi fallsins `who_wins` á eftirfarandi formi:
* lína $1$: $\;\; w[0] \;\; w[1] \; \ldots\; w[n-1]$
