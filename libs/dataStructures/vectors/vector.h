//
// Created by Worker on 05.04.2023.
//

#ifndef VECTORS_VECTOR_H
#define VECTORS_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Vector {
    int *data;    // указатель на массив целых
    size_t size;     // Текущий размер массива
    size_t capacity; // Номинальный размер массива
} Vector;

Vector createVector(size_t n);

void reserve(Vector *v, size_t newCapacity);

void clear(Vector *v);

void shrinkToFit(Vector *v);

void deleteVector(Vector *v);

bool isEmpty(Vector *v);

bool isFull(Vector *v);

int getVectorValue(Vector *v, size_t i);

void pushBack(Vector *v, int x);

void popBack(Vector *v);

#endif //VECTORS_VECTOR_H
