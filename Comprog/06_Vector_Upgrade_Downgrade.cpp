#include <iostream>
#include <vector>
using namespace std;

void printt(vector<pair<string, string>> block, vector<string> g) {
    for (int i = 0; i < g.size(); i++) {
        for (auto a : block) {
            if (a.second == g[i]) {
                cout << a.first << " " << a.second << endl;
            }
        }
    }
}

int main() {
    vector<string> gradelist = { "A", "B+", "B", "C+", "C", "D+", "D", "F" };

    int number;
    cin >> number;

    vector<pair<string, string>> data;

    string code;
    string grade;

    for (int i = 0; i < number; i++) {
        cin >> code >> grade;
        data.push_back({ code, grade });
    }

    string changegrade;
    int g = data[0].first.size();

    while (cin >> changegrade) {
        for (auto& a : data) {
            if (changegrade.substr(0, g) == a.first) {
                for (int i = 0; i < gradelist.size(); i++) {
                    if (a.second == gradelist[i]) { //
                        if (changegrade[g] == '+' && i > 0) {
                            a.second = gradelist[i - 1];
                            break;
                        }
                        else if (changegrade[g] == '-' &&
                            i < gradelist.size() - 1) {
                            a.second = gradelist[i + 1];
                            break;
                        }
                    }
                }
            }
        }
    }

    printt(data, gradelist);
}
