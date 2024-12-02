#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c, t, a, sum = 0;
    cin >> r >> c >> t;

    int data[r][c];
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a;
            data[i][j] = a;
            if (a == 1) {
                q.push({ i, j });
                sum++;
            }
        }
    }

    vector<pair<int, int>> move = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    while (t--) {
        queue<pair<int, int>> nq;
        while (!q.empty()) {
            pair<int, int> k = q.front();
            q.pop();
            for (auto [x, y] : move) {
                int k1 = k.first + x, k2 = k.second + y;
                if (k1 >= 0 && k1 < r && k2 >= 0 && k2 < c &&
                    data[k1][k2] == 0) {
                    data[k1][k2] = 1;
                    nq.push({ k1, k2 });
                    sum++;
                }
            }
        }
        q = nq;
    }

    cout << sum;
}
