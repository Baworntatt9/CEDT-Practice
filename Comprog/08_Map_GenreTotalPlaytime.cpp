#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void printf(vector<pair<int, string>> block) {
    int count = 0;
    for (auto a : block) {
        if (count == 3) {
            break;
        }
        cout << a.second;
        string time;
        int min = a.first / 60;
        int second = a.first - (min * 60);

        cout << " --> " << min << ":" << second << endl;
        count += 1;
    }
}

void sumei(map<string, vector<int>> data) {
    vector<pair<int, string>> lk;
    for (auto a : data) {
        int sum = 0;
        for (auto b : a.second) {
            sum += b;
        }
        lk.push_back({ sum, a.first });
    }

    sort(lk.begin(), lk.end(), greater<>());
    printf(lk);
}

int main() {
    string songName, author, type, time;

    map<string, vector<int>> data;

    while (cin >> songName >> author >> type >> time) {
        int k = 0;
        if (time.size() == 4) {
            k += (time[0] - '0') * 60;
            k += stoi(time.substr(2, 2));
        }
        else if (time.size() == 5) {
            k += (stoi(time.substr(0, 2))) * 60;
            k += stoi(time.substr(3, 2));
        }
        data[type].push_back(k);
    }

    sumei(data);
}
