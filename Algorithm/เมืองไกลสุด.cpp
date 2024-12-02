#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int v, a;
    cin >> v;

    vector<vector<int>> data(v + 1, vector<int>(v + 1));
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            cin >> a;
            data[i][j] = a;
        }
    }

    set<pair<int, int>> pq;
    vector<int> distance(v + 1, INT_MAX);
    distance[1] = 0;
    pq.insert({ 0, 1 }); // cost & node

    while (!pq.empty()) {
        auto [weight, node] = *pq.begin();
        pq.erase(pq.begin());

        for (int i = 1; i <= v; i++) {
            if (data[node][i] > 0) {
                int new_distance = weight + data[node][i];
                if (distance[i] > new_distance) {
                    distance[i] = new_distance;
                    pq.insert({ distance[i], i });
                }
            }
        }
    }

    sort(++distance.begin(), distance.end(), greater<>());
    if (distance[1] == INT_MAX)
        cout << -1;
    else
        cout << distance[1];
}
