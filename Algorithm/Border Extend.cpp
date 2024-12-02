#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, a;
    cin >> n >> m >> k;

    vector<vector<int>> data(n, vector<int>(m));
    vector<pair<int, int>> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            data[i][j] = a;
            if (a == 1) {
                start.push_back({ i, j });
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<tuple<int, int, int>> keep;
    for (auto [v1, v2] : start) {
        keep.push({ v1, v2, 0 });
    }
    while (!keep.empty()) {
        auto [i, j, count] = keep.front();
        keep.pop();
        if (count == k + 1) {
            continue;
        }
        if (visited[i][j]) {
            continue;
        }
        visited[i][j] = true;

        if (data[i][j] == 0) {
            data[i][j] = 2;
        }

        if (j + 1 < data[0].size()) {
            keep.push({ i, j + 1, count + 1 });
        }
        if (j - 1 >= 0) {
            keep.push({ i, j - 1, count + 1 });
        }
        if (i + 1 < data.size()) {
            keep.push({ i + 1, j, count + 1 });
        }
        if (i - 1 >= 0) {
            keep.push({ i - 1, j, count + 1 });
        }
    }

    for (auto h : data) {
        for (auto p : h) {
            cout << p << " ";
        }
        cout << "\n";
    }
}
