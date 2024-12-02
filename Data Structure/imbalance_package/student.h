int MAX = 0;
KeyT i;
int diff(node *n) {
    if (n == NULL)
        return 0;
    int left = diff(n->left);
    int right = diff(n->right);
    if (MAX < std::abs(left - right) ||
        MAX == std::abs(left - right) && mLess(n->data.first, i)) {
        MAX = std::abs(left - right);
        i = n->data.first;
    }
    return std::max(left, right) + 1;
}
KeyT getValueOfMostImbalanceNode() {
    diff(mRoot);
    return i;
}
