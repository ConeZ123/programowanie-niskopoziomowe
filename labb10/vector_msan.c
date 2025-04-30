#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int16_t* vector_alloc(int n) {
    return (int16_t*) malloc(n * sizeof(int16_t));
}

void vector_print(int16_t *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void vector(int n) {
    int16_t *v = vector_alloc(n);
    vector_print(v, n);
    free(v);
}

int main() {
    vector(15);
    return 0;
}