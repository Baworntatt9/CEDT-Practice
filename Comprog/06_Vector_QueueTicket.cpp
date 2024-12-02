#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double avg(vector<int> block) {
    double avg = 0.0;

    for (auto a : block) {
        avg += a;
    }

    avg /= block.size();
    avg = round(avg * 100.0) / 100.0;

    return avg;
}

int main() {
    int num;
    cin >> num;

    vector<pair<string, int>> data;

    string status;
    int num2;

    for (int i = 0; i < num; i++) {
        cin >> status;
        if (status == "next" || status == "avg_qtime")
            data.push_back({ status, -1 });
        else {
            cin >> num2;
            data.push_back({ status, num2 });
        }
    }

    int n = data[0].second;
    int nfirst = n;

    vector<pair<int, int>> time;
    vector<int> extime;

    for (int i = 1; i < num; i++) {
        if (data[i].first == "new") {
            cout << ">> ticket " << n << endl;
            time.push_back({ n, data[i].second });
            n += 1;
        }

        if (data[i].first == "next") {
            cout << ">> call " << nfirst << endl;
            nfirst += 1;
        }

        if (data[i].first == "order") {
            int dif = 0;
            for (auto& a : time) {
                if (a.first == nfirst - 1) {
                    dif = data[i].second - a.second;
                    extime.push_back(dif);
                }
            }
            cout << ">> qtime " << nfirst - 1 << " " << dif << endl;
        }

        if (data[i].first == "avg_qtime") {
            cout << ">> avg_qtime " << avg(extime) << endl;
        }
    }
}
