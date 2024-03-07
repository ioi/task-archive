# Nowruz 

Tinggal beberapa hari menuju Nowruz (tahun baru Persia), dan Sang Kakek mengundang keluarganya ke tamannya.
Terdapat $k$ anak-anak di antara para tamu.
Untuk membuat perkumpulan lebih menarik bagi anak-anak, Sang Kakek akan mengadakan permainan petak umpet.

Taman tersebut dapat dinyatakan sebagai petak-petak berukuran $m \times n$.
Beberapa (mungkin saja nol) petak ditempati batu, dan petak-petak sisanya dikatakan *kosong*.
Dua petak dikatakan *bertetanggaan* jika kedua petak tersebut berbagi sebuah sisi.
Yakni, setiap petak memiliki paling banyak 4 tetangga: dua pada arah horizontal, dan dua pada arah vertikal.
Sang Kakek ingin mengubah tamannya menjadi sebuah labirin.
Untuk mencapat tujuan tersebut, ia dapat menanam semak-semak pada beberapa petak kosong.
Petak yang ia tanami semak-semak tidak lagi kosong.

Sebuah labirin harus memiliki syarat berikut.
Untuk setiap pasang petak kosong $a$ dan $b$ pada labirin tersebut, harus terdapat tepat satu *jalur sederhana* di antara kedua petak tersebut.
Sebuah jalur sederhana di antara petak $a$ dan $b$ adalah sebuah barisan petak kosong yang mana petak pertama adalah $a$, petak terakhir adalah $b$, seluruh petak berbeda-beda, dan setiap dua petak berurutan bertetanggaan.

Seorang anak dapat bersembunyi pada sebuah petak jika dan hanya jika petak tersebut kosong dan memiliki *tepat* satu tetangga kosong. Tidak boleh terdapat dua anak yang bersembunyi pada petak yang sama.

Anda diberikan peta taman sebagai masukan.
Tugas Anda adalah menolong Sang Kakek membuat sebuah labirin yang mana banyak anak dapat bersembunyi.

## Detil implementasi

Ini adalah sebuah soal *output-only* dengan nilai parsial.
Anda diberikan $10$ berkas masukan, yang masing-masing menyatakan taman Sang Kakek.
Untuk setiap berkas masukan, Anda harus mengumpulkan sebuah berkas keluaran berisi sebuah peta labirin.
Untuk setiap berkas keluaran, Anda akan mendapatkan poin berdasarkan banyaknya anak yang dapat bersembunyi pada labirin Anda.

Anda tidak seharusnya mengumpulkan kode sumber apapun untuk soal ini.

## Format masukan

Setiap berkas masukan mendeskripsikan petak-petak yang menyatakan sebuah taman dan memberikan banyaknya anak $k$ yang diundang oleh Sang Kakek. Formatnya adalah sebagai berikut:
* baris $1$: $\;\; m \;\; n \;\; k$
* baris $1+i$ (untuk $1 \leq i \leq m$): baris $i$ dari petak-petak, yang merupakan sebuah *string* sepanjang $n$, berisi karakter-karakter berikut (tanpa *whitespace* apapun):
  - '`.`': sebuah petak kosong,
  - '`#`': sebuah batu.

## Format keluaran

* baris $i$ (untuk $1 \leq i \leq m$): baris $i$ dari labirin Sang Kakek (taman Sang Kakek, setelah semak-semak ditanamkan). Merupakan sebuah *string* sepanjang $n$, yang berisi karakter-karakter berikut (tanpa *whitespace* apapun):
  -  '`.`': sebuah petak kosong,
  -  '`#`': sebuah batu,
  -  '`X`': sebuah semak. (Perhatikan bahwa huruf X harus dalam huruf kapital.)

## Batasan

* $1 \leq m, n \leq 1024$

## Penilaian

Sebuah berkas keluaran dianggap *sah* jika seluruh kondisi berikut terpenuhi:
* Peta keluaran harus cocok dengan peta masukan dengan sebuah pengecualian bahwa nol atau lebih karakter '`.`' pada petak masukan dapat diganti menjadi karakter '`X`' (petak yang ditanami semak-semak)
* Peta keluaran harus memenuhi syarat dari sebuah labirin, seperti yang didefinisikan pada deskripsi soal.

Jika keluaran Anda untuk sebuah kasus uji tidak sah, nilai Anda untuk kasus uji tersebut adalah $0$.
Jika tidak, nilainya adalah $\min(10, 10 \cdot l/k)$ poin, dibulatkan ke bawah dengan dua digit di belakang koma.
Di sini, $l$ adalah banyaknya anak yang dapat bersembunyi di labirin Anda, dan $k$ adalah bilangan yang diberikan pada masukan.
Anda akan mendapatkan $10$ poin untuk sebuah kasus uji jika dan hanya jika keluaran Anda adalah sebuah labirin yang mana $k$ atau lebih anak dapat bersembunyi.
Untuk setiap kasus uji terdapat solusi yang bernilai $10$ poin.

Perhatikan bahwa jika solusi Anda sah namun masih bernilai $0$ poin berdasarkan rumus di atas, *grading verdict* yang Anda akan lihat pada CMS adalah 'Wrong Answer'.

## Contoh

Perhatikan masukan berikut:

```
4 5 5
....#
.#..#
...#.
....#
```

Di bawah ini adalah sebuah keluaran sah yang mungkin:

```
.X.X#
.#..#
...#X
XX..#
```

Karena $l=4$ anak dapat bersembunyi pada labirin ini, solusi ini akan mendapatkan $10 \cdot 4 / 5 = 8$ poin. Petak-petak yang mana anak dapat bersembunyi ditandai dengan `O` di bawah ini:


```
OXOX#
.#.O#
...#X
XX.O#
```

Tiga keluaran berikut tidak sah:

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

Pada keluaran kiri tidak terdapat jalur sederhana di antara petak kosong pada ujung atas kiri dan petak kosong pada kolom paling kanan.
Pada dua keluaran lainnya, untuk setiap pasang petak kosong berbeda terdapat tepat dua jalur sederhana berbeda di antara kedua petak tersebut.
