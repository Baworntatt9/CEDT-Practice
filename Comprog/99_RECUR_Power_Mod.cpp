#include <iostream>
using namespace std;

long long powerMod(long long a, long long k, long long m) {
    if (k == 0) {
        return 1;
    }
    long long half = powerMod(a, k / 2, m);
    half = (half * half) % m;
    if (k % 2 != 0) {
        half = (half * a) % m;
    }

    return half;
}

int main() {
    long long a, k, m;
    cin >> a >> k >> m;

    cout << powerMod(a, k, m);
}
