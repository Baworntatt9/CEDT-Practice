#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<pair<long long, long long>> data;

    long long s1, s2, s3;
    long long a, b, c;
    cin >> s1 >> a >> s2 >> b >> s3 >> c;

    data.push_back({ s1, a });
    data.push_back({ s2, b });
    data.push_back({ s3, c });

    for (int i = 0; i < 100; i++) {
        // คำนวณ index ของถังที่จะเทออกและถังที่จะรับนม
        int from = i % 3;
        int to = (i + 1) % 3;

        // คำนวณปริมาณนมที่จะเท
        long long transfer =
            min(data[from].second, data[to].first - data[to].second);
        data[from].second -= transfer;
        data[to].second += transfer;
    }

    cout << data[0].second << endl;
    cout << data[1].second << endl;
    cout << data[2].second << endl;
}
