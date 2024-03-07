# Kabelių projektavimas

Maryam yra elektros inžinierė. Ji konstruoja kabelių instaliaciją ryšio bokštui. Bokšte skirtinguose aukščiuose išdėstyti jungties taškai. Kabelis gali sujungti bet kuriuos du jungties taškus. Prie kiekvieno jungties taško gali būti prijungtas bet koks skaičius kabelių. Jungties taškai yra raudoni arba mėlyni.

Šiame uždavinyje ryšio bokštą įsivaizduokite kaip tiesę, o jungties taškus - kaip mėlynus ir raudonus taškus šioje tiesėje kurių koordinatės yra sveikieji neneigiami skaičiai. Du taškus jungiančio kabelio ilgis lygus atstumui tarp šių taškų.

Padėkite Maryam sudaryti tokią instaliacijos schemą, kad:

1. Kiekvienas jungties taškas būtų sujungtas su bent vienu kitos spalvos jungties tašku.
1. Bendras visų kabelių ilgis būtų mažiausias galimas.

## Realizacija

Parašykite šią procedūrą:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: $n$ ilgio masyvas, kuriame didėjimo tvarka pateiktos raudonų jungties taškų koordinatės.
* $b$: $m$ ilgio masyvas, kuriame didėjimo tvarka pateiktos mėlynų jungties taškų koordinatės.
* Ši procedūra turi grąžinti mažiausią galimą bendrą kabelių ilgį.
* Atkreipkite dėmesį, kad šios procedūros grąžinamo rezultato tipas yra `int64`.

## Pavyzdys

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Toliau pateikta šio pavyzdžio iliustracija.
![Wiring](wiring.png)

* Bokštas pavaizduotas horizontaliai.
* Nespalvotoje sąlygoje raudoni jungties taškai pavaizduoti tamsia spalva, o mėlyni - šviesia.
* Yra $4$ raudoni jungties taškai, kurių pozicijos yra $1, 2, 3,$ ir $7$.
* Yra $5$ mėlyni jungties taškai, kurių pozicijos yra $0, 4, 5, 9,$ ir $10$.
* Vienas optimalus sprendinys pavaizduotas paveikslėlyje.
* Šiame sprendinyje bendras kabelių ilgis lygus $1 + 2 + 2 + 2 + 3 = 10$, ir tai yra optimalus sprendinys. Taigi, procedūra turi gražinti $10$.
* Atkreipkite dėmesį, kad prie $7$ pozicijoje esančio jungties taško prijungti du kabeliai.

## Ribojimai

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (visiems $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (visiems $0 \leq i \leq m-1$),
* Abu masyvai $r$ ir $b$ yra surikiuoti didėjimo tvarka.
* Visos $n+m$ reikšmių, esančių masyvuose $r$ ir $b$ yra skirtingos.

## Dalinės užduotys

1. (7 taškai) $n, m \leq 200$,
1. (13 taškų) Visų raudonų jungties taškų koordinatės yra mažesnės už bet kurio mėlyno jungties taško.
1. (10 taškų) Yra bent vienas raudonas jungties taškas ir  bent vienas vienas mėlynas jungties taškas tarp bet kurių 7 iš eilės einančių jungties taškų.
1. (25 taškai) Visų jungties taškų koordinatės yra skirtingi skaičiai iš intervalo $[1, n+m]$.
1. (45 taškai) Papildomų ribojimų nėra.

## Pavyzdinis vertintojas

Pavyzdinis vertintojas skaito duomenis tokiu formatu:
* $1$-a eilutė: $\;\; n \;\; m$
* $2$-a eilutė: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* $3$-ia eilutė: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Jis išveda vieną eilutę kurioje yra  `min_total_length`, procedūros grąžinta reikšmė.