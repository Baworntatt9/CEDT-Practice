#include <iostream>
#include <set>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> k;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        k.insert({ a, b });
    }

    for (int i = 0; i < m; i++) {
        int a2, b2;
        cin >> a2 >> b2;

        pair<int, int> answer = { -1, -1 };

        if (k.find({ a2, b2 }) != k.end()) {
            answer = { 0, 0 };
        }
        else {
            auto it = k.lower_bound({ a2, b2 });
            if (it != k.begin()) {
                it--;
                answer = *it;
            }
        }

        cout << answer.first << " " << answer.second << " ";
    }
}
