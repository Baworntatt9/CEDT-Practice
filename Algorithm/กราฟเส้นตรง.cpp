#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int& d1, int& d2, int& nodes, vector<vector<int>>& data,
    vector<bool>& visited) {
    nodes++;
    if (data[i].size() == 1) {
        d1++;
    }
    else if (data[i].size() == 2) {
        d2++;
    }
    for (int k : data[i]) {
        if (!visited[k]) {
            visited[k] = true;
            dfs(k, d1, d2, nodes, data, visited);
        }
    }
}

bool check(int i, vector<vector<int>>& data, vector<bool>& visited) {
    visited[i] = true;
    int d1 = 0, d2 = 0, nodes = 0;
    dfs(i, d1, d2, nodes, data, visited);

    return (nodes == 1 || (d1 == 2 && d2 == nodes - 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int v, e, a, b;
    cin >> v >> e;

    vector<vector<int>> data(v);
    vector<bool> visited(v, false);
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        data[a].push_back(b);
        data[b].push_back(a);
    }

    int count = 0;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (check(i, data, visited)) {
                count++;
            }
        }
    }

    cout << count;
}
