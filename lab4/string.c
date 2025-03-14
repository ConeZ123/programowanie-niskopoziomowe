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
    if (!str) {
        return;
    }

    int start = 0;
    int end = pn_str_len(str) - 1;

    while (str[start] == ' ') {
        start++;
    }

    while (end > start && str[end] == ' ') {
        end--;
    }

    int i = 0;
    while (start <= end) {
        str[i++] = str[start++];
    }

    str[i] = '\0';
    
}

void pn_str_rev(char *str) {
    if (!str) {
        return;
    } 

    int len = pn_str_len(str);
    int left = 0, right = len - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char test1[] = " test ";
    char test2[] = "hello";
    char test3[] = "world";

    printf("Długość 'hello': %d\n", pn_str_len(test2));
    printf("Porównanie 'hello' i 'world': %s\n", pn_str_cmp(test2, test3) ? "tak" : "nie");

    pn_str_capitalize(test2);
    printf("Po kapitalizacji: %s\n", test2);

    pn_str_trim(test1);
    printf("Po trimowaniu: '%s'\n", test1);

    pn_str_rev(test3);
    printf("Po odwróceniu: %s\n", test3);

    return 0;
}