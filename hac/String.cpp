#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		int d;
		cin>>s;
		cin>>d;
		int i=0;
		int count=0;
		while(count<d)
		{
		
		while(i<s.length()-2)
		{
			if(s[i]>s[i+1])
			i++;
			else
			break;
		}
		int k=0;
		while(s[i+1]>=s[i-k])
		{
			k = k+1;
			count++;
			if(count==d)
			break;
			if(i-k<0)
			break;
			
		}
		if(k>0)
		{
			s = s.erase(i-k,i+1);
		}
		else
		s = s.erase(i);
	}
	cout<<s<<"\n";
}
}
