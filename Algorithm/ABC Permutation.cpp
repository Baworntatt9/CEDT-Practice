#include <iostream>
#include <set>
#include <vector>
using namespace std;

void recur(vector<char>& data, int n, set<string>& keep, string re, int k,
    int a, int b, int c) {
    if (k == n) {
        keep.insert(re);
        return;
    }

    if (a > 0) {
        string reee = re + "A";
        recur(data, n, keep, reee, k + 1, a - 1, b, c);
    }
    if (b > 0) {
        string reee = re + "B";
        recur(data, n, keep, reee, k + 1, a, b - 1, c);
    }
    if (c > 0) {
        string reee = re + "C";
        recur(data, n, keep, reee, k + 1, a, b, c - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<char> data;
    for (int i = 0; i < a; i++) {
        data.push_back('A');
    }
    for (int i = 0; i < b; i++) {
        data.push_back('B');
    }
    for (int i = 0; i < c; i++) {
        data.push_back('C');
    }

    set<string> keep;
    string re = "";
    recur(data, n, keep, re, 0, a, b, c);

    cout << keep.size() << "\n";
    for (auto p : keep) {
        cout << p << "\n";
    }
}
