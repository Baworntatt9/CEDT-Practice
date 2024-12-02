#include <iostream>
#include <set>
using namespace std;

int main() {
    string a, b;

    set<string> win;
    set<string> lose;

    while (cin >> a >> b) {
        win.insert(a);
        lose.insert(b);
    }

    set<string> allwin;
    for (auto i = win.begin(); i != win.end(); i++) {
        if (lose.find(*i) == lose.end()) {
            allwin.insert(*i);
        }
    }

    if (allwin.empty()) {
        cout << "None";
    }
    else {
        for (auto a : allwin) {
            cout << a << " ";
        }
    }
}
