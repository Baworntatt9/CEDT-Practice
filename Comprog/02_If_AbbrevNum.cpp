#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;

    cin >> a;

    int b = a.length();

    if (b == 1 || b == 2 || b == 3) {
        cout << a;
    }
    else if (b == 4) {
        double c = stoi(a) / 100.0;
        c = round(c) / 10.0;
        cout << c << 'K';
    }
    else if (b == 5) {
        double c = stoi(a) / 1000.0;
        c = round(c);
        cout << c << 'K';
    }
    else if (b == 6) {
        double c = stoi(a) / 1000.0;
        c = round(c);
        cout << c << 'K';
    }
    else if (b == 7) {
        double c = stoi(a) / 100000.0;
        c = round(c) / 10.0;
        cout << c << 'M';
    }
    else if (b == 8) {
        double c = stoi(a) / 1000000.0;
        c = round(c);
        cout << c << 'M';
    }
    else if (b == 9) {
        double c = stoi(a) / 1000000.0;
        c = round(c);
        cout << c << 'M';
    }
    else if (b == 10) {
        string m = a.substr(0, 5);
        double c = stoi(m) / 1000.0;
        c = round(c) / 10.0;
        cout << c << 'B';
    }
    else if (b == 11) {
        string m = a.substr(0, 5);
        double c = stoi(m) / 1000.0;
        c = round(c);
        cout << c << 'B';
    }
    else if (b == 12) {
        string m = a.substr(0, 5);
        double c = stoi(m) / 100.0;
        c = round(c);
        cout << c << 'B';
    }
    else if (b == 13) {
        string m = a.substr(0, 5);
        double c = stoi(m) / 10.0;
        c = round(c);
        cout << c << 'B';
    }
}
