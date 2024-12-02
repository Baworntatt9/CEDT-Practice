#include <iostream>
#include <map>
using namespace std;

int main() {
    int a;
    cin >> a;

    map<string, double> data;

    for (int i = 0; i < a; i++) {
        string m;
        double n;
        cin >> m >> n;
        data[m] = n;
    }

    int start;
    string typec, typeold;
    cin >> start;
    cin >> typec;
    cout << start << " " << typec;

    typeold = typec;

    while (cin >> typec) {
        if (typec != "THB" && typeold != "THB") {
            start = start * data[typeold] / data[typec];
            cout << " -> " << start << " " << typec;
        }
        else if (typeold == "THB" && typec != "THB") {
            start /= data[typec];
            cout << " -> " << start << " " << typec;
        }
        else if (typec == "THB" && typeold != "THB") {
            start *= data[typeold];
            cout << " -> " << start << " " << typec;
        }
        else { // เหมือนกันทั้งก่อนและหลังพิมค่านั้นมาเลย
            cout << " -> " << start << " " << typec;
        }

        typeold = typec;
    }
}
