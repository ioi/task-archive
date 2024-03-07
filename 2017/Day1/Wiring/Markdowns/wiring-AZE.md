# Kabelləşdirmə

Məryəm elektrik mühəndisidir. O, rabitə qülləsində kabelləşdirmə layihəsini işləyir. Qüllənin müxtəlif hündürlüklərdə yerləşdirilmiş bir neçə birləşmə nöqtəsi var. İstənilən iki birləşmə nöqtəsini kabel vasitəsilə birləşdirmək olar. Hər bir birləşmə nöqtəsinə istənilən sayda naqil birləşə bilər. İki növ birləşmə nöqtəsi mövcuddur: qırmızı və mavi.

Bu məsələ üçün qülləni bir xətt kimi, biləşmə nöqtələrini isə bu xətt üzərində yerləşən, mənfi olmayan koordinatlara malik mavi və qırmızı nöqtələr kimi təsəvvür edin. Kabelin uzunluğu onun birləşdirdiyi iki nöqtə arasında məsafədir.

Siz Məryəmə növbəti şərtlərə cavab verən kabelləşdirmə sxemini tapmağa kömək etməlisiniz:
1. Hər birləşmə nöqtəsini fərqli rəngə malik birləşmə nöqtəsinə bağlayan ən azı bir kabel olsun.
1. Kabellərin ümumi uzunluğu minimal olsun.


## Gerçəkləşdirmə detalları

Növbəti proseduru gerçəkləşdirməlisiniz:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: qırmızı birləşmə nöqtələrinin mövqelərini artan sıra ilə özündə saxlayan $n$ ölçülü massiv.
* $b$: mavi birləşmə nöqtələrinin mövqelərini artan sıra ilə özündə saxlayan $m$ ölçülü massiv.
* Bu prosedur bütün mümkün kabelləşdirmə sxemləri arasında kabellərin minimal ümumi uzunluğunu qaytarmalıdır.
* Nəzərə alın ki, bu prosedurun nəticə tipi `int64` olmalıdır.

## Nümunə

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Aşağıdakı sxem bu nümunəni təsvir edir.
![Wiring](wiring.png)

* Qüllə üfüqi göstərilib.
* Məsələnin ağ-qara çap variantında qırmızı birləşmə nöqtələri tünd, mavilər isə açıq rəngdədir.
* Burada $1, 2, 3$ və $7$-ci mövqedə yerləşən $4$ qırmızı birləşmə nöqtəsi var.
* Burada $0, 4, 5, 9$ və $10$-cu mövqedə yerləşən $5$ mavi birləşmə nöqtəsi var.    
* Yuxarıdakı sxem optimal həllərdən birini göstərir.
* Bu həldə kabellərin ümumi uzunluğu $1 + 2 + 2 + 2 + 3 = 10$ olur ki, bu da optimaldır. Beləliklə, prosedur $10$ qiyməti qaytarmalıdır. 
* Nəzərə alın ki, $7$-ci mövqedə olan birləşmə nöqtəsinə iki kabel birləşib.

## Məhdudiyyətlər

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 109$ (for all $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 109$ (for all $0 \leq i \leq m-1$),
* $r$ və $b$ massivlərinin hər biri artan sıra ilə çeşidlənmişdir.
* $r$ və $b$ massivləri $n+m$ sayda müxtəlif qiymətlərdən ibarətdir.


## Altməsələlər

1. (7 points) $n, m \leq 200$,
1. (13 points) Bütün qırmızı biləşmə nöqtələri ixtiyari mavi birləşmə nöqtəsindən kiçik mövqeyə malikdir.
1. (10 points) Hər $7$ ardıcıl birləşmə nöqtələrinin arasında ən azı bir qırmızı və bir mavi birləşmə nöqtəsi var.
1. (25 points) Bütün birləşmə nöqtələri $[1, n+m]$ aralığında müxtəlif mövqelərdə yerləşirlər.
1. (45 points) Əlavə məhdudiyyət yoxdur.


## Nümunə qreyder

Nümunə qreyder girişi aşağıdakı formatda oxuyur:
* sətir $1$: $\;\; n \;\; m$
* sətir $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* sətir $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Nümunə qreyder bir sətirdə `min_total_length`-in qaytardığı qiyməti çap edir.
