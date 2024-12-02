#include <iostream>
using namespace std;

int main() {
    int n, c0 = 1, c1 = 2, m = 100000007;
    cin >> n;
    while (n--) {
        c1 = (2 * c0 + c1) % m;
        c0 = (c1 - c0 + m) % m;
    }
    cout << c0;
}
