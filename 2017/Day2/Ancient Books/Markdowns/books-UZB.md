# Qadimiy kitoblar (Ancient Books)

Tehram shahrida Eron milliy kutibxonasi joylashgan. Kutubxonaning asosiy hazinasi $n$ ta stollar qatori bor uzun zalda joylashgan bo’lib, stollar chapdan o’nga qarab $0$ dan n – 1 tartibida belgi qo’yilgan. Har bir stolda bittadan qadimiy qo’lyozma kitob joylashtirilgan. Bu kitoblar yoshiga qarab tartiblangan bo’lib, bu tartib tashrif buyuruvchilarda kitoblarni sarlavhasi yordamida qidirishda qiyinchilik tug’diradi. Shuning uchun kutubxona boshqaruvchisi kitoblarni sarlavhasiga qarab alfabet tartibida saralashga qaror qildi.

Bu ishni kutubxonachi Aryan bajarmoqchi. U $0$ dan n – 1 gacha bo’lgan turli butun sonni o’z ichiga olgan $n$ uzunlikdagi $p$ ro’yhatini tuzdi. Bu ro’yhat kitoblarni alfabet tartibida joylashtirish uchun kerakli o’zgarishlarni tasvirlaydi: barcha $0 \leq i < n$ ayni damda $i$ stolda turgan kitob $p[i]$ stolga olinish kerak.

Aryan kitoblarni saralashni $s$ stoldan boshlaydi. U ishni tugatgach ayni o’sha stolga qaytmoqchi. Kitoblar qimat baho bo’lgani uchun bir vaqtning o’zida 1 tadan ko’p kitob ko’tara olmaydi. Kitoblarni saralash paytida Aryan ketma-ketlikda harakat qilish kerak. Harakatlarning har biri quyidagilardan biri bo’lish kerak:
* Agar u kitob olib ketmayotgan bo’lsa va yonida turgan stolda kitob bo’lsa u kitobni olish mumkin.
* Agar u kitob olib ketaytgan bo’lsa va u yonida turgan stolda boshqa kitob bo’lsa u kitoblarni kitoblarni almashtirish mumkin.
* Agar u kitob ko’tarib ketayotgan bo’lsa va bo’sh stol oldida bo’lsa ko’tarib ketayotgan kitobini stol ustiga qo’yishi mumkin.
* U xoxlagan stolga borish mumkin. Yurayotgan paytda faqat bitta kitobni ko’tarish mumkin holos.

Barcha $i$ va $j$ stollar orasidagi masofa |i – j| metr. Sizning vazifangiz barcha kitoblarni saralash maqsadida Aryan bosib o’tish zarur bo’lgan minimal umumiy masofani topishdir.


## Implementation details

Quyidagi ko’rinishdafi funksiya tuzishingiz kerak:

```
int64 minimum_walk(int[] p, int s)
```

* $p$ nomli uzunligi $n$ bo’lgan massiv. $i$ stoldagi kitobni $p[i]$ stolga olish o’tish kerak.
* $s$ Aryan boshida turish kerak bo’lgan stolning raqami va kitoblarni saralab bo’lgandan keyin shu $s$ stolga qaytish kerak.
* Funksiya Aryan kitoblarni saralash uchun kerak bo’ladigan minumal masofani qaytarish kerak.

## Example

```
minimum_walk([0, 2, 3, 1], 0)
```

![Books](books.png)

Bu misolda $n = 4$ va Aryan $0$ stolda turadi. 
U kitoblarini quyidagicha saralaydi:
* U $1$ stolga boradi va undagi kitobni oladi. Bu kitob ikkinchi stolga qo’yishi kerak.
* Keyin u $2$ stolga boradi va ko’tarib kelgan kitobini stoldagi kitob bilan almashtiradi. Yangi kitob $3$ stolga qo’yishi kerak.
* U $3$ stolga boradi va qo’lidagi kitobni stoldagi kitob bilan almashtiradi. 
  Almashtirilgan kitob $1$ stolga qo’yishi kerak.
* Keyin $1$ stolga boradi va keltirgan kitobini qo’yadi.
* Nihoyat u $0$ stolga qaytib keladi.

$0$ stoldagi kotib to’g’ri joylashgan shuning uchun Aryan bu kitobni joyidan qo’g’atish shart emas. U bosib o’tgan yo’lning umumiy masofasi $6$ ga teng. Demak, funksiya $6$ natija qaytarish kerak. Hamma holatni ko’rib kichik ball olish mumkin.

## Constraints

* $1 \le n \le 1\,000\,000$
* $0 \le s \le n-1$
* $p$ massiv elementlari butun [0, n – 1] oraliqda.

## Subtasks

1. (8 points) $n \le 4$ and $s = 0$
1. (16 points) $n \le 1000$ and $s = 0$
1. (8 points) $s = 0$
1. (36 points) $n \le 1000$
1. (32 points) cheklovlar yo’q

## Sample grader

Grader kirish formati :

- qator $1$: $\;\; n \;\; s$
- qator $2$: $\;\; p[0] \;\; p[1] \; \ldots  \; p[n-1]$

`minimum_walk` ni riymatini qaytarish kerak.
