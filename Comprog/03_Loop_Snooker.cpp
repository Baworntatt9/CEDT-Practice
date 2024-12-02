#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int a;

    cin >> a;
    cin.ignore();

    for (int i = 1; i <= a; i++) {
        string line;
        vector<char> score;
        bool check = 0;
        bool check2 = 0;

        int count = 0;

        getline(cin, line);

        while (count < line.size()) {
            int ss = 0;

            if (line[count] != 'R' || check2 == 1) {
                cout << "WRONG_INPUT" << endl;
                check = 1;
                break;
            }
            else if (line[count] == 'R') {
                score.push_back('R');
                ss += 2;
                if (count + 2 < line.size() && line[count + 2] != 'R') {
                    score.push_back(line[count + 2]);
                    ss += 2;
                    if (count + 4 < line.size() && line[count + 4] == 'Y') {
                        score.push_back('Y');
                        ss += 2;
                        check2 = 1;
                        if (count + 6 < line.size() && line[count + 6] == 'G') {
                            score.push_back('G');
                            ss += 2;
                            if (count + 8 < line.size() &&
                                line[count + 8] == 'N') {
                                score.push_back('N');
                                ss += 2;
                                if (count + 10 < line.size() &&
                                    line[count + 10] == 'B') {
                                    score.push_back('B');
                                    ss += 2;
                                    if (count + 12 < line.size() &&
                                        line[count + 12] == 'P') {
                                        score.push_back('P');
                                        ss += 2;
                                        if (count + 14 < line.size() &&
                                            line[count + 14] == 'K') {
                                            score.push_back('K');
                                            ss += 2;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else if (count + 2 < line.size() && line[count + 2] == 'R') {
                    cout << "WRONG_INPUT" << endl;
                    check = 1;
                    break;
                }
            }

            count += ss;
        }

        if (!score.empty() && check != 1) {
            int sum = 0;
            for (int i = 0; i < score.size(); i++) {
                if (score[i] == 'R') {
                    sum += 1;
                }
                if (score[i] == 'Y') {
                    sum += 2;
                }
                if (score[i] == 'G') {
                    sum += 3;
                }
                if (score[i] == 'N') {
                    sum += 4;
                }
                if (score[i] == 'B') {
                    sum += 5;
                }
                if (score[i] == 'P') {
                    sum += 6;
                }
                if (score[i] == 'K') {
                    sum += 7;
                }
            }
            cout << sum << endl;
        }
    }
}
