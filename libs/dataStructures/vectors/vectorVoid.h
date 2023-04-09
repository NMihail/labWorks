//
// Created by Worker on 07.04.2023.
//

#ifndef VECTORS_VECTORVOID_H
#define VECTORS_VECTORVOID_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <assert.h>

typedef struct vectorVoid {
    void *data;          // указатель на нулевой элемент вектора
    size_t size;         // размер вектора
    size_t capacity;     // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
                         // например, если вектор хранит int -
                         // то поле baseTypeSize = sizeof(int)
                         // если вектор хранит float -
                         // то поле baseTypeSize = sizeof(float)
} VectorVoid;

VectorVoid createVectorVoid(size_t n, size_t baseTypeSize);

void reserveVoid(VectorVoid *v, size_t newCapacity);

void clearVoid(VectorVoid *v);

void shrinkToFitVoid(VectorVoid *v);

void deleteVectorVoid(VectorVoid *v);

#endif //VECTORS_VECTORVOID_H
