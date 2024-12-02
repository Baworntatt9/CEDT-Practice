#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool makePath(int b, int c, map<int, vector<int>>& data) {
    if (b == c) {
        return true;
    }

    if (data.find(b) != data.end()) {
        for (auto m : data[b]) {
            if (makePath(m, c, data)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    map<int, vector<int>> data;

    int x, y;
    for (int i = 0; i < a; i++) {
        cin >> x >> y;
        data[x].push_back(y);
    }

    if (makePath(b, c, data)) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
}
