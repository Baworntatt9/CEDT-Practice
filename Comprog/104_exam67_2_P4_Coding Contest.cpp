#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

pair<int, int> calPenal(vector<tuple<int, int, char>> data) {
    pair<int, int> rere;

    map<int, int> pe;
    map<int, int> sc;
    map<int, int> tem; // keep false

    int score = 0;
    int penal = 0;

    for (auto a : data) {
        int time = get<0>(a);
        int problem = get<1>(a);
        char result = get<2>(a);

        if (result == 'T') {
            if (sc[problem] == 0) {
                sc[problem] = 1;
                pe[problem] += time;
                pe[problem] += tem[problem] * 20;
            }
        }
        else if (result == 'F') {
            if (sc[problem] == 0) {
                tem[problem]++;
            }
        }
    }

    for (auto a : sc) {
        score += a.second;
    }
    for (auto a : pe) {
        penal += a.second;
    }

    return { score, penal };
}

int main() {
    int n;
    cin >> n;

    map<string, vector<tuple<int, int, char>>> data;

    for (int i = 0; i < n; i++) {
        int time;
        string team;
        int choice;
        char re;

        cin >> time >> team >> choice >> re;

        data[team].push_back({ time, choice, re });
    }

    set<tuple<int, int, string>> result;

    for (auto a : data) {
        pair<int, int> aa = calPenal(data[a.first]);
        int a1 = aa.first;
        int a2 = aa.second;
        if (a1 > 0) {
            result.insert({ -a1, a2, a.first });
        }
    }

    // out
    auto itr = result.begin();
    int count = 0;

    tuple<int, int, string> third_place;

    while (count < 3 && itr != result.end()) {
        cout << get<2>((*itr)) << " " << -get<0>((*itr)) << " "
            << get<1>((*itr)) << endl;

        if (count == 2) {
            third_place = (*itr);
        }

        itr++;
        count++;
    }

    while (itr != result.end() && get<0>(*itr) == get<0>(third_place) &&
        get<1>(*itr) == get<1>(third_place)) {
        cout << get<2>(*itr) << " " << -get<0>(*itr) << " " << get<1>(*itr)
            << endl;
        itr++;
    }
}
