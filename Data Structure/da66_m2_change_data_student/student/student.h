#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to) {
    stack<vector<queue<int>>> keepTem;

    while (!a.empty()) {
        vector<queue<int>> n1 = a.top();
        a.pop();
        for (auto &k1 : n1) {
            for (int i = 0; i < k1.size(); i++) {
                int g = k1.front();
                if (g == from) {
                    g = to;
                }
                k1.pop();
                k1.push(g);
            }
        }
        keepTem.push(n1);
    }

    while (!keepTem.empty()) {
        a.push(keepTem.top());
        keepTem.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a,
              int from, int to) {
    for (auto itr = a.begin(); itr != a.end(); itr++) {
        pair<priority_queue<int>, int> keep = (*itr).second;
        priority_queue<int> keep1 = keep.first;
        int keep2 = keep.second;

        priority_queue<int> keep1Up;
        int k = keep1.size();
        for (int j = 0; j < k; j++) {
            int g = keep1.top();
            keep1.pop();
            if (g == from) {
                g = to;
            }
            keep1Up.push(g);
        }

        if (keep2 == from) {
            keep2 = to;
        }

        a[(*itr).first] = {keep1Up, keep2};
    }
}

void change_3(
    std::set<std::pair<std::list<int>,
                       std::map<int, std::pair<int, std::string>>>> &a,
    int from, int to) {

    vector<pair<list<int>, map<int, pair<int, string>>>> updates;

    for (auto itr = a.begin(); itr != a.end();) {
        list<int> keep1 = (*itr).first;
        map<int, pair<int, string>> keep2 = (*itr).second;

        for (auto &k : keep1) {
            if (k == from) {
                k = to;
            }
        }

        map<int, pair<int, string>> keep3;
        for (auto itr2 = keep2.begin(); itr2 != keep2.end(); itr2++) {
            int F = (*itr2).first == from ? to : (*itr2).first;
            int k1 = (*itr2).second.first == from ? to : (*itr2).second.first;
            string k2 = (*itr2).second.second;
            keep3[F] = {k1, k2};
        }

        updates.push_back({keep1, keep3});
        itr = a.erase(itr);
    }

    for (const auto &update : updates) {
        a.insert(update);
    }
}

#endif
