#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<string, vector<string>> data;
    vector<string> order;
    string a, b;

    while (cin >> a >> b) {
        if (data.find(b) == data.end()) {
            order.push_back(b); // เก็บลำดับก่อนหลัง
        }
        data[b].push_back(a);
    }

    for (auto a : order) {
        cout << a << ": ";
        for (auto b : data[a]) {
            cout << b << " ";
        }
        cout << endl;
    }
}
