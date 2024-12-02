#include <iostream>
using namespace std;

int lowest(int arr[], int count) {
    int indexmin = count - 1; // เริ่มจากมากสุดเพื่อทำให้เลขลิฟน้อยสุดในกรณีที่มีค่าน้อยสุดเท่ากัน
    for (int i = count - 2; i >= 0; i--) {
        if (arr[i] <= arr[indexmin]) {
            indexmin = i;
        }
    }
    return indexmin;
}

int main() {
    int countlift;
    cin >> countlift;

    int statuslift[countlift][3];
    int inputstatus;

    for (int i = 0; i < countlift; i++) { // รับข้อมูล lift
        for (int j = 0; j < 3; j++) {
            cin >> inputstatus;
            statuslift[i][j] = inputstatus;
        }
    }

    int countquestion;
    cin >> countquestion;

    int statusquestion[countquestion][2];
    int inputstatus2;

    for (int i = 0; i < countquestion; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> inputstatus2;
            statusquestion[i][j] = inputstatus2;
        }
    }

    for (int i = 0; i < countquestion; i++) {
        int keepperquestion[countlift];

        for (int j = 0; j < countlift; j++) {
            int para;
            // เช็คทางผ่าน
            if (statusquestion[i][0] > statusquestion[i][1] &&
                statuslift[j][1] > statuslift[j][2] &&
                statuslift[j][1] >= statusquestion[i][0]) { // up to down
                para = statuslift[j][2] - statusquestion[i][1];
                if (para <= 0) {
                    para = 0; // คุ้มสุด
                }
            }
            else if (statusquestion[i][0] < statusquestion[i][1] &&
                statuslift[j][1] < statuslift[j][2] &&
                statuslift[j][1] <= statusquestion[i][0]) { // down to up
                para = statusquestion[i][1] - statuslift[j][2];
                if (para <= 0) {
                    para = 0; // คุ้มสุด
                }
            }
            else { // เช็คทั่วไป
                para = abs(statuslift[j][2] - statusquestion[i][0]) +
                    abs(statusquestion[i][1] - statusquestion[i][0]);
            }

            keepperquestion[statuslift[j][0] - 1] = para;
        }

        cout << ">> " << lowest(keepperquestion, countlift) + 1
            << endl; // น้อยสุดคือ 0 ต้องบวก 1
    }
}
