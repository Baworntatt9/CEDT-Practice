#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
    size_t minA = a - begin();
    size_t maxA = minA + m - 1;
    size_t minB = b - begin();
    size_t maxB = minB + m - 1;

    if (a < begin() || b < begin()) {
        return false;
    }
    if (m > 0 && maxA < mSize && maxB < mSize && (minB > maxA || minA > maxB)) {
        for (size_t i = 0; i < m; i++) {
            std::swap(mData[minA + i], mData[minB + i]);
        }
        return true;
    }
    return false;
}

#endif
