# Senovinės knygos

Teherane yra įsikūrusi Irano nacionalinė biblioteka. Pagrindis bibliotekos turtas - senovinės ranka rašytos knygos - yra išdėstytas ilgoje salėje, kurioje yra eilė $n$ stalų, sunumeruotų nuo $0$ iki $n-1$ iš kairės į dešinę. Ant kiekvieno stalo yra eksponuojama viena knyga. Šios knygos yra surikiuotos pagal jų amžių, todėl lankytojams yra sunku ieškoti knygų pagal pavadinimą. Taigi bibliotekos direktorius nusprendė surikiuoti knygas abėcėlės tvarka pagal jų pavadinimus.

Bibliotekininkas Aryanas ketina atlikti šį darbą. Jis sudarė $n$ ilgio sąrašą $p$, kurį sudaro skirtingi sveikieji skaičiai nuo $0$ iki $n-1$.
Sąrašas nusako pakeitimus, kuriuos reikia atlikti norint pertvarkyti knygas į abėcėlinę tvarką: visiems $0 \leq i < n$, knyga, dabar esanti ant $i$-ojo stalo, turi būti perkelta ant $p[i]$-ojo stalo.

Aryanas pradeda rikiuoti knygas prie $s$-tojo stalo.
Baigęs darbą jis nori sugrįžti prie to paties stalo.
Kadangi knygos yra labai brangios, jis negali vienu metu nešti daugiau negu vienos knygos.
Rikiuodamas knygas, Aryanas atliks veiksmų seką. Kiekvienas veiksmas bus vienas iš žemiau išvardytų:
* Jei jis neneša knygos ir stovi prie stalo, ant kurio yra knyga, jis gali paimti šią knygą.
* Jei jis neša knygą ir stovi prie stalo, ant kurio yra kita knyga, jis gali sukeisti nešamą knygą su knyga, esančia ant stalo.
* Jei jis neša knygą ir stovi prie tuščio stalo, jis gali padėti nešamą knygą ant šio stalo.
* Jis gali prieiti prie bet kurio stalo. Eidamas jis gali nešti tik vieną knygą. 


Visiems $0 \leq i, j \leq n - 1$, atstumas tarp $i$-ojo ir $j$-ojo stalo yra lygiai $|j-i|$ metrų. Padėkite Aryanui surikiuoti knygas taip, kad jo nueitas kelias būtų mažiausias galimas.

## Realizacija

Parašykite šią procedūrą:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ yra $n$ ilgio masyvas.
Knygą, pradžioje esančią ant $i$-ojo stalo, Aryanas turi nunešti ant $p[i]$-ojo stalo (visiems $0 \leq i < n$).
* $s$ yra numeris stalo, prie kurio Aryanas stovi pradžioje ir prie kurio turi sugrįžti baigęs rikiuoti knygas.
* Ši procedūra turi grąžinti mažiausią galimą bendrą nueito kelio ilgį (metrais), kurį Aryanas turi nueiti, kad surikiuotų knygas.

## Pavyzdys

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

Šiame pavyzdyje $n=4$ ir Aryanas pradiniu momentu yra prie stalo $0$.
Jis knygas rikiuoja taip:
* Nueina prie stalo $1$ ir paima nuo jo knygą. Šią knygą reikia padėti ant stalo $2$.
* Tada jis nueina prie stalo $2$ ir sukeičia nešamą knygą su knyga ant stalo.
Knygą, kurią dabar neša, reikia padėti ant stalo $3$.
* Tada jis nueina prie stalo $3$ ir sukeičia nešamą knygą su knyga ant stalo.
Knygą, kurią dabar neša, reikia padėti ant stalo $1$.
* Tada jis nueina prie stalo $1$ ir padeda nešamą knygą ant šio stalo.
* Galiausiai jis grįžta prie stalo $0$.

Atkreipkite dėmesį, kad knyga ant stalo $0$ jau yra teisingoje vietoje, taigi Aryanui nereikia jos paimti.
Bendras jo nueitas kelias šiame sprendinyje yra $6$ metrai.
Tai yra optimalus sprendinys, taigi procedūra turi grąžinti $6$.

## Ribojimai

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* Masyvą $p$ sudaro $n$ skirtingų sveikųjų skaičių iš intervalo nuo $0$ iki $n-1$ imtinai.

## Dalinės užduotys

1. (12 taškų) $n \le 4$ and $s = 0$
1. (10 taškų) $n \le 1000$ ir $s = 0$
1. (28 taškai) $s = 0$
1. (20 taškų) $n \le 1000$
1. (30 taškų) papildomų ribojimų nėra

## Pavyzdinis vertintojas

Pavyzdinis vertintojas skaito duomenis tokiu formatu:

- $1$-a eilutė: $\;\; n \;\; s$
- $2$-a eilutė: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

Jis išveda vieną eilutę, kurioje yra  `minimum_walk` procedūros grąžinta reikšmė.
