#include <iostream>
using namespace std;

int findmax(int arr[][3], int num) {
    int maxvalue = 0;
    for (int i = 0; i < num; i++) {
        if (arr[i][0] > maxvalue) {
            maxvalue = arr[i][0];
        }
    }
    return maxvalue;
}

int overlapping(int arr[], int arr2[]) {
    int lengthl = max(arr[0], arr2[0]);
    int lengthr = min(arr[2], arr2[2]);
    int heightu = min(arr[3], arr2[3]);
    int heightd = max(arr[1], arr2[1]);
    int length = (lengthr)-(lengthl);
    int height = (heightu)-(heightd);

    if (length < 0 || height < 0) {
        return 0;
    }
    else {
        return length * height;
    }
}

int main() {
    int num;
    cin >> num;

    int data[num][4];

    int point;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> point;
            data[i][j] = point;
        }
    }

    // ความเป็นไปได้
    int sum = 0;
    for (int i = 1; i < num; i++) {
        sum += i;
    }

    int area[sum][3];
    int count = 0;
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            area[count][0] = overlapping(data[i], data[j]);
            area[count][1] = i;
            area[count][2] = j;
            count += 1;
        }
    }

    int valuemax = findmax(area, sum);
    if (valuemax == 0) {
        cout << "No overlaps";
    }
    else {
        cout << "Max overlapping area = " << valuemax << endl;
        for (int i = 0; i < sum; i++) {
            if (area[i][0] == valuemax) {
                cout << "rectangles " << area[i][1] << " and " << area[i][2]
                    << endl;
            }
        }
    }
}
