#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int v, e, a, b, w;
    cin >> v >> e;

    vector<vector<pair<int, int>>> data(v + 1);
    for (int i = 0; i < e; i++) {
        cin >> w >> a >> b;

        data[a].push_back({ b, w });
        data[b].push_back({ a, w });
    }

    set<pair<int, int>> pq;
    pq.insert({ 0, 1 }); // cost & node
    vector<bool> visited(v + 1, false);

    int total_cost = 0;
    while (!pq.empty()) {
        auto [weight, ver] = *pq.begin();
        pq.erase(pq.begin());
        if (visited[ver]) {
            continue;
        }
        visited[ver] = true;
        total_cost += weight;

        for (auto [k1, k2] : data[ver]) {
            if (!visited[k1]) {
                pq.insert({ k2, k1 });
            }
        }
    }

    cout << total_cost;
}
