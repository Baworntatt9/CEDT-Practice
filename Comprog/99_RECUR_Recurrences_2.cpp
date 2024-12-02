#include <cmath>
#include <iostream>
#include <map>
using namespace std;

int F(int n) { // Fibonacci number
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        int fn = F((n / 2) - 1);
        int fn_1 = F(n / 2);
        return (2 * fn + fn_1) * fn_1;
    }
    else {
        int fn = F((n + 1) / 2);
        int fn_1 = F(((n + 1) / 2) - 1);
        return (fn * fn) + (fn_1 * fn_1);
    }
}

int M(int n) { // Motzkin number
    if (n == 0 || n == 1) {
        return 1;
    }
    int g = 0;
    for (int i = 0; i <= n - 2; i++) {
        int fn = M(i);
        int fn_1 = M(n - 2 - i);
        g += fn * fn_1;
    }

    return M(n - 1) + g;
}

int S(int n) { // Schroder–Hipparchus Number
    if (n == 1 || n == 2) {
        return 1;
    }
    int fn = S(n - 1);
    int fn_1 = S(n - 2);
    if (n >= 3) {
        return (((6 * n - 9) * fn) - ((n - 3) * fn_1)) / n;
    }
}

int D(int n) { // Derangement
    if (n == 0) {
        return 1;
    }
    return n * D(n - 1) + pow(-1, n);
}

int main() {
    map<string, int (*)(int)> func = { {"F", F}, {"M", M}, {"S", S}, {"D", D} };
    string fn;
    int p;
    while (cin >> fn >> p) {
        if (func.find(fn) != func.end())
            cout << fn << '(' << p << ") = " << func[fn](p) << endl;
    }
    return 0;
}
