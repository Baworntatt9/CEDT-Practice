#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isValid(int nx, int ny, int r, int c) {
    return (nx >= 0 && ny >= 0 && nx < r && ny < c);
}

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

// Dijkstra
void findShortest(vector<vector<int>>& data, int r, int c) {

    vector<vector<int>> cost(r, vector<int>(c, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<>>
        pq;
    pq.push({ 0, {0, 0} }); // cost && (x, y)
    cost[0][0] = 0;

    while (!pq.empty()) {
        auto [currCost, pos] = pq.top();
        int x = pos.first, y = pos.second;
        pq.pop();

        if (currCost > cost[x][y]) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny, r, c)) {
                int newcost = currCost + data[nx][ny];
                if (newcost < cost[nx][ny]) {
                    cost[nx][ny] = newcost;
                    pq.push({ newcost, {nx, ny} });
                }
            }
        }
    }

    for (auto& s : cost) {
        for (auto& d : s) {
            cout << d << " ";
        }
        cout << "\n";
    }
}

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

    findShortest(data, r, c);
}
