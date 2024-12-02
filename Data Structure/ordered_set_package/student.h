#include <set>
#include <vector>
using namespace std;

template <typename T> vector<T> Union(const vector<T> &A, const vector<T> &B) {
    vector<T> v;
    set<T> x;

    for (auto &a : A) {
        v.push_back(a);
        x.insert(a);
    }

    for (auto &b : B) {
        if (x.find(b) == x.end()) {
            v.push_back(b);
        }
    }

    return v;
}

template <typename T>
vector<T> Intersect(const vector<T> &A, const vector<T> &B) {
    vector<T> v;
    set<T> y;

    for (auto &a : B) {
        y.insert(a);
    }

    for (auto &b : A) {
        if (y.find(b) != y.end()) {
            v.push_back(b);
        }
    }

    return v;
}
