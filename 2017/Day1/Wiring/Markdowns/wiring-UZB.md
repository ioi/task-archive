# Elektr tarmog'i

Mariyam elektr injener.
U minoraga elektr sim o’tkazishni loyihalashtirmoqchi.
Minorada aniq balandlikdagi tutashtiriladigan bir nechta nuqtalar bor.
Sim ihtiyoriy ikkita nuqtalarni bog’lashi kerak.
Har bir tutashtiriladigan nuqta ihtiyoriy raqamdagi nuqta bilan bog’lanishi mumkin.
Ikki turdagi nuqtalar mavjud: qizil va ko’k.

Bu masalani yechishda minorani to’g’ri chiziq deb olamiz va qizil va ko’k nuqtalarini shu chiziqdagi butun koordinatalarda joylashgan deb olamiz.
Simning uzunligi u bog’lagan nuqtalar orasidagi masofaga teng.

Sizning vazifangiz Mariyamga shunday bir sxema tuzishda yordam beringki:
1. Bitta sim turli rangdagi nuqtalarini bog’lasin.
1. Umumiy simlar uzunligi minimal bo’lsin.

## Implementation details

Siz quyidagi ko’rinishdagi funksiya tuzishingiz kerak:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: $n$ ta qizil rangli nuqtalarning koordinatalari o’suvchi ketma-ketligidagi massiv.
* $b$: $m$ ta ko’k rangli nuqtalarning koordinatalari o’suvchi ketma-ketligidagi massiv.
* Funksiya natijasi umumiy simlar uzunligi minimalni qaytarish kerak.
* Natija `int64` da qaytarilish lozim .

## Masalan

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Quyidagi raqamlar misol bo’ladi.
![Wiring](wiring.png)

* Minora gorizontal ravishda ko’rsatilgan.
* Oq-qora tasvirda berilgan versiyada to’q rangdagilar qizilni, yorqin rangdagilar ko’kni ifodalaydi.
* $4$ ta qizil nuqtalar, koordinatalari $1, 2, 3$ va $7$ da berilgan.
* $5$ ta ko’k nuqtalar, koordinatalari $0, 4, 5, 9$ va $10$ da berilgan.
* Rasmda bitta optimal yechim berilgan.
* Bu yechimda simlarning umumiy uzunligi $1 + 2 + 2 + 2 + 3 = 10$ ga teng. Demak, natija $10$ ga teng.
* $7$ raqamga 2 ta sim bog’lanadi.

## Chegaralar

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (barcha $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (barcha $0 \leq i \leq m-1$),
* $r$ va $b$ massivlar qiymatlari o’suvchi.
* $n + m$ qiymatlari $r$ va $b$ massiv qiymatlari aniq.

## Subtasks

1. (7 points) $n, m \leq 200$,
1. (13 points) Barcha qizil ranglardagi nuqtalar koordinatasi ko’k rangdagilardan kichik.
1. (10 points) Har bir $7$ talik koordinatada bitta qizil va bitta ko’k rangdagi nuqtalar bo’ladi.
1. (25 points) Barcha nuqtalar $[1, n + m]$ koordinatada joylashgan.
1. (45 points) Hech qanday cheklovlar yo’q.

## Sample grader

Funksiya kiruvchi ma’lumotlarni quyidagicha o’qiydi:
* $1$ qator: $\;\; n \;\; m$
* $2$ qator: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* $3$ qator: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Funksiya natija sifatida `min_total_length` qiymatini qaytaradi.
