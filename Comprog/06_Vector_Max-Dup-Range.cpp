#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

vector<tuple<int, int, int>> maxr(vector<tuple<int, int, int>> block) {
    int max = 0;
    for (auto a : block) {
        if (get<2>(a) - get<1>(a) > max) {
            max = get<2>(a) - get<1>(a);
        }
    }

    vector<tuple<int, int, int>> tblock;
    for (auto a : block) {
        if (get<2>(a) - get<1>(a) == max) {
            tblock.push_back(a);
        }
    }

    return tblock;
}

void print(vector<tuple<int, int, int>> tblock) {
    sort(tblock.begin(), tblock.end());
    for (auto a : tblock) {
        cout << get<0>(a) << " --> " << "x[ " << get<1>(a) << " : " << get<2>(a)
            << " ]" << endl;
    }
}

int main() {
    string inputnum;
    getline(cin, inputnum);

    istringstream line(inputnum);

    vector<int> number;

    string n;
    while (line >> n) {
        number.push_back(stoi(n));
    }

    vector<tuple<int, int, int>> block;

    int sum = 0;
    while (sum < number.size()) {
        int count = 0;

        int start = -1;
        int end = -1;

        bool check = false;

        while (sum + 1 < number.size() && number[sum] == number[sum + 1]) {
            count += 1;
            sum += 1;
            check = true;
        }
        if (check) {
            start = sum - count;
            end = sum + 1;
            block.push_back({ number[start], start, end });
        }
        else {
            block.push_back({ number[sum], sum, sum + 1 });
        }
        sum += 1;
    }

    print(maxr(block));
}
