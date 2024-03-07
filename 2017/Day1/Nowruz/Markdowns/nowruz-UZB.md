# Navro'z

Navruzga bir necha kun qoldi va bobo oilasini bog’iga taklif qilmoqchi.
Mehmonlar orasida $k$ ta bolalar bor.
Bayramni hushchaqchaq o’tkazish uchun bobo bolalarga bekinmachoq o’yini tashkillashtirmoqchi.

Bog’ni $m \times n$ katakchalardan iborat massiv.
Ayrim kataklar toshlar bilan to’ldirilgan, qolganlari esa *bo’sh*.
*Qo’shni kataklar* deb umumiy tomonga ega bo’lgan kataklarga aytiladi.
Har bir katak 4 ta qo’shni katakga ega: 2 ta gorizontal va  2 ta vertikal.
Bobo bog’ni laberintga aylantirmoqchi.
Buning uchun u ayrim bo’sh kataklarga butalar ekib to’ldirmoqchi.
Buta ekilgan kataklar bo’sh bo’lmaydi.

Labirint quyidagi hossalarga ega bo’lish kerak.
Labirintdagi har bir bo’sh $a$ va $b$ kataklar juftligi uchun ular orasida bitta yo’lakcha bo’lish kerak.
$a$ va $b$ kataklarga mos ravishda yo’lakchaning boshi $a$, oxiri $b$ kataklar, bu yo’ldagi barcha kataklar aniq va yo’ldagi kataklarning har ikkitasi qo’shni kataklar. $a$ va $b$ ga faqat va faqat bitta yo’l bo’lish kerak.

Bola faqatgina bosh katakga berkinish mumkin va bu katakning qo’shnisi ham bosh katak bo’lish kerak. Bitta katakga faqat bitta bola yashirinish mumkin.

Sizga kirish ma’lumoti sifatida bog’ haritasi beriladi. 
Vazifangiz boboga iloji boricha ko’p bola berkinish mumkin bo’lgan labirint yaratishda yordam berishingiz kerak.

## Implementation details

Sizga $10$ ta kiruvchi fayl beriladi. Har bir faylda boboning bog’ini ifodalaydi. Har bir fayl uchun mos ravishda labirint haritasi bo’lgan chiquvchi fayl ko’rsatishingiz kerak. Har bir chiquvchi fayl uchun berikinish mumkin bo’lgan bolalar soniqa mos ravishda ballar beriladi.


Source code ni jo’natilmaydi
.

## Input format

Har bir kiruvchi faylda bog’ni ifodalovchi massiv olinadi va bobo taklif qilgan bolalar soni $k$ ni qiymat beriladi. Format quyidagicha bo’ladi:
* line $1$: $\;\; m \;\; n \;\; k$
* line $1+i$ (for $1 \leq i \leq m$): $i$ massiv qatori, uzunligi $n$, quyidagi belgilarda tashkil topgan(probelsiz):
  - '`.`': bo’sh katak,
  - '`#`': tosh to’ldirilgan katak.

## Output format

* $i$ qator(for $1 \leq i \leq m$): labirintning $i$ qator(butalar ekilgandan keyingi bog’). Bu qator uzunligi $n$, quyidagi belgilardan iborat(probelsiz):
  -  '`.`': bo’sh katak,
  -  '`#`': tosh to’ldirilgan katak,
  -  '`X`': buta bor katak (X bosh harfda bo’lish kerak)

## Constraints

* $1 \leq m, n \leq 1024$

## Scoring

Chiquvchi fayl quyidagi holatga mos kelishi kerak:
* Chiquvchi labirint haritasi bilan berilgan harita o’zaro mos kelish kerak va faqatgina '`.`' chiquvchi labirintda '`X`' almashtirish mumkin (buta bor katak).
* Chiqish haritasi labirintning hossalariga ega bo’lish kerak.

Agar chiquvchi fayl test uchun kerakli hossalarga ega bo’lmasa $0$ ball beriladi.
Aks holda, ball quyidagicha beriladi $\min(10, 10 \cdot l/k)$, ballar 10^2 aniqlikda beriladi.
Bu yerda $l$ chiquvchi faylda berilgan laberintda berikinish mumkin bo’lgan bolalar sonini ifodalaydi, $k$ esa kiruvchi faylda berilgan bolalar soni.
Siz $10$ ball olishingiz uchun chiquvchi faylda berilgan laberintda k ta bola yoki undan ko’p bola berkina olsa.
Har bir test uchun $10$ ballik yechim mavjud.

Agar sizning chiquvchi faylga $0$ ball berilsa 'Wrong	Answer' chiqadi.

## Example

Quyida kiruvchi ma’lumotga etibor bering:

```
4 5 5
....#
.#..#
...#.
....#
```

Quyida to’g’ri formatdagi javob:

```
.X.X#
.#..#
...#X
XX..#
```

Bu labirintda $l = 4$ bola berkinish mumkin bo’lgani uchun sizning ballingiz $10 \cdot 4 / 5 = 8$ ball. Quyida bolalar berkinish mumkin bo’lgan kataklar `O` bilan berilgan:


```
OXOX#
.#.O#
...#X
XX.O#
```

Quyidagi 3 ta noto’g’ri formatdagi javoblar:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

Chapdagi chiquvchi javobda bitta bo’sh katakga borish uchun yo’l yoq, yani, eng chap yuqoridagi  katak(0,0) bilan eng o’ngdagi bo’sh katak(2, 4) o’rtasida yo’l yo’q bo’g’lab bo’lmaydi. qo’lganlarda har bir juftlik uchun yo’lakchalar mavjud, yani, o’rtadagida soat strelkasi yo’nalishda bitta va soat strelkasiga qarshi holatda bitta yo’lakcha bor.
