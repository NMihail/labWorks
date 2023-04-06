//
// Created by Worker on 05.04.2023.
//

#include "vector.h"

Vector createVector(size_t n) {
    size_t size = n == 0 ? 1 : n;

    int *data = (int *)malloc(size * sizeof(int));

    if (data == NULL) {
        fprintf(stderr, "bad alloc");

        exit(1);
    }

    return (Vector) {
        data,
        0,
        size
    };
}

void reserve(Vector *v, size_t newCapacity) {
    size_t size = newCapacity == 0 ? 1 : newCapacity;

    int *data = (int *)realloc(v->data, size);

    if (data == NULL) {
        fprintf(stderr, "bad alloc");

        exit(1);
    }

    v->data = newCapacity ? data : v->data;

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

bool isEmpty(Vector *v) {
    return v->size == 0;
}

bool isFull(Vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(Vector *v, size_t i) {
    return v->data[i];
}

void pushBack(Vector *v, int x) {
    if (v->size == v->capacity) {
        reserve(v, v->capacity*2);
    }

    v->data[v->size++] = x;
}

void popBack(Vector *v) {
    v->size--;
}