#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, ans, mod = 100000007;
    cin >> n;

    int a = 1, b = 3, c = 7;
    for (int i = 2; i < n; i++) {
        ans = ((2 * c) + a) % mod;
        a = b % mod;
        b = c % mod;
        c = ans;
    }

    cout << ans;
}
