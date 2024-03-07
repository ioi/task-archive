# Pengabelan 

Maryam adalah seorang teknisi elektro.
Ia sedang mendesain pengabelan pada sebuah menara komunikasi.
Pada menara tersebut terdapat beberapa titik sambungan, yang terletak pada ketinggian yang berbeda-beda.
Seutas kabel dapat digunakan untuk menyambungkan dua titik sambungan yang mana saja.
Setiap titik sambungan dapat dihubungkan dengan berapapun utas kabel.
Terdapat dua jenis titik sambungan: merah dan biru.

Untuk mempermudah soal, menara tersebut dapat dilihat sebagai sebuah garis dan titik-titik sambungan sebagai titik-titik biru dan merah yang terletak pada koordinat-koordinant bilangan non-negatif pada garis tersebut.
Panjang seutas kabel adalah jarak di antara dua titik sambungan yang terhubung oleh kabel tersebut.

Tugas Anda adalah untuk membantu Maryam menemukan sebuah cara pengabelan sedemikian sehingga:
1. Setiap titik sambungan terhubung dengan setidaknya sebuah titik sambungan yang memiliki warna berbeda.
1. Total panjang kabel adalah sependek-pendeknya.

## Detil implementasi

Anda harus mengimplementasikan prosedur berikut ini:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: *array* dengan panjang $n$ yang berisi posisi-posisi titik sambungan merah dengan urutan menaik.
* $b$: *array* dengan panjang $m$ yang berisi posisi-posisi titik sambungan biru dengan urutan menaik.
* Prosedur ini harus mengembalikan total panjang kabel minimum, di antara semua cara pengabelan yang sah.
* Perhatikan bahwa tipe kembalian prosedur ini adalah `int64`.

## Contoh

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Gambar di bawah ini mengilustrasikan contoh berikut.
![Wiring](wiring.png)

* Menara tersebut ditampilkan secara horizontal.
* Pada cetakan soal versi hitam-putih, titik-titik sambungan merah berwarna gelap, sedangkan titik-titik sambungan biru berwarna terang.
* Terdapat $4$ titik sambungan merah, terletak pada posisi-posisi $1, 2, 3,$ dan $7$.
* Terdapat $5$ titik sambungan biru, terletak pada posisi-posisi $0, 4, 5, 9,$ dan $10$.
* Salah satu solusi optimal ditunjukkan oleh gambar di atas.
* Pada solusi ini, total panjang kabel adalah $1 + 2 + 2 + 2 + 3 = 10$, yang merupakan optimal.
Maka, prosedur tersebut harus mengembalikan $10$.
* Perhatikan bahwa terdapat dua kabel yang terhubung dengan titik sambungan pada posisi $7$.

## Batasan

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (untuk setiap $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (untuk setiap $0 \leq i \leq m-1$),
* Masing-masing dari _array_ $r$ dan $b$ terurut menaik.
* Seluruh $n+m$ nilai pada _array_ $r$ dan $b$ berbeda-beda.

## Subsoal

1. (7 poin) $n, m \leq 200$,
1. (13 poin) Semua titik sambungan merah memiliki posisi-posisi yang lebih kecil daripada titik sambungan biru manapun.
1. (10 poin) Terdapat setidaknya sebuah titik sambungan merah dan sebuah titik sambungan biru di antara setiap $7$ titik sambungan yang berurutan.
1. (25 poin) Semua titik sambungan memiliki posisi-posisi yang berbeda pada interval $[1, n+m]$.
1. (45 poin) Tidak ada batasan tambahan.

## Grader contoh

*Grader* contoh membaca masukan dengan format berikut:

* baris $1$: $\;\; n \;\; m$
* baris $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* baris $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

*Grader* contoh mencetak sebuah baris berisi nilai kembalian dari `min_total_length`.
