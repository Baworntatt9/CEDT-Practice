#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <unordered_set>

template <typename T> void CP::vector<T>::uniq() {
    std::unordered_set<T> s;
    int j = 0;

    for (int i = 0; i < mSize; i++) {
        if (s.insert(mData[i]).second) {
            mData[j++] = mData[i];
        }
    }

    mSize = j;
}

#endif
