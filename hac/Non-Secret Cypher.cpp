#include<iostream>
#include<map>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	map<int,int> nu;
	map<int,int> count;
	map<int,int>::iterator it;
	int a,max=0;
	if(k==1)
	{
		cout<<n*(n+1)/2;
		return 0;
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(nu.find(a)==nu.end())
		nu[a]=i;
		if(count.find(a)!=count.end())
		{
			
			count[a]++;
			if(count[a]>=k)
			{
				max = max+(n-i)*(nu[a]);
				cout<<a<<" "<<n-i<<"  "<<nu[a]<<"\n";
			}
			
		}
		else
		count[a] = 1;
	}
	
	for(it =nu.begin();it!=nu.end();++it)
	  cout<<it->first<<" "<<it->second<<"\n";
	cout<<max;
}
