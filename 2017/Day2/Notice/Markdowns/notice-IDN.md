# Pemberitahuan 

Terdapat sebuah paket lampiran pada setiap soal yang tersedia pada CMS dan *desktop* Anda.

* Paket lampiran berisi contoh-contoh *grader*, contoh-contoh implementasi, kasus-kasus uji contoh, dan *script-script* kompilasi.
* Anda harus mengumpulkan tepat sebuah berkas, dan Anda dapat melakukan paling banyak 50 pengumpulan.
* Pengumpulan Anda tidak boleh membaca dari *standard input*, mencetak ke *standard output* atau berinteraksi dengan berkas lain manapun.
Tetapi, pengumpulan Anda dapat mengeluarkan ke *standard error*.
* Nama berkas yang Anda harus kumpulkan diberikan pada *header* deskripsi soal.
Berkas Anda harus mengimplementasikan prosedur-prosedur yang dideskripsikan pada deskripsi soal menggunakan *signature-signature* yang diberikan pada contoh-contoh implementasi.
* Anda bebas untuk mengimplementasikan prosedur lainnya.
* Ketika menguji program Anda dengan contoh *grader*,
masukan Anda harus cocok dengan format dan batasan pada deskripsi soal, jika tidak, *unspecified behavior* mungkin saja terjadi. 

## Konvensi

Deskripsi-deskripsi soal menyatakan *signature-signature* menggunakan nama-nama tipe umum `bool`, `int`, `int64`, dan `int[]` (*array*).

Pada masing-masing bahasa pemrograman yang didukung, *grader-grader* menggunakan tipe data atau implementasi yang sesuai, sebagaimana diuraikan di bawah ini:

Bahasa | `bool` | `int` | `int64` |  `int[]` | panjang *array* `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Batasan

Soal | Batas waktu | Batas memori
--- | --- | ---
prize | 1 sec | 1024 MB
simurgh | 3 sec | 1024 MB
books | 2 sec | 1024 MB

<div style="margin-top:-1em"></div>