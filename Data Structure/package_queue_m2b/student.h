#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T> void CP::queue<T>::move_to_back(size_t pos) {
    size_t idxStart = (mFront + pos) % mCap;
    T target = mData[idxStart];

    // เลื่อนข้อมูลจากตำแหน่ง `pos` ไปยังท้ายสุด
    for (size_t i = pos; i < mSize - 1; ++i) {
        size_t idxCurrent = (mFront + i) % mCap;
        size_t idxNext = (mFront + i + 1) % mCap;
        mData[idxCurrent] = mData[idxNext];
    }

    // วางค่าของ target ที่ตำแหน่งท้ายคิว
    size_t idxEnd = (mFront + mSize - 1) % mCap;
    mData[idxEnd] = target;
}

#endif