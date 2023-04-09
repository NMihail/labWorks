//
// Created by Worker on 07.04.2023.
//

#include "vectorVoid.h"

void badAllocVoid() {
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
        badAllocVoid();
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
        badAllocVoid();
    }

    v->data = data;

    v->size = newCapacity < v->size ? newCapacity : v->size;

    v->capacity = newCapacity;
}

void clearVoid(VectorVoid *v) {
    v->size = 0;
}

void shrinkToFitVoid(VectorVoid *v) {
    reserveVoid(v, v->size);
}

void deleteVectorVoid(VectorVoid *v) {
    free(v->data);
}

bool isEmptyVoid(VectorVoid *v) {
    return !v->size;
}

bool isFullVoid(VectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueVoid(VectorVoid *v, size_t index, void *destination) {
    if (index >= v->size) {
        fprintf(stderr, "\"IndexError: a[%zu] is not exists\"", index);

        exit(1);
    }

    char *source = (char *)(v->data) + index*v->baseTypeSize;

    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueVoid(VectorVoid *v, size_t index, void *source) {
    v->size++;

    if (index >= v->size) {
        v->size--;

        fprintf(stderr, "\"IndexError: a[%zu] is not exists\"", index);

        exit(1);
    }

    char *dst = (char *)(v->data) + index*v->baseTypeSize;

    memcpy(dst, source, v->baseTypeSize);
}

void popBackVoid(VectorVoid *v) {
    assert(v->size > 0);

    v->size--;
}

void pushBackVoid(VectorVoid *v, void *source) {
    if (!v->capacity) {
        reserveVoid(v, 1);
    }

    if (v->size == v->capacity) {
        reserveVoid(v, v->capacity*2);
    }

    setVectorValueVoid(v, v->size, source);

    v->size++;
}