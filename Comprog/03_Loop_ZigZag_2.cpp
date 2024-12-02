#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int mn1 = x, mx1 = y;
    int mn2 = y, mx2 = x;

    for (int i = 1;; i++) {
        cin >> x;

        if (x == -998 || x == -999) {
            break;
        }

        cin >> y;

        if (i % 2 == 1) {
            mx1 = max(x, mx1);
            mn1 = min(y, mn1);

            mx2 = max(y, mx2);
            mn2 = min(x, mn2);
        }
        else {
            mx1 = max(y, mx1);
            mn1 = min(x, mn1);

            mx2 = max(x, mx2);
            mn2 = min(y, mn2);
        }
    }

    if (x == -998) {
        cout << mn1 << " " << mx1 << endl;
    }
    else {
        cout << mn2 << " " << mx2 << endl;
    }
}
