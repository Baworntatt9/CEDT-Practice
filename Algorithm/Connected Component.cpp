#include <iostream>
#include <vector>
using namespace std;

void fillCom(int n, vector<vector<int>>& data, vector<bool>& visited) {
    visited[n] = true;

    for (int k : data[n]) {
        if (!visited[k]) {
            fillCom(k, data, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int v, e, a, b;
    cin >> v >> e;

    vector<vector<int>> data(v + 1);
    vector<bool> visited(v + 1, false);
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        data[a].push_back(b);
        data[b].push_back(a);
    }

    int count = 0;
    for (int i = 1; i <= v; i++) {
        if (visited[i] == false) {
            fillCom(i, data, visited);
            count++;
        }
    }

    cout << count;
}
