#include <stdio.h>

int main(int argc, char *argv[]) {
    int n;
    printf("Podaj wartość n: ");
    scanf("%d", &n);

    int hex_mode = (argc > 1) ? 1 : 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (hex_mode) {
                printf("%4X", i * j);  
            } else {
                printf("%4d", i * j);  
            }
        }
        printf("\n");
    }

    return 0;
}