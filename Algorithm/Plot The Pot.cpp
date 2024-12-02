#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long recur(long long n) {
    if (n == 1)
        return 1;
    else if (n == 2)
        return 3;

    long long prev1 = 1;
    long long prev2 = 3;
    long long cur = 0;

    for (int i = 3; i <= n; i++) {
        cur = (prev2 + prev1 * 2) % MOD;
        prev1 = prev2;
        prev2 = cur;
    }

    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long n;
    cin >> n;
    cout << recur(n);
}
