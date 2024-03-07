# Katta sovg'a (The Big Prize)

Big Prize mashhur TV o’yin shov hisoblanadi.
Siz juda omadli ishtirokchisiz va finalgacha yetib keldingiz.
Siz $n$ ta qutilar qatori oldida turibsiz va bu qutilarga o’ngdan chapga qarab $0$ dan n – 1 gacha raqamlangan.
Har bir qutida mukofot bor va uni qutini ochilmaguncha ko’rib bo’lmaydi.
U yerda $v \geq 2$ turdagi mukofotlar bor.
Mukofot turlari $1$ dan $v$ gacha raqamlangan va mukofot turining raqami oshgan sari qimmatliligi kamayadi. $v$ yettidan aniq kichik

$1$ turdagi mukofot eng qimat mukofot bo’lib, u olmos.
Qutilarda faqat bittagina olmas bor.
$v$ tipdagi mukofot eng arzon mukofot: konfet.
O’yinni yana ham g’aroyib qilish uchun qimmat sovg’alar sonidan arzon sovg’alarning soni ko’proq.
Yana ham o’ziga hosligi barcha $t$ uchun $2 \leq t \leq v$ biz quyidagicha qonuniyat bor: agar t – 1 sovg’alar $k$ ta bo’lsa, $t$ turdagi sovg’alar $k^2$ dan qati'y ko’p.

Sizning maqsadingiz olmas topish.
O’yin ohirda qutichani ochishingiz kerak va undagi mukofotni olasiz.
Ochish uchun quticha tanlashdan oldin o’yin mezboni Ramboddan bir necha savollar so’rashingiz kerak.
Har bir savol uchun $i$ qutichadan tanlaysiz.
Javob sifatida Rambod ikkita butun soni ichiga olgan $a$ massivini beradi.
Buning ma’nosi quyidagicha:
* $i$ qutidan chapda turgan barcha qutichalar orasida $i$ qutidagidan qimmatroq mukofot soni $a[0]$.
* $i$ qutidan o’ngda turgan barcha qutichalar orasida $i$ qutidagidan qimmatroq mukofot soni $a[1]$.

Masalan, $n = 8$. savol uchun $i = 2$ qutini tanladingiz. Javob sifatida Rambod $a = [1, 2]$ ekanligini aytadi. 
Bu javobning manosi quyidagicha:
* $0$ va $1$ qutilardan bittasi $2$ qutiga nisbat qimmatroq mukofot bor.
* $3, 4, \ldots, 7$ qutilardan aniq ikkitasida $2$ qutiga nisbatan qimatroq mukofot bor.
Sizning vazifangiz kam savol berib olmosni topish.

## Implementation details

Quyidagi funksiyani tuzishingiz kerak:

```
int find_best(int n)
```

* $n$ qutilar soni.
* Bu funksiya olmos mavjud bo’lgan quticha raqami $d$ ni qaytarish kerak $d$ ($0 \leq d \leq n-1$). $1$ yashiringan quti raqamini qaytarish kerak.

Yuqoridagi quyidagi funksiyaga so’rov berish mumkin:

```
int[] ask(int i)
```

* Bu yerda $i$ siz savol berish uchun tanlagan qutichaning raqami. $0 <= i < n$.
* Bu funksiya $2$ ta elementli $a$ massiv qaytaradi. Bunda $i$ qutidan chapda turgan barcha qutichalar orasida $i$ qutidagidan qimatroq mukofot soni $a[0]$, $i$ qutidan o’ngda turgan barcha qutichalar orasida $i$ qutidagidan qimatroq mukofot soni $a[1]$.


## Example

Grader quyidagicha so’ralsa:

```
find_best(8)
```

Bu yerda $n = 8$. Tasavvur qiling mukofot turlari $[3,2,3,1,3,3,2,3]$. Barcha aks funksiya mumkin bo’lgan so’rovlar va javob qaytarilgan qiymat quyida berilgan.

- `ask(0)` returns $[0, 3]$
- `ask(1)` returns $[0, 1]$
- `ask(2)` returns $[1, 2]$
- `ask(3)` returns $[0, 0]$
- `ask(4)` returns $[2, 1]$
- `ask(5)` returns $[2, 1]$
- `ask(6)` returns $[1, 0]$
- `ask(7)` returns $[3, 0]$

Bu misolda olmos $3$ qutida. Demak, `find_best` funksiyasi $3$ qaytarish kerak.

![Prize1](prize.png "600") 

Yuqoridagi raqam bu misolni tushuntirib beradi.
Yuqoridagi rasmlar har bir qutidagi mukofot turlarini ko’rsatadi.
Pasdagilari `ask(2)` so’rovni ifodalaydi.
Belgi qo’yilgan qutilar $2$ qutidagi mukofotga nisbatan qimmatroq mukofotga ega.

## Constraints

* $3 \leq n \leq 200\,000$.
* Qutidagi sovg’a turi $[1, v]$ oralig’ida.
* Olmos ya'ni, $1$ faqat bitta qutida bor.
* $t – 1$ sovg’alar $k$ ta bo’lsa, $t$ turdagi sovg’alar $k^2$ dan *qati'y ko’p*.

## Subtasks and scoring

Ayrim test holatlarida graderni moslashtirish mumkin.
Bu shu deganiki bu test holatlarida grader aniq tartibdagi mukofotlarga ega emas. Uning o’rniga grader tomonida berilgan javoblar sizning yechimigiz tomonidan berilgan savollar bog’liq bo’ladi. 
Shu usulda grader javoblar shunday kafolatlanadi-ki har bir javobdan keyin berilgan javoblarga mos bitta mukofot bo’ladi.

1. (20 ball) Aniq bitta olmos va n – 1 ta konfet bor $(v = 2)$. Siz `ask` funksiyasini ko’pi bilan $10\,000$ marta berishigiz mumkin.Oddiygina ikkilik qidirish.
1. (80 points) Cheklovlarsiz.

2 da siz qisman ballga ega bo’lasiz.
Barcha test holatlari ichida aks funksiyasiga bo’lgan so’rovlarning maksimal soni $q$ deb belgilaylik.
So’ngra bu topshiriq uchun ballingizni quyidagi jadvalga ko’ra hisoblang:

Questions | Score
--- | ---
$10\,000 < q$ | $0$ (reported in CMS as 'Wrong Answer')
$6000 < q \leq 10\,000$ | $70$
$5000 < q \leq 6000$ | $80 - (q-5000)/100$
$q \leq 5000$ | $80$

## Sample grader

Namuna grader moslashuvchan emas.
Buning o’rniga u shunchaki aniq belgilangan mukofot turlaring $p$ massivini o’qiydi va foydalanadi. Barcha $0 \leq b \leq n-1$ uchun b qutidagi mukofot turi p[b] sifarida beriladi. Namuna grader kirish formati quyidagicha:

- line $1$: $\;\; n$
- line $2$: $\;\; p[0] \;\; p[1]  \; \ldots \; p[n-1]$

The sample grader prints a single line containing the return value of `find_best` and the number of calls to the procedure `ask`.