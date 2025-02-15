#include <iostream>
#include<vector>
#include<algorithm>
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
	int target,i=0;
	cin>>target;
	int c=0;
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++)
	{
	int f=0;
		for(int j=i;j<n;j++)
		{
			if(v[j]-v[i]==target)
			f++;
		}
		if(f>0)
		c++;
	}
	cout<<c;
	t--;
	}
}
