template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last) {
    size_t pos = position - begin();
    size_t insertCount = last - first;

    ensureCapacity(mSize + insertCount);

    for (size_t i = mSize + insertCount - 1; i >= pos + insertCount; --i) {
        mData[i] = mData[i - insertCount];
    }

    for (size_t i = 0; i < insertCount; ++i) {
        mData[pos + i] = *(first + i);
    }

    mSize += insertCount;
}