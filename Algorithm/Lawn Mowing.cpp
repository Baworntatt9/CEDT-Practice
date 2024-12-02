#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v(n + 1, 0);
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i - 1] + k;
    }

    while (m--) {
        ll a, b;
        cin >> a >> b;
        auto itr = upper_bound(v.begin(), v.end(), v[a] + b);

        if (itr == v.begin() + 1) {
            cout << 0 << "\n";
            continue;
        }
        itr--;

        cout << *itr - v[a] - ((itr - v.begin() - a) * k) << "\n";
    }
}
