#include<iostream>
#include<vector>
#include<algorithm>
//q1
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t!=0)
    {
        int n;
        cin>>n;
        vector<char>v;
        for(int i=0;i<n;i++)
        {
            char x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int a[26];
        for(int i=0;i<26;i++)
        {a[i]=0;
        }
        for(int i=0;i<v.size();i++)
        {
            int x=(int)(v[i])-97;
            a[x]=a[x]+1;
        }
        int m=a[0],x=0,f1=0;
        char in;
        for(int i=0;i<26;i++)
        {
        if(a[i]==1)
        x++;
        if(m<a[i])
        {
        in=(char)(i+97);
        f1=1;
        m=a[i];
        }
        }
        if(x==v.size())
        cout<<-1<<endl;
        else
        cout<<in<<m<<endl;
       
        t--;
    }
    return 1;
}
