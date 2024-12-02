#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
    int shift = 0;
    for (int i = 0; i < pos.size(); i++) {
        int index = pos[i] - shift;
        erase(begin() + index);
        shift++;
    }
}

#endif
