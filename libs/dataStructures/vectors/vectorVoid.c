//
// Created by Worker on 07.04.2023.
//

#include "vectorVoid.h"

void badAlloc() {
    fprintf(stderr, "bad alloc");

    exit(1);
}

VectorVoid createVectorVoid(size_t n, size_t baseTypeSize) {
    if (!n) {
        return (VectorVoid) {
                NULL,
                0,
                0,
                baseTypeSize
        };
    }

    void *data = malloc(n * baseTypeSize);

    if (data == NULL) {
        badAlloc();
    }

    return (VectorVoid) {
            data,
            0,
            n,
            baseTypeSize
    };
}

void reserveVoid(VectorVoid *v, size_t newCapacity) {
    if (!newCapacity) {
        *v = createVectorVoid(0, v->baseTypeSize);

        return;
    }

    void *data = realloc(v->data, newCapacity*v->baseTypeSize);

    if (data == NULL) {
        badAlloc();
    }

    v->data = data;

    v->size = newCapacity < v->size ? newCapacity : v->size;

    v->capacity = newCapacity;
}

void clearVoid(VectorVoid *v) {
    v->size = 0;
}

void shrinkToFitVoid(VectorVoid *v) {
    reserveVoid(v, v->size*v->baseTypeSize);
}

void deleteVectorVoid(VectorVoid *v) {
    free(v->data);

    v->size = 0;

    v->capacity = 0;

    v->baseTypeSize = 0;
}