# Nowruz

Za parę dni Irańczycy świętują Nowy Rok (Nowruz). Dziadek z tej okazji zaprosił do swojego ogrodu rodzinę. Wśród gości będzie $k$ dzieci. Specjalnie dla nich dziadek planuje zabawę w chowanego. 

Ogród składa się identycznych kwadratowych pól tworzących siatkę -- prostokąt $m \times n$. 
Niektóre pola (być może zero) są zablokowane przez skały, pozostałe są *wolne*. 
Dwa pola *sąsiadują* ze sobą, jeśli mają wspólną krawędź. 
Zatem każde pole może mieć co najwyżej $4$ sąsiadów: dwóch w  poziomie i dwóch w pionie. 
Dziadek chce zmienić swój ogród w labirynt. 
W tym celu zamierza zablokować niektóre pola, sadząc na nich krzaki.
Pola z posadzonymi krzakami przestają być wolne. 

Labirynt musi mieć następującą własność.   
Każda para pól $a$ i $b$ musi być połączona dokładnie jedną *ścieżką prostą*. 
Ścieżka prosta między polami $a$ i $b$ to ciąg wolnych pól, z których pierwsze to $a$, ostatnie to $b$, wszystkie pola są różne i każde dwa kolejne pola są sąsiadami. 

Dziecko jest w stanie ukryć się na danym polu wtedy i tylko wtedy, gdy jest ono wolne oraz ma *dokładnie* jednego wolnego sąsiada. 
Każde pole może pomieścić co najwyżej jedno dziecko. 

Na wejściu dana jest mapa ogrodu. 
Zadanie polega na pomocy dziadkowi w zaplanowaniu labiryntu tak, aby umożliwić schowanie się wielu dzieciom. 

## Szczegóły implementacji

To jest zadanie typu "tylko wyjście" z ocenami częściowymi.
Dostaniesz $10$ plików wejściowych; każdy opisuje ogród dziadka. 
Dla każdego z tych plików powinieneś wygenerować plik z mapą labiryntu. 
Za każdy plik wyjściowy dostaniesz punkty, których liczba będzie zależała od liczby dzieci, które mogą się ukryć w labiryncie. 

Nie musisz zgłaszać kodu programu dla tego zadania. 

## Format wejścia

Każdy plik wejściowy opisuje jeden prostokąt złożony z pól, reprezentujący ogród i określający liczbę dzieci $k$ zaproszonych przez dziadka. Format jest następujący:
* wiersz $1$: $\;\; m \;\; n \;\; k$
* wiersz $1+i$ (dla $1 \leq i \leq m$):  $i$-ty wiersz siatki, który jest napisem o długości $n$, składającym się z następujących znaków (bez odstępów).
  - '`.`': wolna komórka,
  - '`#`': skała.

## Format wyjścia

* wiersz $i$ (dla $1 \leq i \leq m$): $i$-ty wiersz labiryntu (ogród po zasadzeniu krzaków). Jest to napis długości $n$, składający się z następujących znaków (bez odstępów):
  -  '`.`': wolne pole,
  -  '`#`': skała,
  -  '`X`': krzak. (Uwaga: X musi być wielką literą)

## Ograniczenia

* $1 \leq m, n \leq 1024$

## Punktacja

Plik wyjściowy jest poprawny, jeśli wszystkie poniższe warunki są spełnione:
* Mapa wyjściowa musi zgadzać się z wejściową. Jedyna różnica dotyczyć może znaków '`.`', których dowolna liczba może być zastąpiona przez znaki  '`X`' (pola blokowane przez krzaki).
* Mapa wyjściowa musi być labiryntem spełniającym warunki podane w specyfikacji zadania. 

Jeśli Twoje wyjście nie jest poprawne, to wynikiem testu będzie $0$. 
W przeciwnym razie, wynik będzie równy  $\min(10, 10 \cdot l/k)$ punktów, zaokrąglone w dół do dwóch cyfr po przecinku. 
W tym wzorze $l$ jest liczbą dzieci, które mogą sie ukryć w labiryncie, a $k$ jest liczbą dzieci podaną na wejściu.
Za każdy test otrzymasz $10$ punktów  wtedy i tylko wtedy, gdy stworzysz labirynt w którym może się ukryć co najmniej $k$ dzieci. 
Dla każdego testu istnieje rozwiązanie uzyskujące $10$ punktów. 

Jeśli Twoje rozwiązanie jest poprawne, ale zgodnie z podanym wzorem uzyskałoby $0$ punktów, to system oceniający CMS wypluje "Wrong Answer". 

## Przykład

Dla następującego wejścia:

```
4 5 5
....#
.#..#
...#.
....#
```

poprawne jest następujące wyjście:

```
.X.X#
.#..#
...#X
XX..#
```

W tym labiryncie może się schować $l=4$ dzieci, dlatego
rozwiązanie to uzyska $10 \cdot 4 / 5 = 8$ punktów. Pola, w których mogą się ukryć dzieci, są oznaczone poniżej przez `O`:


```
OXOX#
.#.O#
...#X
XX.O#
```

Następujące trzy wyjscia są niepoprawne: 

```
.XXX#        ...X#        XXXX#
.#XX#        .#.X#        X#XX#
...#.        ...#X        ..X#X
XX..#        XXXX#        ..XX#

```

W pierwszym z nich nie ma prostej ścieżki między lewym górnym rogiem, a wolnym polem na prawej krawędzi. 
W pozostałych dwóch przypadkach dla każdej pary różnych pól istnieją dokładnie dwie ścieżki proste łączące je. 