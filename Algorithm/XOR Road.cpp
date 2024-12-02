#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef unsigned long long ull;

/* Normal
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int v;
    unsigned long long a;
    cin >> v;

    vector<unsigned long long> ver;
    for (int i = 0; i < v; i++) {
        cin >> a;
        ver.push_back(a);
    }

    vector<vector<pair<int, unsigned long long>>> data(v);
    for (int i = 0; i < v; i++) {
        for (int j = i + 1; j < v; j++) {
            unsigned long long weight = ver[i] ^ ver[j];
            data[i].emplace_back(j, weight);
            data[j].emplace_back(i, weight);
        }
    }

    priority_queue<pair<unsigned long long, int>> pq;
    vector<bool> visited(v, false);
    unsigned long long totalBeauty = 0;

    visited[0] = true;
    for (auto edge : data[0]) {
        pq.emplace(edge.second, edge.first); // cost & node
    }

    while (!pq.empty()) {
        auto [weight, node] = pq.top();
        pq.pop();

        if (visited[node]) {
            continue;
        }

        visited[node] = true;
        totalBeauty += weight;

        for (auto edge : data[node]) {
            if (!visited[edge.first]) {
                pq.emplace(edge.second, edge.first);
            }
        }
    }

    cout << totalBeauty;
}
*/

// Better
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> road(n);
    vector<bool> visited(n, false);
    vector<ull> value(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> road[i];
    }

    value[0] = 0;
    visited[0] = true;
    int now = road[0];

    ull ans = 0;
    for (int r = 1; r < n; r++) {
        ull maxs = 0;
        int next = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ull dist = road[i] ^ now;
                if (dist > value[i]) {
                    value[i] = dist;
                }
                if (value[i] > maxs) {
                    maxs = value[i];
                    next = i;
                }
            }
        }
        visited[next] = true;
        ans += maxs;
        now = road[next];
    }

    cout << ans;
}
