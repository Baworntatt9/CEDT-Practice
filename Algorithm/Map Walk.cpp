#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[11][11];

void solve(vector<vector<int>>& vec, int nowi, int nowj, string& nows) {
    if (nowi == n && nowj == m) {
        cout << nows << endl;
        return;
    }
    if (nowi < 1 || nowi > n || nowj > m)
        return;
    if (vec[nowi][nowj] == 1)
        return;
    if (visited[nowi][nowj])
        return;

    visited[nowi][nowj] = true;
    pair<int, int> moves[] = { {0, 1}, {1, 0}, {-1, 0} };
    char ALP[] = { 'A', 'B', 'C' };

    for (int i = 0; i < 3; i++) {
        nows += ALP[i];
        solve(vec, nowi + moves[i].first, nowj + moves[i].second, nows);
        nows.pop_back();
    }

    visited[nowi][nowj] = false;
    return;
}

int main() {
    cin >> n >> m;

    vector<vector<int>> vec(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> vec[i][j];
        }
    }
    string tmp = "";
    solve(vec, 1, 1, tmp);
    cout << "DONE";
}
