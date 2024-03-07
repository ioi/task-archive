# Toy Train

Blizanci Arezou i Borzou su za rođendan dobili fantastičan poklon: model vozića na baterije i skup šina i stanica.Oni žele da sagrade mini željeznički sistem od $n$ stanica, numerisanih brojevima od $0$ do $n-1$ i  $m$ *jednosmjernih* linija. Moguće je postaviti šine tako da obrazuju *jednosmjerne* linije između stanica, tako da svaka linija polazi iz jedne stanice i završava u istoj ili drugoj stanici. Iz svake stanice polazi bar jedna linija.

Neke stanice su *energetske stanice*. Uvijek kada vozić dođe u *energetsku stanicu* dopunjava svoju bateriju na maksimalnu vrijednost. Takav vozić ima dovoljno energije da može putovati duž $n$ uzastopnih linija. To znači da će, od trenutka posljednjeg punjena baterije, vozić neposredno prije ulaska u $(n+1)$-vu liniju ostati bez energije    

U svakoj stanici postoji skretnica koji se može pomjeriti tako da pokazuje na bilo koju liniju koja polazi iz te stanice. Vozić napušta stanicu po onoj liniji na koju pokazuje skretnica.  

Blizanci planiraju posebnu igru sa svojom novom igračkom. 
Već su podijelili stanice, tako da je svaka od stanica pripala ili  Arezou ili Borzou.
Postoji tačno jedan vozić, koji se na početku igre nalazi u stanici  $s$ a baterija je napunjena do maksimuma. 
Na početku igre,  vlasnik stanice $s$ pomjera skretnicu te stanice na jednu od linija koje polaze iz stanice $s$. 
Zatim, pokreće vozić koji počinje putovanje duž linija.

Uvijek kada vozić prvi put uđe u neku od stanica, vlasnik stanice postavi skretnicu u toj stanici. Jednom postavljena skretnica ostaje na toj poziciji do kraja igre.   
Dakle, ako vozić ponovi uđe u stanicu koju je već posjetio, napustiće je po istoj liniji kao i ranije. 

Kako postoji konačan broj stanica, vozić će upasti u takozvani  *ciklus*.
Ciklus je niz *različitih* stanica $c[0], c[1], \cdots, c[k-1]$ takvih da vozić napušta stanicu  $c[i]$ (za $0 \leq i < k-1$) koristeći liniju ka stanici  $c[i+1]$, a na kraju napušta stanicu  $c[k-1]$ koristeći liniju ka stanici $c[0]$.
Primjetite da ciklus može imati i samo jednu stanicu  (npr., kada je $k=1$) ako vozić napušta stanicu  $c[0]$ koristeći liniju koja ga vraća u  $c[0]$.

Arezou pobjeđuje ako vozić nikada ne stane (tj. kreće se beskonačno), dok Borzou pobjeđuje ako vozić ostane bez energije tj, kada mu se istroši baterija.  
Drugim riječima, ako je bar jedna od stanica  $c[0], c[1], \cdots, c[k-1]$ *energetska stanica*, vozić može dopuniti bateriju i kretati se beskonačno, pa pobjeđuje Arezou. U suprotnom, vozić će ostati bez energije, moguće poslije više prolazaka kroz ciklus, pa pobjeđuje Borzou.

Dat je opis sistema koji su blizanci napravili.
Arezou i Borzou odigraće  $n$ partija.
U $s$-toj partiji igre, gdje je $0 \leq s \leq n-1$, polazna stanica vozića biće stanica $s$.
Vaš zadatak je da za svaku od partija odredite da li postoji strategija koja garantuje pobjedu Arezou, bez obzira kako igra Borzou.

## Detalji implementacije

Implementirajte sljedeću funkciju:

```
int[] who_wins(int[] a, int[] r, int[] u, int[] v)
```

* $a$: niz dužine $n$. Ako je Arezou vlasnik stanice $i$, $a[i] = 1$. U suprotnom, Borzou je vlasnik  stanice $i$ i $a[i] = 0$.
* $r$: niz dužine $n$. Ako je stanica $i$ *energetska stanica*, $r[i] =1$. U suprotnom, $r[i] = 0$.
* $u$ i $v$: nizovi dužine $m$.
Za svako $0 \leq i \leq m-1$, postoji jednosmjerna linija koja polazi iz stanice $u[i]$ i završava u stanici $v[i]$.
* Ova funkcija vraća niz $w$ dužine $n$.
Za svako $0 \leq i \leq n-1$, vrijednost $w[i]$ treba da je $1$ ako Arezou može pobijediti u partiji koja počinje iz stanice $i$, bez obzira kako Borzou igra.
U suprotnom, vrijednost $w[i]$ treba da je $0$.

## Primjer

```
who_wins([0, 1], [1, 0], [0, 0, 1, 1], [0, 1, 0, 1])
```

![Train](train.png)

* Postoje $2$ stanice.
Borzou je vlasnik stanice $0$, koje je energetska stanica.
Arezou je vlasnik stanice $1$, koje nije energetska stanica.
* Postoje $4$ linije $(0, 0), (0, 1), (1, 0)$ i $(1, 1)$, gdje  $(i, j)$ označava jednosmjernu liniju od stanice $i$ do stanice $j$.
* Razmotrićemo slučaj partije u kojoj je vozić na početku u stanici  $0$.
Ako Borzou postavi skretnicu na stanici  $0$ ka liniji $(0, 0)$, vozić će se beskonačno kretati po toj liniji (primjetite da je stanica $0$ energetska stanica), pa pobjeđuje Arezou.
Ako Borzou postavi skretnicu na stanici  $0$ ka liniji $(0, 1)$, Arezou može postaviti skretnicu na stanici  $1$ ka liniji $(1, 0)$, pa će vozić beskonačno kružiti kroz obje stanice. Opet pobjeđuje Arezou jer je stanica $0$ energetska stanica i vozić će se kretati beskonačno.
Otuda, Arezou može da pobijedi bez obzira kako igra Borzou.
* Razmotrimo sada igru u kojoj je vozić polazi iz stanice $1$.
 Arezou može usmjeriti skretnicu u stanici $1$ ka liniji $(1, 0)$.
Ako Borzou usmjeri skretnicu u stanici $0$ prema liniji $(0, 0)$ vozić će izaći iz stanice $1$, ući u stanicu $0$ i 
beskonačno kružiti kroz nju, pa Arezou pobjeđuje.
 Ako Borzou usmjeri skretnicu u stanici $0$ prema liniji $(0, 1)$ 
vozić će beskonačno kružiti kroz obje stanice.

* U obje igre Arezou pobjeđuje, pa funkcija vraća $[1, 1]$.

## Ograničenja

* $1 \leq n \leq 5000$.
* $n \leq m \leq 20\,000$.
* Postoji bar jedna energetska stanica.
* Iz svake stanice polazi bar jedna linija.
* Postoje linije koje polaze i završavaju u istoj stanici (tj., $u[i] = v[i]$).
* Sve linije su međusobno različite.
Drugim riječima, ne postoje indeksi  $i$ i $j$ ($0 \leq i < j \leq m-1$) takvi da je $u[i]=u[j]$ i $v[i]=v[j]$.
* $0 \leq u[i], v[i] \leq n-1$ (za svako $0 \leq i \leq m-1$).

## Podzadaci

1. (5 bodova) Za svako  $0 \leq i \leq m-1$, ili je $v[i] = u[i]$ ili je $v[i] = u[i] + 1$.
1. (10 bodova) $n \leq 15$.
1. (11 bodova) Arezou je valsnik svih stanica.
1. (11 bodova) Borzou je vlasnik svih stanica.
1. (12 bodova) Postoji tačno jedna energetska stanica.
1. (51 bod) Nema ograničenja.

## Program za ocjenjivanje

Program za ocjenjivanje učitava podatke u sljedećem formatu:
* red $1$: $\;\; n \;\; m$
* red $2$: $\;\; a[0] \;\; a[1] \; \ldots\; a[n-1]$
* red $3$: $\;\; r[0] \;\; r[1] \; \ldots\; r[n-1]$
* redovi $4 + i$ (za $0 \leq i \leq m-1$): $\;\; u[i] \;\; v[i]$

Program za ocjenjivanje štampa niz `who_wins` u sljedećem formatu:
* rez $1$: $\;\; w[0] \;\; w[1] \; \ldots\; w[n-1]$