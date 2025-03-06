#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* arr_new(size_t n) {
    int *arr = (int*)malloc(sizeof(int) * (n+1));
    arr[0] = n;
    return n; 
}                     

void arr_free(int *a) {
    free(a);    
}

size_t arr_length(int *a) {
    return a[0];
}

void arr_print(const int *a) {
    for(size_t i = 1; i <= arr_length(a);i++) {
        printf("%d", a[i]);
    }
} 

void arr_clear(int *a) {
    for(size_t i = 1; i <= arr_length(a);i++) {
        a[i] = 0;
    }
}

void arr_set(int *a, size_t index, int value) {
    a[index + 1] = value;
}

int arr_get(int *a, size_t index) {
    return a[index + 1];
}

void arr_rand(int *a) {
    for (size_t i = 1; i <= arr_length; i++) {
        a[i] = rand();
    }
}

int arr_dot(int *a, int *b) {

    int dot = 0;
    if (arr_length(a) == arr_length(b)) {
        for(size_t i = 1; i <= arr_length(a);i++) {
            dot += a[i] * b[i];
        }
    }
    return dot;
}

bool arr_add(int *dest, int *arr) {
    if (arr_length(dest) == arr_length(arr)) {
        for (size_t i = 1; i <= arr_length; i++) {
            dest[i] += arr[i];
        }
        return true;
    }
}


// do zrobienia
int* arr_add_new(int *a, int *b) {

}


int main() {

}