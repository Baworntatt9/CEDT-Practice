#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

vector<bool> used;
unordered_map<int, int> mp;

bool check(int b) {
    if (mp.find(b) != mp.end() && !used[mp[b]]) {
        return false;
    }

    return true;
}

void permu(int now, int end, string str) {
    if (now == end) {
        cout << str << "\n";
        return;
    }

    for (int i = 0; i < end; i++) {
        if (!used[i] && check(i)) {
            used[i] = true;
            permu(now + 1, end, str + to_string(i) + " ");
            used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    used.resize(n, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        mp[b] = a;
    }

    permu(0, n, "");

    return 0;
}
