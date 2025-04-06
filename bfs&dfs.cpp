#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;
void bfs(vector <int>G[],int v,int source)
{
    queue<int>q;
    q.push(source);
    vector<bool>visited(v,false);
    visited[source]=true;
    while(!q.empty())
    {
        int vertex=q.front();
        q.pop();
        for(auto i:G[vertex])
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                q.push(i);
            }
        }
        cout<<vertex<<" ";
    }
}
void dfs(vector<int> G[], int v, int source) 
{
    vector<bool> visited(v, false);
    stack<int> st;
    st.push(source);
    visited[source]=true;
    while (!st.empty()) 
    {
        int vertex = st.top();
        st.pop();
        visited[vertex]=true;
        for (auto i :G[vertex]) 
        {
            if (visited[i]==false) 
            {
                visited[i]=true;
                st.push(i);
            }
        }
        cout << vertex << " ";
    }
}
int main()
{
    int v,e;
    cin>>v>>e;
    vector<int>G[v];
    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>>s>>d;
        G[s].push_back(d);
        G[d].push_back(s);
    }
    cout<<"Dfs ";
    dfs(G,v,0);
}


