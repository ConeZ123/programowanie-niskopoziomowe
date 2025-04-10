## Programowanie niskopoziomowe - kolokwium 1

Napisz program który działa jako kalkulator.

Obsługiwane operacje:
- plus (dodawanie),
- minus (odejmowanie),
- przez (dzielenie),
- do (potęgowanie).

Do programu jako parametr wywoływania przekazywana jest ilość obliczeń (N), które zamierzamy przeprowadzić , np. dla N =3:
```
./kalkulator 3
```
Działanie:
- Program alokuje dynamicznie N-elementową tablicę typu double, do której będą zapisywane wyniki poszczególnych obliczeń.
- Program pyta użytkownika N razy o wartości potrzebne do obliczeń: pierwszą liczbę, słowny opis operacji i drugą liczbę.
- Program oblicza wynik przez funkcję ***calc*** przyjmując jako argument strukturę oraz zapisuje go do kolejnej pozycji w tablicy.
```C
double calc(struct Calculation *c);
```

Struktura zawiera dwie liczby (***double***) i rodzaj operacji (***enum Operation***). Pamiętaj o specjalnym przypadku dzielenia, którego się nie da obliczyć (jako wynik zapisz wtedy wartość -1).
- Wszystkie wyniki są wypisywane na ekran w jednej linii, oddzielone spacjami.
- Dodatkowo obliczana i wyświetlana jest średnia wszystkich wyników.

```
./kalkulator 3

Podaj dane: 4 plus 5
Podaj dane: 1 razy 100
Podaj dane: 3 przez 4

Wyniki: 9.00000 100.00000 0.75000
Średnia: 36.58333
```
Program wypisuje wszystkie liczby z dokładnością do pięciu miejsc po przecinku.

Uwagi:
- Do potęgowania użyj funkcji ***pow*** z ***<math.h>*** (biblioteka -lm).
- Pamiętaj o prawidłowej obsłudze pamięci (zwolnienie pamięci, inicjalizacja zmiennych).
- Unikaj używania zmiennych globalnych.
- Podziel kod na małe części (oddzielne funkcje).
