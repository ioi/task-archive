# Bildiriş

Hər məsələyə aid bağlamanı həm CMS-də, həm də kompyuterinizin iş masasında tapa bilərsiniz.

"Yalnız çıxışlı" məsələlər üçün:
* Bağlama giriş və nümunə testlərindən ibarətdir. Hər bir test fərqli alt-tapşırıqdır.
* Siz bir-neçə çıxış faylını zip faylı şəklində göndərə bilərsiniz. Bunun üçün sizin çıxış fayllarınız `??.out` adlanmalıdır, harda ki, `??` test nömrəsini bildirir (məsələn `03.out`). Bir neçə faylı növbəti komandayla ilə zip-ləmək olar: `zip output.zip *.out`
* Yalnız cıxışlı məsələlərdə cavabı sistemə ən çox 100 dəfə göndərmək mümkündür. Hər dəfə testlərin istənilən alt çoxluğu üçün çıxış fayllarını göndərə bilərsiniz.

Digər məsələlər üçün:
* Bağlama nümunə qreyderlər, nümunə realizasiyalar, nümunə testlər və kompilasiya skriptlərindən ibarətdir.
* Yalnız bir fayl göndərməli, və ən çoxu 50 dəfə həll göndərə bilərsiniz.
* Göndərdiyiniz həll standart girişdən oxumamalı, standart çıxışa yazmamalı və heç bir faylla əməliyyat etməməlidir. Bununla belə, standart xəta axınına yazmağa icazə verilir.
* Göndərməli olduğunuz faylın adı məsələnin başlığında verilir. Məsələnin şərtində təsvir olunmuş prosedurlar nümunə həllərdə verilmiş kod strukturuna uyğun olaraq reallaşdırılmalıdır.
* Kodda digər prosedurlardan da istifadə edə bilərsiniz.
* Nümunə qreyderlə proqramlarınızı yoxlayan zaman, giriş verilənlərin formatı məsələdə qoyulmuş məhdudiyyətlərə uyğun olmalıdır, əks halda, proqramın gözlənilməyən davranışıyla qarşılaşa bilərsiniz.

## Anlaşmalar

Məsələ şərtlərində prosedurların adlandırmasında ümumi tiplər $-$ `bool`, `integer`, `int64`, və `int[]` (massiv) istifadə olunur.

Dəstəklənən hər bir proqramlaşdırma dilində qreyderlər uyğun verilənlər tipindən və ya kodlaşmadan istifadə edir:

Dil | `bool` | `integer` | `int64` |  `int[]` |  `a` massivinin uzunluğu
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limitlər

Məsələ | Vaxt limiti | Yaddaş limiti
--- | --- | ---
nowruz | Yalnız çıxışlı | Yalnız çıxışlı
wiring | 1 sec | 256 MB
train | 2 sec | 256 MB
