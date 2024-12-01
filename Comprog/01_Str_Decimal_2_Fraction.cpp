#include <iostream>
#include <string>
using namespace std;

long gcd(long a, long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int a;
    string b, c;
    cin >> a >> b >> c;

    string s = b + c;
    int o = stoi(s);
    int j = stoi(b);

    int up = o - j;

    int c1 = b.length();
    int c2 = c.length();

    string x;
    for (int i = 1; i <= c2; i++) {
        x += '9';
    }
    for (int i = 1; i <= c1; i++) {
        x += '0';
    }

    int xx = stoi(x);

    int tup = (a * xx) + up;

    long hun = gcd(tup, xx);

    cout << tup / hun << " / " << xx / hun;
}
