#include <iostream>
#include <vector>
using namespace std;

int r, c;
bool visited[11][11];

void makePath(vector<vector<int>> &data, int nowi, int nowj, string &k) {
    if (nowi == r && nowj == c) {
        cout << k << "\n";
        return;
    }
    if (nowi > r || nowi < 1 || nowj > c)
        return;
    if (visited[nowi][nowj])
        return;
    if (data[nowi][nowj] == 1)
        return;

    visited[nowi][nowj] = true;
    pair<int, int> type[] = {{0, 1}, {1, 0}, {-1, 0}};
    char typeChar[] = {'A', 'B', 'C'};

    for (int i = 0; i < 3; i++) {
        k += typeChar[i];
        makePath(data, nowi + type[i].first, nowj + type[i].second, k);
        k.pop_back();
    }

    visited[nowi][nowj] = false;
    return;
};

int main() {
    cin >> r >> c;

    vector<vector<int>> data(r + 1, vector<int>(c + 1));

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> data[i][j];
        }
    }

    string k = "";
    makePath(data, 1, 1, k);
    cout << "DONE";
};