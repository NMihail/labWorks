//
// Created by Worker on 07.04.2023.
//

#include "testVectors.h"

void test_pushBack_emptyVector() {
    Vector v = createVector(0);

    pushBack(&v, 0);
    pushBack(&v, 1);
    pushBack(&v, 2);

    assert(v.data[0] == 0);
    assert(v.data[1] == 1);
    assert(v.data[2] == 2);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    Vector v = createVector(5);

    pushBack(&v, 0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);
    pushBack(&v, 5);

    assert(v.capacity == 5*2);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    Vector v = createVector(0);

    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);

    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    Vector v = createVector(4);

    pushBack(&v, 1);
    pushBack(&v, 5);
    pushBack(&v, 2);

    int *secondElement = atVector(v, 1);

    assert(*secondElement == v.data[1]);

    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    Vector v = createVector(3);

    pushBack(&v, 1);
    pushBack(&v, 5);
    pushBack(&v, 2);

    int *lastElement = atVector(v, v.size - 1);

    assert(*lastElement == v.data[v.size - 1]);

    deleteVector(&v);
}

void test_back_oneElementInVector() {
    Vector v = createVector(3);

    pushBack(&v, 1);

    int *lastElement = back(v);

    assert(*lastElement == v.data[v.size - 1]);

    deleteVector(&v);
}

void test_front_oneElementInVector() {
    Vector v = createVector(3);

    pushBack(&v, 1);

    int *firstElement = front(v);

    assert(*firstElement == v.data[v.size - 1]);

    deleteVector(&v);
}

void test_pushBackVoid_and_setVectorValueVoid_and_getVectorValueVoid() {
    VectorVoid vInt = createVectorVoid(0, sizeof(int));
    VectorVoid vFloat = createVectorVoid(0, sizeof(float));

    int a = 2;
    float b = (float)4.23;

    pushBackVoid(&vInt, &a);
    pushBackVoid(&vFloat, &b);

    int vIntFirst;
    getVectorValueVoid(&vInt, 0, &vIntFirst);

    float vFloatFirst;
    getVectorValueVoid(&vFloat, 0, &vFloatFirst);

    assert(vIntFirst == a);
    assert(vFloatFirst - b < EPS_FLOAT);

    b = (float)3.11;

    setVectorValueVoid(&vFloat, 0, &b);

    getVectorValueVoid(&vFloat, 0, &vFloatFirst);

    assert(vFloatFirst - b < EPS_FLOAT);

    deleteVectorVoid(&vInt);
    deleteVectorVoid(&vFloat);
}

void tests_vector() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
    test_pushBackVoid_and_setVectorValueVoid_and_getVectorValueVoid();
}