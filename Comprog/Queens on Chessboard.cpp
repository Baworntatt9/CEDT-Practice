#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;

    vector<vector<char>> line;

    for (int i = 1; i <= a; i++) {
        vector<char> ss;
        for (int j = 1; j <= a; j++) {
            char b;
            cin >> b;
            ss.push_back(b);
        }
        line.push_back(ss);
    }

    vector<vector<char>> line2;

    for (int i = 0; i < a; i++) {
        vector<char> lll;
        for (int j = 0; j < a; j++) {
            if (line[i][j] == 'Q') {
                bool LL = 0;
                for (int k = 1; k < a; k++) {
                    if (((i + k < a) && (j + k < a) &&
                        line[i + k][j + k] == 'Q') ||
                        ((i - k >= 0) && (j - k >= 0) &&
                            line[i - k][j - k] == 'Q') ||
                        ((i + k < a) && (j - k >= 0) &&
                            line[i + k][j - k] == 'Q') ||
                        ((i - k >= 0) && (j + k < a) &&
                            line[i - k][j + k] == 'Q')) {
                        LL = 1;
                        break;
                    }
                    if (((j + k < a) && line[i][j + k] == 'Q') ||
                        ((j - k >= 0) && line[i][j - k] == 'Q') ||
                        ((i + k < a) && line[i + k][j] == 'Q') ||
                        ((i - k >= 0) && line[i - k][j] == 'Q')) {
                        LL = 1;
                        break;
                    }
                }
                if (LL == 1) {
                    lll.push_back('-');
                }
                else {
                    lll.push_back('Q');
                }
            }
            else {
                lll.push_back('-');
            }
        }
        line2.push_back(lll);
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout << line2[i][j];
        }
        cout << endl;
    }
}
