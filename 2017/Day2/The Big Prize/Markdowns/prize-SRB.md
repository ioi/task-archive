# Utešna nagrada (prize)

Nakon završene Balkanijade iz programiranja za sve takmičare koji nisu uspeli da osvoje medalju na takmičenju organizovana je nagradna igra "Utešna nagrada" gde takmičari imaju šansu da osvoje barem nešto i ne odu kući praznih ruku.

Tom prilikom je pred Momčiloda postavljen niz od $n$ kutija, označenih od $0$ do $n-1$, s leva na desno.
Svaka kutija sadrži tačno jednu nagradu, koja ostaje nepoznata dok se ta kutija ne otvori.
Postoji $v \geq 2$ tipova nagrada.
Tipovi su numerisani od $1$ do $v$ po *opadajućem* redosledu vrednosti.

Nagrada tipa $1$ je najskuplja: dijamantske štikle.
Postoje tačno jedne dijamantske štikle u kutijama.
Nagrada tipa $v$ je najjeftinija: lizalica.
Kako bi igra bila uzbudljivija, broj jeftinijih nagrada je mnogo veći od broja skupljih nagrada.
Preciznije, za svako $t$ za koje $2 \leq t \leq v$ znamo sledeće:
Ako ima $k$ nagrada tipa $t-1$, onda ima *strogo više* od $k^2$ nagrada tipa $t$.

Momčilodov cilj je da osvoji dijamantske štikle.
Na kraju igre Momčilod otvara jednu kutiju i osvaja nagradu koja se nalazi u njoj.
Pre nego što odabere koju će kutiju otvoriti, ima priliku da Tinadi, voditeljki kviza, postavi neka pitanja.
Za svako pitanje odabira neku kutiju $i$.
Kao svoj odgovor, Tinada će dati niz $a$ koji sadrži dva cela broja.
Njihovo značenje je sledeće:
* Među svim kutijama levo od kutije $i$ ima tačno $a[0]$ kutija koje sadrže skuplju nagradu od nagrade u kutiji $i$. 
* Među svim kutijama desno od kutije $i$ ima tačno $a[1]$ kutija koje sadrže skuplju nagradu od nagrade u kutiji $i$. 

Na primer, pretpostavimo da je $n=8$. Za svoje pitanje odabrao je kutiju $i=2$.
Tinadin odgovor je $a=[1,2]$.
Značenje ovog odgovora je:
* Tačno jedna od kutija $0$ i $1$ sadrži nagradu koja je skuplja od nagrade u kutiji $2$.
* Tačno dve od kutija $3, 4, \ldots, 7$ sadrže nagradu koja je skuplja od nagrade u kutiji $2$.

Tvoj zadatak je da pomogneš Momčilodu da nađe kutiju koja sadrži dijamantske štikle postavljajući mali broj pitanja.

## Detalji implementacije

Potrebno je da implementiraš sledeću funkciju:

```
int find_best(int n)
```

* Ova procedura se poziva tačno jednom od strane grejdera.
* $n$: broj kutija.
* Ova funkcija treba da vrati oznaku kutije koja sadrži dijamantske štikle, tj. ceo broj $d$ ($0 \leq d \leq n-1$) takav da kutija $d$ sadrži nagradu tipa $1$.

Ova funkcija može da poziva sledeću funkciju:

```
int[] ask(int i)
```

* $i$: oznaka kutije za koju postavljaš pitanje. Vrednost $i$ mora biti između $0$ i $n-1$, uključujući i te brojeve.
* Ova funkcija vraća niz $a$ sa $2$ elementa. Ovde je $a[0]$ broj skupljih nagrada u kutijama levo od kutije $i$, a $a[1]$ je broj skupljih nagrada u kutijama desno od kutije $i$.

## Primer

Grader poziva sledeću proceduru:

```
find_best(8)
```

Postoji $n=8$ kutija. Pretpostavimo da su tipovi nagrada $[3,2,3,1,3,3,2,3]$. Svi mogući pozivi procedure `ask` i odgovarajući odgovori su navedeni ispod.

- `ask(0)` vraća $[0, 3]$
- `ask(1)` vraća $[0, 1]$
- `ask(2)` vraća $[1, 2]$
- `ask(3)` vraća $[0, 0]$
- `ask(4)` vraća $[2, 1]$
- `ask(5)` vraća $[2, 1]$
- `ask(6)` vraća $[1, 0]$
- `ask(7)` vraća $[3, 0]$

U ovom primeru, dijamantske štikle su u kutiji $3$, te zbog toga procedura `find_best` treba da vrati $3$.

![Prize1](prize.png "600") 

Slika iznad prikazuje ovaj primer (dijamantske štikle su zgodno označene dijamantom).
Gornji deo slike prikazuje tipove nagrada u svakoj kutiji.
Donji deo slike prikazuje upit `ask(2)`. Čekirane kutije sadrže vrednije nagrade od nagrade koja se nalazi u kutiji $2$.

## Ograničenja

* $3 \leq n \leq 200\,000$.
* Tipovi nagrada u svakoj od kutija su između $1$ i $v$, uključujući te brojeve.
* Postoji tačno jedna nagrada tipa $1$.
* Za sve $2 \leq t \leq v$, ukoliko postoji $k$ nagrada tipa $t-1$, onda postoji *strogo* više od $k^2$ nagrada tipa $t$.

## Podzadaci i bodovanje

U nekim test primerima grejder može da se ponaša adaptivno. To znači da u tim test primerima grejder nema fiksan niz nagrada, nego odgovor grejdera može da zavisi od pitanja koje mu tvoj program postavi.
Garantuje se da će grejder odgovarati tako da nakon svakog odgovora postoji barem jedan niz nagrada konzistentan sa svim odgovorima do tada.

1. (20 bodova) Postoji tačno $1$ dijamantske štikole i $n-1$ lizalica ($v = 2$). Možes pozvati proceduru `ask` najviše $10\,000$ puta.
1. (80 bodova) Nema dodatnih ograničenja.

U podzadatku 2 možes da dobiješ parcijalne bodove.
Neka je $q$ najveći broj poziva procedure `ask` među svim test primerima u ovom podzadatku.
Onda će se tvoj broj bodova za ovaj podzadatak računati prema sledećoj tabeli:

Broj pitanja | Bodovi
--- | ---
$10\,000 < q$ | $0$ (prikazano u CMS-u kao 'Wrong Answer')
$6000 < q \leq 10\,000$ | $70$
$5000 < q \leq 6000$ | $80 - (q-5000)/100$
$q \leq 5000$ | $80$

## Primer grejdera

Primer grejdera nije adaptivan.
Umesto toga, primer grejdera samo učitava i koristi fiksan niz tipova nagrada $p$. Za sve $0 \leq b \leq n-1$, tip nagrade u kutiji $b$ je dat sa $p[b]$.
Primer grejdera očekuje ulaz u sledećem formatu:

- linija $1$: $\;\; n$
- linija $2$: $\;\; p[0] \;\; p[1]  \; \ldots \; p[n-1]$

Primer grejdera ispisuje jednu liniju koja sadrži vraćenu vrednost od funkcije `find_best` i broj poziva procedure `ask`.