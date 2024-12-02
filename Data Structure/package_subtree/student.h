#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "map_bst.h"
#include <algorithm>
#include <vector>

template <typename KeyT, typename MappedT, typename CompareT>
size_t CP::map_bst<KeyT, MappedT, CompareT>::process(node *n) {
    if (!n) {
        return 0;
    }
    return process(n->left) + process(n->right) + 1;
}

template <typename KeyT, typename MappedT, typename CompareT>
std::pair<KeyT, MappedT> CP::map_bst<KeyT, MappedT, CompareT>::subtree(
    map_bst<KeyT, MappedT, CompareT> &left,
    map_bst<KeyT, MappedT, CompareT> &right) {
    // write your code here
    if (empty())
        return std::pair<KeyT, MappedT>();

    delete_all_nodes(left.mRoot); // เคลียของเดิมก่อน
    delete_all_nodes(right.mRoot);

    left.mRoot = mRoot->left;
    right.mRoot = mRoot->right;

    left.mSize = process(mRoot->left);
    right.mSize = mSize - 1 - left.mSize;
    mSize = 1;

    mRoot->left = NULL;
    mRoot->right = NULL;

    return mRoot->data;
}

#endif
