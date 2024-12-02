#include <iostream>
using namespace std;

bool isDOVIC(string x, int k) {
    if (k == 1) {
        return (x[0] == '0' && x[1] == '1');
    }

    string a = x.substr(0, 1 << k - 1), b = x.substr(1 << k - 1), c = a;
    reverse(c.begin(), c.end());
    return (isDOVIC(a, k - 1) || isDOVIC(c, k - 1)) && isDOVIC(b, k - 1);
}

int main() {
    int q, n;
    cin >> q >> n;

    for (int i = 0; i < q; i++) {
        string x = "";
        for (int j = 0; j < 1 << n; j++) {
            char z;
            cin >> z;
            x += z;
        }
        cout << (isDOVIC(x, n) ? "yes\n" : "no\n");
    }
}
