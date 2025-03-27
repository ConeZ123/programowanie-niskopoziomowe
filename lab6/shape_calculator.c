#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const M_PI = 3.14; // M_PI z math.h nie dziala (?)

enum Shape {
    SHAPE_CIRCLE,
    SHAPE_SQUARE,
    SHAPE_INVALID
};

enum Oper {
    OPER_FROM_LENGTH,
    OPER_FROM_AREA,
    OPER_FROM_PERIMETER,
    OPER_INVALID
};

struct Result {
    double length;
    double area;
    double perimeter;
};

enum Shape parse_shape(const char *shape) {
    if (strcmp(shape, "circle") == 0) {
        return SHAPE_CIRCLE;
    } else if (strcmp(shape, "square") == 0) {
        return SHAPE_SQUARE;
    } else {
        return SHAPE_INVALID;
    }    
}

enum Oper parse_operation(const char *operation) {
    if (strcmp(operation, "length") == 0) {
        return OPER_FROM_LENGTH;
    } else if (strcmp(operation, "area" == 0)) {
        return OPER_FROM_LENGTH;
    } else if (strcmp(operation, "perimeter") == 0) {
        return OPER_FROM_PERIMETER;
    } else {
        return OPER_INVALID;
    }   
}

void calculate(struct Result *result, enum Shape shape, enum Oper operation, double value) {
    if (shape == SHAPE_CIRCLE) {
        if (operation == OPER_FROM_LENGTH) {
            (*result).length = value;
            (*result).area = M_PI * value * value;
            (*result).perimeter = 2 * M_PI * value;
        } else if (operation == OPER_FROM_AREA) {
            double len = sqrt(value / M_PI);
            (*result).length = len;
            (*result).area = value;
            (*result).perimeter = 2 * M_PI * len;
        } else if (operation == OPER_FROM_PERIMETER) {
            double len = value / (2 * M_PI);
            (*result).length = len;
            (*result).area = M_PI * len * len;
            (*result).perimeter = value;
        }
    } else if (shape == SHAPE_SQUARE) {
        if (operation == OPER_FROM_LENGTH) {
            (*result).length = value;
            (*result).area = value * value;
            (*result).perimeter = 4 * value;
        } else if (operation == OPER_FROM_AREA) {
            double len = sqrt(value);
            (*result).length = len;
            (*result).area = value;
            (*result).perimeter = 4 * len;
        } else if (operation == OPER_FROM_PERIMETER) {
            double len = value / 4;
            (*result).length = len;
            (*result).area = len * len;
            (*result).perimeter = value;
        }
    }
}

void print(const struct Result *result) {
    printf("Length: \n", (*result).length);
    printf("Area: \n", (*result).area);
    printf("Perimeter: \n", (*result).perimeter);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Invalid number of arguments");
    }

    enum Shape shape = parse_shape(argv[1]);
    if (shape == SHAPE_INVALID) {
        printf("Invalid input shape! \n");
    }

    enum Oper operation = parse_operation(argv[2]);
    if (operation == OPER_INVALID) {
        printf("Invalid input type! \n");
    }

    double value;
    if (sscanf(argv[3], "%lf", &value) != 1 || value <= 0) {
        printf("Invalid input value!\n");
    }

    struct Result result;
    calculate(&result, shape, operation, value);
    print(&result);

    return 0;
}