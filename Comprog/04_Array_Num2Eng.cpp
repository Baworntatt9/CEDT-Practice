#include <iostream>
#include <string>
using namespace std;

int main() {
    string single[] = { "zero",    "one",       "two",      "three",
                       "four",    "five",      "six",      "seven",
                       "eight",   "nine",      "ten",      "eleven",
                       "twelve",  "thirteen",  "fourteen", "fifteen",
                       "sixteen", "seventeen", "eighteen", "nineteen" };
    string ten[] = { "twenty", "thirty",  "forty",  "fifty",
                    "sixty",  "seventy", "eighty", "ninety" };
    string base[] = { "hundred", "thousand", "million", "billion", "trillion" };

    string input;
    cin >> input;

    int nofull = input.length() % 3;
    int full = input.length() / 3;

    if (nofull == 1) {
        input.insert(0, 2, '0');
    }
    else if (nofull == 2) {
        input.insert(0, 1, '0');
    }

    string keepfull = "";
    nofull = 0;
    int a = (input.length() - 1) / 3;

    for (int i = 0; i < input.length() / 3; i++) {
        bool allzero = false;

        if (input[nofull] != '0') {
            keepfull += single[input[nofull] - '0'] + " " + base[0] + " ";
            if (input[nofull + 1] != '0') {
                if (input[nofull + 1] == '1') {
                    keepfull += single[stoi(input.substr(nofull + 1, 2))] + " ";
                }
                else {
                    keepfull += ten[input[nofull + 1] - '0' - 2] + " ";
                    if (input[nofull + 2] != '0') {
                        keepfull += single[input[nofull + 2] - '0'] + " ";
                    }
                }
            }
            else {
                keepfull += single[input[nofull + 2] - '0'];
            }
        }
        else if (input[nofull] == '0' && input[nofull + 1] != '0') {
            if (input[nofull + 1] == '1') {
                keepfull += single[stoi(input.substr(nofull + 1, 2))] + " ";
            }
            else {
                keepfull += ten[input[nofull + 1] - '0' - 2] + " ";
                if (input[nofull + 2] != '0') {
                    keepfull += single[input[nofull + 2] - '0'] + " ";
                }
            }
        }
        else if (input[nofull] == '0' && input[nofull + 1] == '0') {
            if (input[nofull + 2] != '0') {
                keepfull += single[input[nofull + 2] - '0'] + " ";
            }
            else {
                allzero = true;
                if (i == 0) {
                    keepfull += single[0];
                }
            }
        }
        if (i != input.length() / 3 - 1 && allzero == false) {
            keepfull += base[a] + " ";
        }

        a--;
        nofull += 3;
    }

    cout << keepfull;
}
