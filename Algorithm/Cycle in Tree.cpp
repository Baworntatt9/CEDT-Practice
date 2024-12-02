#include <iostream>
#include <vector>
using namespace std;

vector<int> d[100000];
int value[100000];
int ans = 0;

void dfs(int i, int j, int count) {
    value[i] = count;

    for (int k : d[i]) {
        if (value[k] == 0) {
            dfs(k, i, count + 1);
        }
        else if (k != j) {
            ans = abs(count - value[k]) + 1;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int v, a, b;
    cin >> v;

    for (int i = 0; i < v; i++) {
        cin >> a >> b;
        d[a].push_back(b);
        d[b].push_back(a);
    }

    dfs(0, -1, 1);
    cout << ans;
}
