#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> firstlineintable;

    for (int i = 1; i <= 5; i++) {
        string first;
        cin >> first;
        firstlineintable.push_back(first);
    }

    vector<vector<string>> alllineintable;
    alllineintable.push_back(firstlineintable);

    string gettable;

    for (int i = 1; i <= 5; i++) {
        vector<string> anotherlineintable;

        for (int i = 1; i <= 5; i++) {
            cin >> gettable;
            anotherlineintable.push_back(gettable);
        }
        alllineintable.push_back(anotherlineintable);
    }
    //
    int check[5][5] = { 0 };
    check[2][2] = 1; // เปลี่ยนกลางให้เป็น 1

    string data;
    bool bingo = false;
    int allcount = 0;
    bool allcountcheck = false;
    while (bingo == false && cin >> data) {
        allcount += 1;
        int let;
        for (int i = 0; i < 5; i++) {
            if (string(1, data[0]) == alllineintable[0][i]) {
                let = i;
                break;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (alllineintable[i + 1][let] == data.substr(1))
                check[i][let] = 1;
        }

        for (int i = 0; i < 5; i++) { // นอน
            int count = 0;
            if (check[i][0] == 1) {
                count += 1;
                for (int j = 1; j < 5; j++) {
                    if (check[i][j] == 1) {
                        count += 1;
                        if (count == 5) {
                            cout << allcount << endl;
                            allcountcheck = true;
                            for (int k = 0; k < 5; k++) {
                                if (k == 4) {
                                    cout << alllineintable[0][k] +
                                        alllineintable[i + 1][k]
                                        << endl;
                                    bingo = true; // เป็นแนวแรกเลยไม่ต้อง if
                                    break;
                                }
                                if (i != 2 || k != 2)
                                    cout << alllineintable[0][k] +
                                    alllineintable[i + 1][k]
                                    << ", ";
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < 5; i++) { // ตั้ง
            int count = 0;
            if (check[0][i] == 1) {
                count += 1;
                for (int j = 1; j < 5; j++) {
                    if (check[j][i] == 1) {
                        count += 1;
                        if (count == 5) {
                            if (allcountcheck == false) {
                                cout << allcount << endl;
                            }
                            allcountcheck = true;
                            for (int k = 0; k < 5; k++) {
                                if (k == 4) {
                                    cout << alllineintable[0][i] +
                                        alllineintable[k + 1][i]
                                        << endl;
                                    bingo = true;
                                    break;
                                }
                                if (i != 2 || k != 2) {
                                    cout << alllineintable[0][i] +
                                        alllineintable[k + 1][i]
                                        << ", ";
                                }
                            }
                        }
                    }
                }
            }
        }
        // เฉียง
        if (check[0][0] == 1) {
            int count = 0;
            count += 1;
            for (int i = 1; i < 5; i++) {
                if (check[i][i] == 1) {
                    count += 1;
                    if (count == 5) {
                        if (allcountcheck == false) {
                            cout << allcount << endl;
                        }
                        allcountcheck = true;
                        for (int j = 0; j < 5; j++) {
                            if (j == 4) {
                                cout << alllineintable[0][j] +
                                    alllineintable[j + 1][j]
                                    << endl;
                                bingo = true;
                                break;
                            }
                            if (j != 2) {
                                cout << alllineintable[0][j] +
                                    alllineintable[j + 1][j]
                                    << ", ";
                            }
                        }
                    }
                }
            }
        }
        // เฉียง
        if (check[4][0] == 1) {
            int count = 0;
            count += 1;
            for (int i = 3, j = 1; j < 5; i--, j++) {
                if (check[i][j] == 1) {
                    count += 1;
                    if (count == 5) {
                        if (allcountcheck == false) {
                            cout << allcount << endl;
                        }
                        allcountcheck = true;
                        for (int k = 4, m = 0; k < 5; k--, m++) {
                            if (m == 4) {
                                cout << alllineintable[0][m] +
                                    alllineintable[k + 1][m]
                                    << endl;
                                bingo = true;
                                break;
                            }
                            if (m != 2) {
                                cout << alllineintable[0][m] +
                                    alllineintable[k + 1][m]
                                    << ", ";
                            }
                        }
                    }
                }
            }
        }
    }
}
