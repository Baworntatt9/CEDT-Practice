#include <iostream>
using namespace std;

// Dynamic Programmimg (Memoization / Top-Down)
int table[999] = { 0 };

int fibo(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    if (n >= 2) {
        if (table[n] > 0) {
            return table[n];
        }
        int sum = fibo(n - 1) + fibo(n - 2);
        table[n] = sum;
        return sum;
    }
}

int main() {
    int n;
    cin >> n;
    int k = fibo(n);
    cout << k;
}
