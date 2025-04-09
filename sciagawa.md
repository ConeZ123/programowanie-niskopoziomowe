
# 📘 C Language Cheatsheet – Kolokwium 1

## 1. Argumenty wejściowe

```c
int main(int argc, char *argv[]) {
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}
```

## 2. printf / scanf

```c
int x;
printf("Podaj liczbe: ");
scanf("%d", &x);
printf("Podałeś: %d\n", x);
```

## 3. Funkcje

```c
int dodaj(int a, int b) {
    return a + b;
}

int wynik = dodaj(2, 3);
printf("%d\n", wynik);
```

## 4. Wskaźniki (Pointery)

```c
int x = 10;
int *ptr = &x;
printf("%d\n", *ptr);  // 10
```

## 5. Tablice

### Jednowymiarowe

```c
int arr[5] = {1, 2, 3, 4, 5};
```

### Wielowymiarowe

```c
int mat[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

## 6. Dynamiczna alokacja – malloc

### Jednowymiarowa

```c
int *arr = malloc(5 * sizeof(int));
arr[0] = 42;
free(arr);
```

### Dwuwymiarowa

```c
int **mat = malloc(3 * sizeof(int*));
for (int i = 0; i < 3; ++i) {
    mat[i] = malloc(4 * sizeof(int));
}
// Użycie...
for (int i = 0; i < 3; ++i) {
    free(mat[i]);
}
free(mat);
```

## 7. Stringi C-style (char *)

```c
char str[] = "Hello";
char *dyn = malloc(6 * sizeof(char));
strcpy(dyn, "World");
printf("%s %s\n", str, dyn);
free(dyn);
```

## 8. Struktury

```c
struct Student {
    char name[50];
    int age;
};

struct Student s1;
strcpy(s1.name, "Janek");
s1.age = 20;
```

## 9. Wyliczenia (enum)

```c
enum Day { MON, TUE, WED, THU, FRI };
enum Day today = WED;
if (today == WED) {
    printf("Środa!\n");
}
```
