# Nowruz
Likus kelioms dienoms iki Nowruz (Persijos Naujųjų metų) senelis sukvietė šeimą į savo sodą. Tarp svečių yra $k$ vaikų. Kad susitikimas vaikams būtų linksmesnis, senelis ketina surengti slėpynes.

Sodą galima pavaizduoti $m \times n$ vienetinių langelių gardele. Kai kuriuose langeliuose (jų gali būti ir nulis) yra po didelį akmenį, o likę langeliai yra *laisvi*. Du langeliai yra *kaimynai*, jei jie turi bendrą kraštinę. Taigi kiekvienas langelis turi iki 4 kaimynų: du horizontaliai ir du vertikaliai.
Senelis nori paversti sodą labirintu. Šiam tikslui jis kai kuriuose laisvuose langeliuose gali pasodinti krūmų. Krūmais apsodinti langeliai jau nėra laisvi.

Labirintas turi turėti tokią savybę: kiekvienai laisvų langelių labirinte porai $a$ ir $b$ turi būti vientintelis *paprastas kelias* tarp jų. Paprastas kelias tarp langelių $a$ ir $b$ yra laisvų langelių seka, kuri prasideda langeliu $a$, baigiasi langeliu $b$, visi langeliai joje yra skirtingi, ir visi gretimi sekos langeliai yra kaimynai.

Vaikas gali pasislėpti langelyje tada ir tik tada, jei tas langelis yra laisvas ir turi *lygiai* vieną laisvą kaimyną. Viename langelyje gali slėptis tik vienas vaikas.

Duotas sodo žemėlapis. Padėkite seneliui sukurti labirintą, kuriame galėtų pasislėpti daug vaikų.

## Realizacija

Tai yra rezultatų uždavinys su daliniu vertinimu. Jums yra duota $10$ įvesties failų, kurių kiekvienas apibūdina senelio sodą. Kiekvienam įvesties failui pateikite išvesties failą su labirinto žemėlapiu. Už kiekvieną išvesties failą gausite taškus priklausomai nuo vaikų, kurie gali pasislėpti labirinte, skaičiaus.

Šiam uždaviniui nereikia pateikti jokios jį sprendžiančios programos.

## Įvesties formatas

Kiekvienas įvesties failas apibūdina sodą atvaizduojančią gardelę ir jame pateikiamas senelio pakviestų vaikų skaičius $k$. Failo formatas:
* $1$-oji eilutė: $\;\; m \;\; n \;\; k$
* $i+1$-oji eilutė ($1 \leq i \leq m$): $i$-oji gardelės eilutė, kurią sudaro $n$ simbolių be tarpų, kurie gali būti tokie:
  - '`.`': laisvas langelis,
  - '`#`': akmuo

## Išvesties formatas

* $i$-oji eilutė ($1 \leq i \leq m$): $i$-oji labirinto (sodo, kuriame susodinti krūmai) eilutė. Tai yra $n$ simbolių eilutė, sudaryta iš tokių simbolių be tarpų:
  - '`.`': laisvas langelis,
  - '`#`': akmuo,
  -  '`X`': krūmas. (Atkreipkite dėmesį, kad X yra didžioji raidė.)

## Ribojimai

* $1 \leq m, n \leq 1024$

## Vertinimas

Išvesties failas yra laikomas *korektišku*, jei jis atitinka šiuos reikalavimus:
* Žemėlapis įvesties faile turi sutapti su žemėlapiu išvesties faile, išskyrus neribotą kiekį '`.`' simbolių įvesties faile pakeistų simboliais '`X`' (tai krūmais apsodinti langeliai).
* Išvesties žemėlapis turi pasižymėti sąlygoje aprašyta labirinto savybe.

Jei išvestis kuriam nors testui nekorektiška, už tą testą gausite $0$ taškų. Kitu atveju gausite $\min(10, 10 \cdot l/k)$ taškų, suapvalintų žemyn iki dviejų skaičių po kablelio. Čia $l$ yra vaikų, kurie gali pasislėpti jūsų pateiktame labirinte skaičius, o $k$ yra skaičius, pateiktas įvestyje. Už testą gausite $10$ taškų tada ir tik tada, jei jūsų pateiktame labirinte gali pasislėpti $k$ arba daugiau vaikų. Kiekvienam testui egzistuoja sprendimas, vertas $10$ taškų.

Atkreipkite dėmesį, kad jei pateikta išvestis yra korektiška, bet pagal aukščiau esančią formulę surenka $0$ taškų, tai CMS rodys 'Wrong answer' (neteisingas atsakymas).

## Pavyzdys

Panagrinėkime tokią įvestį:

```
4 5 5
....#
.#..#
...#.
....#
```

Žemiau pateikta korektiška išvestis:

```
.X.X#
.#..#
...#X
XX..#
```

Kadangi šiame labirinte gali pasislėpti $l = 4$ vaikai, sprendimas surinktų $10 \cdot 4 / 5 = 8$ taškus. Langeliai, kuriuose vaikai gali pasislėpti, žemiau pažymėti `O`:

```
OXOX#
.#.O#
...#X
XX.O#
```

Šie trys išvesties variantai yra nekorektiški:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

Kairiame labirinte nėra paprasto kelio tarp laisvo langelio kairiąjame viršutiniame kampe ir laisvo langelio dešiniąjame stulpelyje. Likusiuose dviejuose labirintuose tarp bet kurių dviejų skirtingų laisvų langelių yra lygiai du skirtingi paprasti keliai.