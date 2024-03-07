# Mudelrong

Arezou ja tema vend Borzou on kaksikud ja nad said sünnipäevaks ägeda mudelrongikomplekti, millega saab ehitada $n$ jaama ning $m$ *ühesuunalise* teega raudteesüsteemi.
Iga tee algab ühest jaamast ja lõpeb kas samas või mõnes teises jaamas.
Igast jaamast saab alguse vähemalt üks tee.

Mõned jaamad on *laadimisjaamad*.
Kui rong jõuab laadimisjaama, siis laetakse selle aku täielikult täis.
Täislaetud akuga rong saab sõita läbi $n$ järjestikust teed.
See tähendab, et rong jääb seisma just siis, kui ta oleks sisenenud $(n+1)$-le teele pärast laadimist.

Igas jaamas on lüliti, mida saab pöörata iga sellest jaamast väljuva tee suunas.
Kui rong siseneb jaama, siis ta väljub sellele teele, kuhu lüliti näitab.

Kaksikud mängivad rongiga mängu.
Jaamad on ära jagatud - iga jaam kuulub kas Arezoule või Borzoule.
Mängus on ainult üks rong.
Mängu alguses on rong jaamas $s$ ja täielikult laetud.
Mängu alguses lülitab jaama $s$ omanik selle jaama lüliti mingi jaamast $s$ algava tee suunas.

Iga kord, kui rong siseneb esimest korda mingisse jaama, seab selle omanik jaama lüliti mõne sealt väljuva tee suunas.
Kui lüliti on kord seatud, jääb ta kogu mängu vältel samasse asendisse.
Seega, kui rong jõuab uuesti samasse jaama, väljub ta sealt alati sama teed mööda kui eelmisel korral.

Kuna jaamade arv on lõplik, satub rong lõpuks *tsüklisse*.
Tsükkel on *erinevate* jaamade $c[0], c[1], \cdots, c[k-1]$ jada, kus rong väljub jaamast $c[i]$ ($0 \leq i < k-1$) mööda teed, mis viib jaama $c[i+1]$ ja väljub jaamast 
$c[k-1]$ mööda teed, mis viib jaama $c[0]$.
Pane tähele, et tsükkel võib koosneda ka ainsast jaamast (s.t $k=1$) kui rong väljub jaamast $c[0]$ mööda teed, mis viib tagasi jaama $c[0]$.

Arezou võidab mängu, kui rong jääb lõputult liikuma ja Borzou võidab, kui rong jääb millalgi seisma.
Teiste sõnadega, kui tsüklis $c[0], c[1], \cdots, c[k-1]$, kuhu rong lõpuks jääb, on vähemalt üks laadimisjaam, jääb rong sinna lõputult liikuma ja Arezou võidab.
Kui laadimisjaama pole, saab rongi aku lõpuks tühjaks (võimalik, et ta peab vahepeal mitu korda läbi vastava tsükli sõitma) ja Borzou võidab.

Ülesandes on antud raudteesüsteemi kirjeldus.
Arezou ja Borzou mängivad $n$ mängu.
$s$-ndas mängus ($0 \leq s \leq n-1$) alustab rong liikumist jaamast $s$.
Sinu ülesanne on iga mängu jaoks leida, kas Arezoul on strateegia, mis võimaldab tal alati võita, sõltumata sellest, kuidas Borzou mängib.

## Tehnilised detailid

Sul tuleb kirjutada järgmine protseduur:

```
int[] who_wins(int[] a, int[] r, int[] u, int[] v)
```

* $a$: massiiv pikkusega $n$. Kui jaam $i$ kuulub Arezoule, siis $a[i] = 1$. Vastasel korral kuulub jaam $i$ Borzoule ja $a[i] = 0$.
* $r$: massiiv pikkusega $n$. Kui jaam $i$ on laadimisjaam, siis $r[i] =1$. Vastasel korral $r[i] = 0$.
* $u$ ja $v$: massiivid pikkusega $m$.
Iga $0 \leq i \leq m-1$ puhul on süsteemis ühesuunaline tee, mis algab jaamast $u[i]$ ja lõpeb jaamas $v[i]$.
* Protseduur peab tagastama massiivi $w$ pikkusega $n$.
Iga $0 \leq i \leq n-1$ korral peab $w[i]$ väärtus olema $1$, kui Arezou saab mängu võita, kui mäng algab jaamas $i$, ükskõik kuidas Borzou ka ei mängiks.
Vastasel korral peab $w[i]$ väärtus olema $0$.

## Näide

```
who_wins([0, 1], [1, 0], [0, 0, 1, 1], [0, 1, 0, 1])
```

![Train](train.png)

* Meil on $2$ jaama.
Borzoule kuulub jaam $0$, mis on laadimisjaam.
Arezoule kuulub jaam $1$, mis ei ole laadimisjaam.
* Meil on ka $4$ teed $(0, 0), (0, 1), (1, 0)$ ja $(1, 1)$, kus $(i, j)$ tähistab ühesuunalist teed jaamast $i$ jaama $j$.
* Vaatame mängu, kus rong on alguses jaamas $0$.
Kui Borzou seab lüliti jaamas $0$ teele $(0, 0)$, jääb rong lõputult sellele teele (sest jaam $0$ on laadimisjaam),
seega Arezou võidab.
Kui Borzou seab lüliti tee $(0, 1)$ suunas, saab Arezou seada jaama $1$ lüliti suunda $(1, 0)$.
Sel juhul jääb rong lõputult kahe jaama vahet sõitma ja Arezou võidab jälle.
Seega saab Arezou alati võita, ükskõik, mida Borzou ka ei teeks.
* Sarnasel viisil, kui mäng algab jaamas $1$, saab Arezou alati võita, kuidas Borzou ka ei mängiks. Seega peab protseduur tagastama $[1, 1]$.

## Piirangud

* $1 \leq n \leq 5000$.
* $n \leq m \leq 20\,000$.
* Mängus on alati vähemalt üks laadimisjaam.
* Igast jaamast algab alati vähemalt üks tee.
* Teed võivad viia tagasi samasse jaama ($u[i] = v[i]$).
* Iga tee ühendab erinevat jaamade paari, s.t ei leidu selliseid $i$ ja $j$ ($0 \leq i < j \leq m-1$), kus $u[i]=u[j]$ ja $v[i]=v[j]$.
* $0 \leq u[i], v[i] \leq n-1$ (for all $0 \leq i \leq m-1$).

## Alamülesanded

1. (5 punkti) Iga $0 \leq i \leq m-1$ puhul kehtib kas $v[i] = u[i]$ või $v[i] = u[i] + 1$.
1. (10 punkti) $n \leq 15$.
1. (11 punkti) Kõik jaamad kuuuvad Arezoule.
1. (11 punkti) Kõik jaamad kuuluvad Borzoule.
1. (12 punkti) Mängus on täpselt üks laadimisjaam.
1. (51 punkti) Täiendavad piirangud puuduvad.

## Näidistester

Näidistester loeb sisendit järgmisel kujul:
* rida $1$: $\;\; n \;\; m$
* rida $2$: $\;\; a[0] \;\; a[1] \; \ldots\; a[n-1]$
* rida $3$: $\;\; r[0] \;\; r[1] \; \ldots\; r[n-1]$
* rida $4 + i$ ($0 \leq i \leq m-1$): $\;\; u[i] \;\; v[i]$

Näidistester kirjutab protseduuri `who_wins` tagastatud väärtuse järgmisel kujul:
* rida $1$: $\;\; w[0] \;\; w[1] \; \ldots\; w[n-1]$
