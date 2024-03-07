# Simurgh

Samkvæmt fornum persneskum sögum úr Shahnameh, þá er persneska hetjan Zal mjög
ástfangin af Rudaba, prinsessu Kabul. Þegar Zal bað um hönd Rudaba, þá gaf
faðir hennar honum verkefni.

Í Persíu eru $n$ borgir, númeraðar frá $0$ til $n-1$, og $m$ vegir sem hægt er að ferðast yfir í báðar áttir, númeraðir frá $0$ til $m-1$.
Hver vegur tengir par af mismunandi borgum.
Hvert par af borgum er tengt með í mesta lagi einum veg.
Sumir af vegunum eru *konunglegir vegir* sem eru notaðir af konunglegu fólki.
Verkefni Zal er að ákvarða hverjir af vegunum eru konunglegir vegir.

Zal er með kort af öllum borgum og vegum í Persíu.
Hann veit ekki hverjir af vegunum eru konunglegir, en hann getur fengið hjálp frá Simurgh, góðviljaða goðsagnakennda fuglinum sem er verndari Zal.
Simurgh vill þó ekki gefa beint upp hverjir af vegunum eru konunglegir.
Í staðinn segir hún Zal að konunglegu vegirnir mynda saman *gullið mengi*.
Mengi af vegum er gullið þá og því aðeins að:
* það hefur *nákvæmlega* $n-1$ vegi, og
* fyrir hvert par af borgum þá er hægt að ferðast á milli þeirra með því að nota aðeins vegina í þessu mengi.

Þar að auki getur Zal spurt Simurgh spurningar.
Fyrir hverja spurningu:
1. Zal velur *gullið* mengi af vegum, og svo:
1. Simurgh segir Zal hversu margir af vegunum í valda gullna menginu eru konunglegir vegir.

Forritið þitt á að hjálpa Zal að finna mengið af konunglegu vegunum með því að spyrja Simurgh í mesta lagi $q$ spurningar. Dómarinn mun gegna hlutverki Simurgh.

## Útfærsluatriði

Þú átt að útfæra eftirfarandi fall:

```
int[] find_roads(int n, int[] u, int[] v)
```

* $n$: fjöldi borga,
* $u$ og $v$: fylki af lengd $m$. Fyrir öll $0 \leq i \leq m-1$, $u[i]$ og $v[i]$ eru borgirnar sem vegur $i$ tengir.
* Þetta fall á að skila fylki af lengd $n-1$ sem inniheldur númerin á konunglegu vegunum (í hvaða röð sem er).

Lausnin þín getur kallað allt að $q$ sinnum í eftirfarandi dómarafall:

```
int count_common_roads(int[] r)
```

* $r$: fylki af lengd $n-1$ sem inniheldur númerin á vegum í gullnu mengi (í hvaða röð sem er).
* Þetta fall skilar fjölda konunglegra vega í $r$.

## Sýnidæmi

```
find_roads(4, [0, 0, 0, 1, 1, 2], [1, 2, 3, 2, 3, 3])
```

![Simurgh](simurgh.png)

Í þessu sýnidæmi eru $4$ borgir og $6$ vegir.
Við látum $(a, b)$ tákna veg sem tengir borgir $a$ og $b$.
Vegirnir eru númeraðir frá $0$ til $5$ í eftirfarandi röð: $(0, 1)$, $(0, 2)$, $(0, 3)$, $(1, 2)$, $(1, 3)$, og $(2, 3)$.
Hvert gullið mengi hefur $n-1=3$ vegi.

Gerum ráð fyrir að konunglegu vegirnir séu númeraðir $0$, $1$, og $5$, það er, vegirnir $(0, 1)$, $(0, 2)$, og $(2, 3)$. Þá:
* `count_common_roads([0, 1, 2])` skilar $2$. Þessi fyrirspurn er um vegina sem eru númeraðir $0, 1$, og $2$, það er, vegina $(0, 1)$, $(0, 2)$ og $(0,3)$. Tveir þeirra eru konunglegir vegir.
* `count_common_roads([5, 1, 0])` skilar $3$. Þessi fyrirspurn er um alla konunglegu vegina.

Fallið `find_roads` ætti að skila `[5, 1, 0]` eða hvaða fylki af lengd $3$ sem inniheldur þessi þrjú gildi.

Athugið að eftirfarandi köll eru ekki leyfileg:
* `count_common_roads([0, 1])`: hér er lengdin á $r$ ekki $3$.
* `count_common_roads([0, 1, 3])`: hér lýsir $r$ ekki gullnu mengi,
þar sem það er ekki hægt að ferðast frá borg $0$ til borgar $3$ með því að nota bara vegina $(0,1)$, $(0,2)$, $(1,2)$.

## Takmarkanir

* $2 \leq n\leq 500$
* $n - 1 \leq m \leq n (n-1) / 2$
* $0 \leq u[i], v[i] \leq n-1$ (fyrir öll $0 \leq i \leq m-1$)
* Fyrir öll $0 \leq i \leq m-1$, þá tengir vegur $i$ tvær mismunandi borgir (þ.e., $u[i] \neq v[i]$).
* Það er í mesta lagi einn vegur á milli hvers pars af borgum.
* Það er hægt að ferðast á milli hverra tveggja borga með því að nota vegina.
* Mengi allra konunglegra vega er gullið mengi.
* `find_roads` má kalla allt að $q$ sinnum í `count_common_roads`.
Í hverju kalli á mengið af vegum sem $r$ lýsir að vera gullið mengi.

## Hlutverkefni

1. (13 stig) $n \leq 7$, $q = 30\,000$
1. (17 stig) $n \leq 50$, $q = 30\,000$
1. (21 stig) $n \leq 240$, $q = 30\,000$
1. (19 stig) $q = 12\,000$ og það er vegur á milli allra para af borgum
1. (30 stig) $q = 8000$

## Sýnishorn af dómara

Sýnishorn af dómara les inntakið á eftirfarandi formi:
* lína $1$: $\;\; n \;\; m$
* lína $2 + i$ (fyrir öll $0 \leq i \leq m-1$): $\;\; u[i] \;\; v[i]$
* lína $2 + m$: $\;\; s[0] \;\; s[1] \; \ldots\; s[n-2]$

Hér eru $s[0], s[1], \ldots, s[n-2]$ númerin á konunglegu vegunum.

Sýnishorn af dómara skrifar út `YES`, ef `find_roads` kallar í mesta lagi $30\,000$ sinnum á `count_common_roads` og skilar réttu mengi af konunglegu vegunum. Annars skrifar það út `NO`.

Passið ykkur að fallið `count_common_roads` í sýnishorni af dómara athugar ekki hvort $r$ uppfylli skilyrði þess að vera gullið mengi.
Í staðinn telur það og skilar fjölda númera á konunglegum vegum í fylkinu $r$.
Hinsvegar, ef forritið sem þú skilar kallar í `count_common_roads` með mengi af númerum sem lýsir ekki gullnu mengi, þá mun dómurinn vera 'Wrong Answer'.

## Tæknileg athugasemd

Fallið `count_common_roads` í C++ og Pascal notar *pass by reference* til að stuðla að því að fallið sé skilvirkt.
Þú getur enn kallað í fallið eins og venjulega.
Dómarinn mun ekki breyta gildi $r$.