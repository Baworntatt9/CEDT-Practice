#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> N;
    vector<int> M;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        N.push_back(a);
    }

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        M.push_back(a);
    }

    set<int> data(N.begin(), N.end());

    for (int k = 0; k < M.size(); k++) {
        bool c = 0;
        for (int i = 0; i < N.size(); i++) {
            int needed = M[k] - N[i];
            if (data.find(needed) != data.end() && needed != N[i]) {
                c = 1;
                break;
            }
        }
        if (c) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
