#ifndef __STUDENT_H__
#define __STUDENT_H__

template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::process(node *ptr) const {
    if (ptr == NULL)
        return 0;

    size_t count = ((ptr->left == NULL) != (ptr->right == NULL)) ? 1 : 0;

    count += process(ptr->left);
    count += process(ptr->right);

    return count;
}

template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::count_unary() const {
    // write your code here
    if (mRoot->left == NULL && mRoot->right == NULL) {
        return 0;
    }

    return process(mRoot);
}

#endif
