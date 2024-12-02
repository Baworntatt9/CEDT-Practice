#include <iostream>
#include <vector>
using namespace std;

void fillCon(int n, int m, int k, vector<vector<int>>& data,
    vector<bool>& visited) {
    visited[n] = true;
    if (m == k) {
        return;
    }
    for (auto a : data[n]) {
        fillCon(a, m + 1, k, data, visited);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int v, e, k, a, b;
    cin >> v >> e >> k;

    vector<vector<int>> data(v);
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        data[a].push_back(b);
        data[b].push_back(a);
    }

    int max = 1;
    for (int i = 0; i < v; i++) {
        int count = 0;
        vector<bool> visited(v, false);
        fillCon(i, 0, k, data, visited);
        for (int j = 0; j < v; j++) {
            if (visited[j]) {
                count++;
            }
        }
        if (count > max) {
            max = count;
        }
    }

    cout << max;
}
