#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void printf(vector<pair<string, string>> re) {
    sort(re.begin(), re.end());
    for (auto a : re) {
        cout << a.first << " " << a.second << endl;
    }
}

void result(vector<tuple<double, string, vector<string>>> keep,
    map<string, int> data) {
    vector<pair<string, string>> re;

    for (int i = 0; i < keep.size(); i++) {
        for (auto a : get<2>(keep[i])) {
            if (data[a] > 0) {
                re.push_back({ get<1>(keep[i]), a });
                data[a] -= 1;
                break;
            }
        }
    }

    printf(re);
}

int main() {
    int a;
    cin >> a;

    map<string, int> data;

    for (int i = 0; i < a; i++) {
        string b;
        int c;
        cin >> b >> c;
        data[b] = c;
    }

    int a2;
    cin >> a2;

    vector<tuple<double, string, vector<string>>> keep;

    for (int i = 0; i < a2; i++) {
        string pass;
        double score;
        cin >> pass >> score;

        vector<string> type;

        for (int i = 0; i < 4; i++) {
            string d;
            cin >> d;
            type.push_back(d);
        }

        keep.push_back({ score, pass, type });
    }

    sort(keep.begin(), keep.end(), greater<>());

    result(keep, data);
}
