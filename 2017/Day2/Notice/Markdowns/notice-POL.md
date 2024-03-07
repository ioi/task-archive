# Uwagi

Do każdego zadania dołączono archiwum dostępne zarówno w systemie CMS oraz na Twoim pulpicie.

* Dołączone archiwum zawiera przykładowe sprawdzaczki, przykładowe implementacje, testy przykładowe i skrypty kompilacji.
* Należy wysłać dokładnie jeden plik, możesz wysłać do 50 zgłoszeń.
* Twoje rozwiązania nie mogą odczytywać standardowego wejścia, wypisywać na standardowe wyjście lub komunikować się z jakimkolwiek innym plikiem.
Możesz natomiast wypisywać na standardowe wyjście diagnostyczne.
* Nazwa pliku, który należy wysłać jest podana w nagłówku treści zadania.
Plik powinien zawierać implementację funkcji opisanych w treści zadania używając sygnatur podanych w przykładowych implementacjach.
* Możesz implementować dodatkowe funkcje.
* Testując z użyciem przykładowej sprawdzaczki,
Twoje wejście powinno być w formacie z treści zadania i spełniać wszystkie ograniczenia, w przeciwnym przypadku mogą wystąpić nieprzewidziane problemy.

## Stosowane konwencje

Treści zadań opisują sygnatury używając ogólnych typów `bool`, `integer`, `int64`, and `int[]` (tablica).

W każdym z dostępnych języków programowania, sprawdzaczki używają następujących typów danych lub implementacji:

Język | `bool` | `integer` | `int64` |  `int[]` | długość tablicy `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Ograniczenia

Zadanie | Limit czasu | Limit pamięci
--- | --- | ---
prize | 1 sec | 1024 MB
simurgh | 3 sec | 1024 MB
books | 2 sec | 1024 MB

<div style="margin-top:-1em"></div>