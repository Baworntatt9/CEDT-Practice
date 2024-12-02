#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int findmaxpercase(vector<int> line) {
    int n = line.size();
    int maxallcase = 0;
    for (int i = 0; i < n; i++) {
        int maxbycase = 0;
        for (int j = i; j < i + n; j++) {
            int ocurrent =
                line[j % n]; // ตน.นั้น mod จน.ทั้งหมด (ถ้า j เกิน n ไปก็จะกลับมา 0 ใหม่)
            int onext = line[(j + 1) % n];

            maxbycase += ocurrent;
            if (ocurrent > onext) {
                break;
            }
        }
        maxallcase = max(maxbycase, maxallcase);
    }

    return maxallcase;
}

int maxsamatiall(vector<int> line) {
    int maxwithoutcut1 = findmaxpercase(line);

    int n = line.size();
    int maxwithcut1 = 0;
    for (int i = 0; i < n; i++) {
        vector<int> tem = line;
        tem.erase(tem.begin() + i);
        int M = findmaxpercase(tem);
        maxwithcut1 = max(maxwithcut1, M);
    }

    int MMM = max(maxwithoutcut1, maxwithcut1);
    return MMM;
}

int main() {
    int a;
    cin >> a;

    vector<int> data;

    for (int i = 0; i < a; i++) {
        int b;
        cin >> b;
        data.push_back(b);
    }

    cout << maxsamatiall(data);
}
