#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void comBi(vector<string>& data, map<string, int>& result, int start,
    string l) {
    if (start == data.size()) {
        sort(l.begin(), l.end());
        result[l] += 1;
        return;
    }

    for (auto a : data[start]) {
        comBi(data, result, start + 1, l + a);
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> data;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        data.push_back(word);
    }

    map<string, int> result;
    comBi(data, result, 0, "");

    int m;
    cin >> m;

    vector<pair<int, string>> sorted;
    for (auto& x : result) {
        sorted.push_back({ x.second, x.first });
    }
    sort(sorted.begin(), sorted.end(),
        [](const pair<int, string>& a, const pair<int, string>& b) {
            return (a.first > b.first) ||
                (a.first == b.first &&
                    a.second < b.second); // ถ้าค่าเท่ากันเอาตามพจนา
        });

    for (int i = 0; i < m; i++) {
        cout << sorted[i].second << endl;
    }
}
