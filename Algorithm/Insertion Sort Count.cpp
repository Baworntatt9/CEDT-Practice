#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, a;
    cin >> n >> k;

    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    for (int i = 0; i < k; i++) {
        cin >> a;
        int result = 0;
        int idx = 0;
        while (true) {
            if (data[idx] == a) {
                break;
            }
            if (data[idx] > a) {
                result++;
            }
            idx++;
        }
        cout << result << "\n";
    }
}
