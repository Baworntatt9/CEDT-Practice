#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double w, h;

    cin >> w;
    cin >> h;

    double mos = sqrt(w * h) / 60;
    double hay = 0.024265 * pow(w, 0.5378) * pow(h, 0.3964);

    double s = 0.6157 - (0.0188 * log10(w));

    double boyd = 0.0333 * pow(w, s) * pow(h, 0.3);

    cout << setprecision(15) << mos << endl;
    cout << setprecision(15) << hay << endl;
    cout << setprecision(15) << boyd;
}
