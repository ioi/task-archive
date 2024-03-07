# Papučarenje (books)

Poznato je da Duled voli da provodi vreme pričajući sa svojom devojkom, a isto tako je poznato i da Duled ima kolekciju od $n$ papuča. Te papuče su naslagane u niz i zgodno označene brojevima od $0$ do $n-1$ počevši sa leve ka desnoj strani. Te papuče je poređao Duled, međutim njegova devojka želi da Duled sortira te papuče po boji od boje jorgovana do boje ljubičice. Duledova devojka je odlučila da neće pričati sa Duledom sve dokle on ne sortira papuče kako ona želi.

Kako Duded ne raspoznaje boje najbolje, njegova devojka je kreirala listu $p$ dužine $n$, koja sadrži različite cele brojeve od $0$ do $n-1$.
Ova lista opisuje promene potrebne za preraspoređivanje papuča po bojama:
za sve $0 \leq i < n$, papuče koje su trenutno na mestu $i$ treba premestiti na mesto $p[i]$.

Duled počinje sortiranje papuča krenuvši od mesta $s$.
On mora da se vrati na isto, početno, mesto nakon završenog posla. 
Pošto su papuče veoma vredne, u svakom trenutku on može nositi najviše jedne papuče.
Dok sortira papuče, Duled će izvršiti niz radnji.
Svaka od tih radnji može biti neka od ovde navedenih:
* Ako ne nosi nijedne papuče, a papuče stoje na mestu do kojeg je on došao, Duled može uzeti papuče sa tog mesta.
* Ako nosi jedne papuče, a postoje neke druge papuče na mestu do kojeg je došao, on može da promeni one papuče koje nosi sa papučama koje su na tom mestu.
* Ako nosi papuče, a došao je do praznog mesta (mesta bez papuča), on onda može staviti papuče koje nosi na to mesto.
* Duled može doći do bilo kog mesta. U svakom trenutku može nositi najviše jedne papuče.

Za sve $0 \leq i, j \leq n - 1$, rastojanje između mesta $i$ i $j$ je tačno $|j-i|$ metara. Vaš zadatak da pomognete Duledu i izračunate minimalnu ukupnu razdaljinu koju Duled treba da prošeta da bi sortirao sve papuče, kako bi njegova devojka opet propričala sa njim i da se on ne bi rasplakao.

## Detalji implementacije
```
int64 minimum_walk(int[] p, int s)
```

* $p$ je niz dužine $n$.
Papuče koje su bile na početku na mestu $i$ Duled treba odneti na mesto $p[i]$ (za sve $0 \leq i < n$).
* $s$ je oznaka mesta sa kojeg Duled počinje i gde treba biti nakon što sortira sve papuče.
* Ova procedura treba vratiti najmanju moguću udaljenost (u metrima) koju Duled mora prepešačiti kako bi sortirao sve papuče.

## Primer

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

U ovom primeru, $n=4$ i Duled počinje od mesta $0$.
Duled sortira papuče na sledeći način:
* Prošeta do mesta $1$ i uzme papuče koje se nalaze na tom mestu. Ove papuče treba staviti na mesto $2$.
* Onda, Duled ode do mesta $2$ i zameni papuče koje nosi sa papučama koje se nalaze na tom mestu.
Nove papuče koje sada nosi treba staviti na mesto $3$.
* Nakon toga, Duled ode do mesta $3$ i zameni papuče koje nosi sa papučama koje se nalazi na tom mestu.
Nove papuče koje sada nosi treba staviti na mesto $1$.
* Zatim, Duled ode do mesta $1$ i spusti papuče koje nosi na to mesto. 
* Konačno, kako se mora vratiti do početnog mesta on prošeta do mesta $0$.

Primetimo da su papuče na mestu $0$ već na dobrom mestu, na mestu $0$, tako da Duled ne mora uzimati papuče sa tog mesta.
Ukupna udaljenost koju je prešao u ovom rešenju je $6$ metara.
Ovo je optimalno rešenje; pa prema tome, procedura treba vratiti $6$.

## Ograničenja

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* Niz $p$ sadrži $n$ različitih celih brojeva izmedju $0$ i $n-1$, uključujući te brojeve.

## Podzadaci

1. (12 bodova) $n \le 4$ i $s = 0$
1. (10 bodova) $n \le 1000$ i $s = 0$
1. (28 bodova) $s = 0$
1. (20 bodova) $n \le 1000$
1. (30 bodova) Nema dodatnih ograničenja

## Primer grejdera

Primer grejdera čita ulazne podatke u sledećem formatu:

- linija $1$: $\;\; n \;\; s$
- linija $2$: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

Primer grejdera ispisuje samo vrednost koju vraća funkcija `minimum_walk`.