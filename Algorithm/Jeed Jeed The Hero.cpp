#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// BFS
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int r, c;
    cin >> r >> c;

    vector<vector<int>> data(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> data[i][j];
        }
    }

    vector<vector<bool>> visited(r, vector<bool>(c, false));
    queue<tuple<int, int, int>> keep;
    keep.push({ 0, 0, 0 });

    int total_distance = 0;
    while (!keep.empty()) {
        auto [i, j, count] = keep.front();
        keep.pop();
        if (visited[i][j]) {
            continue;
        }
        visited[i][j] = true;

        if (data[i][j] == 2) {
            total_distance += (count * 2);
            data[i][j] = 1;
        }

        if (j + 1 < data[0].size() && data[i][j + 1] != 0) {
            keep.push({ i, j + 1, count + 1 });
        }
        if (j - 1 >= 0 && data[i][j - 1] != 0) {
            keep.push({ i, j - 1, count + 1 });
        }
        if (i + 1 < data.size() && data[i + 1][j] != 0) {
            keep.push({ i + 1, j, count + 1 });
        }
        if (i - 1 >= 0 && data[i - 1][j] != 0) {
            keep.push({ i - 1, j, count + 1 });
        }
    }

    cout << total_distance;
}
