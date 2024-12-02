#include <iostream>
using namespace std;

int arr[1000] = { 0 };

int fibo(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    if (n >= 2) {
        if (arr[n] > 0) {
            return arr[n];
        }
        int sum = fibo(n - 1) + fibo(n - 2);
        arr[n] = sum;
        return sum;
    }
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n);
}
