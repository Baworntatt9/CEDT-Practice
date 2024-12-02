#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void Union(set<set<int>> block) {
    set<int> Unionset;
    for (auto a : block) {
        for (auto b : a) {
            Unionset.insert(b);
        }
    }

    if (Unionset.empty()) {
        cout << "U: empty set";
    }
    else {
        cout << "U: ";
        for (auto a : Unionset) {
            cout << a << " ";
        }
    }
    cout << endl;
}

void Intersect(set<set<int>> block) {
    set<int> Intersectset;

    for (auto a : block) {
        for (auto b : a) {
            Intersectset.insert(b); // start set
        }
        break;
    }

    block.erase(block.begin());

    for (auto a : block) { // ทีละ 2 interseectset เทียบปัจจุบัน
        set<int> temset;
        for (auto k = a.begin(); k != a.end(); k++) {
            if (Intersectset.find(*k) != Intersectset.end()) {
                temset.insert(*k);
            }
        }
        Intersectset = temset;
    } // ลบตัวซ้ำออกเรื่อยๆ

    if (Intersectset.empty()) {
        cout << "I: empty set";
    }
    else {
        cout << "I: ";
        for (auto a : Intersectset) {
            cout << a << " ";
        }
    }
    cout << endl;
}

void Dif(vector<set<int>> block) {
    set<int> Dif;

    for (auto a : block) {
        for (auto b : a) {
            Dif.insert(b);
        }
        break;
    }

    block.erase(block.begin());

    for (auto a : block) {
        set<int> tem = Dif;
        for (auto b = a.begin(); b != a.end(); b++) {
            if (Dif.find(*b) != Dif.end()) {
                tem.erase(*b);
            }
        }
        Dif = tem;
    }

    if (Dif.empty()) {
        cout << "D: empty set";
    }
    else {
        cout << "D: ";
        for (auto a : Dif) {
            cout << a << " ";
        }
    }
}

int main() {
    string a;

    set<set<int>> AA;
    vector<set<int>> BB;

    while (getline(cin, a)) {
        set<int> b;

        istringstream k(a);
        string g;
        while (k >> g) {
            b.insert(stoi(g));
        }
        AA.insert(b);
        BB.push_back(b);
    }

    Union(AA);
    Intersect(AA);
    Dif(BB);
}
