#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int16_t* vector_alloc(int n) {
    return (int16_t*) malloc(n * sizeof(int16_t));
}

void vector_fill(int16_t *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % (INT16_MAX + 1);
    }
}

void vector_print(int16_t *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i] / i);
    }
    printf("\n");
}

void vector(int n) {
    int16_t *v = vector_alloc(n);
    vector_fill(v, n);
    vector_print(v, n);
    free(v);
}

int main() {
    srand(0);
    vector(15);
    return 0;
}