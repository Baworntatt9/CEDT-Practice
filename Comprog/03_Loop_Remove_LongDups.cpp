#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    int a;
    cin >> a;

    int i = 0;

    string re;

    while (i < line.size()) {
        int count = 1;
        while (i + count < line.size() && line[i] == line[i + count]) {
            count++;
        }
        if (count < a) {
            re.append(line.substr(i, count));
        }
        i += count;
    }

    cout << re;
}