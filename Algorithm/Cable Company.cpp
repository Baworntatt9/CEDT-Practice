#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int v, cost;
    cin >> v;

    vector<vector<int>> data(v, vector<int>(v, -1));
    for (int i = 0; i < v - 1; i++) {
        for (int j = 0; j < v - i - 1; j++) {
            cin >> cost;
            data[i][i + j + 1] = cost;
            data[i + j + 1][i] = cost;
        }
    }

    vector<bool> visited(v, false);
    set<pair<int, int>> pq;
    pq.insert({ 0, 0 }); // cost & node

    int total_cost = 0;
    while (!pq.empty()) {
        auto [cost, u] = *pq.begin();
        pq.erase(pq.begin());

        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        total_cost += cost;

        for (int i = 0; i < v; i++) {
            if (!visited[i] && data[u][i] > -1) {
                pq.insert({ data[u][i], i });
            }
        }
    }

    cout << total_cost;
}
