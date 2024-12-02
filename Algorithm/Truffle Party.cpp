#include <iostream>
#include <vector>
using namespace std;

long long count_truffles(long long time, const vector<int>& times) {
    long long truffles = 0;
    for (int t : times) {
        truffles += time / t;
    }
    return truffles;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> times(m);
    for (int i = 0; i < m; ++i) {
        cin >> times[i];
    }

    // Binary search for the minimum time
    long long left = 0,
        right = (long long)n * (*min_element(times.begin(), times.end()));
    long long answer = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (count_truffles(mid, times) >= n) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer;
}
