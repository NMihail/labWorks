#include <assert.h>

#include "libs/dataStructures/vectors/vector.h"

void test_pushBack_emptyVector() {
    Vector v = createVector(5);

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


void tests_vector() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {
    tests_vector();

    return 0;
}
