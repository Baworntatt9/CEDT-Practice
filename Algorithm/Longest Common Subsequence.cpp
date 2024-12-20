#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestCommonSubsequence(const string& A, const string& B) {
    int m = A.size();
    int n = B.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string A, B;
    cin >> A;
    cin >> B;

    int result = longestCommonSubsequence(A, B);

    cout << result << endl;
}
