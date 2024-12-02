#include <iostream>
using namespace std;

bool isDovic2(string g) {
    int c1 = 0, c2 = 0;
    for (int i = 0; i < g.size() / 2; i++) {
        if (g[i] == '1')
            c1++;
    }
    for (int i = g.size() / 2; i < g.size(); i++) {
        if (g[i] == '1')
            c2++;
    }

    string g1 = "", g2 = "";
    if (abs(c2 - c1) < 2) {
        if (g.size() == 4) {
            return true;
        }
        g1 = g.substr(0, g.size() / 2);
        g2 = g.substr(g.size() / 2);
    }
    else {
        return false;
    }

    return (isDovic2(g1) && isDovic2(g2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string g = "";
        for (int j = 0; j < 1 << k; j++) {
            char a;
            cin >> a;
            g += a;
        }
        if (k == 1) {
            cout << "yes" << endl;
            continue;
        }
        if (isDovic2(g))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
