#include <iostream>
#include <string>
using namespace std;

int main() {
    int a;

    cin >> a;

    a = a - 543;

    string b = to_string(a);
    int l = b.length();
    string c;

    if (l == 3) {
        c = b.substr(1, 2);
    }
    if (l == 4) {
        c = b.substr(2, 2);
    }

    int y = stoi(c);
    int min = y / 4;

    int sum = y + min + 11;

    cout << sum % 7;
}
