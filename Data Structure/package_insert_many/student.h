#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data) {
    int oldSize = mSize;
    T *arr = new T[(mSize + 1) * 2]();
    for (size_t i = 0; i < mSize; i++) {
        arr[2 * i + 1] = mData[i];
    }

    for (const auto &pair : data) {
        arr[2 * pair.first] = pair.second;
    }
    mData = arr;

    mSize = 0;
    for (size_t i = 0; i < (oldSize + 1) * 2; i++) {
        if (arr[i] != T()) {
            mData[mSize] = arr[i];
            mSize++;
        }
    }
}

#endif
