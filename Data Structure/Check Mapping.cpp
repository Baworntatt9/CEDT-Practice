#include <iostream>
#include <set>
using namespace std;

int main() {
    int a;
    cin >> a;

    set<int> data;

    for (int i = 0; i < a; i++) {
        int b;
        cin >> b;

        data.insert(b);
    }

    auto y = data.begin();
    auto x = ++data.begin();
    bool check = 0;
    for (int i = 0; i < a - 1; i++) {
        if ((*y) + 1 != (*x)) {
            check = 1;
            break;
        }
        y++;
        x++;
    }

    if (check) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
}
