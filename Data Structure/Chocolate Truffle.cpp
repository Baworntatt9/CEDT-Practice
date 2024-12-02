#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long r, c, k;
    cin >> r >> c >> k;

    vector<long long> target;

    for (int i = 0; i < k; i++) {
        long long t1, t2;
        cin >> t1 >> t2;
        target.push_back(t1 + t2 - 1 + (c - 1) * (t1 - 1));
    }

    long long Q;
    cin >> Q;
    sort(target.begin(), target.end());

    while (Q--) {
        long long s1, s2;
        cin >> s1 >> s2;

        long long s3 = s1 + s2 - 1 + (c - 1) * (s1 - 1);
        auto itr = lower_bound(target.begin(), target.end(), s3);

        long long gg = (*itr) - s3;
        if (gg < 0) {
            long long ggg = r * c - s3 + target[0];
            cout << ggg << endl;
        }
        else {
            cout << gg << endl;
        }
    }
}
