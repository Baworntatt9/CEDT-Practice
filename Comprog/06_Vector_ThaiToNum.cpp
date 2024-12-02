#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std; // if 10 do one and break

int sum(vector<int> block) {
    int sum = 0;
    for (auto a : block) {
        sum += a;
    }
    return sum;
}

void cal(vector<string> data, vector<string> one, vector<string> luk) {
    int keep1 = 0;
    int keep2 = 0;

    vector<int> rere;

    for (int i = 0; i < data.size(); i++) {
        if (i % 2 == 0) {
            if (data[i] == "sip") { // 12 13 16 17
                if (i + 1 < data.size()) {
                    if (data[i + 1] == "et") {
                        keep1 = 11;
                    }
                    else {
                        for (int j = 2; j < one.size(); j++) {
                            if (data[i + 1] == one[j]) {
                                keep1 = 10 + j;
                            }
                        }
                    }
                }
                else if (i + 1 == data.size()) {
                    keep1 = 10;
                }
                keep2 = 1;
                rere.push_back(keep1 * keep2);
                break;
            }
            else {
                if (data[i] == one[11]) { // et
                    keep1 = 1;
                    rere.push_back(keep1);
                    break;
                }
                else if (data[i] == one[12]) { // yi
                    keep1 = 2;
                }
                else {
                    for (int j = 0; j < one.size(); j++) {
                        if (data[i] == one[j]) {
                            keep1 = j;
                        }
                    }
                }
            }

            if (i == data.size() - 1) {
                rere.push_back(keep1);
                break;
            }
        }
        // keep2
        else {
            for (int j = 0; j < luk.size(); j++) { // 0 is luk 10
                if (data[i] == luk[j]) {
                    keep2 = pow(10, j + 1);
                    break;
                }
            }
            rere.push_back(keep1 * keep2);
        }
    }
    // suminrere & cout
    cout << sum(rere) << endl;
}

int main() {
    vector<string> one = { "soon", "neung", "song", "sam", "si", "ha", "hok",
                          "chet", "paet",  "kao",  "sip", "et", "yi" };
    vector<string> luk = { "sip", "roi", "phan", "muen", "saen", "lan" };

    string d;
    while (getline(cin, d) && d != "q") {
        stringstream k(d);
        vector<string> data;
        string c;

        while (k >> c) {
            data.push_back(c);
        }
        cal(data, one, luk);
    }
}
