#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int f, w, n;
    cin >> f >> w >> n;

    vector<int> food_positions(f);
    for (int i = 0; i < f; ++i) {
        cin >> food_positions[i];
    }

    sort(food_positions.begin(), food_positions.end());

    int lights = 0;
    int covered_until = 0;

    int i = 0;
    while (i < f) {
        if (food_positions[i] <= covered_until) {
            ++i;
            continue;
        }

        int light_position = food_positions[i] + w;
        covered_until = light_position + w;

        ++lights;
        ++i;
    }

    cout << lights << endl;
}
