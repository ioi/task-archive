# Starinske bukve

V Teheranu je Narodna knjižnica Irana.
Glavni zaklad knjižnice se skriva v dolgi dvorani z $n$ mizami, označenimi s števili od $0$ do $n-1$ od leve proti desni.
Na vsaki mizi je izložena ena starinska bukva.
Bukve so urejene po starosti, kar pa obiskovalcem, ki iščejo knjige po naslovih, povzroča preglavice.
Zatorej se je knjižničar odločil, da knjige uredi v abecednem redu.

Knjižničar Aryan bo opravil delo.
Napravil je seznam $p$ dolžine $n$, ki vsebuje različna števila od $0$ do $n-1$.
Seznam opisuje potrebne spremembe, da bodo knjige v abecednem redu:
za vse $0 \leq i < n$ mora prestaviti knjigo z mize $i$ na mizo $p[i]$.

Aryan začne urejati pri mizi $s$.
Ko konča z urejanjem, želi biti pri isti mizi.
Ker so knjige dragocene, ne sme nositi več kot eno hkrati.
Ko Aryan ureja knjige napravi sledeče zadeve.
Vsako dejanje mora biti eno od sledečih:
* Če ne nosi nobene knjige v roki in je pri mizi, na kateri je knjiga, jo vzame.
* Če nosi knjigo in je pri mizi, na kateri je knjiga, jo sme zamenjati.
* Če nosi knjigo in na mizi, pri kateri je, ni nobene knjige, sme na mizo položiti knjigo.
* Ko se sprehaja med mizami, sme nositi eno knjigo.

Za vse $0 \leq i, j \leq n-1$ velja, da je razdalja med mizama $i$ in $j$ natanko $|j-i|$ metrov. Tvoja naloga je, da poiščeš najmanjšo skupno razdaljo, ki jo mora Aryan prehoditi, da uredi vse knjige in zaključi pri mizi $s$.

## Podrobnosti implementacije

Implementirati moraš naslednjo funkcijo:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ polje dolžine $n$.
Knjigo, ki je na mizi $i$, mora Aryan odnesti na mizo $p[i]$ (za vse $0 \leq i < n$).
* $s$ je oznaka mize, pri kateri se Aryan nahaja na začetku in kjer mora končati z urejanjem knjig.
* Funkcija naj vrne najmanjšo skupno razdaljo (v metrih), ki jo mora Aryan prehoditi.

## Primer

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

V tem primeru $n=4$ in Aryan se na začetku nahaja pri mizi $0$. 
Knjige uredi na sledeči način:
* Sprehodi se do mize $1$ in z nje vzame knjigo. Knjigo mora prestaviti na mizo $2$.
* Zato se sprehodi do mize $2$ in zamenja knjigi. 
To knjigo mora prestaviti na mizo $3$.
* Sprehodi do mize $3$, kjer zamenja knjigi. 
Novo knjigo mora prestaviti na mizo $1$.
* Zato se sprehodi do mize $1$, kjer zamenja knjigi.
* Končno se lahko sprehodi do mize $0$.

Knjiga na mizi $0$ je že na pravem mestu, zato mu je ni treba vzeti.
Skupna razdalja rešitve je $6$ metrov.
To je tudi najboljša rešitev, zatorej naj funkcija vrne $6$.

## Omejitve

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* Polje $p$ vsebuje $n$ različnih celih števil med vključno $0$ in $n-1$.

## Podnaloge

1. (12 točk) $n \le 4$ in $s = 0$
1. (10 točk) $n \le 1000$ in $s = 0$
1. (28 točk) $s = 0$
1. (20 točk) $n \le 1000$
1. (30 točk) ni dodatnih omejitev

## Vzorčni ocenjevalnik

Vzorčni ocenjevalnik bere vhod sledeče oblike:

- $1.$ vrstica: $\;\; n \;\; s$
- $2.$ vrstica: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

Vzorčni ocenjevalnik izpiše eno vrstico, ki vsebuje vrnjeno vrednost funkcije `minimum_walk`.