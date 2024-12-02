#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T> void CP::queue<T>::reverse(int a, int b) {
    for (int i = 0; i <= (b - a) / 2; i++) {
        int idx1 = (mFront + a + i) % mCap;
        int idx2 = (mFront + b - i) % mCap;
        std::swap(mData[idx1], mData[idx2]);
    }
}

#endif
