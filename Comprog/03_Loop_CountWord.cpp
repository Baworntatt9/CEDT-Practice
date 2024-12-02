#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string w;
    string line;

    cin >> w;
    cin.ignore();
    getline(cin, line);

    line.erase(remove_if(line.begin(), line.end(), ispunct), line.end());

    istringstream ke(line);

    string n;
    int c = 0;
    while (getline(ke, n, ' ')) {
        if (w == n) {
            c += 1;
        }
    }

    cout << c;
}