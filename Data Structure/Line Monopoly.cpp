#include <iostream>
using namespace std;

bool arr[20000000] = { 0 };

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, now = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            long long j = 0, k = 0;
            cin >> j >> k;

            while (j <= k) {
                if (!arr[j] && !arr[j - 1] && !arr[j + 1]) {
                    now++;
                }
                if (!arr[j] && arr[j - 1] && arr[j + 1]) {
                    now--;
                }

                arr[j] = 1;
                j++;
            }

        }
        else {
            cout << now << "\n";
        }
    }
}
