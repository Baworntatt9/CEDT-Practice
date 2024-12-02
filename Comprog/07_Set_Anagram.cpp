#include <cctype>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    multiset<char> k1;
    multiset<char> k2;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != ' ') {
            k1.insert(tolower(a[i]));
        }
    }

    for (int i = 0; i < b.size(); i++) {
        if (b[i] != ' ') {
            k2.insert(tolower(b[i]));
        }
    }

    bool check = true;
    if (k1.size() != k2.size()) {
        check = false;
    }
    else {
        for (auto i = k1.begin(), j = k2.begin(); i != k1.end(); i++, j++) {
            if (*i != *j) {
                check = false;
            }
        }
    }

    if (check == true) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
