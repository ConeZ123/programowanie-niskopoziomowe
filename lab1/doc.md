# Program generujący tabliczkę mnożenia w C

## Opis

Program w języku C, który generuje tabliczkę mnożenia o wymiarach `n x n`. Użytkownik podaje wartość `n`, a program wyświetla wyniki w systemie dziesiętnym lub szesnastkowym, jeśli uruchomiony zostanie z dodatkowym argumentem w wierszu poleceń.

## Kod źródłowy z omówieniem

```c
#include <stdio.h>  // Dołączenie biblioteki do obsługi wejścia/wyjścia

int main(int argc, char *argv[]) {  // Główna funkcja programu, przyjmuje argumenty wiersza poleceń
    int n;  // Deklaracja zmiennej do przechowywania wartości `n`
    
    printf("Podaj wartość n: ");  // Prośba o podanie wartości `n`
    scanf("%d", &n);  // Odczytanie wartości `n` od użytkownika

    // Sprawdzenie, czy program uruchomiono z dodatkowymi argumentami
    // Jeśli tak, włączamy tryb szesnastkowy
    int hex_mode = (argc > 1) ? 1 : 0;

    // Pętla iterująca po wierszach tabliczki mnożenia
    for (int i = 1; i <= n; i++) {
        // Pętla iterująca po kolumnach tabliczki mnożenia
        for (int j = 1; j <= n; j++) {
            if (hex_mode) {  // Jeśli tryb szesnastkowy jest aktywny
                printf("%4X", i * j);  // Wypisanie wartości w systemie szesnastkowym
            } else {  // W przeciwnym razie
                printf("%4d", i * j);  // Wypisanie wartości w systemie dziesiętnym
            }
        }
        printf("\n");  // Przejście do nowego wiersza
    }

    return 0;  // Zakończenie programu
}
```
## Sposób użycia
1. Skompiluj program:

```
gcc program.c -o program
```

2. Uruchom program:
```
./program
```
Podaj liczbę n, a program wygeneruje tabliczkę mnożenia w systemie dziesiętnym.

3. Uruchomienie w trybie szesnastkowym:
```
./program hex
```
w miejsce hex można wstawić dowolną wartość

## Przykładowe wyniki dla n = 5
System dziesiętny:
```
 1   2   3   4   5
 2   4   6   8  10
 3   6   9  12  15
 4   8  12  16  20
 5  10  15  20  25
```
System szesnastkowy:
```
1   2   3   4   5
2   4   6   8   A
3   6   9   C   F
4   8   C  10  14
5   A   F  14  19
```


