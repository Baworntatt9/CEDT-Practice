#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    cin >> n >> k;

    map<int, int> data;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        data[a] += b;
    }

    vector<pair<int, int>> data2(data.begin(), data.end());
    vector<int> result(data2.size());
    result[0] = data2[0].second;

    for (int i = 1; i < data2.size(); i++) {
        result[i] = (result[i - 1] + data2[i].second);
    }

    for (int i = 0; i < k; i++) {
        int m;
        cin >> m;
        cout << data2[lower_bound(result.begin(), result.end(), m) -
            result.begin()]
            .first
            << "\n";
    }
}
