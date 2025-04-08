#include <iostream>
#include <algorithm>
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
    vector<pair<int,pair<int,int>>> kruskals(vector<pair<int,pair<int,int>>> G,int e,int v)
    {
        vector<pair<int,pair<int,int>>> sol;
        sort(G.begin(),G.end());
        vector<int>parent(v);
        for(int i=0;i<v;i++)
        parent[i]=i;
        for(int i=0;i<e;i++)
        {
            int w=G[i].first,s=G[i].second.first,d=G[i].second.second;
            if(find(s)!=find(d))
            {
                sol.push_back(G[i]);
                unionf(s,d);
            }
        }
        return sol;
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
    UnionFind uf(6);
    int nodes = 5;
    vector<pair<int,pair<int,int>>> edges;
    edges.push_back(make_pair(1,make_pair(0,1)));
    edges.push_back(make_pair(2,make_pair(1,2)));
    edges.push_back(make_pair(3,make_pair(2,3)));
    edges.push_back(make_pair(4,make_pair(3,4)));
    edges.push_back(make_pair(5,make_pair(0,2)));
    edges.push_back(make_pair(6,make_pair(1,3)));
    vector<pair<int,pair<int,int>>> v=uf.kruskals(edges,6,4);
    int w=0;
    for(int i=0;i<v.size()-1;i++)
    {
        w+=v[i].first;
        cout<<v[i].second.first<<"->";
    }
    cout<<v[v.size()-2].second.second<<endl;
    cout<<"weight-"<<w;
    
    return 0;
}
