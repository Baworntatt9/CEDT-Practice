#include <iostream>
using namespace std;

int main() {
    int a;

    cin >> a; // จน แถว = a

    int arr[a][a];

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            int re;
            cin >> re;
            arr[i][j] = re;
        }
    }

    int zero; // แถวที่ 0 ยุ เริ่มที่ 0
    int arrst[a * a - 1];

    int cc = 0;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (arr[i][j] == 0) {
                zero = i;
            }
            else {
                arrst[cc] = arr[i][j];

                cc += 1;
            }
        }
    }

    int m = a * a - 1;
    int inver = 0;

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (arrst[i] > arrst[j]) {
                inver += 1;
            }
        }
    }

    if (a % 2 != 0) {
        if (inver % 2 == 0) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    else if (a % 2 == 0) {
        if (inver % 2 != 0) {
            if (zero % 2 == 0) {
                cout << "YES";
            }
            else {
                cout << "NO";
            }
        }
        else if (inver % 2 == 0) {
            if (zero % 2 != 0) {
                cout << "YES";
            }
            else {
                cout << "NO";
            }
        }
    }
}
