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
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }
        int key=0,f=0;
        cin>>key;
        sort(v.begin(),v.end());
        int l=0,r=v.size()-1;
        while(l<r)
        {
        int mid=(l+r)/2;
        if(v[l]+v[r]<key)
        {
        l++;
        }
        else if(v[l]+v[r]>key)
            r--;
         else
         {
         f=1;
         cout<<v[l]<<" "<<v[r]<<endl;
         break;
         }
        }
        if(f==0)
        cout<<"not found";
        
        t--;
    }
    return 1;
}
