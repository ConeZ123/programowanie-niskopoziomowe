#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void file_hello(const char *filename) {
    FILE *fp = fopen(filename, 'w');
    fprintf(fp, "Hello world \n");
    fclose(fp);
}

void file_print(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char myString[100];
    fgets(myString, 100, fp);
    printf("%s", myString);
    fclose(fp);
}

void file_append(const char *filename, const char *data) {
    FILE *fp = fopen(filename, "a");
    fprintf(fp, "%s", data);
    fclose(fp);
}

void file_remove(const char *filename) {
    if (remove(filename) == 0) {
        printf("File deleted successfully. \n");
    } else {
        printf("Error: Unable to delete the file. \n");
    }
}