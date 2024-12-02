#include <iostream>
using namespace std;

int lowest(int arr[], int count) {
    int indexmin = count - 1; // ������ҡ�ҡ�ش���ͷ�����Ţ�Կ�����ش㹡óշ���դ�ҹ����ش��ҡѹ
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

    for (int i = 0; i < countlift; i++) { // �Ѻ������ lift
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
            // �礷ҧ��ҹ
            if (statusquestion[i][0] > statusquestion[i][1] &&
                statuslift[j][1] > statuslift[j][2] &&
                statuslift[j][1] >= statusquestion[i][0]) { // up to down
                para = statuslift[j][2] - statusquestion[i][1];
                if (para <= 0) {
                    para = 0; // �����ش
                }
            }
            else if (statusquestion[i][0] < statusquestion[i][1] &&
                statuslift[j][1] < statuslift[j][2] &&
                statuslift[j][1] <= statusquestion[i][0]) { // down to up
                para = statusquestion[i][1] - statuslift[j][2];
                if (para <= 0) {
                    para = 0; // �����ش
                }
            }
            else { // �礷����
                para = abs(statuslift[j][2] - statusquestion[i][0]) +
                    abs(statusquestion[i][1] - statusquestion[i][0]);
            }

            keepperquestion[statuslift[j][0] - 1] = para;
        }

        cout << ">> " << lowest(keepperquestion, countlift) + 1
            << endl; // �����ش��� 0 ��ͧ�ǡ 1
    }
}
