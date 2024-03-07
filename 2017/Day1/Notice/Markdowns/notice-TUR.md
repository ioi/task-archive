# Uyarı (Notice)

Her bir görevin hem CMS hem de bilgisayarınızda bulunan ek paketi vardır.

"Sadece-çıktı" görevleri için:

* Ek paket girdi test durumlarını ve örnek test durumlarını içerir.
Her bir test durumu farklı bir altgörevdir. 
* Birden fazla çıktı dosyasını tek bir zip dosyası olarak gönderebilirsiniz. Bu amaç için, çıktı dosyalarınız `??.out` olarak adlandırılmalıdır, burada `??` test durum numarasıdır (örnek, `03.out`). Şu komutu kullanarak birden fazla dosyayı zip'layabilirsiniz:  `zip output.zip *.out`
* Sadece-çıktı görevleri için, 100'e kadar kadar gönderim yapabilirsiniz. Her bir gönderiminizde, test durumlarının herhangi bir alt kümesi için çıktı dosyaları gönderebilirsiniz.

Diğer görevler için:
* Ek paket örnek değerlendirici, örnek kodlama, örnek test durumları ve derleyici script'leri içerir.
* Tam olarak bir tane dosya göndermelisiniz, ve 50'ye kadar gönderim yapabilirsiniz. 
* Gönderiminiz, standart girdiden okuma, standart çıktıya yazma veya başka dosyalar ile iletişimde bulunmamalıdır. Ancak, standart hata akımına (standart error stream) yazabilir. 
* Göndermeniz gereken dosyanın ismi görev başlığında verilmiştir. Örnek kodlamadaki imzaları kullanarak, görev içinde tanımlanan prosedürleri gerçekleştirmelidir. 
* Başka prosedürleri kodlamada özgürsünüz.
* Programlarınızı örnek değerlendirici ile test ettiğinizde, girdiniz, format ile ve görev tanımındaki kısıtlar ile uygun olmalıdır. Diğer durumda, belirsiz durumlar görülebilir. 

## Genel kullanım 

Görev tanımları imzaları genel tür isimleri ile  `bool`, `integer`, `int64`, ve `int[]` (array) belirler. 

Desteklenen her bir programlama dili için, değerlendirici aşağıda listelendiği gibi uygun veri türünü veya kodlamasını kullanır:

Dil | `bool` | `integer` | `int64` |  `int[]` | `a` dizisinin uzunluğu
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Sınırlar

Görev | Zaman sınırı | Hafıza sınırı
--- | --- | ---
nevruz (nowruz) | Sadece-çıktı | Sadece-çıktı
kablolama | 1 sn | 256 MB
oyun treni (train) | 2 sn | 256 MB
