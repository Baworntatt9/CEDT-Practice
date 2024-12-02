#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    vector<vector<double>> line;

    for (int i = 1; i <= a; i++) {
        vector<double> num;
        for (int j = 1; j <= b; j++) {
            double d;
            cin >> d;
            num.push_back(d);
        }
        line.push_back(num);
    }

    vector<vector<double>> line2;

    for (int i = 1; i <= a - 2; i++) {
        vector<double> k;
        for (int j = 1; j <= b - 2; j++) {
            double mm =
                (line[i - 1][j - 1] + line[i - 1][j] + line[i - 1][j + 1] +
                    line[i][j - 1] + line[i][j] + line[i][j + 1] +
                    line[i + 1][j - 1] + line[i + 1][j] + line[i + 1][j + 1]) /
                9.0;
            k.push_back(mm);
        }
        line2.push_back(k);
    }

    for (int i = 0; i < line2.size(); i++) {
        for (int j = 0; j < line2[0].size(); j++) {
            cout << round(line2[i][j] * 100) / 100.0 << " ";
        }
        cout << endl;
    }
}
