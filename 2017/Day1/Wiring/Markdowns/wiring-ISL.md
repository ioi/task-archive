# Raflagnir
Maryam er rafmagnsverkfræðingur.
Hún er að skipuleggja raflagnir á samskiptaturni.
Á turninum eru nokkrir tengipunktar, sem eru staðsettir á mismunandi hæðum.
Það er hægt að nota vír til að tengja hvaða tvo tengipunkta sem er.
Hver tengipunktur má vera tengdur við marga víra.
Það eru tvær gerðir af tengipunktum: rauðir og bláir.

Í þessu verkefni ætlum við að horfa á turninn sem línu og tengipunktana sem bláa og rauða punkta sem eru staðsettir á heiltöluhnitum, stærri eða jöfn núlli, á þessari línu.
Lengd vírs er fjarlægðin á milli tengipunktanna tveggja sem hann tengir.

Þitt takmark er að hjálpa Maryam að finna skipulag á raflögnunum þannig að:
1. Hver tengipunktur hefur að minnsta kosti einn vír sem tengist við tengipunkt af mismunandi lit.
1. Heildarlengd víranna er lágmörkuð.

## Útfærsluatriði

Þú átt að útfæra eftirfarandi fall:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: fylki af lengd $n$ sem inniheldur staðsetningarnar á rauðu tengipunktunum í hækkandi röð.
* $b$: fylki af lengd $m$ sem inniheldur staðsetningarnar á bláu tengipunktunum í hækkandi röð.
* Fallið á að skila minnstu heildarlengd víra sem hægt er að ná með gildu skipulagi á raflögnunum.
* Athugaðu að skilagildi fallsins er af taginu `int64`.

## Sýnidæmi

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Myndin að neðan sýnir þetta dæmi.
![Wiring](wiring.png)

* Turninn er sýndur láréttur.
* Í svarthvítu útprentuninni af verkefnalýsingunni eru rauðu tengipunktarnir dökkir og bláu tengipunktarnir ljósir.
* Það eru $4$ rauðir tengipunktar, staðsettir á hnitunum $1, 2, 3,$ og $7$.
* Það eru $5$ bláir tengipunktar, staðsettir á hnitunum $0, 4, 5, 9,$ og $10$.
* Ein af mögulegu bestu lausnunum er sýnd á myndinni að ofan.
* Í þessari lausn er heildarlengd víranna $1 + 2 + 2 + 2 + 3 = 10$, sem er eins stutt og mögulegt er. Fallið á því að skila $10$.
* Athugaðu að tveir vírar eru tengdir við tengipunktinn á hniti $7$.

## Takmarkanir

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (fyrir öll $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (fyrir öll $0 \leq i \leq m-1$),
* Hvert af fylkjunum $r$ og $b$ eru röðuð í hækkandi röð.
* Öll $n+m$ gildin í fylkjunum $r$ og $b$ eru mismunandi.

## Hlutverkefni

1. (7 stig) $n, m \leq 200$,
1. (13 stig) Allir rauðu tengipunktarnir eru staðsettir á lægri hnitum en bláu tengipunktarnir.
1. (10 stig) Það er að minnsta kosti einn rauður tengipunktur og einn blár tengipunktur á meðal hverra $7$ samliggjandi tengipunkta.
1. (25 stig) Allir tengipunktar hafa mismunandi staðsetningar á bilinu $[1, n+m]$.
1. (45 stig) Engar frekari takmarkanir.

## Sýnishorn af dómara

Sýnishorn af dómara les inntak á eftirfarandi formi:
* lína $1$: $\;\; n \;\; m$
* lína $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* lína $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Sýnishorn af dómara skrifar út eina línu sem inniheldur skilagildi fallsins `min_total_length`.