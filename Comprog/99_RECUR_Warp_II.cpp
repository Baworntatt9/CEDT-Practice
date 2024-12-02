#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

void makePath(int b, int c, map<int, vector<int>>& data, vector<int>& path,
    set<vector<int>>& allpaths) {
    path.push_back(b);

    if (b == c) {
        allpaths.insert(path);
    }
    else {
        if (data.find(b) != data.end()) {
            for (auto m : data[b]) {
                makePath(m, c, data, path, allpaths);
            }
        }
    }

    path.pop_back();
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    map<int, vector<int>> data;
    set<vector<int>> allpaths;
    vector<int> path;
    int x, y;

    for (int i = 0; i < a; i++) {
        cin >> x >> y;
        data[x].push_back(y);
    }

    makePath(b, c, data, path, allpaths);
    if (allpaths.empty()) {
        cout << "no";
    }
    else {
        for (auto g : allpaths) {
            for (auto h : g) {
                if (h == g[g.size() - 1]) {
                    cout << h;
                    break;
                }
                cout << h << " -> ";
            }
            cout << endl;
        }
    }
}
