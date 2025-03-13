#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int pn_str_len(const char *str) {
    if(str == NULL) {
        return -1;
    }

    int length = 0;
    while (str[length] != "\0") {
        length++;
    }
    return length;
}

bool pn_str_cmp(const char *a, const char * b) {
    if (*a == NULL && *b == NULL) {
        return -1;
    }

    if (pn_str_len(a) != pn_str_len(b)) {
        return false;
    }

    while (*a && *b) {
       if (*a != *b) {
            return false;
       }
       a++;
       b++;
    }
    return true;
}

void pn_str_capitalize(char *str) {
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - ('a' - 'A'); 
    }
}

void pn_str_trim(char *str) {
    int start = 0;
    int end = pn_str_len(str) - 1;

    while (str[start] == ' ') {
        start++;
    }


}

void pn_str_rev(char *str) {}

int main() {

}