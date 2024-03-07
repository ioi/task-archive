# Nevruz

Nevruz Bayramı’na birkaç gün kalmıştır ve büyükbaba ailesini Nevruz kutlaması için bahçesine davet etmiştir. Davetliler arasında $k$ tane çocuk vardır ve büyükbaba bahçesini saklambaç oyunu için hazırlamak istemektedir.

Bahçe $m \times n$’lik eşit birim hücrelerden oluşan bir ızgara (grid) olarak düşünülebilir. Bazı (sıfır yada daha çok) hücrelerde kaya vardır (bu hücrelere bloke hücreler denmektedir), kaya olmayan hücreler ise *boştur*. Arasında kenar (edge) bulunan hücrelere *komşu* hücreler denir. Her hücrenin en fazla 4 komşusu vardır: iki tanesini yatayda ve iki tanesi düşeyde. Büyükbaba bazı boş hücrelere çalı dikip bu hücreleri bloke hücreye çevirmek suretiyle bahçesini bir labirente (maze) dönüştürmek istemektedir.

Bir labirentte her $a$ ve $b$ boş hücre ikilisi arasında sadece bir tane *basit yol* bulunmalıdır. $a$ ve $b$ boş hücreleri arasında bir basit yol; ilk hücresi $a$, son hücresi $b$, bütün hücreleri farklı ve ardışık iki hücresi komşu olan bir boş hücreler dizisidir.

Bir çocuk bir hücrede saklanabilir ancak ve ancak o hücre boşsa ve o hücrenin *tam olarak* bir tane boş komşu hücresi varsa. Bir hücreye sadece bir çocuk sağlanabilir.

Girdi olarak size bahçenin bir haritası veriliyor ve sizden mümkün olduğunca çok çocuğun saklanabileceği bir labirent oluşturmanız bekleniyor.


## Gerçekleştirim Detayları
Bu soru kısmi puan alınabilecek sadece-çıktı türündedir. 
Size büyükbabanın bahçesini gösteren $10$ girdi dosyası veriliyor ve sizden herbir girdi dosyası için oluşturduğunuz labirenti içeren bir çıktı dosyası göndermeniz beklenmektedir. Herbir çıktı dosyasında saklanabilecek çocuk sayısına bağlı olarak kısmi bir puan alacaksanız.

Bu soruda sizden kaynak kod göndermeniz beklenmemektedir.



## Girdi Formatı

Her girdi dosyası bahçeyi tarif eden bir ızgara (grid) ve büyükbaba tarafından davet edilen çocuk sayısı $k$'yı içermektedir. Format aşağıdaki gibidir:
* satır $1$: $\;\; m \;\; n \;\; k$
* satır $1+i$ ($1 \leq i \leq m$ için): ızgaranın $i$'inci satırını temsil etmektedir. Boşluk içermeyen ve aşağıdaki karakterlerden oluşan $n$ uzunluğunda bir dizgidir.
  - '`.`': boş hücre,
  - '`#`': kaya bulunan hücre.

## Çıktı formatı

* satır $i$ ($1 \leq i \leq m$ için): Bahçenin çalılar dikildikten sonraki halinin $i$'inci satırını temsil etmektedir. Boşluk içermeyen ve aşağıdaki karakterlerden oluşan $n$ uzunluğunda bir dizgidir.
  -  '`.`': boş hücre,
  -  '`#`': kaya bulunan hücre,
  -  '`X`': çalı bulunan hücre. (X harfi büyük harfle yazılmalıdır.)

## Kısıtlar

* $1 \leq m, n \leq 1024$

## Puanlama

Çıktı dosyasının *geçerli* olması için aşağıdaki şartları sağlaması gerekmektedir:
* Çıktı dosyasındaki haritanın girdi dosyasındaki haritadan tek farkı, girdi dosyasındaki bazı '`.`' karakterlerinin '`X`' karakterine dönüştürülmüş olmasıdır (Değişen karakterler çalı ekilen hücreleri göstermektedir). 
* Çıktı haritası soruda verilen labirent özelliğini sağlmalıdır.

Bir test durumu için çıktınız geçerli değilse, bu test durumundan $0$ puan alırsınız.
Aksi taktirde, bu test durumu için puanınız  $\min(10, 10 \cdot l/k)$ formülü ile hesaplanır. Puanınızda noktadan sonra iki basamak vardır ve bu iki basamak aşağı yuvarlama ile elde edilmiştir.
Bu formüldeki $l$, çıktı labirentinizde saklanabilecek çocuk sayısını göstermektedir, $k$ ise size girdi dosyasında verilen sayıdır.
Bir test durumundan $10$ puan alabilmeniz için çıktınızdaki labirentte en az $k$ çocuk saklanabilmelidir. Herbir test durumu için $10$ puan alacak bir çözüm vardır.

Çözümünüz geçerliyse ve yukarıdaki formüle göre yine de $0$ puan alıyorsanız, CMS'de göreceğiniz notlandırma kararı 'Wrong Answer' olacaktır.

## Örnek

Aşağıdaki örnek girdiyi göz önüne alın:

```
4 5 5
....#
.#..#
...#.
....#
```

Yukarıdaki örnek girdi için geçerli bir çıktı aşağıda verilmiştir.

```
.X.X#
.#..#
...#X
XX..#
```

Labirentte $l=4$ çocuk saklanabildiği için, bu çözüm $10 \cdot 4 / 5 = 8$ puan kazandırır. Aşağıda çocukların saklanabilecekleri hücreler `O` ile gösterilmiştir.


```
OXOX#
.#.O#
...#X
XX.O#
```

Aşağıda verilen üç çıktı ise geçerli değildir.

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

Soldaki çıktıda sol üst köşedeki boş hücre ile en sağ sütündaki boş hücre arasında basit yol yoktur.
Diğer iki çıktıda ise, her farklı boş hücre ikilisi arasında iki farklı basit yol vardır.
