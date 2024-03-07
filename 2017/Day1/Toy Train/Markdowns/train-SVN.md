# Vlakec

Arezou in njen brat Borzou sta dvojčka.
Za rojstni dan sta dobila fantastičen komplet električne železnice in vlakca. Z njim sta sestavila omrežje z $n$ postajami in $m$ *enosmernimi* tiri. Postaje so označene s števili od $0$ do $n-1$.
Vsak tir se prične na eni postaji in se zaključi na isti ali neki drugi postaji.
Na vsaki postaji se začne vsaj en tir.

Nekatere izmed postaj so *polnilnice*.
Kadarkoli vlakec zapelje na polnilnico, se popolnoma napolni.
Popolnoma napolnjen vlakec ima dovolj energije da prepotuje $n$ zaporednih tirov.
To je, vlakcu zmanjka energije v trenutku ko zapelje na $(n+1)$-ti tir po zadnjem polnjenju.

Na vsaki postaji je kretnica, ki določa na kateri izmed izhodnih tirov bo vlakec zapeljal.
Ko je vlakec na postaji, jo zapusti na tiru določenem s kretnico na tej postaji.

Dvojčka bosta odigrala igro s svojim vlakcem.
Med seboj sta si razdelila vse postaje: vsaka postaja je ali Arezouvina ali Borzouova.
Obstaje zgolj en vlakec.
Na začetku igre je vlakec na postaji $s$ in je popolnoma napolnjen.
Da se igra prične, lastnik postaje $s$ nastavi kretnico postaje $s$ na enega izmed tirov ki se pričnejo na postaji $s$.
Za tem vklopita vlakec in vlakec prične potovati po tirih.

Kadarkoli vlakec prvič prispe na določeno postajo, njen lastnik nastavi kretnico te postaje.
Ko je kretnica nastavljena, ostane v tem položaju do konca igre.
Torej, če vlakec ponovno prispe na postajo katero je že obiskal, jo bo zapustil po istem tiru kot predhodno.

Ker obstaja končno mnogo postaj, bo vlakec slej kot prej pričel potovati po *ciklu*.
Cikel je zaporedje *različnih* postaj $c[0], c[1], \cdots, c[k-1]$, kjer vlakec zapusti postajo $c[i]$ (za $0 \leq i < k-1$) po tiru, ki gre do postaje $c[i+1]$, ter zapusti postajo $c[k-1]$ po tiru, ki gre nazaj do postaje $c[0]$.
Zapazimo, da cikel lahko vsebuje eno samo postajo (t.j., $k=1$) če vlakec zapusti postajo $c[0]$ po tiru, ki gre nazaj do iste postaje $c[0]$.

Arezou zmaga igro, če se vlakec nikoli ne ustavi, Borzou pa zmaga v primeru, ko vlakcu zmanjka energije. 
Z drugimi besedami, če se med postajami $c[0], c[1], \cdots, c[k-1]$ nahaja vsaj ena polnilnica, se vlakec lahko napolni in potuje po ciklu v neskončnost in zmaga Arezou.
V nasprotnem primeru bo vlakcu zmanjkalo energije (po možnosti po večkratnem obhodu cikla) in zmaga Borzou.

Podan je opis železniškega omrežja.
Arezou in Borzou bosta odigrala $n$ iger.
V $s$-ti igri, za $0 \leq s \leq n-1$, bo vlakec na začetku stal na postaji $s$.
Tvoja naloga je ugotoviti za vsako igro, ali obstaja takšna strategija za Arezou, ki ji zagotavlja zmago, neglede na to, kako igra Borzou.

<dl>
  <dt> &nbsp;</dt>
  <dd>&nbsp;</dd>
</dl>
## Podrobnosti implementacije

Implementiraj naslednjo funkcijo:

```
int[] who_wins(int[] a, int[] r, int[] u, int[] v)
```

* $a$: polje dolžine $n$. Če si Arezou lasti postajo $i$, $a[i] = 1$. Sicer si jo lasti Borzou in $a[i] = 0$.
* $r$: polje dolžine $n$. Če je $i$-ta postaja polnilnica, $r[i] =1$. Sicer $r[i] = 0$.
* $u$ in $v$: polji dolžine $m$.
Za vse $0 \leq i \leq m-1$, obstaja enosmerni tir, ki se začne pri postaji $u[i]$ in zaključi pri postaji  $v[i]$.
* Funkcija naj vrne polje $w$ dolžine $n$.
Za vsak $0 \leq i \leq n-1$, naj bo vrednost $w[i]$ $1$, če lahko Arezou zmaga igro, ki se prične na postaji $i$, ne grede na to, kako igra Borzou.
V nasprotnem primeru naj bo vrednost $w[i]$ enaka $0$.

## Primer

```
who_wins([0, 1], [1, 0], [0, 0, 1, 1], [0, 1, 0, 1])
```

![Train](train.png)

* Obstajata $2$ postaji.
Borzou je lastnik postaje $0$, ki je polnilnica.
Arezou lastnica postaje $1$, ki ni polnilnica.
* Obstajajo $4$ tiri $(0, 0), (0, 1), (1, 0)$, in $(1, 1)$, kjer $(i, j)$ predstavlja enosmerni tir med postajo $i$ in postajo $j$.
* Razmislimo o igri, kjer je vlakec začne na postaji $0$.
Če Borzou nastavi kretnico na postaji $0$ proti tiru $(0, 0)$, bo vlakec v neskončnost krožil po tem tiru (postaja $0$ je polnilnica).
V tem primeru zmaga Arezou.
Sicer, če Borzou nastavi kretnico postaje $0$ proti tiru $(0, 1)$, lahko Arezou nastavi kretnico postaje $1$ proti $(1, 0)$.
Če se to zgodi, bo vlakec neskončno krožil med obema postajama. Ponovno zmaga Arezou, saj je postaja $0$ polnilnica in se vlakec ne bo ustavil.
Zato lahko Arezou zmaga igro, ne glede na to, kaj naredi Borzou.
* Po podobnem razmisleku, v igri ki se prične na postaji $1$, lahko Arezou zmaga, ne glede na to kako igra Borzou. Zatorej bo funkcija vrnila $[1, 1]$.

<dl>
  <dt> &nbsp;</dt>
  <dd>&nbsp;</dd>
  <dd>&nbsp;</dd>
  <dd>&nbsp;</dd>
  <dd>&nbsp;</dd>
</dl>
## Omejitve

* $1 \leq n \leq 5000$.
* $n \leq m \leq 20\,000$.
* Obstaja vsaj ena polnilnica.
* Na vsaki postaji se prične vsaj en tir.
* Lahko obstajajo tiri, ki se pričnejo in končajo na isti postaji (t.j., $u[i] = v[i]$).
* Vsak tir je edinstven.
Povedano drugače, ne obstajata takšna dva indeksa $i$ in $j$ ($0 \leq i < j \leq m-1$), tako da $u[i]=u[j]$ in $v[i]=v[j]$.
* $0 \leq u[i], v[i] \leq n-1$ (za vse $0 \leq i \leq m-1$).

## Podnaloge

1. (5 točk) Za vse $0 \leq i \leq m-1$ velja ali $v[i] = u[i]$ ali $v[i] = u[i] + 1$.
1. (10 točk) $n \leq 15$.
1. (11 točk) Arezou si lasti vse postaje.
1. (11 točk) Borzou si lasti vse postaje.
1. (12 točk) Obstaja natanko ena polnilnica.
1. (51 točk) Brez dodatnih omejitev.

## Vzorčni ocenjevalnik

Vzorčni ocenjevalnik bere vhod v naslednji obliki:
* $1$. vrstica: $\;\; n \;\; m$
* $2$. vrstica: $\;\; a[0] \;\; a[1] \; \ldots\; a[n-1]$
* $3$. vrstica: $\;\; r[0] \;\; r[1] \; \ldots\; r[n-1]$
* vrstice $4 + i$ (za $0 \leq i \leq m-1$): $\;\; u[i] \;\; v[i]$

Vzorčni ocenjevalnik izpiše rezultat funkcije `who_wins` v naslednji obliki:
* $1$. vrstica: $\;\; w[0] \;\; w[1] \; \ldots\; w[n-1]$