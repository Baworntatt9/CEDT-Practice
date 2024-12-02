#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT, typename MappedT, typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT>
CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val) {
    CP::map_bst<KeyT, MappedT, CompareT> result;
    node *n = mRoot, *tmp, *rightRoot;

    while (n != NULL) {
        if (mLess(n->data.first, val)) {
            n = n->right;
        } else {
            tmp = n->left;

            if (n == mRoot) {
                mRoot = tmp;
                if (n->left != NULL) {
                    n->left = NULL;
                    tmp->parent = NULL;
                }
            } else {
                child_link(n->parent, n->data.first) = tmp;
                if (n->left != NULL) {
                    tmp->parent = n->parent;
                    n->left = NULL;
                }
            }

            if (result.mRoot == NULL) {
                result.mRoot = n;
                n->parent = NULL;
            } else {
                n->parent = tmp;
                rightRoot->left = n;
            }

            rightRoot = n;
            n = tmp;
        }
    }

    return result;
}

#endif
