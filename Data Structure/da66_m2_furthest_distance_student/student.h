#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

using namespace std;

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, int &aux) {
    if (n == NULL)
        return 0;
    int l = my_recur(n->left, aux);
    int r = my_recur(n->right, aux);

    int curr = l + r + 1;
    aux = max(aux, curr);
    return max(l, r) + 1;
}

template <typename KeyT, typename MappedT, typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance() {
    int aux = 0;
    my_recur(mRoot, aux);
    return aux - 1;
}

#endif
