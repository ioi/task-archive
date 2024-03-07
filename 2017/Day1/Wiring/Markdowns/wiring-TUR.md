# Kablolama (Wiring)


Meryem bir iletişim kulesinde kabloların nasıl bağlanacağını tasarlayan bir elektrik mühendisidir. Kule
üzerinde her biri farklı yüksekliklerde bağlanma noktaları vardır. Bir kablo herhangi iki bağlanma
noktasını birbirine bağlamak için kullanılmaktadır. Her bağlanma noktası bir veya daha çok bağlanma
noktasına bağlanabilir. Her bağlantı noktası şu iki renkten birindedir: Kırmızı veya Mavi.

Bu problemde kule, kırmızı veya mavi renkli bağlantı noktalarının herbirinin ayrı bir negatif olmayan
tamsayıya karşılık geldiği bir sayı doğrusu olarak düşünülebilir. Her kablonun uzunluğu bağladığı noktalar
arasındaki uzaklığa eşittir.

Meryem’in aşağıdaki şartları sağlayan bir kablolama yapmasına yardım etmeniz bekleniyor:
1. Her bağlanma noktası farklı renkteki bir bağlanma noktasına bir kablo aracılığıyla bağlı olmalı,
1. Kullanılan kabloların uzunlukları toplamı minimize edilmelidir.


## Gerçekleştirim detayları

Aşağıdaki prosedürü kodlamalısınız:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: $n$ uzunluğunda dizi. Bu dizi kırmızı bağlantı noktalarının pozisyonlarını artan sırada içerir. 
* $b$: $m$ uzunluğunda dizi. Bu dizi mavi bağlantı noktalarının pozisyonlarını artan sırada içerir. 
* Bu prosedür tüm geçerli kablolama şekilleri içinden minimum toplam kablo uzunluğunu dönmelidir. 
* Not: bu prosedürün döneceği değerin türü `int64` 'dür. 

## Örnek

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Aşağıdaki şekil, bu örneği açıklar.
![Wiring](wiring.png)

* Kule yatay şekilde görülmektedir. 
* Bu problemin siyah-beyaz çıktısında, kırmızı bağlantı noktaları koyu ve mavi bağlantı noktaları açık renktir. 
* $1, 2, 3,$ and $7$ pozisyonunda olan $4$ kırmızı bağlantı noktaları vardır. 
* $0, 4, 5, 9,$ and $10$ pozisyonunda olan $5$ mavi bağlantı noktası vardır. 
* Yukarıdaki şekilde bir optimal çözüm görülmektedir.  
* Bu çözümde, kabloların toplam uzunluğu $1 + 2 + 2 + 2 + 3 = 10$ olacaktır ki bu optimaldir. Yani, prosedür $10$ dönmelidir. 
* Not: $7$ pozisyonundaki bağlantı noktasına iki kablo bağlıdır. 

## Sınırlar

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (tüm $0 \leq i \leq n-1$ için),
* $0 \leq b[i] \leq 10^9$ ($0 \leq i \leq m-1$ için),
* $r$ ve $b$ dizilerinin her biri artan sırada sıralıdır. 
* $r$ ve $b$ dizilerinin tüm  $n+m$ değerleri farklıdır.

## Altgörevler

1. (7 puan) $n, m \leq 200$,
1. (13 puan) Tüm kırmızı bağlantı noktalarının pozisyonları herhangi bir mavi bağlantı noktasından küçüktür. 
1. (10 puan) Her $7$ ardışık bağlantı noktası içinde en az bir kırmızı bağlantı noktası ve bir mavi bağlantı noktası vadır.
1. (25 puan) Tüm bağlantı noktalarının $[1, n+m]$ aralığında farklı pozisyonları vardır.
1. (45 puan) Ek kısıt yoktur.

## Örnek değerlendirici

Örnek değerlendirici girdiyi aşağıdaki formatta okur:
* satır $1$: $\;\; n \;\; m$
* satır $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* satır $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Örnek değerlendirici `min_total_length` in dönme değerini içeren tek bir satır yazar.
