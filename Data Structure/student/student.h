#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
#include <algorithm>
#include <vector>

template <typename T> void CP::queue<T>::remove_many(std::vector<size_t> pos) {
    T *newData = new T[mCap];
    std::sort(pos.begin(), pos.end());

    int j = 0, k = 0;
    for (int i = 0; i < mSize; i++) {
        if (pos[j] == i) {
            j++;
        } else {
            newData[k] = mData[(mFront + i) % mCap];
            k++;
        }
    }

    delete[] mData;
    mData = newData;
    mSize = mSize - pos.size();
    mFront = 0;
}

#endif
