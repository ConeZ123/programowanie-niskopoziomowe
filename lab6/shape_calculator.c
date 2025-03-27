#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
void calculate(struct Result *result, enum Shape shape, enum Oper operation, double value);
void print(const struct Result *result);