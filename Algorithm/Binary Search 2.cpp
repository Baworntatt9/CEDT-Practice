#include <iostream>
#include <vector>
using namespace std;

int check(vector<int>& data, int a, int start, int end) {
    if (data[0] > a) {
        return -1;
    }
    if (end - start == 0) {
        return data[start];
    }

    int m = (start + end + 1) / 2;
    if (data[m] > a) {
        return check(data, a, 0, m - 1);
    }
    else {
        return check(data, a, m, end);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> data;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        data.push_back(a);
    }

    for (int i = 0; i < k; i++) {
        int a, start = 0, end = data.size() - 1;
        cin >> a;
        cout << check(data, a, start, end) << "\n";
    }
}
