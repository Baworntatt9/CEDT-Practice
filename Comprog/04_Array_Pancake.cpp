#include <iostream>
using namespace std;

int max(int arr[], int i) {
    int max = 0;

    for (int j = 1; j <= i; j++) {
        if (arr[j] > arr[max]) {
            max = j;
        }
    }

    return max;
}

void flip1(int arr[], int indmax) {
    for (int i = 0, j = indmax; i <= indmax / 2; i++, j--) {
        swap(arr[i], arr[j]);
    }
}

void printt(int arr[], int a) {
    for (int i = 0; i < a; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int a;
    cin >> a;
    int arr[a];

    for (int i = 0; i < a; i++) {
        int b;
        cin >> b;
        arr[i] = b;
    }

    printt(arr, a);

    for (int i = a - 1; i > 0; i--) {
        int indmax = max(arr, i);

        if (indmax != i) {
            if (indmax > 0) {
                flip1(arr, indmax);
                printt(arr, a);
            }
            flip1(arr, i);
            printt(arr, a);
        }
    }
}
