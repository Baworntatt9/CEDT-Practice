#include <iostream>
#include <set>
using namespace std;

void findAs(set<int>& data, int k, int n) {
    if (k >= n) {
        return;
    }
    data.insert(k);

    int k1 = k * 2 + 1;
    int k2 = k * 2 + 2;
    findAs(data, k1, n);
    findAs(data, k2, n);
}

int main() {
    int n, a;
    cin >> n >> a;

    int k = a;
    set<int> data;
    data.insert(k);

    findAs(data, k, n);

    cout << data.size() << endl;

    for (auto m : data) {
        cout << m << " ";
    }
}
