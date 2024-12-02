#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string x, y;

    cin >> x;

    y = x + "$";

    vector<string> line;

    for (int i = 0; i < y.size(); i++) {
        int k = y.size() - 1;

        line.push_back(y);

        y.insert(0, 1, y[k]);
        y.erase(y.size() - 1);
    }

    sort(line.begin(), line.end());

    string sum;

    for (int i = 0; i < line.size(); i++) {
        sum += line[i][y.size() - 1];
    }

    cout << sum;
}
