# Pemberitahuan 

Terdapat sebuah paket lampiran pada setiap soal yang tersedia pada CMS dan *desktop* Anda.

Untuk soal-soal "Output-only":
* Paket lampiran berisi kasus-kasus uji masukan dan kasus-kasus uji contoh.
Setiap kasus uji adalah subsoal terpisah.
* Anda dapat mengumpulkan beberapa berkas keluaran sebagai sebuah berkas zip. Untuk tujuan ini, berkas-berkas keluaran Anda harus diberi nama `??.out`, yang mana `??` adalah nomor kasus uji (sebagai contoh, `03.out`). Anda dapat *zip* beberapa berkas menggunakan perintah berikut: `zip output.zip *.out`
* Anda dapat melakukan paling banyak 100 pengumpulan untuk soal-soal *output-only*. Pada setiap pengumpulan, Anda dapat mengumpulkan berkas-berkas keluaran untuk subhimpunan kasus uji manapun.

Untuk soal-soal lainnya:
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

Deskripsi-deskripsi soal menyatakan *signature-signature* menggunakan nama-nama tipe umum `bool`, `integer`, `int64`, dan `int[]` (*array*).

Pada masing-masing bahasa pemrograman yang didukung, *grader-grader* menggunakan tipe data atau implementasi yang sesuai, sebagaimana diuraikan di bawah ini:

Bahasa | `bool` | `integer` | `int64` |  `int[]` | panjang *array* `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Batasan

Soal | Batas waktu | Batas memori
--- | --- | ---
nowruz | *Output-only* | *Output-only*
wiring | 1 sec | 256 MB
train | 2 sec | 256 MB
