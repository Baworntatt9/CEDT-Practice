#include <iostream>
#include <set>
using namespace std;

void makeAnagram(string word, int start, set<string>& data) {
    if (start == word.size() - 1) {
        data.insert(word);
        return;
    }

    for (int i = start; i < word.size(); i++) {
        swap(word[start], word[i]);
        makeAnagram(word, start + 1, data);
        swap(word[start], word[i]);
    }
}

void printAnagram(string word) {
    set<string> data;

    makeAnagram(word, 0, data);

    for (auto k : data) {
        cout << k << " ";
    }
}

int main() {
    string a;
    cin >> a;
    printAnagram(a);
}
