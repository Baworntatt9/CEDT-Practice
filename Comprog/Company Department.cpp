#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    map<string, set<string>> data;
    map<string, string> data2; // ¤¹ ä» ºÃÔÉÑ·

    for (int i = 0; i < a; i++) {
        string name, type;
        cin >> name >> type;

        data[type].insert(name);
        data2[name] = type;
    }

    for (int i = 0; i < b; i++) {
        int pass;
        cin >> pass;

        string s1, s2;
        cin >> s1 >> s2;

        if (pass == 1) {
            string found = data2[s1];
            for (auto& a : data[found]) {
                if (a == s1) {
                    data[found].erase(s1);
                }
            }
            data2.erase(s1);
            data[s2].insert(s1);
            data2[s1] = s2;
        }
        else if (pass == 2) {
            for (auto& k : data[s1]) {
                data[s2].insert(k);
            }
            data.erase(s1);
        }
    }

    for (auto& k : data) {
        cout << k.first << ": ";
        for (auto& l : k.second) {
            cout << l << " ";
        }
        cout << endl;
    }
}
