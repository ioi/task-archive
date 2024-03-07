# Uyarı

Her bir görevin hem CMS hem de bilgisayarınızda bulunan ek paketi vardır.

* Ek paket örnek değerlendirici, örnek kodlama, örnek test durumları ve derleyici script'leri içerir.
* Tam olarak bir tane dosya göndermelisiniz, ve 50'ye kadar gönderim yapabilirsiniz.
* Gönderiminiz, standart girdiden okuma, standart çıktıya yazma veya başka dosyalar ile iletişimde bulunmamalıdır. Ancak, standart hata akımına (standart error stream) yazabilir.
* Göndermeniz gereken dosyanın ismi görev başlığında verilmiştir. Örnek kodlamadaki imzaları kullanarak, görev içinde tanımlanan prosedürleri gerçekleştirmelidir.
* Başka prosedürleri kodlamada özgürsünüz.
* Programlarınızı örnek değerlendirici ile test ettiğinizde, girdiniz, format ile ve görev tanımındaki kısıtlar ile uygun olmalıdır. Diğer durumda, belirsiz durumlar görülebilir.

## Genel kullanım

Görev tanımları imzaları genel tür isimleri ile `bool`, `int`, `int64`, and `int[]` belirler.

Desteklenen her bir programlama dili için, değerlendirici aşağıda listelendiği gibi uygun veri türünü veya kodlamasını kullanır:

Dil | `bool` | `int` | `int64` |  `int[]` | `a` dizisinin uzunluğu
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Sınırlar

Görev | Zaman sınırı | Hafıza sınırı 
--- | --- | ---
büyük ödül (prize) | 1 sn | 1024 MB
simurgh | 3 sn | 1024 MB
eski kitaplar (books) | 2 sn | 1024 MB

<div style="margin-top:-1em"></div>