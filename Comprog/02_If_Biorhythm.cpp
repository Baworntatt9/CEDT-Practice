#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int d, m, y, d2, m2, y2;

    cin >> d >> m >> y >> d2 >> m2 >> y2;

    int red, blue, black;

    int ks = y - 543;
    string k = to_string(y - 543);
    string kk = k.substr(2, 2);

    int gs = y2 - 543;
    string g = to_string(y2 - 543);
    string gg = g.substr(2, 2);

    int gap = y2 - y - 1;
    int gapn = gap * 365;
    black = gapn;

    if ((kk != "00" && ks % 4 == 0) || (kk == "00" && ks % 400 == 0)) {
        if (m == 1) {
            red = 335 + 31 - d + 1;
        }
        if (m == 2) {
            red = 306 + 29 - d + 1;
        }
        if (m == 3) {
            red = 275 + 31 - d + 1;
        }
        if (m == 4) {
            red = 245 + 30 - d + 1;
        }
        if (m == 5) {
            red = 214 + 31 - d + 1;
        }
        if (m == 6) {
            red = 184 + 30 - d + 1;
        }
        if (m == 7) {
            red = 153 + 31 - d + 1;
        }
        if (m == 8) {
            red = 122 + 31 - d + 1;
        }
        if (m == 9) {
            red = 92 + 30 - d + 1;
        }
        if (m == 10) {
            red = 61 + 31 - d + 1;
        }
        if (m == 11) {
            red = 31 + 30 - d + 1;
        }
        if (m == 12) {
            red = 31 - d + 1;
        }
    }
    else {
        if (m == 1) {
            red = 334 + 31 - d + 1;
        }
        if (m == 2) {
            red = 306 + 28 - d + 1;
        }
        if (m == 3) {
            red = 275 + 31 - d + 1;
        }
        if (m == 4) {
            red = 245 + 30 - d + 1;
        }
        if (m == 5) {
            red = 214 + 31 - d + 1;
        }
        if (m == 6) {
            red = 184 + 30 - d + 1;
        }
        if (m == 7) {
            red = 153 + 31 - d + 1;
        }
        if (m == 8) {
            red = 122 + 31 - d + 1;
        }
        if (m == 9) {
            red = 92 + 30 - d + 1;
        }
        if (m == 10) {
            red = 61 + 31 - d + 1;
        }
        if (m == 11) {
            red = 31 + 30 - d + 1;
        }
        if (m == 12) {
            red = 31 - d + 1;
        }
    }

    if ((gg != "00" && gs % 4 == 0) || (gg == "00" && gs % 400 == 0)) {
        if (m2 == 12) {
            blue = 335 + d2 - 1;
        }
        if (m2 == 11) {
            blue = 305 + d2 - 1;
        }
        if (m2 == 10) {
            blue = 274 + d2 - 1;
        }
        if (m2 == 9) {
            blue = 244 + d2 - 1;
        }
        if (m2 == 8) {
            blue = 213 + d2 - 1;
        }
        if (m2 == 7) {
            blue = 182 + d2 - 1;
        }
        if (m2 == 6) {
            blue = 152 + d2 - 1;
        }
        if (m2 == 5) {
            blue = 121 + d2 - 1;
        }
        if (m2 == 4) {
            blue = 91 + d2 - 1;
        }
        if (m2 == 3) {
            blue = 60 + d2 - 1;
        }
        if (m2 == 2) {
            blue = 31 + d2 - 1;
        }
        if (m2 == 1) {
            blue = d2 - 1;
        }
    }
    else {
        if (m2 == 12) {
            blue = 334 + d2 - 1;
        }
        if (m2 == 11) {
            blue = 304 + d2 - 1;
        }
        if (m2 == 10) {
            blue = 273 + d2 - 1;
        }
        if (m2 == 9) {
            blue = 243 + d2 - 1;
        }
        if (m2 == 8) {
            blue = 212 + d2 - 1;
        }
        if (m2 == 7) {
            blue = 181 + d2 - 1;
        }
        if (m2 == 6) {
            blue = 151 + d2 - 1;
        }
        if (m2 == 5) {
            blue = 120 + d2 - 1;
        }
        if (m2 == 4) {
            blue = 90 + d2 - 1;
        }
        if (m2 == 3) {
            blue = 59 + d2 - 1;
        }
        if (m2 == 2) {
            blue = 31 + d2 - 1;
        }
        if (m2 == 1) {
            blue = d2 - 1;
        }
    }

    int sum = red + black + blue;

    double p, e, i;
    double pi = 3.14159265358979323846;

    p = sin(2 * sum * pi / 23);
    e = sin(2 * sum * pi / 28);
    i = sin(2 * sum * pi / 33);

    cout << sum << " " << round(100.0 * p) / 100.0 << " "
        << round(100.0 * e) / 100.0 << " " << round(100.0 * i) / 100.0;
}
