#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "priority_queue.h"
#include <algorithm>
#include <vector>

template <typename T, typename Comp>
T CP::priority_queue<T, Comp>::get_kth(size_t k) const {
    if (k == 2) {
        return (mLess(mData[1], mData[2])) ? mData[2] : mData[1];
    } else if (k == 3) {
        T temp = (mLess(mData[1], mData[2])) ? mData[1] : mData[2];
        temp = (mLess(temp, mData[3])) ? mData[3] : temp;
        temp = (mLess(temp, mData[4])) ? mData[4] : temp;
        temp = (mLess(temp, mData[5])) ? mData[5] : temp;
        return (mLess(temp, mData[6])) ? mData[6] : temp;
    } else {
        return mData[0];
    }
}

#endif
