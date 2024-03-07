# Toy Train

Adriana i njezin brat Beker su blizanci. Za svoj rođendan dobili su veliki vlačni skup. Od njega su sastavili sustav željeznica s $n$ stanica i $m$ jednosmjernih pruga. Stanice su označene brojevima od $0$ do $n-1$. Svaka pruga polazi iz jedne i dolazi u istu ili različitu stanicu. Iz svake stanice polazi barem jedna pruga.

Neke stanice su *punjene stanice*.
Kad god vlak stigne u punjenu stanicu, potpuno se napuni.
Potpuno napunjeni vlak ima dovoljno energije da prođe $n$ uzastopnih pruga.
Točnije, trenutak prije nego vlak uđe na ($n+1$)-u prugu nakon zadnjeg punjenja, ostane bez energije i stane.

Na svakoj stanici je skretnica koji je moguće usmjeriti u bilo koju prugu koja polazi iz te stanice. Vlak izlazi iz stanice koristeći prugu u koju ga usmjerava skretnica na toj stanici.

Blizanci će zaigrati sljedeću igru sa svojim vlakom.
Podijelili su stanice među sobom: svaku stanicu posjeduje ili Adriana ili Beker.
Postoji jedaaan vlak.
Na početku vlak se nalazi u stanici $s$ i potpuno je napunjen.
Igra počinje time što vlasnik stanice $s$ usmjeri skretnicu iz stanice $s$ u jednu od izlaznih pruga.
Tada uključe vlak i on kreće putovati prugama.

Kad god vlak prvi put uđe u stanicu, vlasnik te stanice usmjeri skretnicu u njoj.
Jednom kad je skretnica postavljena, ostat će u toj poziciji do kraja igre.
Dakle, ako vlak ponovo uđe u stanicu koju je već posjetio, izaći će istom prugom kao i prije.

S obzirom da je broj stanica konačan, vlak će ući u *ciklus*. Ciklus je niz jedinstvenih stanica $c[0], c[1], \cdots, c[k-1]$ takvih da vlak iz stanice $c[i]$ (for $0 \leq i < k$) izlazi prugom prema stanici $c[i+1]$. Poviše, vlak iz stanice $c[k-1]$ izlazi prugom prema stanici $c[0]$.
Ciklus može sadržavati samo jednu stanicu (t.j. $k = 1$) ako postoji pruga koja izlazi iz te stanice i ulazi u nju.

Adriana pobjeđuje igru ako se vlak nastavi kretati dok Kile ne osvoji medalju na olimpijadi (tj. beskonačno), a Beker ako vlak ostane bez energije.
Drugim riječima, ako postoji barem jedna punjena stanica među $c[0], c[1], \cdots, c[k-1]$, vlak se može napuniti i kružiti dok ne sastavimo stabilnu vladu i Adriana pobjeđuje.
Inače će ostati bez energije (moguće nakon što prođe nekoliko krugova) i Beker pobjeđuje.

Oba djeteta su pametna i uvijek igraju optimalno. To znači da ako igrač može pobijediti bez obzira na protivnikove poteze, tada će uistinu i pobijediti.

Dan vam je opis željezničke mreže i zadatak vam je za svaki $0 \leq s \leq n-1$ odrediti tko je pobjednik ako igra počinje na stanici $s$.

## Implementacijski detalji

Trebate implementirati sljedeću funkciju:

```
int[] who_wins(int[] a, int[] r, int[] u, int[] v)
```

* $a$: niz duljine $n$. Ako Adriana posjeduje stanicu $i$, $a[i] = 1$. Inače, Beker posjeduje $i$ i $a[i] = 0$.
* $r$: niz duljine $n$. Ako je stanica $i$ punjena stanica, $r[i] =1$. Inače, $r[i] = 0$.
* $u$ i $v$: nizovi duljine $m$.
Za sve $0 \leq i \leq m-1$, postoji jednosmjerna pruga iz stanice $u[i]$ prema stanici $v[i]$.
* Ova funkcija treba vratiti niz $w$ duljine $n$.
Vrijednost $w[i]$ treba biti $1$ ako Adriana pobjeđuje kada igra počinje na stanici $i$.
Inače, vrijednost $w[i]$ treba biti $0$.

## Primjer

```
who_wins([0, 1], [1, 0], [0, 0, 1, 1], [0, 1, 0, 1])
```

![Train](train.png)

* Postoje $2$ stanice.
Beker je vlasnik stanice $0$ koja je punjena stanica.
Adriana je vlasnica stanice $1$, koja nije punjena stanica.
* Postoje $4$ pruge $(0, 0), (0, 1), (1, 0)$ i $(1, 1)$, pri čemu $(i, j)$ označava jednosmjernu prugu iz stanice $i$ prema stanici $j$.
* Promotrimo igru u kojoj je vlak početno na stanici $0$.
Ako Beker usmjeri skretnicu u stanici $0$ prema pruzi $(0, 0)$, vlak će beskonačno kružiti ovom prugom (primijetite da je stanica $0$ punjena stanica).
U ovom slučaju Adriana pobjeđuje.
Inače, ako Beker usmjeri skretnicu u stanici $0$ prema pruzi $(0, 1)$, Adriana može usmjeriti skretnicu u stanici $1$ prema $(1, 0)$.
U tom slučaju, vlak će beskonačno kružiti kroz obje stanice. Ponovo, Adriana pobjeđuje jer je stanica $0$ punjena stanica i vlak se neće zaustaviti.
Dakle, Adriana može pobijediti, bez obzira što Beker učini.
* Promotrimo sada igru u kojoj je vlak početno na stanici $1$.
Adriana može usmjeriti skretnicu u stanici $1$ prema pruzi $(1, 0)$.
Ako Beker usmjeri skretnicu u stanici $0$ prema pruzi $(0, 0)$ vlak će izaći iz stanice $1$, ući u stanicu $0$ i beskonačno kružiti kroz nju, dakle Adriana pobjeđuje.
Inače, ako Beker usmjeri skretnicu u stanici $0$ prema pruzi $(0, 1)$ vlak će beskonačno kružiti kroz obje stanice.
* U obje igre Adriana pobjeđuje, pa funkcija treba vratiti $[1, 1]$.

## Ograničenja

* $1 \leq n \leq 5000$.
* $n \leq m \leq 20\,000$.
* Postoji barem jedna punjena stanica.
* Iz svake stanice izlazi barem jedna pruga.
* Mogu postojati stanice koje izlaze i ulaze u istu stanicu (i.e., $u[i] = v[i]$).
* Sve pruge su jedinstvene.
Drugim riječima, ne postoje indeksi $i$ i $j$ ($0 \leq i < j \leq m-1$) takvi da $u[i]=u[j]$ i $v[i]=v[j]$.
* $0 \leq u[i], v[i] \leq n-1$ (za sve $0 \leq i \leq m-1$).

## Podzadaci

1. (5 bodova) Za sve $0 \leq i \leq m-1$, ili $v[i] = u[i]$ ili $v[i] = u[i] + 1$.
2. (10 bodova) $n \leq 15$.
3. (11 bodova) Adriana posjeduje sve stanice.
4. (11 bodova) Beker posjeduje sve stanice.
5. (12 bodova) Postoji točno jedna punjena stanica.
6. (51 bodova) Bez dodatnih ograničenja.

## Sempl grejder

Sempl grejder čita ulazne podatke u sljedećem formatu:
* redak $1$: $\;\; n \;\; m$
* redak $2$: $\;\; a[0] \;\; a[1] \; \ldots\; a[n-1]$
* redak $3$: $\;\; r[0] \;\; r[1] \; \ldots\; r[n-1]$
* redak $4 + i$ (za $0 \leq i \leq m-1$): $\;\; u[i] \;\; v[i]$

Sempl grejder ispisuje vrijednost koju vraća funkcija `who_wins` u sljedećem formatu:
* redak $1$: $\;\; w[0] \;\; w[1] \; \ldots\; w[n-1]$
