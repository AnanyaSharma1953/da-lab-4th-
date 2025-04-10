#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void prims(vector<vector<pair<int,int>>>G,int v)
{
     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int>key(v,INT_MAX);
    vector<int>inMST(v,false);
    vector<int>parent(v,-1);
    key[0]=0;
    pq.push({0,0});
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(inMST[u])
        continue;
        inMST[u]=true;
        for (auto p : G[u]) 
        {
    int v_neigh = p.first;
    int weight = p.second;
            if(!inMST[v_neigh]&&weight+key[u]<key[v_neigh])
            {
                key[v_neigh]=weight+key[u];
                parent[v_neigh]=u;
                pq.push({weight,v_neigh});
            }
        }
    }
    for(int i=1;i<v;i++)
    cout<<parent[i]<<"->"<<i<<"  "<<endl;
}
   
int main()
{
    int v;
    cin>>v;
    vector<vector<pair<int,int>>>G(v);
    int e;
    cin>>e;
    int u,v1,w;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v1>>w;
        G[u].push_back({v1, w});
        G[v1].push_back({u, w});
    }
    prims(G,v);
};
