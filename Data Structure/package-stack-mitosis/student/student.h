#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T> void CP::stack<T>::mitosis(int a, int b) {
    T arr[b + 1];
    for (int i = b; i >= 0; i--) {
        arr[i] = top();
        pop();
    }
    for (int i = 0; i <= b; i++) {
        push(arr[i]);
        if (i < b - a + 1)
            push(arr[i]);
    }
}

#endif