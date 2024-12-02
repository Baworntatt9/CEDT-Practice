#include <iostream>
#include <string>
using namespace std;

namespace CP {
    template <typename T1, typename T2> class pair {
    public:
        T1 first;
        T2 second;
        bool operator==(const pair<T1, T2>& other) {
            return (first == other.first && second == other.second);
        }
    };
} // namespace CP

int main() {
    CP::pair<int, int> p1, p2;
    p1.first = 20;
    p1.second = 20;

    p2 = p1;

    cout << (p2 == p1 ? "true" : "false");
}
