# Qədim kitablar

Tehran şəhərində İran Milli Kitabxanası yerləşir. Bu kitabxananın baş xəzinəsi sıra ilə düzülmüş və soldan sağadək $0$-dan $n-1$-dək nömrələnmiş $n$ masanın olduğu uzun bir zalda yerləşdirilib.
Hər masanın üzərində bir qədim əlyazma kitabı var. Bu kitablar onların yaşlarına görə sıralanıb ki, bu da ziyarətçilərin kitabları adlarına görə tapması işini çətinləşdirir. Ona görə də kitabxana müdiri kitabları adlarına görə əlifba sırası üzrə çeşidləməyi qərara aldı.

Kitabxanaçı Ayan bu tapşırığı yerinə yetirməlidir. O, $0$-dan $n-1$-dək tam ədədlərin olduğu $n$ uzunluqlu $p$ siyahısını tərtib etdi. Bu siyahı kitabları əlifba sırası ilə düzmək üçün lazım olan dəyişiklikləri təsvir edir: bütün $0 \leq i < n$ üçün hazırda $i$ masasında olan kitab $p[i]$ masasına keçirilməlidir. 

Ayan kitabları çeşidləməyi $s$ masasından başlayır. O, tapşırığı sona çatdırandan sonra həmin masaya qayıtmaq istəyir. Kitablar çox qiymətli olduğundan o hər dəfə bir kitabdan artığını daşıya bilməz. Kitabları çeşidləyənədək Ayan müəyyən hərəkətlər ardıcıllığını yerinə yetirməlidir. Bu hərəkətlərin hər biri aşağıdakılardan biri ola bilər:
* Əgər o, kitab daşımırsa və onun yanında olduğu masanın üzərində kitab varsa, o həmin kitabı götürə bilər.
* Əgər o, kitab daşıyırsa və onun yanında olduğu masanın üzərində kitab varsa, o apardığı kitabı masanın üzərindəki kitabla dəyişə bilər.
* Əgər o, kitab daşıyırsa və onun yanında olduğu masa boşdursa, o daşıdığı kitabı həmin masanın üzərinə qoya bilər.
* O istənilən masaya yaxınlaşa bilər. Bu işləri yerinə yetirdiyi müddətdə o yalnız bir kitabı daşıya bilər.

Bütün $0 \leq i, j \leq n - 1$ üçün $i$ və $j$ masaları arasındakı məsafə düz $|j-i|$ metrdir. Ayana yardım edin ki, kitabları çeşidləmək üçün onun qət etdiyi toplam məsafə minimal olsun.

## Gerçəkləşdirmə detalları

Siz aşağıdakı proseduru gerçəkləşdirməlisiniz:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ uzunluğu $n$ olan massivdir.
Başlanğıcda $i$ masasının üzərindəki kitab Ayan tərəfindən $p[i]$ (bütün $0 \leq i < n$ üçün) masasına aparılmalıdir.
* $s$ Ayanın başlanğıcda yanında olduğu və kitabları çeşidlədikdən sonra qayıdacağı masanın nömrəsidir.
* Bu prosedur Ayannın kitabları çeşidləmək üçün qət edəcəyi minimal toplam məsafəni (metrlə) qaytarmalıdır.

## Nümunə

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

Bu nümunədə $n=4$ və Ayan başlanğıcda $0$ masasının yanındadır.
O, kitabları aşağıdakı kimi çeşidləyir:
* $1$ masasına yaxınlaşır və onun üzərindəki kitabı götürür. Bu kitab $2$ masasına qoyulmalıdır.
* Sonra o $2$ masasına yaxınlaşır və gətirdiyi kitabı masasın üzərindəki kitabla dəyişir. Götürdüyü yeni kitabı o $3$ masasının üzərinə qoymalıdır.
* Sonra o $3$ masasına yaxınlaşır və gətirdiyi kitabı masasın üzərindəki kitabla dəyişir. Götürdüyü yeni kitabı o $1$ masasının üzərinə qoymalıdır.
* Sonra o $1$ masasına yaxınlaşır və gətirdiyi kitabı masanın üzərinə qoyur.
* Sonda o $0$ masasının yanına qayıdır.

Diqqət edin ki, $0$ masasının üzərindəki kitab düzgün yerindədir, ona görə də Ayan onu götürmür. Bu həll üçün onun qət etdiyi minimal toplam məsafə $6$ metrdir.
Bu həll optimaldır; ona görə də prosedur $6$ qiymətini qaytarmalıdır.

## Məhdudiyyətlər

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* $p$ massivi $0$ və $n-1$ aralığında $n$ sayda tam ədəddən ibarətdir.

## Altməsələlər

1. (12 xal) $n \le 4$ və $s = 0$
1. (10 xal) $n \le 1000$ və $s = 0$
1. (28 xal) $s = 0$
1. (20 xal) $n \le 1000$
1. (30 xal) əlavə məhdudiyyətlər yoxdur.

## Nümunə yoxlayıcı

Nümunə yoxlayıcı giriş verilənlərini aşağıdakı formatda oxuyur:

- sətir $1$: $\;\; n \;\; s$
- sətir $2$: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

Nümunə yoxlayıcı `minimum_walk` prosedurunun qaytardığı qiyməti çıxışa verəcəkdir.
