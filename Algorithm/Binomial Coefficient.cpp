#include <cstring>
#include <iostream>
using namespace std;

int arr[100][100];

int cnr(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    }
    if (arr[n][r] > -1) {
        return arr[n][r];
    }
    int k = cnr(n - 1, r - 1) + cnr(n - 1, r);
    arr[n][r] = k;
    return k;
}

int main() {
    memset(arr, -1, sizeof(arr));
    int n, r;
    cin >> n >> r;
    cout << cnr(n, r);
}
