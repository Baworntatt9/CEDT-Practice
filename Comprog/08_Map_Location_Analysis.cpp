#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int a;
    cin >> a;

    map<string, vector<string>> data;
    vector<string> keep;

    string pass;
    string coun;
    for (int i = 0; i < a; i++) {
        cin >> pass;
        keep.push_back(pass);
        data[pass] = {};
        while (cin >> coun && coun != "*") {
            data[pass].push_back(coun);
        }
    }

    string target;
    cin >> target;

    bool check = false;
    bool checkone = false;
    for (auto a : keep) {
        if (a != target) { // äÅè check
            for (auto b : data[a]) {
                bool checkone = false;
                for (auto q : data[target]) { // loop àªç¤¢Í§ target
                    if (b == q) {
                        cout << ">> " << a << endl;
                        checkone = true;
                        check = true;
                        break;
                    }
                }
                if (checkone == true) {
                    break;
                }
            }
        }
    }
    if (check == false) {
        cout << ">> " << "Not Found";
    }
}
