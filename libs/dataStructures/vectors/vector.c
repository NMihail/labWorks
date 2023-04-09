//
// Created by Worker on 05.04.2023.
//

#include "vector.h"

void badAlloc() {
    fprintf(stderr, "bad alloc");

    exit(1);
}

Vector createVector(size_t n) {
    if (!n) {
        return (Vector) {
            NULL,
            0,
            0
        };
    }

    int *data = (int *) malloc(n* sizeof(int));

    if (data == NULL) {
        badAlloc();
    }

    return (Vector) {
        data,
        0,
        n
    };
}

void reserve(Vector *v, size_t newCapacity) {
    if (!newCapacity) {
        *v = createVector(0);

        return;
    }

    int *data = (int *)realloc(v->data, newCapacity* sizeof(int));

    if (data == NULL) {
        badAlloc();
    }

    v->data = data;

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
    if (!v->capacity) {
        reserve(v, 1);
    }

    if (v->size == v->capacity) {
        reserve(v, v->capacity*2);
    }

    v->data[v->size++] = x;
}

void popBack(Vector *v) {
    v->size--;
}

int* atVector(Vector v, size_t index) {
    if (index > v.size) {
        fprintf(stderr, "\"IndexError: a[%zu] is not exists\"", index);

        exit(1);
    }

    return &v.data[index];
}

int* back(Vector v) {
    assert(v.size);

    return &v.data[v.size - 1];
}

int* front(Vector v) {
    assert(v.size);

    return &v.data[0];
}