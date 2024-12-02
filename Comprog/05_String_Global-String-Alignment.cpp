#include <iostream>
using namespace std;

int matches(string X, int sx, string Y, int sy) {
    int c = 0;
    while (sx < X.length() &&
        sy < Y.length()) { // หาว่าตรงกันกี่ตัวตั้งแต่ sx และ sy คืน c
        if (X[sx++] == Y[sy++]) {
            ++c;
        }
    }
    return c;
}

int max_align(string X, string Y) {
    int mx = 0, shift_y = 0;
    for (int sy = 0; sy < Y.length(); ++sy) {
        int n = matches(X, 0, Y, sy);
        if (n > mx) {
            mx = n;
            shift_y = sy;
        }
    }
    return shift_y;
}

int main() {
    string X, Y;
    cin >> X >> Y;
    int sy = max_align(X, Y);
    int sx = max_align(Y, X);
    int max1 = matches(X, 0, Y, sy);
    int max2 = matches(Y, 0, X, sx);

    if (max2 > max1) { // ใช้ sx
        cout << X << endl;
        cout << string(sx, '-') << Y << endl;
        cout << max2 << endl;
    }
    else { // ใช้ sy
        cout << string(sy, '-') << X << endl;
        cout << Y << endl;
        cout << max1 << endl;
    }
}
