#include <iostream>
#include <vector>
using namespace std;

void generateBarcodes(int pos, int A, int B, int ones, string& barcode,
    vector<string>& result) {
    if (pos == B) {
        if (ones == A) {
            result.push_back(barcode);
        }
        return;
    }

    barcode[pos] = '0';
    generateBarcodes(pos + 1, A, B, ones, barcode, result);

    if (ones < A) {
        barcode[pos] = '1';
        generateBarcodes(pos + 1, A, B, ones + 1, barcode, result);
    }
}

int main() {
    int A, B;
    cin >> A >> B;

    vector<string> result;
    string barcode(B, '0');

    generateBarcodes(0, A, B, 0, barcode, result);

    for (const auto& code : result) {
        cout << code << endl;
    }
}
