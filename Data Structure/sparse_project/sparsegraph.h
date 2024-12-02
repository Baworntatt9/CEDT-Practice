#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

#include <set>
#include <vector>
using namespace std;

class SparseGraph {
  public:
    SparseGraph() {
        n = 3;
        data.resize(3);
    }

    SparseGraph(int n_in) {
        n = n_in;
        data.resize(n_in);
    }

    SparseGraph(const SparseGraph &G) {
        n = G.n;
        data = G.data;
    }

    void AddEdge(int a, int b) {
        if (!DoesEdgeExist(a, b)) {
            data[a].insert(b);
        }
    }

    void RemoveEdge(int a, int b) {
        if (DoesEdgeExist(a, b)) {
            data[a].erase(b);
        }
    }

    bool DoesEdgeExist(int a, int b) const {
        if (data[a].find(b) != data[a].end()) {
            return true;
        }
        return false;
    }

    SparseGraph Transpose() const {
        SparseGraph result(n);

        for (int i = 0; i < n; i++) {
            for (auto &k : data[i]) {
                result.AddEdge(k, i);
            }
        }

        return result;
    }

  protected:
    long long n;
    vector<set<int>> data;
};
#endif // __SPARSE_GRAPH_H__
