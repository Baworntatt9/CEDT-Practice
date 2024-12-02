#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;

    vector<int> line1;

    for (int i = 1; i <= a; i++) {
        int g1;
        cin >> g1;
        line1.push_back(g1);
    }

    string get;
    cin.ignore();
    getline(cin, get);

    string n;

    vector<int> line2;

    istringstream number(get);

    while (getline(number, n, ' ')) {
        int k = stoi(n);
        line2.push_back(k);
    }

    int n2;
    vector<int> line3;

    while (cin >> n2 && n2 != -1) {
        line3.push_back(n2);
    }

    vector<int> linesum;

    for (int i = 0; i < line1.size(); i++) {
        linesum.push_back(line1[i]);
    }
    for (int i = 0; i < line2.size(); i++) {
        linesum.push_back(line2[i]);
    }
    for (int i = 0; i < line3.size(); i++) {
        linesum.push_back(line3[i]);
    }

    vector<int> re;

    int c1 = linesum.size() - 1; // 5 4
    int d1 = linesum.size() - 2; // 5 3
    int c2 = 0;

    if (linesum.size() % 2 == 0) {
        for (int i = 1; i <= linesum.size() / 2; i++) {
            if (c1 >= 0) {
                re.push_back(linesum[c1]);
            }
            c1 -= 2;
        }
        for (int i = 1; i <= linesum.size() / 2; i++) {
            if (c2 <= linesum.size()) {
                re.push_back(linesum[c2]);
            }
            c2 += 2;
        }
    }
    else {
        for (int i = 1; i <= linesum.size() / 2 + 1; i++) {
            if (d1 >= 0) {
                re.push_back(linesum[d1]);
            }
            d1 -= 2;
        }
        for (int i = 1; i <= linesum.size() / 2; i++) {
            if (c2 <= linesum.size()) {
                re.push_back(linesum[c2]);
            }
            c2 += 2;
        }
        re.push_back(linesum[linesum.size() - 1]);
    }

    cout << '[';

    for (int i = 0; i < re.size(); i++) {
        if (i == re.size() - 1) {
            cout << re[i];
            break;
        }
        cout << re[i] << ", ";
    }

    cout << ']';
}
