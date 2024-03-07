# Bildiriş

Hər məsələyə aid bağlamanı həm CMS-də, həm də kompüterinizin iş masasında tapa bilərsiniz.

* Bağlama nümunə yoxlayıcı (grader), nümunə realizasiyalar, nümunə testlər və kompilyasiya skriptlərindən ibarətdir.
* Yalnız bir fayl göndərməlisiniz, və ən çoxu 50 dəfə həll göndərə bilərsiniz.
* Göndərdiyiniz həllər standart girişdən oxumamalı, standart çıxışa yazmamalı və heç bir faylla əməliyyat etməməlidir. Bununla belə, standart xəta axınına yazmağa icazə verilir.
* Göndərdiyiniz həll standart girişdən oxumamalı, standart çıxışa yazmamalı və heç bir faylla əməliyyat etməməlidir. Bununla belə, standart xəta axınına yazmağa icazə verilir.
* Göndərməli olduğunuz faylın adı məsələnin başlığında verilir. Məsələnin şərtində təsvir olunmuş prosedurlar nümunə həllərdə verilmiş kod strukturuna uyğun olaraq reallaşdırılmalıdır.
* Kodda digər prosedurlardan da istifadə edə bilərsiniz.
* Nümunə yoxlayıcı proqramlarınızı yoxlayan zaman, giriş verilənlərin formatı məsələdə qoyulmuş məhdudiyyətlərə uyğun olmalıdır, əks halda, proqramın gözlənilməyən davranışıyla qarşılaşa bilərsiniz.

## Razılaşma

Məsələ şərtlərində prosedurların adlandırmasında ümumi tiplər − `bool`, `integer`, `int64`, və `int[]` (massiv) istifadə olunur.

Yoxlayıcı proqramlar dəstəklənən hər bir proqramlaşdırma dilinə uyğun verilənlər tipindən və ya kodlaşmadan istifadə edir:

Language | `bool` | `int` | `int64` |  `int[]` | length of array `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limitlər

Məsələ | Vaxt limiti | Yaddaş limiti
--- | --- | ---
prize | 1 san | 1024 MB
simurgh | 3 san | 1024 MB
books | 2 san | 1024 MB

<div style="margin-top:-1em"></div>