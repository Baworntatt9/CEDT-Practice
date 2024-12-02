#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string a;

    getline(cin, a);

    vector<string> line;

    istringstream m(a);
    string b;

    while (m >> b) {
        line.push_back(b);
    }

    string k1 = line[0];
    string k2 = line[line.size() - 1];
    string ek1, ek2;
    string ee1, ee2;

    for (int i = 1; i < k1.size(); i++) {
        if (tolower(k1[i]) == 'a' || tolower(k1[i]) == 'e' ||
            tolower(k1[i]) == 'i' || tolower(k1[i]) == 'o' ||
            tolower(k1[i]) == 'u') {
            ee1 = k1.substr(0, i);
            ek1 = k1.substr(i, k1.size() - i);
            break;
        }
    }

    for (int i = 1; i < k2.size(); i++) {
        if (tolower(k2[i]) == 'a' || tolower(k2[i]) == 'e' ||
            tolower(k2[i]) == 'i' || tolower(k2[i]) == 'o' ||
            tolower(k2[i]) == 'u') {
            ee2 = k2.substr(0, i);
            ek2 = k2.substr(i, k2.size() - i);
            break;
        }
    }

    // ee1 ee2 ek1 ek2

    string new1 = ee1 + ek2;
    string new2 = ee2 + ek1;

    line[0] = new1;
    line[line.size() - 1] = new2;

    for (int i = 0; i < line.size(); i++) {
        if (i == line.size() - 1) {
            cout << line[i];
            break;
        }
        cout << line[i] << " ";
    }
}
