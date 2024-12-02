#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    string a, b;

    map<string, vector<string>> data;

    while (cin >> a >> b && !b.empty()) {
        data[a].push_back(b);
        data[b].push_back(a);
    }

    string target = a;

    // find 0ne
    set<string> one;
    for (auto c : data) {
        if (c.first == target) {
            for (auto d : c.second) {
                one.insert(d);
            }
        }
    }

    // find two
    set<string> two;
    for (auto c : one) {
        for (auto d : data) {
            if (c == d.first) {
                for (auto e : d.second) {
                    if (e != target) {
                        two.insert(e);
                    }
                }
            }
        }
    }

    set<string> sum = one;
    sum.insert(target);
    for (auto n : two) {
        sum.insert(n);
    }

    for (auto k : sum) {
        cout << k << endl;
    }
}
