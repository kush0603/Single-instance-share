#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n;
	cin>>n;
	stack<long long> k;
	long long max=0,a,ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(k.empty())
		k.push(a);
		else if(k.top()>a)
		{
//			cout<<a<<"  "<<k.top()<<"\n";
			max = a^k.top();
			if(max>ans)
			ans = a^k.top();
//			cout<<"ans is  "<<ans<<"\n"; 
			k.push(a);
		}
		else
		{
			while(k.top()<a && !k.empty())
			{
				
//				cout<<"pop karu  "<<a<<"  "<<k.top()<<"\n";
				max = a^k.top();
				if(max>ans)
				ans = a^k.top();
			     k.pop();
//			    cout<<"ans is  "<<ans<<"\n"; 
			     if(k.empty())
			     break;
			}
			if(!k.empty())
			{
			    max = a^k.top();
				if(max>ans)
				ans = a^k.top();
				
			}
			k.push(a);
		
		}
	}
	if(!k.empty())
	{
		a= k.top();
		k.pop();
	}
	
	while(!k.empty())
	{
//		cout<<"baad waale  "<<a<<"  "<<k.top()<<"\n";
		max = a^k.top();
		if(max>ans)
		ans = a^k.top();
//		cout<<"ans is  "<<ans<<"\n"; 
	     a = k.top();
	     k.pop();
	}
	cout<<ans;
}
