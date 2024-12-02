#include <iostream>
#include <vector>
using namespace std;

int minimumSwaps(vector<int>& arr) {
    int n = arr.size();

    int count1 = 0, count2 = 0, count3 = 0;
    for (int num : arr) {
        if (num == 1)
            ++count1;
        else if (num == 2)
            ++count2;
        else
            ++count3;
    }

    int misplaced12 = 0, misplaced13 = 0;
    int misplaced21 = 0, misplaced23 = 0;
    int misplaced31 = 0, misplaced32 = 0;

    for (int i = 0; i < count1; ++i) {
        if (arr[i] == 2)
            ++misplaced12;
        else if (arr[i] == 3)
            ++misplaced13;
    }
    for (int i = count1; i < count1 + count2; ++i) {
        if (arr[i] == 1)
            ++misplaced21;
        else if (arr[i] == 3)
            ++misplaced23;
    }
    for (int i = count1 + count2; i < n; ++i) {
        if (arr[i] == 1)
            ++misplaced31;
        else if (arr[i] == 2)
            ++misplaced32;
    }

    int directSwaps = min(misplaced12, misplaced21) +
        min(misplaced13, misplaced31) +
        min(misplaced23, misplaced32);
    int cycleSwaps = 2 * (max(0, misplaced12 - misplaced21) +
        max(0, misplaced13 - misplaced31));

    return directSwaps + cycleSwaps;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << minimumSwaps(arr) << endl;
}
