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

    while (end > start && str[end] == ' ') {

    }

    int i = 0;
    
}

void pn_str_rev(char *str) {}

int main() {
    char str1[] = "   hello world   ";
    char str2[] = "hello world";
    char str3[] = "hello";
    char str4[] = " world";
    
    printf("Dlugosc str1: %d\n", pn_str_len(str1));  
    printf("Czy identyczne:  %d\n", pn_str_cmp(str2, str3));  
    
    pn_str_capitalize(str3);
    printf("Duza litera: str3: %s\n", str3);  
    
    pn_str_trim(str1);
    printf("Usuniete spacje str1: '%s'\n", str1);  
    
    pn_str_rev(str4);
    printf("Odwrocony str4: %s\n", str4);

    return 0;
}