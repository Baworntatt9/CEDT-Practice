#include <iostream>
#include <string>
using namespace std;

void encode(string fake, string data, string arr[]) { // เข้ารหัสนับ , - ด้วย
    string reul;
    for (auto a : data) {
        if (a == '-') {
            reul += arr[10];
        }
        else if (a == ',') {
            reul += arr[11];
        }
        else {
            reul += arr[a - '0'];
        }
    }

    int punct = 0;
    for (auto a : fake) {
        if (ispunct(a)) {
            punct += 1; // 5
        }
    }

    int m = reul.size();
    int n = 1;
    string nfake = fake;
    while (nfake.size() - (punct * n) < m) {
        nfake += fake;
        n += 1;
    } //

    int count = 0;
    int ff = 0;
    for (int i = 0; i < nfake.size(); i++) {
        if (count == reul.size()) {
            break;
        }
        else if (isalpha(nfake[i])) {
            count += 1;
        }
        ff += 1;
    }
    // change lower upper
    string Tfake;
    int count2 = 0;
    for (int i = 0; i < ff; i++) {
        if (reul[count2] == 'U' && !ispunct(nfake[i])) {
            Tfake += toupper(nfake[i]);
            count2 += 1;
        }
        else if (reul[count2] == 'L' && !ispunct(nfake[i])) {
            Tfake += tolower(nfake[i]);
            count2 += 1;
        }
        else if (ispunct(nfake[i])) {
            Tfake += nfake[i];
        }
    }
    cout << Tfake << endl;
}

void decode(string data, string arr[]) { // ถอดรหัส
    string newdata;

    for (int i = 0; i < data.size(); i++) {
        if (!ispunct(data[i]) && data[i] != ' ') {
            newdata += data[i];
        }
    }

    string re;
    string renum;

    for (int i = 0; i < newdata.size(); i++) {
        if (isupper(newdata[i])) {
            re += "U";
        }
        else {
            re += "L";
        }
    }

    for (int i = 0; i < re.size(); i += 4) {
        for (int j = 0; j < 12; j++) {
            if (re.substr(i, 4) == arr[j]) {
                if (j == 10) {
                    renum += "-";
                    break;
                }
                else if (j == 11) {
                    renum += ",";
                    break;
                }
                else {
                    renum += to_string(j);
                    break;
                }
            }
        }
    }
    cout << renum << endl;
}

int main() {
    string arr[12] = { "UUUU", "UUUL", "UULU", "UULL", "ULUU", "ULUL",
                      "ULLU", "ULLL", "LUUU", "LUUL", "LULU", "LULL" };

    string fake;
    getline(cin, fake);

    string type, data;

    while (cin >> type) {
        cin.ignore();
        getline(cin, data);

        if (type == "E") {
            encode(fake, data, arr);
        }
        else {
            decode(data, arr);
        }
    }
}
