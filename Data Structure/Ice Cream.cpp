#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, start;
    cin >> n >> m >> start;

    vector<int> q(100001, 0);

    while (n--) {
        int a, x;
        cin >> a >> x;
        q[a] = x;
    }

    q[0] = start;
    int money = start;
    for (int i = 1; i <= 100000; ++i) {
        if (q[i] != 0) {
            money = q[i];
        }
        q[i] = q[i - 1] + money; // เงินรวมแต่ละวัน
    }

    while (m--) {
        int P, x;
        cin >> P >> x;

        int ans = P + q[x]; // เหมือนโดนหลอกแล้วต้องเริ่มใหม่
        if (P <= q[x]) {    // เงินถึงก่อนโดนหลอก
            ans = P;
        }

        int pos = lower_bound(q.begin(), q.end(), ans) - q.begin();
        cout << pos << " ";
    }
}
