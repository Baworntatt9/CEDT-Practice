#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, a;
    cin >> n;

    int arr[1000] = { 0 };

    int max = 0;
    for (int i = 0; i < n; i++) {
        int g = 0;
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (a == 1)
                g++;
        }
        arr[g]++;
        if (g > max) {
            max = g;
        }
    }

    for (int i = 0; i <= max; i++) {
        cout << arr[i] << " ";
    }
}
