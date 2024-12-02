#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

bool hasNegativeCycle(vector<vector<double>>& data, int m) {
    vector<vector<double>> logGraph(m, vector<double>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            logGraph[i][j] = -log(data[i][j]);
        }
    }

    // Bellman-Ford
    vector<double> distance(m, INT_MAX);
    distance[0] = 0;

    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                if (distance[j] + logGraph[j][k] < distance[k]) {
                    distance[k] = distance[j] + logGraph[j][k];
                }
            }
        }
    }

    // Detect Negative Cycle
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < m; k++) {
            if (distance[j] + logGraph[j][k] < distance[k]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m;
        vector<vector<double>> data(m, vector<double>(m));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                cin >> data[j][k];
            }
        }

        if (hasNegativeCycle(data, m))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
