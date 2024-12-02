#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string a;

    getline(cin, a);

    a.erase(remove(a.begin(), a.end(), ' '), a.end());

    for (int i = 0; i < a.length(); i++) {
        a[i] = tolower(a[i]);
    }

    vector<char> line;

    for (int i = 0; i < a.length(); i++) { // เก็บตัวโดยไม่ซ้ำกัน
        auto t = (find(line.begin(), line.end(), a[i]));
        if (!isdigit(a[i]) && !ispunct(a[i]) && t == line.end()) {
            line.push_back(a[i]);
        }
    }

    sort(line.begin(), line.end());

    int n = line.size();

    for (int i = 0; i < n; i++) { // check string a and line

        int count = 0;

        for (int j = 0; j < a.length(); j++) {
            if (line[i] == a[j]) {
                count += 1;
            }
        }

        cout << line[i] << " -> " << count << endl;
    }
}
