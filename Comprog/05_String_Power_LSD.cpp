#include <iostream>
#include <string>
using namespace std;

int main() {
    string buff;
    while (getline(cin, buff)) {
        string a = buff.substr(0, buff.find(' '));
        string n = buff.substr(buff.find(' ') + 1);

        if (n.length() == 1 && n == "0") {
            cout << ">> 1\n";
            continue;
        }

        if (n.length() > 3) {
            n = n.substr(n.length() - 3);
        }

        int ax = a[a.length() - 1] - '0';
        int nx = stoi(n) % 4;

        if (nx == 0) {
            nx = 4;
        }

        int res = 1;
        while (nx--) {
            res = (res * ax) % 10;
        }

        cout << ">> " << res << endl;
    }
}
