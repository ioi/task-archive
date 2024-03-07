# Novruz

Novruza bir neçə gün qalıb və baba ailə üzvlərini öz bağına dəvət edib. 
Qonaqların arasında $k$ sayda uşaq var. Qonaqlığı uşaqlar üçün daha əyləncəli etmək üçün baba gizlənpaç oynamaq istəyir. 

Bağ hər bir xanasının tərəfi vahid olan $m \times n$ ölçülü tor (şəbəkə) şəklində göstərilə bilər. Bəzi (sıfır da ola bilər) xanalar daşlarla bloklanıb və yerdə qalan xanalara *sərbəst xanalar* deyilir. Ortaq tərəfi olan iki xana *qonşu* adlanır. Hər xananın ən çoxu 4 qonşusu ola bilər: ikisi üfüqi, ikisi isə şaquli istiqamətdə. Baba bağı labirintə çevirmək istəyir. Bu məqəsədlə, o, bəzi sərbəst xanalara kol əkməklə onları bloklaya bilər. Onun kol əkdiyi xanaların sayı sərbəst xanaların sayından çox ola bilməz.

Labirint aşağıdakı xassəyə malik olmalıdır. Labirintin istənilən iki sərbəst $a$ və $b$ xanası üçün onlar arasında yeganə bir *sadə yol* olmalıdır.
$a$ və $b$ xanaları arasında sadə yol $a$ xanasından başlayıb $b$ xanasında bitən, xanaları təkrarlanmayan və iki ardıcıl xanası qonşu olan sərbəst xanalar ardıcıllığıdır.

Uşaq yalnız və yalnız o halda xanada gizlənə bilər ki, həmin xana sərbəst olsun və onun *yalnız* bir sərbəst qonşusu olsun. Eyni xanada iki uşaq gizlənə bilməz.

Giriş verilənləri kimi sizə bağın xəritəsi verilir. Babaya çox uşağın gizlənə biləcəyi labirint qurmaqda kömək edin.

## Gerçəkləşdirmə detalları

Bu, qismən qiymətləndirilən "yalnız çıxışlı" məsələdir.
Sizə, hər biri babanın bağını təsvir edən $10$ giriş faylı verilir. Hər bir giriş faylı üçün labirintin xəritəsinin olduğu çıxış faylını göndərməlisiniz. Hər bir çıxış faylı üçün siz labirintdə gizlənə bilən uşaqların sayına əsaslanan xal alırsınız.

Bu məsələ üçün heç bir proqram kodu göndərməli deyilsiniz.

## Giriş verilənlərinin formatı

Hər bir giriş faylı bağı göstərən bir toru təsvir edir və babanın qonağı olan uşaqların $k$ sayını verir. Format aşağıdakı kimidir:
* sətir $1$: $\;\; m \;\; n \;\; k$
* sətir $1+i$ ($1 \leq i \leq m$ üçün): torun $n$ simvoldan ibarət $i$-ci sətri aşağıdakı simvollardan (boşluq simvolu ola bilməz) ibarətdir:
  - '`.`': sərbəst xana,
  - '`#`': daş.

## Çıxış verilənlərinin formatı

* sətir $i$ ($1 \leq i \leq m$ üçün): labirintin $i$-ci sətri (kollar əkildikdən sonra bağın vəziyyəti).  Bu, aşağıdakı simvollardan (boşluq simvolu ola bilməz) ibarət $n$ uzunluqlu sətirdir:
  -  '`.`': sərbəst xana,
  -  '`#`': daş,
  -  '`X`': kol. (X hərfinin yuxarı registrdə olmasına diqqət edin.)

## Məhdudiyyətlər

* $1 \leq m, n \leq 1024$

## Qiymətləndirmə

Çıxış faylı aşağıdakı şərtlər ödəndikdə *düzgün* hesab edilir:
* Çıxış xəritəsi yalnız bir istisna ilə giriş faylına uyğun olmalıdır - giriş xəritəsində istənilən sayda  '`.`'  simvolu '`X`' simvolu (xana kolla bloklanıb) ilə əvəzlənməlidir.
* Çıxış xəritəsi məsələnin şərtində təyin olunmuş xassəyə malik labirint olmalıdır.

Əgər sizin çıxış faylınız verilən test üçün düzgün deyilsə, bu test üçün xalınız $0$ olacaq.
Əks halda, xalınız onluq nöqtədən sonra iki rəqəmədək yuvarlaqlanmış $\min(10, 10 \cdot l/k)$ olmalıdır. Burada $l$ sizin çıxış labirintinizdə gizlənə biləcək uşaqların sayıdır, $k$ isə girişdə olan uşaqların sayıdır.
Əgər sizin çıxışınız, $k$ və ya daha çox uşağın gizlənə biləcəyi labirintdirsə, onda bu testlər üçün $10$ xal alacaqsınız.
Hər bir test üçün $10$ xalla qiymətləndirilən həll mövcuddur.

Nəzərə alın ki, əgər sizin həll düzgündürsə, ancaq yuxarıdakı düstura görə 0 xal alarsa, onda CMS-də yoxlayıcı sistemin cavabı 'Wrong Answer' olacaqdır.

## Nümunə

Aşağıdakı giriş verilənlərinə baxaq:

```
4 5 5
....#
.#..#
...#.
....#
```

Düzgün çıxış verilənləri aşağıdakı ola bilər:

```
.X.X#
.#..#
...#X
XX..#
```

Bu labirintdə $l=4$ uşaq gizlənə bildiyindən bu həll $10 \cdot 4 / 5 = 8$ xal verəcək. Uşaqların gizlənə biləcəyi xanalar aşağıda `O` ilə qeyd edilib:


```
OXOX#
.#.O#
...#X
XX.O#
```

Aşağıdakı üç çıxış verilənləri düzgün deyil:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

Soldakı çıxış verilənlərində sol yuxarı küncdəki sərbəst xana ilə ən sağ sütundakı boş xana arasında sadə yol yoxdur.
Digər iki çıxış verilənlərində istənilən iki boş xana arasında iki ayrıca sadə yol var. 
