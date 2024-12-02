#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string code;
    double countcode;

    vector<string> codeline;
    vector<double> countcodeline;

    while (cin >> code && code != "END" && cin >> countcode) {
        codeline.push_back(code);
        countcodeline.push_back(countcode);
    }

    string buy;
    cin.ignore();
    getline(cin, buy);

    istringstream buyeiei(buy);

    vector<string> buylist;
    string gg;

    while (buyeiei >> gg) {
        buylist.push_back(gg);
    }

    vector<double> sum;

    for (int i = 0; i < codeline.size(); i++) {
        int count = 0;
        for (int j = 0; j < buylist.size(); j++) {
            if (codeline[i] == buylist[j]) {
                count += 1;
            }
        }
        sum.push_back(countcodeline[i] * count);
    }

    vector<pair<string, double>> sumei;

    for (int i = 0; i < codeline.size(); i++) {
        if (sum[i] != 0) {
            sumei.push_back(make_pair(codeline[i], sum[i]));
        }
    }

    sort(sumei.begin(), sumei.end());

    for (int i = 0; i < sumei.size(); i++) {
        for (int j = i + 1; j < sumei.size(); j++) {
            if (sumei[i].second < sumei[j].second) {
                swap(sumei[i], sumei[j]);
            }
        }
    }

    int mk = sumei.size();
    for (int i = 0; i < min(3, mk); i++) {
        cout << sumei[i].first << " " << sumei[i].second << endl;
    }
    if (sumei.empty()) {
        cout << "No Sales";
    }
}
