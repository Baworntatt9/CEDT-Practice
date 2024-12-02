#include <iomanip>
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

    for (int i = 0; i < a; i++) { // ทำจากล่างขึ้นบน
        double x = arr[i];

        for (int j = i - 1; j >= 0; j--) {
            x = arr[j] + 1 / x;
        }

        cout << setprecision(10) << x << endl;
    }
}
