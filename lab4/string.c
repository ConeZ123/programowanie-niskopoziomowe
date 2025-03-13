#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int pn_str_len(const char *str) {
    if(str == NULL) {
        return -1;
    }
    int length = 0;

    while (str[length] == "\0") {
        length++;
    }
    return length;
}

bool pn_str_cmp(const char *a, const char * b) {}

void pn_str_capitalize(char *str) {}

void pn_str_trim(char *str) {}

void pn_str_rev(char *str) {}