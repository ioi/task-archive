# Okablowanie

Maryam jest elektrykiem i projektuje okablowanie na wieży komunikacyjnej.
Na wieży znajdują się punkty komunikacyjne umieszczone na różnych wysokościach.
Dwa punkty komunikacyjne można połączyć z użyciem kabla.
Do każdego punktu komunikacyjnego może być podłączone dowolnie wiele kabli.
Są dwa rodzaje punktów komunikacyjnych: czerwone i niebieskie.

Na potrzeby tego zadania uznajemy wieżę jako oś liczbową, a punkty komunikacyjne
jako niebieskie i czerwone punkty leżące na nieujemnych całkowitych współrzędnych na tej osi.
Długość kabla to odległość pomiędzy łączonymi punktami komunikacyjnymi.

Twoim celem jest pomóc Maryam w zaprojektowaniu takiego okablowania, że:
1. Każdy punkt komunikacyjny ma co najmniej jeden kabel łączący go z punktem komunikacyjnym innego koloru.
1. Łączna długość użytych kabli jest najmniejsza możliwa.

## Szczegóły implementacji

Należy zaimplementować następującą funkcję:

```
int64 min_total_length(int[] r, int[] b)
```

* $r$: tablica długości $n$ zawierająca pozycje czerwonych punktów komunikacyjnych, w kolejności rosnącej.
* $b$: tablica długości $m$ zawierająca pozycje niebieskiech punktów komunikacyjnych, w kolejności rosnącej.
* Funkcja powinna zwrócić minimalną łączną długość okablowania wśród wszystkich poprawnych okablowań.
* Zauważ, że zwracanym typem funkcji jest `int64`.

## Przykład

```
min_total_length([1, 2, 3, 7], [0, 4, 5, 9, 10])
```

Obrazek poniżej ilustruje ten przykład.
![Wiring](wiring.png)

* Wieża pokazana jest w poziomie.
* W wersji czarno-białej treści zadania: czerwone punkty komunikacyjne są ciemne, zaś niebieskie punkty komunikacyjne są jasne.
* Są $4$ czerwone punkty komunikacyjne, zlokalizowane na współrzędnych $1, 2, 3$ oraz $7$.
* Jest $5$ niebieskich punktów komunikacyjnych, zlokalizowanych na współrzędnych $0, 4, 5, 9$ oraz $10$.
* Jedno z optymalnych rozwiązań znajduje się na obrazku powyżej.
* W tym rozwiązaniu łączna długość kabli wynosi $1 + 2 + 2 + 2 + 3 = 10$, co jest optymalne.
W związku z tym funkcja powinna zwrócić $10$.
* Zauważ, że dwa kable połączone są z punktem komunikacyjnym na współrzędnej $7$.

## Ograniczenia

* $1 \leq n, m \leq 100\,000$,
* $0 \leq r[i] \leq 10^9$ (dla każdego $0 \leq i \leq n-1$),
* $0 \leq b[i] \leq 10^9$ (dla każdego $0 \leq i \leq m-1$),
* Każda z tablic $r$ oraz $b$ jest posortowana rosnąco.
* Wszystkie $n+m$ wartości w tablicach $r$ i $b$ są parami różne.

## Podzadania

1. (7 punktów) $n, m \leq 200$.
1. (13 punktów) Wszystkie czerwone punkty komunikacyjne są na współrzędnych mniejszych niż wszystkie niebieskie punkty komunikacyjne.
1. (10 punktów) Wśród każdych $7$ kolejnych punktów komunikacyjnych jest co najmniej jeden czerwony i jeden niebieski.
1. (25 punktów) Wszystkie punkty komunikacyjne mają różne pozycje w przedziale $[1, n+m]$.
1. (45 punktów) Brak dodatkowych ograniczeń.

## Przykładowa sprawdzaczka

Przykładowa sprawdzaczka odczytuje wejście w następującym formacie:
* wiersz $1$: $\;\; n \;\; m$
* wiersz $2$: $\;\; r[0] \;\;  r[1] \;  \ldots \; r[n-1]$
* wiersz $3$: $\;\; b[0] \;\;  b[1] \;  \ldots \; b[m-1]$

Przykładowa sprawdzaczka wypisuje jeden wiersz zawierający zwróconą wartość funkcji `min_total_length`.