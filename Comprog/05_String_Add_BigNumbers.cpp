#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string k;

    vector<string> line;
    vector<int> linesi;

    while (cin >> k && k != "END") {
        line.push_back(k);
    }

    for (int i = 0; i < line.size(); i++) {
        linesi.push_back(line[i].size());
    }

    sort(linesi.begin(), linesi.end());

    for (int i = 0; i < line.size(); i++) {
        if (line[i].size() < linesi[linesi.size() - 1]) {
            int dif = linesi[linesi.size() - 1] - line[i].size();
            line[i].insert(line[i].begin(), dif, '0');
        }
    }

    string sum;
    int frac = 0;

    for (int i = linesi[linesi.size() - 1] - 1; i >= 0; i--) {
        int count = frac;

        for (int j = 0; j < line.size(); j++) {
            int n = line[j][i] - '0';
            count += n;
        }
        sum += to_string(count % 10);
        frac = count / 10;
    }

    reverse(sum.begin(), sum.end());

    if (frac == 0) {
        cout << sum;
    }
    else {
        cout << to_string(frac) + sum;
    }
}
