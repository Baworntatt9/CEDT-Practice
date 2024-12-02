#include <algorithm>
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>
using namespace std;

int sum(vector<int> k) {
    int s = 0;
    for (auto a : k) {
        s += a;
    }
    return s;
}

vector<vector<int>> firstfit(vector<int> k) {
    vector<vector<int>> block;
    for (auto a : k) {
        bool check = false;
        for (auto& b : block) {
            if (sum(b) + a <= 100) {
                b.push_back(a);
                check = true;
                break;
            }
        }
        if (!check) {
            block.push_back({ a });
        }
    }
    return block;
}

vector<vector<int>> bestfit(vector<int> k) {
    vector<vector<int>> block;
    for (auto a : k) {
        int min_r = 100;
        int fit_i = -1;
        for (int i = 0; i < block.size(); i++) {
            int r = 100 - sum(block[i]) - a;
            if (r >= 0 && r < min_r) {
                fit_i = i;
                min_r = r;
            }
        }
        if (fit_i == -1) {
            block.push_back({ a });
        }
        else {
            block[fit_i].push_back(a);
        }
    }
    return block;
}

void print_result(vector<vector<int>> block) {
    vector<tuple<int, int, vector<int>>> s;
    for (auto a : block) {
        sort(a.begin(), a.end());
        s.push_back({ 100 - sum(a), a.size(), a }); // มันมองเป็น make_tuple เอง
    }
    sort(s.begin(), s.end()); // ได้ลำดับที่ถูกต้อง
    for (auto& a : s) {
        for (auto m : get<2>(a)) {
            cout << m << " ";
        }
        cout << endl;
    }
}

int main() {
    string type;
    cin >> type;

    string num;
    vector<int> numberline;
    cin.ignore();
    getline(cin, num);

    istringstream gg(num);
    string n;

    while (gg >> n) {
        numberline.push_back(stoi(n));
    }

    if (type == "first")
        print_result(firstfit(numberline));
    else
        print_result(bestfit(numberline));
}
