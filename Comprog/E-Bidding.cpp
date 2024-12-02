#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    map<string, map<string, pair<int, int>>> bids;
    set<string> bidders;
    int n;
    cin >> n;

    for (int k = 0; k < n; ++k) {
        char op;
        string b, p;
        int v = 0;
        cin >> op >> b >> p;
        if (op != 'W')
            cin >> v;
        if (op == 'B') {
            bidders.insert(b);
            bids[p][b] = { v, k };
        }
        else if (op == 'W') {
            if (bids.find(p) != bids.end() &&
                bids[p].find(b) != bids[p].end()) {
                bids[p][b] = { 0, k };
            }
        }
    }

    map<string, vector<pair<int, string>>> B;
    for (auto& p : bids) {
        tuple<int, int, string> maxt = { 0, 0, "" };
        for (auto& p2 : p.second) {
            tuple<int, int, string> t = { p2.second.first, -p2.second.second,
                                         p2.first };
            if (t > maxt)
                maxt = t;
        }
        if (get<0>(maxt) > 0) {
            B[get<2>(maxt)].push_back({ get<0>(maxt), p.first });
        }
    }

    for (auto& b : bidders) {
        vector<string> ps;
        int sum_v = 0;
        for (auto& p : B[b]) {
            ps.push_back(p.second);
            sum_v += p.first;
        }
        sort(ps.begin(), ps.end());
        if (ps.size() == 0) {
            cout << b << ": $0" << endl;
        }
        else {
            cout << b << ": $" << sum_v << " -> ";
            for (auto e : ps)
                cout << e << ' ';
            cout << endl;
        }
    }
}
