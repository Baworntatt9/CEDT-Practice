#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    while (getline(cin, line) && !line.empty()) {
        int count = 0;
        char m = ' ';

        line.erase(line.length() - 1);

        for (char d : line) {
            if (ispunct(d) && d != '-') {
                m = d;
                break;
            }
        }

        for (char c : line) {
            if (c == m) {
                count += 1;
            }
        }

        string newl;
        int k = -1;

        for (int i = 1; i <= count / 2; i++) {
            int arr[2];

            k = line.find(m, k + 1);
            arr[0] = k;
            k = line.find(m, k + 1);
            arr[1] = k;

            newl += line.substr(arr[0] + 1, arr[1] - arr[0] - 1);
        }

        if (count == 0) {
            cout << "" << endl;
        }
        else {
            cout << newl << endl;
        }
    }
}
