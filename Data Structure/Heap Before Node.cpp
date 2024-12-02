#include <iostream>
#include <set>
using namespace std;

void Ecur(set<int>& data, int k, int n) {
    if (k > n) {
        return;
    }
    data.erase(k);

    Ecur(data, 2 * k + 1, n);
    Ecur(data, 2 * k + 2, n);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    cin >> n >> k;

    set<int> data;
    for (int i = 0; i < n; i++) {
        data.insert(i);
    }

    Ecur(data, k, n);

    cout << data.size() << endl;
    for (auto& a : data) {
        cout << a << " ";
    }
}
