#include <iostream>
using namespace std;

int main() {
    int a;

    cin >> a;

    int arr[a];

    for (int i = 0; i < a; i++) {
        int get;
        cin >> get;
        arr[i] = get;
    }

    int arrs[a - 2];

    for (int i = 1; i < a - 1; i++) {
        int maxl = arr[0];
        for (int j = 0; j < i; j++) {
            if (arr[j] > maxl) {
                maxl = arr[j];
            }
        }
        int maxr = arr[i + 1];
        for (int j = i + 1; j < a; j++) {
            if (arr[j] > maxr) {
                maxr = arr[j];
            }
        }

        arrs[i - 1] = min(maxl, maxr);
    }

    int sum = 0;

    for (int i = 0; i < a - 2; i++) {
        if (arrs[i] - arr[i + 1] < 0) {
            arrs[i] = 0;
        }
        else {
            arrs[i] = arrs[i] - arr[i + 1];
        }
    }

    for (int i = 0; i < a - 2; i++) {
        sum += arrs[i];
    }

    cout << sum;
}
