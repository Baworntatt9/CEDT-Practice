#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;
    cin.ignore();

    map<string, vector<string>> data;

    for (int i = 0; i < a; i++) {
        string nameSong, author;
        getline(cin, nameSong, ',');
        getline(cin, author);
        author.erase(0, 1);

        data[nameSong].push_back(author);
    }

    string target;
    getline(cin, target);
    target += ',';

    stringstream m(target);
    string k;

    while (getline(m, k, ',')) {
        if (k[0] == ' ') {
            k.erase(0, 1);
        }

        if (data.find(k) != data.end()) {
            cout << k << " -> ";
            for (int i = 0; i < data[k].size(); i++) {
                if (i == data[k].size() - 1) {
                    cout << data[k][i];
                    break;
                }
                else
                    cout << data[k][i] << ", ";
            }
        }
        else {
            cout << k << " -> " << "Not found";
        }
        cout << endl;
    }
}
