#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum Operations {
    PLUS,
    MINUS,
    RAZY,
    PRZEZ,
    DO
};

struct Calculation {
    double a;
    double b;
    enum Operations oper;
};

double calc(struct Calculation *c) {
    switch (c -> oper) {
        case PLUS:
            return c->a + c->b;
        case MINUS:
            return c->a - c->b;
        case RAZY:
            return c->a * c->b;
        case PRZEZ:
            return (c->b == 0) ? -1 : c->a / c->b;
        case DO:
            return pow(c->a, c->b);
        default:
            return 0;
    }
}

enum Operations parse_operation(char* operation) {
    if (strcmp(operation , "plus") == 0) return PLUS;
    if (strcmp(operation, "minus") == 0) return MINUS;
    if (strcmp(operation, "razy") == 0) return RAZY;
    if (strcmp(operation, "przez") == 0) return PRZEZ;
    if (strcmp(operation, "do") == 0) return DO;
    return PLUS;
}

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);

    struct Calculation *opeartions = malloc(N * sizeof(struct Calculation));
    double *results = malloc(N * sizeof(double));

    if (!opeartions && !results) {
        printf("Błąd alokacji pamięci");
    }

    for (int i = 0; i < N; i++) {
        char buff[10];
        printf("\nPodaj dane: ");
        scanf("%lf %s %lf", &opeartions[i].a, buff, &opeartions[i].b);
        opeartions[i].oper = parse_operation(buff);
        results[i] = calc(&opeartions[i]);
    }

    double sum = 0;
    printf("Wyniki: ");
    for (int i = 0; i < N; i++) {
        printf("%.5f ", results[i]);
        sum += results[i];
    }
    printf("\nŚrednia: %.5f ", sum / N);

    free(opeartions);
    free(results);
    return 0;
}
