#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

#include <map>
#include <vector>
using namespace std;
class DenseGraph {
  public:
    DenseGraph() { // default constructor
        n = 3;
        data.resize(3, std::vector<bool>(3, false));
    }

    DenseGraph(int n_in) {
        n = n_in;
        data.resize(n, std::vector<bool>(n, false));
    }

    DenseGraph(const DenseGraph &G) { // copy constructor
        n = G.n;
        data = G.data;
    }

    void AddEdge(int a, int b) { data[a][b] = true; }

    void RemoveEdge(int a, int b) { data[a][b] = false; }

    bool DoesEdgeExist(int a, int b) const {
        if (data[a][b])
            return true;
        return false;
    }

    DenseGraph Transpose() const {
        DenseGraph temp(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                temp.data[i][j] = data[j][i];
            }
        }

        return temp;
    }

  protected:
    int n;
    vector<vector<bool>> data; // จะมีขนาดเป็นจำนวน node * จำนวน node เสมอ
};
#endif // __DENSE_GRAPH_H__
