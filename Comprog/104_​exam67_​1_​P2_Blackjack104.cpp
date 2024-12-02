#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    string arr[10] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
    string arr2[3] = { "J", "Q", "K" };

    string lk1[a];
    string lk2[b];

    // รับไพ่ a
    for (int i = 0; i < a; i++) {
        string m;
        cin >> m;
        lk1[i] = m;
    }

    // รับไพ่ b
    for (int i = 0; i < b; i++) {
        string n;
        cin >> n;
        lk2[i] = n;
    }

    // คำนวณคะแนน a
    int sum1 = 0;
    int aceCount1 = 0; // ตัวนับไพ่ A
    for (int i = 0; i < a; i++) {
        if (lk1[i] == "A") {
            sum1 += 11; // ให้ A มีค่า 11
            aceCount1++;
        }
        else if (lk1[i] == "J" || lk1[i] == "Q" || lk1[i] == "K") {
            sum1 += 10; // ไพ่ J, Q, K มีค่า 10
        }
        else {
            sum1 += stoi(lk1[i]); // ไพ่ตัวเลขตามหน้าไพ่
        }
    }

    // ปรับค่า A ถ้าคะแนนเกิน 21
    while (sum1 > 21 && aceCount1 > 0) {
        sum1 -= 10; // ปรับ A จาก 11 เป็น 1
        aceCount1--;
    }

    // คำนวณคะแนน b
    int sum2 = 0;
    int aceCount2 = 0; // ตัวนับไพ่ A
    for (int i = 0; i < b; i++) {
        if (lk2[i] == "A") {
            sum2 += 11; // ให้ A มีค่า 11
            aceCount2++;
        }
        else if (lk2[i] == "J" || lk2[i] == "Q" || lk2[i] == "K") {
            sum2 += 10; // ไพ่ J, Q, K มีค่า 10
        }
        else {
            sum2 += stoi(lk2[i]); // ไพ่ตัวเลขตามหน้าไพ่
        }
    }

    // ปรับค่า A ถ้าคะแนนเกิน 21
    while (sum2 > 21 && aceCount2 > 0) {
        sum2 -= 10; // ปรับ A จาก 11 เป็น 1
        aceCount2--;
    }

    if (sum1 > 21 && sum2 > 21) {
        cout << "Draw" << endl;
    }
    else if (sum1 > 21) {
        cout << "B" << endl;
    }
    else if (sum2 > 21) {
        cout << "A" << endl;
    }
    else if (sum1 > sum2) {
        cout << "A" << endl;
    }
    else if (sum2 > sum1) {
        cout << "B" << endl;
    }
    else {
        cout << "Draw" << endl;
    }

    cout << sum1 << " " << sum2 << endl;

    // *** บวก 11 ไปก่อนเลยแล้วค่อยมาลด
}
