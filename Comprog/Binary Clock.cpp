#include <iostream>
#include <string>
using namespace std;

int main() {
    string l;
    cin >> l;

    string h = (l.substr(0, 2));
    string m = (l.substr(3, 2));
    string s = (l.substr(6, 2));

    string hms = h + m + s;

    char box[4][6] = { {' ', '0', ' ', '0', ' ', '0'},
                      {' ', '0', '0', '0', '0', '0'},
                      {'0', '0', '0', '0', '0', '0'},
                      {'0', '0', '0', '0', '0', '0'} };

    for (int i = 0; i < hms.size(); i++) {
        if (hms[i] == '1') {
            box[3][i] = '1';
        }
        else if (hms[i] == '2') {
            box[2][i] = '1';
        }
        else if (hms[i] == '3') {
            box[2][i] = '1';
            box[3][i] = '1';
        }
        else if (hms[i] == '4') {
            box[1][i] = '1';
        }
        else if (hms[i] == '5') {
            box[1][i] = '1';
            box[3][i] = '1';
        }
        else if (hms[i] == '6') {
            box[1][i] = '1';
            box[2][i] = '1';
        }
        else if (hms[i] == '7') {
            box[1][i] = '1';
            box[2][i] = '1';
            box[3][i] = '1';
        }
        else if (hms[i] == '8') {
            box[0][i] = '1';
        }
        else if (hms[i] == '9') {
            box[0][i] = '1';
            box[3][i] = '1';
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            cout << box[i][j];
        }
        cout << endl;
    }
}
