#include <iostream>
#include <vector>
using namespace std;

bool isCycle(int n, int a, vector<vector<int>>& data, vector<bool>& visited) {
    visited[n] = true;
    for (int k : data[n]) {
        if (!visited[k]) {
            if (isCycle(k, n, data, visited)) {
                return true;
            }
        }
        else if (k != a) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, v, e, a, b;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v >> e;
        vector<vector<int>> data(v);
        vector<bool> visited(v, false);

        for (int j = 0; j < e; j++) {
            cin >> a >> b;
            data[a].push_back(b);
            data[b].push_back(a);
        }

        bool check = false;
        for (int j = 0; j < v; j++) {
            if (!visited[j]) {
                if (isCycle(j, -1, data, visited)) {
                    check = true;
                    break;
                }
            }
        }

        cout << (check ? "YES" : "NO") << "\n";
    }
}
