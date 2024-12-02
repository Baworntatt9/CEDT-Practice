#include <cmath>
#include <iostream>
using namespace std;

int main() {
    long long m, n;

    cin >> m >> n;

    long long luk = 1;
    long long count = 0;

    // การคำนวณ เช่น 111 112 113 มี 9 หลัก มาจาก (113 - 111 + 1) * 3
    // เช่น n = 12 แสดงว่ามี 1 - 9 แน่ๆ ก้เลยเข้า loop
    while (n >= (long long)pow(10, luk)) { // 0 <-> n
        count += luk * 9 * (long long)pow(10, luk - 1);
        luk++;
    }
    count += luk * (n - (long long)pow(10, luk - 1) + 1);

    long long luk2 = 1;
    long long count2 = 0;
    long long lm = m - 1;

    while (lm >= (long long)pow(10, luk2)) { // 0 <-> m - 1
        count2 += luk2 * 9 * (long long)pow(10, luk2 - 1);
        luk2++;
    }
    count2 += luk2 * ((lm)-(long long)pow(10, luk2 - 1) + 1);

    cout << count - count2 << endl;
}
