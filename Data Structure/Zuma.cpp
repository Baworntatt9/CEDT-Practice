#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> beads;

    int n, k, v, a;
    cin >> n >> k >> v;

    while (n--) {
        cin >> a;
        beads.push_back(a);
    }

    auto itr = beads.insert(next(beads.begin(), k), v);
    auto itr2 = itr;
    bool first = true;

    while (!beads.empty()) {
        size_t left = 0, right = 0;

        while ((*itr) == (*++itr)) { // count same right
            ++right;
        }

        while ((*itr2) == (*--itr2)) { // count same left
            ++left;
        }

        ++itr2;

        int range = left + right + 1;
        // ถ้ารอบแรกจะบึ้มเสมอรอบต่อไปต้องชนกันสองด้านถึงจะบึ้ม
        if (range >= 3 && (first || left >= 1)) {
            while (range--) {
                itr2 = beads.erase(itr2);
            }
        }
        else {
            break;
        }

        first = false;
    }

    for (auto& x : beads) {
        cout << x << ' ';
    }
}
