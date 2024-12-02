#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string line;

    getline(cin, line);

    int a = 0;

    vector<string> get;

    string line2 = line;
    line2[0] = tolower(line2[0]);

    for (int i = 0; i < line.length(); i++) {

        if ((isupper(line2[i])) ||
            ((i > 0 && isdigit(line2[i]) && !isdigit(line2[i - 1]))) ||
            i > 0 && (isalpha(line2[i]) && (isdigit(line2[i - 1])))) {
            get.push_back(line.substr(a, i - a));
            a = i;
        }
    }

    get.push_back(line.substr(a));

    for (int i = 0; i < get.size(); i++) {
        if (i == get.size() - 1) {
            cout << get[get.size() - 1];
            break;
        }
        cout << get[i] << ", ";
    }
}
