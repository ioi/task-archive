# Ožičenje

Maryam je elektroinženirka. 
Dobila je nalogo, da postavi žice na novem komunikacijskem stolpu. 
Na stolpu je potrebno povezati nekaj točk, ki so postavljenje na različnih višinah. 
Žico lahko uporabi, da poveže dve točki. 
Vsaka točka je lahko povezana na določeno število žic. 
Obstajata dva tipa točk: rdeče in modre.

Za namen te naloge lahko na stolp gledamo kot premico, točke pa kot rdeče in modre točke na ne-negativnih koordinatah te premice.
Dolžina žice je enaka razdalji med točkama, ki ju žica povezuje.

Tvoja naloga je, da pomagaš Maryam poiskati shemo ožičenja, tako da velja:

* $1$. Vsaka točka mora biti povezana z vsaj eno drugo točko nasprotne barve.
* $2$. Skupna dolžina žic je minimalna.

## Podrobnosti implementacije

Implementirati moraš funkcijo:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: polje dolžine $n$, ki vsebuje položaje rdečih točk v naraščajočem vrstnem redu.
* $b$: polje dolžine $m$, ki vsebuje položaje modrih točk v naraščajočem vrstnem redu.
* Funkcija naj vrne minimalno dolžino žic med vsemi veljavnimi shemami.
* Funkcija naj vrne rezultat tipa `int64`.

## Primer

``` 
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Spodnja skica prikazuje ta primer.
![Wiring](wiring.png)

* Stolp je prikazan vodoravno.
* Na sivinski tiskani obliki so rdeče točke predstavljene temneje, modre pa svetleje.
* Imamo $4$ rdeče točke na pozicijah $1, 2, 3$ in $7$.
* Imamo $5$ modrih točk na pozicijah $0, 4, 5, 9$ in $10$.
* Ena izmed optimalnih rešitev je prikazana zgoraj.
* Pri tej rešitvi je skupna dolžina žic enaka $1+2+2+2+3 = 10$, kar je optimalno. Zato funkcija vrne $10$.
* Na točko $7$ sta zezani dve žici.

## Omejitve

* $1 \leq n, m \leq 100\,000$, 
* $0 \leq r[i] \leq 10^9$ (za vse $0 \leq i \leq n-1$), 
* $0 \leq b[i] \leq 10^9$ (za vse $0 \leq i \leq m-1$),
* Polji $r$ in $b$ sta urejeni v naraščajočem vrstnem redu.
* Vse vrednosti $n+m$ v poljih $r$ in $b$ so različne.

## Podnaloge

* $1.$ podnaloga: (7 točk) $n,m \leq 200$
* $2.$ podnaloga: (13 točk) Vse rdeče točke so na položajih manjših kot katerakoli modra točka.
* $3.$ podnaloga: (10 točk) Med $7$ zaporednimi točkami je vsaj ena rdeča in vsaj ena modra točka.
* $4.$ podnaloga: (25 točk) Vse točke imajo različne položaje na intervalu $[1, n+m]$.
* $5.$ podnaloga: (45 točk) Ni dodatnih omejitev.

## Vzorčni ocenjevalnik

Vzorčni ocenjevalnik prebere vhod sledeče oblike:

* $1.$ vrstica: $\;\; n \;\; m$
* $2.$ vrtica: $\;\; r[0] \;\; r[1] \; \ldots \; r[n-1]$
* $3.$ vrstica: $\;\; b[0] \;\; b[1] \; \ldots \; b[m-1]$

Vzorčni ocenjevalnik izpiše eno vrstico, ki vsebuje vrednost, ki jo vrne funkcija `min_total_length`.
