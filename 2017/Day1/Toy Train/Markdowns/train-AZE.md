# Oyuncaq Qatar

Gülşən və onun qardaşı Elşən əkizdirlər.
Onlar öz ad günlərinə çox gözəl oyuncaq, $n$ sayda stansiya və $m$ sayda *birtərəfli* relsdən ibarət qatar hədiyyəsi alıblar. Hər rels bir stansiyada başlayır, və eyni və ya fərqli stansiyada bitir. Hər stansiyada başlayan ən azı bir rels var.

Bəzi stansiyalar *enerji doldurma stansiyalarıdır*. 
Enerji doldurma stansiyasına çatan qatar tam olaraq enerji ilə dolur, və ardıcıl olaraq $n$ sayda rels üzrə hərəkət edə bilir. Yəni, ən son enerji doldurduqdan sonra, qatar $n+1$-ci relsə daxil olmamış enerjisini itirir və dayanır.

Hər stansiyada bir çevirgəç var, hansı ki, bu stansiyada başlayan relslərdən istənilən birinə yönələ bilir.
Qatar hər hansı bir stansiyada olduğu zaman, o, çevirgəçin yönəldiyi relslə bu stansiyanı tərk edir.

Əkizlər öz qatarları ilə belə bir oyun oynamaq istəyirlər. Onlar artıq bütün stansiyaları öz aralarında bölüşdürüblər: hər stansiya ya Elşən ya da Gülşənə məxsusdur. Yalnız bir qatar var. Oyunun başlanğıcında qatar $s$ stansiyasında tam enerji ilə doldurulmuş vəziyyətdədir.
Oyunu başlamaq üçün, $s$ stansiyasının sahibi həmin stansiyada olan çevirgəçi stansiyadan çıxan relslərdən birinə tərəf yönəldir. Sonra qatar işə salınır və qatar relslər üzrə hərəkətə başlayır.

Qatar hər bir stansiyaya ilk dəfə daxil olduqda, stansiyanın sahibi həmin stansiyada olan çevirgəçi istədiyi relsə yönəldir. 
Elə ki, çevirgəç hər hansı bir vəziyyətə gətirildi, oyunun sonuna qədər həmin vəziyyətdə qalır.
Beləliklə, əgər qatar əvvəl keçdiyi stansiyaya yenidən gələrsə, stansiyanı əvvəl tərk etdiyi relslə tərk edəcəkdir.

Stansiyaların sayı sonlu olduğu üçün, sonunda qatar bir *dövr* boyu hərəkət etməyə başlayacaqdır.
Dövr *fərqli* stansiyaların $c[0], c[1], \cdots, c[k-1]$ ardıcıllığıdır, belə ki, qatar $c[i]$ (for $0 \leq i < k-1$) stansiyasını $c[i+1]$ stansiyasına gedən rels üzrə, və  $c[k-1]$ stansiyasını $c[0]$ stansiyasına gedən rels üzrə tərk edir.
Qeyd edək ki, qatar $c[0]$ stansiyasını $c[0]$ stansiyasına qayıdan relslə tərk edirsə ($k=1$ olarsa), dövr bir stansiyadan da ibarət ola bilər.

Əgər qatar dayanmadan hərəkət edirsə, oyunun qalibi Gülşən, əks halda, qatar enerjisini itirib dayanarsa, oyunun qalibi Elşən olur.
Başqa sözlə, əgər $c[0], c[1], \cdots, c[k-1]$ stansiyaları arasında heç olmazsa bir enerji doldurma stansiyası olarsa, qatar enerjisini yenidən doldura və dayanmadan hərəkət edə bilər, bu halda Gülşən qalib gələr.
Əks halda, onun enerjisi tükənər (ola bilsin ki, bir neçə dəfə dövr etdikdən sonra), Elşən qalib gələr.

Qatar yolu barədə məlumat sizə verilmişdir.
Elşən və Gülşən $n$ oyun oynayacaq.
$s$ nömrəli ($0 \leq s \leq n-1$) oyunun əvvəlində qatar $s$ stansiyasındadır.
Sizin tapşırığınız, hər oyun üçün Elşən və ya Gülşənin qalib gəlməsini müəyyən etməkdir.

## Gerçəkləşdirmə detalları

Aşağıda verilən proseduru gerçəkləşdirməlisiniz:

```
int[] who_wins(int[] a, int[] r, int[] u, int[] v)
```

* $a$: ölçüsü $n$ olan massivdir. Stansiya $i$ Gülşənə məxsus olarsa, $a[i] = 1$. Əks halda, stansiya $i$ Elşənə məxsusdur və $a[i] = 0$.
* $r$: ölçüsü $n$ olan massivdir. Stansiya $i$ enerji doldurma stansiyası olarsa, $r[i] =1$. Əks halda, $r[i] = 0$.
* $u$ və $v$: ölçüləri $m$ olan massivlərdir.
Hər bir $0 \leq i \leq m-1$ üçün, $u[i]$ stansiyasında başlayan və $v[i]$ stansiyasında bitən birtərəfli rels mövcuddur.
* Bu prosedur ölçüsü $n$ olan $w$ massivini qaytarmalıdır.
Hər bir $0 \leq i \leq n-1$ üçün, $i$ stansiyasında başlayan oyunda Gülşən qalib gələ bilərsə $w[i] = 1$ olmalı, Elşən qalib gələ bilərsə $w[i] = 0$ olmalıdır.

## Nümunə

```
who_wins([0, 1], [1, 0], [0, 0, 1, 1], [0, 1, 0, 1])
```

![Train](train.png)

* $2$ stansiya var.
Elşənə enerji doldurma stansiyası olan 0 nömrəli stansiya məxsusdur.
Gülşənə isə $1$ nömrəli, enerji doldurma stansiyası olmayan stansiya məxsusdur.
* Qatar yolu $4$ relsdən ibarətdir $(0, 0), (0, 1), (1, 0)$, and $(1, 1)$. Burada $(i, j)$  $i$ stansiyasında $j$ stansiyasına birtərəfli relsi göstərir.
* Qatarın $0$ nömrəli stansiyada başladığı oyunu nəzərdən keçirək. Əgər Elşən $0$ stansiyasında çevirgəçi $(0, 0)$ relsi tərəfə yönəldərsə, qatar bu rels üzrə dayanmadan hərəkət edəcək (qeyd edək ki, $0$ stansiyası enerji doldurma stansiyasıdır). Bu halda Gülşən qalib gəlir. Əks halda, Elşən $0$ stansiyasında çevirgəçi $(0, 1)$ relsinə yönəldərsə, Gülşən $1$ stansiyasında çevirgəçi $(1, 0)$ relsinə çevirə bilər. Bu halda qatar dayanmadan dövr üzrə hər iki stansıyadan keçərək hərəkət edər. Yenə də, Gülşən qalib gəlir, çünki $0$ stansiyasında enerji doldurularaq bərpa olunur və qatar heç vaxt dayanmayacaq.
Beləliklə, Gülşən, Elşənin nə etməsindən aslı olmayaraq oyunda qalib gəlir.
* Eyni məntiqlə, $1$ stansiyasında başlayan oyunun qalibi, Elşənin necə oynamasından aslı olmayaraq, Gülşən olacaqdır. Beləliklə, prosedur $[1, 1]$ massivini qaytarmalıdır.

## Məhdudiyyətlər

* $1 \leq n \leq 5000$.
* $n \leq m \leq 20\,000$.
* Ən azı bir enerji doldurma stansiyası vardır.
* Hər stansiyada başlayan ən azı bir rels vardır.
* Eyni stansiyada başlayan və bitən relslər mövcud ola bilər (i.e., $u[i] = v[i]$).
* Heç bir rels təkrarlanmır.
Başqa sözlə, elə iki indeks $i$ və $j$ ($0 \leq i < j \leq m-1$) tapmaq mümkün deyil ki, $u[i]=u[j]$ və $v[i]=v[j]$ olsun.
* $0 \leq u[i], v[i] \leq n-1$ (hər bir $0 \leq i \leq m-1$).

## Alt-məsələlər

1. (5 points) Hər bir $0 \leq i \leq m-1$, $v[i] = u[i]$ və ya $v[i] = u[i] + 1$.
1. (10 points) $n \leq 15$.
1. (11 points) Bütün stansiyalar Gülşənə məxsusdur.
1. (11 points) Bütün stansiyalar Elşənə məxsusdur.
1. (12 points) Cəmi bir dənə enerji doldurma stansiyası var.
1. (51 points) Əlavə məhdudiyyət yoxdur.

## Nümunə qreyder

Nümunə qreyder girişdən aşağıdakı formatda oxuyur:
* sətir $1$: $\;\; n \;\; m$
* sətir $2$: $\;\; a[0] \;\; a[1] \; \ldots\; a[n-1]$
* sətir $3$: $\;\; r[0] \;\; r[1] \; \ldots\; r[n-1]$
* sətir $4 + i$ (for $0 \leq i \leq m-1$): $\;\; u[i] \;\; v[i]$

Nümunə qreyder `who_wins` prosedurunun nəticəsini növbəti formatda çap edir:
* sətir $1$: $\;\; w[0] \;\; w[1] \; \ldots\; w[n-1]$
