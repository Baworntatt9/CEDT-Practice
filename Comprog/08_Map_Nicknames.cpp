#include <iostream>
#include <map>
using namespace std;

int main() {
    int a;
    cin >> a;

    map<string, string> line;

    string m, n;
    for (int i = 0; i < a; i++) {
        cin >> m;
        cin >> n;

        line[m] = n;
        line[n] = m;
    }

    int k;
    cin >> k;

    string l;
    for (int i = 0; i < k; i++) {
        cin >> l;

        if (line.find(l) == line.end()) {
            cout << "Not found" << endl;
        }
        else {
            cout << line[l] << endl;
        }
    }
}
