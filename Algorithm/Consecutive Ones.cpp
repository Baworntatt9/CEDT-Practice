#include <iostream>
#include <string>
#include <vector>
using namespace std;

void gen(int k, string findd, string current) {
    if (k == 0) {
        auto a = current.find(findd);
        if (a != string::npos)
            cout << current << endl;
    }
    else {
        gen(k - 1, findd, current + "0");
        gen(k - 1, findd, current + "1");
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    string s = string(k, '1');
    gen(n, s, "");
}
