#include <iostream>
#include <map>
#include <string>
using namespace std;

string findMode(map<int, int>& data, int start, int end) {
    map<int, int> keep;
    bool check = 0;
    for (int i = start; i <= end; i++) {
        if (data.find(i) != data.end()) {
            check = 1;
            keep[data[i]] += 1;
        }
    }

    auto itr = keep.begin();
    int s = (*itr).first;
    for (auto a : keep) {
        if (a.second > keep[s]) {
            s = a.first;
        }
    }

    if (check) {
        return to_string(s);
    }
    else {
        return "X";
    }
}

void printData(int k, int n, map<int, int>& data) {

    for (int i = 1; i <= n; i++) {
        cout << findMode(data, i - k, i + k) << " ";
    }
}

int main() {
    int k, n, m;
    cin >> k >> n >> m;

    map<int, int> data;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        data[a] = b;
    }

    printData(k, n, data);
}
