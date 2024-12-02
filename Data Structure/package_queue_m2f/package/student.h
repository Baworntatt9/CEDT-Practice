#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T> void CP::queue<T>::move_to_front(size_t pos) {
    int idx = (mFront + pos) % mCap;
    T element = mData[idx];

    for (int i = idx; i != mFront;) {
        int preIdx = (i - 1 + mCap) % mCap; // index ตัวก่อนหน้า
        mData[i] = mData[preIdx];
        i = preIdx;
    }
    mData[mFront] = element;
}

#endif
