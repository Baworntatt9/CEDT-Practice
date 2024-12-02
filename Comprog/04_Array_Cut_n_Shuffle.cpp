#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

void cut(string arr[], int a) {
    int b = a / 2;
    string k[a];

    for (int i = 0; i < a; i++) {
        k[i] = arr[i];
    }
    for (int i = 0, j = b; i < b; i++, j++) {
        arr[i] = k[j];
    }
    for (int i = b, j = 0; i < a; i++, j++) {
        arr[i] = k[j];
    }
}

void shuf(string arr[], int a) {
    int b = a / 2;
    string k[a];

    for (int i = 0; i < a; i++) {
        k[i] = arr[i];
    }

    int count = 0;

    for (int i = 0, j = b; i < b; i++, j++) {
        arr[count] = k[i];
        arr[count + 1] = k[j];
        count += 2;
    }
}

int main() {

    int num;

    cin >> num;

    string arr[num];

    for (int i = 0; i < num; i++) {
        string a;
        cin >> a;

        arr[i] = a;
    }

    string cs;
    cin.ignore();
    getline(cin, cs);

    cs.erase(remove(cs.begin(), cs.end(), ' '), cs.end());

    for (int i = 0; i < cs.length(); i++) {
        if (cs[i] == 'C') {
            cut(arr, num);
        }
        else if (cs[i] == 'S') {
            shuf(arr, num);
        }
    }

    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
}
