#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int findmax(vector<int> k) {
    int indexmax = 0;
    for (int i = 1; i < k.size(); i++) {
        if (k[i] > k[indexmax]) {
            indexmax = i;
        }
    }
    return indexmax;
}

int sum(vector<int> s) {
    int sss = 0;
    for (auto a : s) {
        sss += a;
    }
    return sss;
}

vector<tuple<int, long, string>> member(vector<pair<string, int>> block) {
    long allsum = 0;
    for (auto a : block) {
        allsum += a.second;
    }

    double perone = allsum / 100;

    vector<int> frac;
    vector<int> ss;

    for (auto a : block) {
        int ssinpar = 0;
        int fraction = 0;

        ssinpar = a.second / perone;
        fraction = a.second % (int)perone;

        ss.push_back(ssinpar);
        frac.push_back(fraction);
    }

    while (sum(ss) < 100) {
        int maxindex = findmax(frac);
        ss[maxindex] += 1;
        frac[maxindex] = 0;
    }

    vector<tuple<int, long, string>> block2;

    for (int i = 0; i < block.size(); i++) {
        if (ss[i] == 0) {
            continue;
        }
        block2.push_back({ ss[i], block[i].second, block[i].first });
    }

    return block2;
}

void printf(vector<tuple<int, long, string>> block2) {
    sort(block2.begin(), block2.end(), greater<>());

    for (auto a : block2) {
        cout << get<2>(a) << " " << get<0>(a) << " " << get<1>(a) << endl;
    }
}

int main() {
    vector<pair<string, int>> info;

    string party;
    int count;

    while (cin >> party && party != "END" && cin >> count) {
        info.push_back({ party, count });
    }

    printf(member(info));
}
