#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) 
{   
	vector<int> dist(V, 1e8);
	dist[src] = 0;
	for (int i = 0; i < V; i++) 
    {
		for (vector<int> edge : edges) 
        {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) 
            {
                if(i == V - 1)
                    return {-1};
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
}
int main()
{
    int v;
    cin>>v;
    vector<vector<int>>G;
    int e;
    cin>>e;
    int u,v1,w;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v1>>w;
        G.push_back({u,v1,w});
    }
    vector<int> v2=bellmanFord(v,G,0);
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<"  ";
    }
};
