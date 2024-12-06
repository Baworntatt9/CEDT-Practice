#include <algorithm>
#include <iostream>
using namespace std;

long long dp[501][501];
int ans[8];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m, k, a, b, c;
    long long sum, mn = INT_MAX;
    cin >> n >> m >> k;

    for (int i = 0; i < 501; i++) {
        for (int j = 0; j < 501; j++) {
            dp[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> ans[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dp[a - 1][b - 1] = dp[b - 1][a - 1] = c;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || dp[i][k] == INT_MAX || dp[k][j] == INT_MAX) {
                    continue;
                }
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    sort(ans, ans + k);
    do {
        sum = 0;
        for (int i = 1; i < k; i++) {
            sum += dp[ans[i] - 1][ans[i - 1] - 1];
        }
        mn = min(mn, sum);
    } while (next_permutation(ans, ans + k));

    cout << mn;
}
