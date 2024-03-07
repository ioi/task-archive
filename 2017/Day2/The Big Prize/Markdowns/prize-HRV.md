# The Big Prize

Velika nagrada je poznati TV gejm šou. Ti si sretan natjecatelj koji je prošao u završnu rundu. Stojiš ispred $n$ kutija u nizu, označenih od $0$ do $n-1$ slijeva nadesno. Svaka kutija sadrži nagradu koja je vidljiva tek kad se kutija otvori. Postoji $v \geq 2$ različitih *vrsta* nagrada. One su označene brojevima od $1$ do $v$ *padajuće* po vrijednosti.

Nagrada vrste $1$ je najvrjednija: bista maršala Teetougha. Postoji točno jedna bista među kutijama. Nagrada vrste $v$ je najjeftinija: potpis Bozhe Petrowa.
Da bi igra bila što zanimljivija, broj jeftinijih nagrada je znatno veći od broja skupljih.
Preciznije, za svaki $t$ takav da $2 \leq t \leq v$ poznato je sljedeće: ako postoji $k$ nagrada vrste $t-1$, tada postoji *strogo više* od $k^2$ nagrada vrste $t$.

Tvoj cilj je osvojiti bistu.
Na kraju igre otvorit ćeš kutiju i osvojiti nagradu koja je u njoj. Prije nego što odabereš kutiju koju ćeš otvoriti možeš pitati voditelja šoua Kileta (Kile je nakon svojeg mentalnog sloma počeo  kockati s Pogijem, skupljati kiki bombone, a nedavno se zaposlio kao voditelj ovoga šoua) nekoliko pitanja. Za svako pitanje odabereš neku kutiju $i$.
Kile će ti kao odgovor dati niz $a$ koji sadrži dva cijela broja.
Njihovo značenje je sljedeće:
* Među kutijama lijevo od kutije $i$ nalazi se točno  $a[0]$ kutija koje sadrže vrjedniju nagradu od one u kutiji $i$.
* Među kutijama desno od kutije $i$ nalazi se točno  $a[1]$ kutija koje sadrže vrjedniju nagradu od one u kutiji $i$.

Primjerice, uzmimo $n=8$. Za svoje pitanje, odabrao si kutiju $i=2$. Kile ti je, kao odgovor, dao $a=[1,2]$. Značenje ovog odgovora je:
* Točno jedna od kutija $0$ i $1$ sadržu nagradu vrjedniju od one u kutiji $2$.
* Točno dvije od kutija $3, 4, \ldots, 7$ sadrže nagradu vrjedniju od one u kutiji $2$.

Tvoj zadatak je pronaći mističnu bistu postavljajući što manji broj pitanja.

## Implementacijski detalji

Trebaš implementirati sljedeću funkciju:

```
int find_best(int n)
```

* Grejder će točno jednom pozvati ovu funkciju.
* $n$: broj kutija.
* Funkcija treba vratiti oznaku kutije u kojoj se nalazi bista, tj. jedinstveni cijeli broj $d$ ($0 \leq d \leq n-1$) takav da kutija $d$ sadrži nagradu vrste $1$.

Funkcija dana iznad može pozivati sljedeću funkciju:

```
int[] ask(int i)
```

* $i$: oznaka kutije za koju postavljaš pitanje. Vrijednost $i$ mora biti između $0$ i $n-1$, uključivo.
* Ova funkcija vraća niz $a$ s $2$ elementa. $a[0]$ je broj vrjednijih nagrada u kutijama lijevo od kutije $i$, a $a[1]$ je broj vrjednijih nagrada u kutijama desno od kutije $i$.


## Primjer

Grejder će učiniti sljedeći poziv funkcije:

```
find_best(8)
```

Ima $n=8$ kutija. Pretpostavimo da su vrste nagrada $[3,2,3,1,3,3,2,3]$.
Svi mogući pozivi funkcije `ask` i odgovarajuće vrijednosti koje ona vraća su dane dolje.

- `ask(0)` vraća $[0, 3]$
- `ask(1)` vraća $[0, 1]$
- `ask(2)` vraća $[1, 2]$
- `ask(3)` vraća $[0, 0]$
- `ask(4)` vraća $[2, 1]$
- `ask(5)` vraća $[2, 1]$
- `ask(6)` vraća $[1, 0]$
- `ask(7)` vraća $[3, 0]$

U ovom primjeru, bista je u kutiji $3$. Dakle, funkcija `find_best` treba vratiti $3$.

![Prize1](prize.png "600") 

Slika iznad ilustrira ovaj primjer.
Gornji dio prikazuje vrijednosti nagrada u svakoj kutiji.
Donji dio prikazuje upit `ask(2)`.
Označene kutije sadrže vrijednije nagrade od one u kutiji $2$.

## Ograničenja

* $3 \leq n \leq 200\,000$.
* Vrsta nagrada u svakoj kutiji je između $1$ i $v$, uključivo.
* Postoji točno jedna nagrada vrste $1$.
* Za svaki $2 \leq t \leq v$, ako postoji $k$ nagrada vrste $t-1$, tada postoji *strogo* više od $k^2$ nagrada vrste $t$.

## Podzadaci i bodovanje

U nekim test primjerima, ponašanje grejdera je adaptivno. To znači da u tim test primjerima grejder nema fiksni niz nagrada, već odgovori koje grejder vraća mogu ovisiti o pitanjima koje vaše rješenje postavlja. Garantirano je da grejder odgovara tako da postoji barem jedan niz nagrada konzistentan sa svim odgovorima koji su dani.

1. (20 bodova) Postoji točno $1$ bista i $n-1$ potpisa (dakle, $v = 2$).
Smiješ pozvati funkciju `ask` najviše $10\,000$ puta.
1. (80 points) Bez dodatnih ograničenja.

U podzadatku 2 možeš ostvariti parcijalne bodove. Neka je $q$ najveći broj poziva funkcije `ask` među svim primjerima u ovom podzadatku. Tada se tvoji bodovi za ovaj podzadatak računaju prema ovoj tablici:

Broj poziva | Bodovi
--- | ---
$10\,000 < q$ | $0$ ( CMS predstavlja kao  'Wrong Answer')
$6000 < q \leq 10\,000$ | $70$
$5000 < q \leq 6000$ | $80 - (q-5000)/100$
$q \leq 5000$ | $80$

## Sempl grejder

Sempl grejder nije adaptivan. Umjesto toga, on iz ulaza čita fiksni niz $p$ koji predstavlja vrste nagarada. Za svaki $0 \leq b \leq n-1$, vrsta nagrade u kutiji $b$ je dana kao $p[b]$.
Sempl grejder očekuje ulaz u sljedećem formatu:

- redak $1$: $\;\; n$
- redak $2$: $\;\; p[0] \;\; p[1]  \; \ldots \; p[n-1]$

Sempl grejder ispisuje jedan redak koji sadrži vrijednost koju je vratila funkcija `find_best` i broj poziva funkcije `ask`.