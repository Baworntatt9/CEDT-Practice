#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cin >> name;

    int p;
    cin >> p;

    string first = name.substr(0, 1);
    int firsti = stoi(first);

    string al = name.substr(1, 2);

    string num = name.substr(4, 3);
    int numi = stoi(num);

    string m = " ";

    if (numi + p < 10) {
        m = "00" + to_string(numi + p);
    }
    else if (numi + p >= 10 && numi + p < 100) {
        m = "0" + to_string(numi + p);
    }
    else {
        m = to_string(numi + p);
    }

    string k = m;
    string mk = "0";
    string lk = k.substr(k.size() - 3, 3);

    if (k.size() > 3) {
        mk = k.substr(0, k.size() - 3);
        lk = k.substr(k.size() - 3, 3);
    }

    for (int i = 1; i <= stoi(mk); i++) {
        if (al[1] != 'Z') {
            al[1] += 1;
        }
        else if (al[1] == 'Z') {
            al[1] = 65;

            if (al[0] != 'Z') {
                al[0] += 1;
            }
            else {
                al[0] = 'A';
                firsti += 1;
            }
        }
    }

    cout << to_string(firsti) + al + '-' + lk;
}
