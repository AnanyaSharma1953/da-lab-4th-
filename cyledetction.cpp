#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    vector<int> parent;
public:
    UnionFind(int size) {
        parent.resize(size);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]); 
        return parent[i];
    }

    bool unionf(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv)
            return false; 
        parent[pv] = pu;
        return true;
    }
};

int main() {
    int nodes = 5;
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(1, 3));
    UnionFind uf(nodes);
    for (size_t i = 0; i < edges.size(); i++) 
    {
        int u = edges[i].first;
        int v = edges[i].second;
        if (!uf.unionf(u, v)) 
        {
            cout << "Cycle detected when adding edge: " << u << " - " << v << endl;
            return 0;
        }
    }
    cout << "No cycle detected in the graph." << endl;
    return 0;
}
