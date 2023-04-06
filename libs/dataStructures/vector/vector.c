//
// Created by Worker on 05.04.2023.
//

#include "vector.h"

Vector createVector(size_t n) {
    int *data = (int *)malloc(n*sizeof(int));

    if (data == NULL) {
        fprintf(stderr, "bad alloc");

        exit(1);
    }

    return (Vector) {
            n ? data : NULL,
            0,
            n
    };
}

void reserve(Vector *v, size_t newCapacity) {
    int *data = (int *)realloc(v->data, newCapacity);

    if (data == NULL) {
        fprintf(stderr, "bad alloc");

        exit(1);
    }

    v->data = newCapacity ? data : NULL;

    v->size = newCapacity < v->size ? newCapacity : v->size;

    v->capacity = newCapacity;
}

void clear(Vector *v) {
    v->size = 0;
}

void shrinkToFit(Vector *v) {
    reserve(v, v->size);
}

void deleteVector(Vector *v) {
    free(v->data);

    v->size = 0;

    v->capacity = 0;
}