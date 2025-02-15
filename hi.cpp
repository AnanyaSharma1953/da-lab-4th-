#include <iostream>
#include<vector>
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
	int target,mid=0,mid1=0,i=0;
	cin>>target;
	for (i=0; i<n; i++){
            if (v[i] == target){
                mid = i;
                break;
            }
        }
		if(i!=n){
        for (int i=n-1; i>=0; i--){
            if (v[i] == target){
                mid1 = i;
                break;
            }
        }
        cout<<target<<"  "<<(mid1-mid);
        }
        else
        	cout<<"not present";
	t--;
	}
}
