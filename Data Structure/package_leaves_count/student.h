#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

// you can modify and use this function
template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::leaves_count(node *n) {
    if (n->left == NULL && n->right == NULL) {
        return 1;
    }
    size_t a = 0;

    if (n->left != NULL) {
        a += leaves_count(n->left);
    }
    if (n->right != NULL) {
        a += leaves_count(n->right);
    }
    return a;
}

template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::leaves_count() {
    return leaves_count(mRoot);
    // write your code here
}

#endif
