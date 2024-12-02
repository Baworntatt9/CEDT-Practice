#include <climits>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int trueMax = INT_MIN;
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (i > 0 && j > 0) {
                arr[i][j] = max(arr[i][j], arr[i][j] + arr[i - 1][j - 1]);
            }
            trueMax = max(trueMax, arr[i][j]);
        }
    }

    cout << trueMax;
}
