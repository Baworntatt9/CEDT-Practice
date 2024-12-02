#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, a;
    cin >> n >> k;

    vector<int> data;
    while (n--) {
        cin >> a;
        data.push_back(a);
    }

    while (k--) {
        cin >> a;
        int lhs = 0, rhs = data.size();
        while (lhs < rhs) {
            int m = (lhs + rhs) / 2;
            if (data[m] <= a) {
                lhs = m + 1;
            }
            else {
                rhs = m;
            }
        }
        cout << lhs - 1 << "\n";
    }
}
