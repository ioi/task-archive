# Uwagi

Do każdego zadania dołączono archiwum dostępne zarówno w systemie CMS oraz na Twoim pulpicie.

Dla zadań "Tylko wyjście":

* Dołączone archiwum zawiera pliki z testami (dane wejściowe) i testy przykładowe.
Każdy plik testowy (z danymi wejściowymi) stanowi osobne podzadanie.
* Możesz wysłać wiele plików wyjściowych jako archiwum zip. W tym celu Twoje pliki wyjściowe powinny być nazwane `??.out`, gdzie `??` jest numerem testu (na przykład: `03.out`). Możesz zarchiwizować wiele plików używając polecenia: `zip output.zip *.out`
* Możesz wysłać do 100 zgłoszeń dla zadań typu "Tylko wyjście". W każdym zgłoszeniu, możesz wysłać odpowiedzi dla dowolnego zbioru testów.

Dla pozostałych zadań:

* Dołączone archiwum zawiera przykładowe sprawdzaczki, przykładowe implementacje, testy przykładowe i skrypty kompilacji.
* Należy wysłać dokładnie jeden plik. Możesz wysłać do 50 zgłoszeń.
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
nowruz | "Tylko wyjście" | "Tylko wyjście"
wiring | 1 sec | 256 MB
train | 2 sec | 256 MB