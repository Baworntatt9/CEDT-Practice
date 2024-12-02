#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int a;
    cin >> a;

    map<string, string> data;

    string l1, l2, k;
    for (int i = 0; i < a; i++) {
        cin >> l1 >> l2 >> k;

        data[l1 + " " + l2] = k;
        data[k] = l1 + " " + l2;
    }

    int m;
    cin >> m;
    cin.ignore();

    string n;
    for (int i = 0; i < m; i++) {
        getline(cin, n);
        if (data.find(n) == data.end()) {
            cout << n << " --> " << "Not found" << endl;
        }
        else {
            cout << n << " --> " << data[n] << endl;
        }
    }
}
