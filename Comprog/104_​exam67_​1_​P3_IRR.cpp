#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

double calSum(vector<int> a, double irr) {
    double sum = 0.0;

    for (int i = 0; i < a.size(); i++) {
        sum += a[i] / pow((1 + irr), i);
    }

    return sum;
}

int main() {
    int m;
    cin >> m;

    vector<int> data;
    for (int i = 0; i < m + 1; i++) {
        int b;
        cin >> b;
        data.push_back(b);
    }

    double l = -1.0, u = 1.0;
    double x = 0.0;

    while (u - l > pow(10, -9)) {
        x = (l + u) / 2;
        double sum = calSum(data, x);

        if (sum > 0) { // ถ้าเกิน 0 ก็ปรับลง โดยการปรับช่วงทางซ้ายเข้ามา
            l = x;
        }
        else { // ถ้าน้อยกว่า 0 ก็ปรับช่วงทางขวาเข้ามา
            u = x;
        }
    }

    cout << setprecision(8) << x;
}
