#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

int main() {
    const char *filename = 'content.txt';
    file_hello(filename);
    char choice[16];
    char buffer[256];

    while (1) {
        printf("\n Wybierz opcję (print , append, exit): ");
        scanf("%15s", choice);

        if (strcmp(choice, "print") == 0) {
            printf("Wprowadź dane do dopisania: ");
            getchar();
            fgets(buffer, sizeof(buffer), stdin);
            file_append(filename, buffer);
        } else if (strcmp(choice, "exit") == 0) {
            file_remove(filename);
            break;
        } else {
            printf("Nieprawidłowa operacja \n");
        }
    }

    return 0;
}