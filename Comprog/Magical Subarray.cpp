#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;

    int arr[a];

    for (int i = 0; i < a; i++) {
        int b;
        cin >> b;
        arr[i] = b;
    }

    int count = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = 0; j <= a - i; j++) {
            bool magic = true;
            bool found[i + 1];
            for (int t = 0; t < i + 1; t++) {
                found[t] = false;
            }
            for (int k = j; k <= i + j - 1; k++) {
                if (arr[k] < 1 || arr[k] > i || found[arr[k]] == true) {
                    magic = false;
                    break;
                }
                found[arr[k]] = true;
            }

            if (magic == true) {
                count++;
            }
        }
    }

    cout << count;
}
