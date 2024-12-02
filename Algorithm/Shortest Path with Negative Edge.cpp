#include <iostream>
#include <vector>
using namespace std;

int main() {
    int v, e, s, a, b, w;
    cin >> v >> e >> s;

    vector<vector<pair<int, int>>> data(v);

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> w;
        data[a].push_back({ b, w });
    }

    const int INF = INT_MAX / 2;
    vector<int> D(v, INF); // dist & weight
    D[s] = 0;

    // Bellman-Ford algorithm
    for (int i = 1; i < v; i++) {
        for (int j = 0; j < v; j++) {
            for (int k = 0; k < data[j].size(); k++) {
                int f = data[j][k].first;
                int g = data[j][k].second;
                if (D[f] > D[j] + g) {
                    D[f] = D[j] + g;
                }
            }
        }
    }

    // Check for negative weight cycle
    bool negative = false;
    for (int j = 0; j < v; j++) {
        for (int k = 0; k < data[j].size(); k++) {
            int f = data[j][k].first;
            int g = data[j][k].second;
            if (D[f] > D[j] + g) {
                negative = true;
                break;
            }
        }
        if (negative)
            break;
    }

    if (negative) {
        cout << -1;
    }
    else {
        for (auto k : D) {
            cout << k << " ";
        }
    }
}
