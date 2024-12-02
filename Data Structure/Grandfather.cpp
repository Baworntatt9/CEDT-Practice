#include <iostream>
#include <map>
using namespace std;

long long findGrand(long long x, map<long long, long long>& y) {
    if (y.find(x) == y.end()) {
        return -1;
    }
    long long parent = y[x];
    if (y.find(parent) == y.end()) {
        return -1;
    }
    long long grand = y[parent];

    return grand;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    map<long long, long long> a;
    for (int i = 0; i < n; i++) {
        long long f, s;
        cin >> f >> s;
        a[s] = f;
    }

    for (int i = 0; i < m; i++) {
        long long A, B;
        cin >> A >> B;

        if (A == B) {
            cout << "NO" << '\n';
            continue;
        }

        long long X = findGrand(A, a);
        long long Y = findGrand(B, a);
        if (X != -1 && Y != -1 && X == Y) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}
