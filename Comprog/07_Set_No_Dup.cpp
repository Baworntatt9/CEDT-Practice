#include <iostream>
#include <set>
using namespace std;

int main() {
    int a;
    set<int> b;

    int count = 0;
    bool check = true;
    while (cin >> a) {
        if (b.find(a) == b.end()) {
            b.insert(a);
            count += 1;
        }
        else {
            check = false;
            break;
        }
    }

    if (check == false) {
        cout << count + 1;
    }
    else {
        cout << "-1";
    }
}
