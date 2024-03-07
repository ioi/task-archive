# Didysis prizas

Didysis Prizas yra garsus TV šou.
Jūs esate laimingas dalyvis, kurį pakvietė dalyvauti finale.
Prieš jus pastatyta $n$ dėžių, sunumeruotų nuo $0$ iki $n-1$ iš kairės į dešinę.
Kiekvienoje dėžėje yra paslėptas prizas ir koks tai prizas sužinosite tik tada kai atidarysite dėžę.
Iš viso yra $v \geq 2$ skirtingų prizų *tipų*.
Prizų tipai sunumeruoti nuo $1$ iki $v$ prizų tipų verčių *mažėjimo* tvarka.

Prizas, kurio tipas $1$  - deimantas. Jo vertė pati didžiausia.
Yra lygiai viena dėžė su deimantu.
 Prizas, kurio tipas $v$ - pats pigiausias: ledinukas. 
Pigių prizų yra daug daugiau negu brangių.
Konkrečiau, visiems $t$ tokiems, kad $2 \leq t \leq v$, galioja:
jei yra $k$ tipo $t-1$ prizų, tuomet yra *griežtai daugiau* nei $k^2$ tipo $t$ prizų.

Jūsų tikslas - laimėti deimantą. 
Žaidimo gale atidaysite dėžę ir gausite joje esantį prizą. Prieš atidarydamas galite užduoti klausimus žaidimo vedėjui Rambodui.
Užduodami klausimą nurodote dėžę $i$.
Atsakydamas Rambodas pateiks jums masyvą $a$, kuriame bus du skaičiai:
* Tarp dėžių, esančių dėžės $i$ kairėje yra lygiai $a[0]$ dėžių su prizais, brangesniais, nei dėžėje  $i$.
* Tarp dėžių, esančių dėžės $i$ dešinėje yra lygiai $a[1]$ dėžių su prizais brangesniais nei dėžėje  $i$.

Pavyzdžiui, $n=8$. Klausdami pasirenkate dėžę $i=2$.
Atsakydamas Rambodas pasako jums, kad $a=[1,2]$.
Tai reiškia, kad 
* Lygiai vienoje iš dėžių $0$ ir $1$ yra prizas, brangesnis, nei dėžėje $2$.
* Lygiai dviejose iš dėžių $3, 4, \ldots, 7$ yra po prizą, brangesnį nei dėžėje $2$.

Jūsų užduotis - nustatyti, kurioje dėžėje yra deimantas, užduodant kuo  mažiau klausimų.

## Realizacija

Parašykite šią procedūrą:

```
int find_best(int n)
```

* Šią procedūrą vertinimo programa iškviečia lygiai vieną kartą.
* $n$: dėžių skaičius.
* Procedūra turi grąžinti dėžės su deimantu numerį, t.y.  sveikajį skaičių $d$ ($0 \leq d \leq n-1$) tokį, kad dėžėje $d$ yra prizas, kurio tipas yra $1$.

Aukščiau aprašyta procedūra gali iškviesti šią procedūrą:

```
int[] ask(int i)
```

* $i$: dėžės, apie kurią užduosite klausimą, numeris. $i$ reikšmė turi būti nuo $0$ iki $n-1$ imtinai.
* Ši procedūra grąžina masyvą $a$ sudarytą iš $2$ elementų. Čia $a[0]$ yra prizų, esančių dėžės $i$ kairėje ir brangesnių už dėžėje $i$ esantį prizą, skaičius, o $a[1]$ - prizų, esančių dėžės $i$ dešinėje ir brangesnių už dėžėje $i$ esantį prizą, skaičius.

## Pavyzdys

Vertintojas atlieka tokį kvietimą:

```
find_best(8)
```

Yra $n=8$ dėžės. Tarkime, kad prizų tipai yra $[3,2,3,1,3,3,2,3]$.
Žemiau pateikti visi galimi procedūros  `ask` iškvietimai ir atitinkamos grąžintos reikšmės.

- `ask(0)` grąžina $[0, 3]$
- `ask(1)` grąžina  $[0, 1]$
- `ask(2)` grąžina  $[1, 2]$
- `ask(3)` grąžina  $[0, 0]$
- `ask(4)` grąžina  $[2, 1]$
- `ask(5)` grąžina  $[2, 1]$
- `ask(6)` grąžina  $[1, 0]$
- `ask(7)` grąžina  $[3, 0]$

Šiame pavyzdyje deimantas yra dėžėje $3$. Taigi procedūra `find_best` turi grąžinti $3$.

![Prize1](prize.png "600") 

Aukščiau pateikta pavyzdžio iliustracija.
Pirmoje prizų eilėje parodyti prizų tipai.
Antroje prizų eilėje iliustruojama užklausa  `ask(2)`.
Varnelėmis pažymėtose dėžėse yra prizai, brangesni, nei esantys dėžėje  $2$.

## Ribojimai

* $3 \leq n \leq 200\,000$.
* Prizų tipai yra skaičiai nuo $1$ iki $v$ imtinai.
* Yra lygiai vienas prizas, kurio vertė yra $1$.
* Visiems $2 \leq t \leq v$ galioja: jeigu yra $k$ tipo $t-1$ prizų, tai $t$ tipo prizų yra *griežtai* daugiau nei $k^2$.

## Dalinės užduotys ir vertinimas

Kai kuriose situacijose vertinimo programa veiks adaptyviai.
Tai reiškia, kad šiuose testuose vertinimo programa nenaudos fiksuotos prizų tipų sekos.
Kitaip sakant vertinimo programos pateikti atsakymai priklausys nuo jūsų sprendimo užduodamų klausimų.
Užtikrinama, kad vertinimo programa veiks taip, kad po kiekvieno jos atsakymo bus mažiausiai viena galima prizų verčių seka, atitinkanti visus iki šiol pateiktus atsakymus.

1. (20 taškų) Yra lygiai $1$ deimantas ir $n-1$ ledinukų (taigi, $v = 2$).
Procedūrą `ask` galite iškviesti daugiausia $10\,000$ kartų.
1. (80 taškų) Papildomų ribojimų nėra.

2-oje dalinėje užduotyje yra dalinis vertinimas.
Pažymėkime $q$ didžiausią procedūros  `ask` iškvietimų skaičių tarp visų šios dalinės užduoties testų.
Tuomet taškai, skiriami už šią dalinę užduotį, apskaičiuojami remiantis šia lentele:

Klausimai | Taškai
--- | ---
$10\,000 < q$ | $0$ (CMS pateiks 'Wrong Answer')
$6000 < q \leq 10\,000$ | $70$
$5000 < q \leq 6000$ | $80 - (q-5000)/100$
$q \leq 5000$ | $80$

## Pavyzdinis vertintojas

Pavyzdinis vertintojas nėra adaptyvus. 
Jis perskaito fiksuotą prizų tipų masyvą $p$. Visiems $0 \leq b \leq n-1$ dėžutėje $b$ esančio prizo tipas yra $p[b]$.
Pavyzdinis vertintojas pradinius duomenis skaito tokiu formatu:

- $1$-oji eilutė: $\;\; n$
- $2$-oji eilutė: $\;\; p[0] \;\; p[1]  \; \ldots \; p[n-1]$

Vertintojas vienoje eilutėje išveda grąžinamą `find_best` reikšmę ir kreipinių į procedūrą `ask` skaičių.
<div style="margin-top:-1em"></div>