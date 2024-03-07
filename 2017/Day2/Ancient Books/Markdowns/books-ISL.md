# Fornar bækur

Þjóðarbókasafn Íran á heima í borginni Teheran.
Helsti fjársjóður bókasafnsins er á löngum gangi með röð af $n$ borðum, númeruð $0$ til $n-1$ frá vinstri til hægri.
Á hverju borði er ein forn handskrifuð bók til sýningar.
Þessar bækur eru raðaðar eftir aldri, sem gerir það erfitt fyrir gesti að finna bækur eftir titli.
Framkvæmdastjóri bókasafnsins hefur því ákveðið að raða bókunum í stafrófsröð eftir titlum þeirra.

Bókasafnsvörðurinn Aryan ætlar að koma þessu í verk.
Hann hefur búið til lista $p$ af lengd $n$, sem inniheldur mismunandi heiltölur frá $0$ til $n-1$.
Þessi listi lýsir breytingunum sem þarf að gera til að endurraða bókunum í stafrófsröð:
fyrir öll $0 \leq i < n$, þá á að færa bókina sem er á borði $i$ yfir á borð $p[i]$.

Þegar Aryan ætlar að raða bókunum, þá byrjar hann við borð $s$.
Hann vill enda við sama borð þegar hann er búinn með verkið.
Þar sem bækurnar eru mjög verðmætar, þá getur hann ekki haldið á fleiri en einni bók í einu.
Á meðan Aryan raðar bókunum þá mun hann framkvæma röð aðgerða.
Hver af þessum aðgerðum þarf að vera ein af eftirfarandi:
* Ef hann heldur ekki á bók og það er bók á borðinu sem hann er hjá, þá getur hann tekið þessa bók.
* Ef hann heldur á bók og það er bók á borðinu sem hann er hjá, þá getur hann skipt á bókinni sem hann heldur á og þeirri sem er á borðinu.
* Ef hann heldur á bók og hann er hjá borði sem er tómt, þá getur hann sett bókina sem hann heldur á niður á borðið.
* Hann getur gengið að hvaða borði sem er. Hann má halda á einni bók á meðan hann gerir það.

Fyrir öll $0 \leq i, j \leq n - 1$, þá er fjarlægðin á milli borða $i$ og $j$ nákvæmlega $|j-i|$ metrar. Þitt verkefni er að reikna minnstu mögulegu fjarlægð sem Aryan þarf að ganga til að raða öllum bókunum.

## Útfærsluatriði

Þú átt að útfæra eftirfarandi fall:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ er fylki af lengd $n$.
Aryan á að fara með bókina sem er upphaflega á borði $i$ yfir á borð $p[i]$ (fyrir öll $0 \leq i < n$).
* $s$ er númerið á borðinu sem Aryan er hjá í upphafi, og borðinu sem hann á að enda hjá þegar hann er búinn að raða bókunum.
* Þetta fall á að skila minnstu heildarvegalengd (í metrum) sem Aryan þarf að ganga til að raða öllum bókunum.

## Sýnidæmi

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

Í þessu sýnidæmi er $n=4$ og Aryan byrjar við borð $0$.
Hann raðar bókunum á eftirfarandi hátt:
* Hann gengur að borði $1$ og tekur upp bókina sem þar liggur. Þessa bók á að færa yfir á borð $2$.
* Svo gengur hann að borði $2$ og skiptir á bókinni sem hann heldur á og bókinni sem er á borðinu.
Nýju bókina sem hann heldur á á að færa yfir á borð $3$.
* Svo gengur hann að borði $3$ og skiptir á bókinni sem hann heldur á og bókinni sem er á borðinu.
Nýju bókina sem hann heldur á á að færa yfir á borð $1$.
* Svo gengur hann að borði $1$ og setur bókina sem hann heldur á niður á borðið.
* Að lokum gengur hann aftur að borði $0$.

Athugið að bókin sem er á borði $0$ er þegar á réttri staðsetningu, borði $0$, svo Aryan þarf ekki að taka hana upp.
Heildarfjarlægðin sem hann gengur í þessari lausn er $6$ metrar.
Þetta er besta lausnin; þar af leiðandi á fallið að skila $6$.

## Takmarkanir

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* Fylkið $p$ inniheldur $n$ mismunandi heiltölur á bilinu $0$ til $n-1$.

## Hlutverkefni

1. (12 stig) $n \le 4$ og $s = 0$
1. (10 stig) $n \le 1000$ og $s = 0$
1. (28 stig) $s = 0$
1. (20 stig) $n \le 1000$
1. (30 stig) engar frekari takmarkanir

## Sýnishorn af dómara

Sýnishorn af dómara les inntakið á eftirfarandi formi:

- lína $1$: $\;\; n \;\; s$
- lína $2$: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

Sýnishorn af dómara skrifar út eina línu sem inniheldur skilagildi `minimum_walk`.