#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;

    map<int, vector<string>> data;
    map<string, int> data2;

    for (int i = 0; i < a; i++) {
        string name;
        int score;

        cin >> name >> score;

        data[score].push_back(name);

        if (data2[name] <= score) {
            data2[name] = score;
        }
    }

    for (auto l = data.begin(); l != data.end(); l++) {
        sort((*l).second.begin(), (*l).second.end());
    }

    int k;
    cin >> k;

    auto itr = --data.end();
    for (int i = 0; i < k; i++) {
        bool check = 0;
        for (auto j = data2.begin(); j != data2.end(); j++) {
            if ((*itr).first == (*j).second) {
                check = 1;
                break;
            }
        }
        if (check) {
            cout << (*itr).first << " ";
        }

        for (auto a : (*itr).second) {
            if (data2[a] == (*itr).first) {
                cout << a << " ";
            }
        }
        cout << endl;
        if (i >= data.size() - 1) {
            break;
        }
        itr--;
    }
}
