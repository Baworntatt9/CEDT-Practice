#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T> void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
    // write your code here

    auto it = ls.begin();
    for (int i = 0; i < ls.size(); i++) {
        mSize += (*it).size();

        if ((*it).size() > 0) {
            (*it).begin().ptr->prev = mHeader->prev;
            mHeader->prev->next = (*it).begin().ptr;

            auto last = (*it).end();
            last--;

            mHeader->prev = last.ptr;
            last.ptr->next = mHeader;

            (*it).end().ptr->prev = (*it).end().ptr;
            (*it).end().ptr->next = (*it).end().ptr;
        }
        (*it).mSize = 0;
        it++;
    }
}

#endif
