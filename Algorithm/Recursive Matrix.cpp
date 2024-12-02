#include <iostream>
using namespace std;

int fa, fb;

void matr(int a, int b, int sum, int n) {
    if (n == 1) {
        cout << sum << " ";
        return;
    }
    n = n / 2;
    fa = floor(a / n);
    fb = floor(b / n);
    matr(a - fa * n, b - fb * n, sum + fa - fb, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, p;
    cin >> n >> s;
    p = pow(2, n);
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            matr(i, j, s, p);
        }
        cout << endl;
    }
}
