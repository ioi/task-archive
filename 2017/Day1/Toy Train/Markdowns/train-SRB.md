# Železnice Avalona (train)

Slabo je poznato da Merlin i Morgana rade u dispečerskom centru u Železnicama Avalona. Oni upravljaju železničkim sistemom sa $n$ stanica i $m$ *jednosmernih* pruga. Stanice su označene brojevima od $0$ do $n-1$. Svaka izlazi iz jedne i ulazi u istu ili različitu stanicu. Iz svake stanice izlazi barem jedna pruga.

Neke stanice su *energetske stanice*.
Kad voz stigne u energetsku stanicu, potpuno se napuni.
Potpuno napunjen voz ima dovoljno energije da prođe $n$ uzastopnih pruga.
Tačnije, trenutak pre nego što voz uđe na ($n+1$)-u prugu, nakon poslednjeg punjenja, ostaje bez energije i staje.

Na svakoj stanici je skretnica kojom je moguće usmeriti voz u bilo koju prugu koja izlazi iz te stanice. Voz izlazi iz stanice koristeći prugu u koju ga usmerava skretnica na toj stanici.

Merlin i Morgana igraju sledeću igru.
Podelili su stanice među sobom: svaku stanicu poseduje ili Merlin ili Morgana.
Postoji *jedan* voz i mašinovođa je naravno Persival koji će morati da sluša sve što mu se kaže.
Voz se na početku nalazi u stanici $s$ i potpuno je napunjen.
Igra počinje tako što vlasnik stanice $s$ usmeri skretnicu iz stanice $s$ u jednu od izlaznih pruga.
Tada Persival pokreće voz i kreće na putovanje.

Kad voz prvi put uđe u neku stanicu, vlasnik te stanice usmeri skretnicu u njoj.
Jednom kad je skretnica usmerena, ostaće u toj poziciji do kraja igre.
Dakle, ako voz ponovo uđe u stanicu koju je već posetio, izaći će istom prugom kao i pre.

Obzirom na to da je broj stanica konačan, voz će ući u *ciklus*. Ciklus je niz različitih stanica $c[0], c[1], \cdots, c[k-1]$ takvih da voz iz stanice $c[i]$ (za $0 \leq i < k$) odlazi u stanicu $c[i+1]$, a voz iz stanice $c[k-1]$ odlazi u stanicu $c[0]$.
Moguće je da ciklus sadrži samo jednu stanicu (tj. $k = 1$), što se dešava ako postoji pruga koja ulazi u istu stanicu iz koje i izlazi.

Merlin pobeđuje igru ako voz nikad ne prestane da se kreće, a Morgana ako voz u nekom momentu ostane bez energije.
Drugim rečima, ako postoji barem jedna energetska stanica među stanicama $c[0], c[1], \cdots, c[k-1]$, voz se može napuniti i kružiti zauvek i tada Merlin pobeđuje. U suprotnom će ostati bez energije (moguće nakon što prođe nekoliko krugova) i tada Morgana pobeđuje.

Merlin i Morgana uvek igraju optimalno. To znači da ako neko može pobediti bez obzira na poteze protivnika, tada će zaista i pobediti.

Dat vam je opis železničke mreže. Vaš zadatak je da za svako $0 \leq s \leq n-1$ odredite ko je pobednik ako igra počinje na stanici $s$.

## Detalji implementacije

Treba da implementirate sledeću funkciju:

```
int[] who_wins(int[] a, int[] r, int[] u, int[] v)
```

* $a$: niz dužine $n$. Ako Merlin poseduje stanicu $i$, $a[i] = 1$. Inače, Morgana poseduje stanicu $i$ i $a[i] = 0$.
* $r$: niz dužine $n$. Ako je stanica $i$ energetska stanica, $r[i] =1$. Inače, $r[i] = 0$.
* $u$ i $v$: nizovi dužine $m$.
Za sve $0 \leq i \leq m-1$, postoji jednosmerna pruga iz stanice $u[i]$ prema stanici $v[i]$.
* Ova funkcija treba vratiti niz $w$ dužine $n$.
Vrednost $w[i]$ treba biti $1$ ako Merlin pobeđuje kada igra počinje na stanici $i$ bez obzira na to kako Morgana igra.
Inače, vrednost $w[i]$ treba biti $0$.

## Primer

```
who_wins([0, 1], [1, 0], [0, 0, 1, 1], [0, 1, 0, 1])
```

![Train](train.png)

* Postoje $2$ stanice.
Morgana je vlasnica stanice $0$ koja je energetska stanica.
Merlin je vlasnik stanice $1$, koja nije energetska stanica.
* Postoje $4$ pruge $(0, 0), (0, 1), (1, 0)$ i $(1, 1)$, pri čemu $(i, j)$ označava jednosmernu prugu iz stanice $i$ prema stanici $j$.
* Posmatrajmo igru u kojoj je voz početno na stanici $0$.
Ako Morgana usmeri skretnicu u stanici $0$ prema pruzi $(0, 0)$, voz će beskonačno kružiti ovom prugom (primetite da je stanica $0$ energetska stanica).
U ovom slučaju Merlin pobeđuje.
Inače, ako Morgana usmeri skretnicu u stanici $0$ prema pruzi $(0, 1)$, Merlin može usmeriti skretnicu u stanici $1$ prema $(1, 0)$.
U tom slučaju, voz će beskonačno kružiti kroz obe stanice. Ponovo, Merlin pobeđuje jer je stanica $0$ energetska stanica i voz se neće zaustaviti.
Dakle, Merlin može pobediti, bez obzira na to šta Morgana uradi.
* Slično možemo zaključiti da će Merlin pobediti i ako Persival polazi iz stanice $1$ bez obzira na to kako Morgana igra. Funkcija treba vratiti $[1, 1]$.

## Ograničenja

* $1 \leq n \leq 5000$.
* $n \leq m \leq 20\,000$.
* Postoji bar jedna energetska stanica.
* Iz svake stanice izlazi bar jedna pruga.
* Mogu postojati pruge koje izlaze i ulaze u istu stanicu (tj. $u[i] = v[i]$).
* Sve pruge su različite. Drugim rečima, ne postoje indeksi $i$ i $j$ ($0 \leq i < j \leq m-1$) takvi da $u[i]=u[j]$ i $v[i]=v[j]$.
* $0 \leq u[i], v[i] \leq n-1$ (za sve $0 \leq i \leq m-1$).

## Podzadaci

1. (5 bodova) Za sve $0 \leq i \leq m-1$, ili $v[i] = u[i]$ ili $v[i] = u[i] + 1$.
2. (10 bodova) $n \leq 15$.
3. (11 bodova) Merlin poseduje sve stanice.
4. (11 bodova) Morgana poseduje sve stanice.
5. (12 bodova) Postoji tačno jedna energetska stanica.
6. (51 bodova) Nema dodatnih ograničenja.

## Primer grejdera

Primer grejdera čita ulazne podatke u sledećem formatu:
* linija $1$: $\;\; n \;\; m$
* linija $2$: $\;\; a[0] \;\; a[1] \; \ldots\; a[n-1]$
* linija $3$: $\;\; r[0] \;\; r[1] \; \ldots\; r[n-1]$
* linija $4 + i$ (za $0 \leq i \leq m-1$): $\;\; u[i] \;\; v[i]$

Primer grejdera ispisuje vrednost koju vraća funkcija `who_wins` u sledećem formatu:
* linija $1$: $\;\; w[0] \;\; w[1] \; \ldots\; w[n-1]$