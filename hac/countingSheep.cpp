#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int test,t=1;
	cin>>test;
	while(t<=test)
	{
	long long  n,nu;
	cin>>n;
	if(n==0)
	{
		cout<<"Case #"<<t<<": "<<"INSOMNIA"<<"\n";
		t++;
		continue;
	}
	
	nu = n;
	int c[10];
	memset(c,0,sizeof c);
	while(n>0)
	{
		c[n%10]++;
		n = n/10;
	}
	long long k=2;
	while(1)
	{
		n = nu*k;
	 while(n>0)
	{
		c[n%10]++;
		n = n/10;
	}
	 k++;
	int t;
//	 cout<<"values are\n";
	 for(t=0;t<10;t++)
	 {
//	 	cout<<t<<" "<<c[t]<<" ";
	 	if(c[t]==0)
	 	break;
	 }
//	 cout<<"\n";
	 if(t==10)
	 break;
   }
//   cout<<"kitna multipy karna hai   "<<carry<<"\n";
   cout<<"Case #"<<t<<": "<<(k-1)*nu<<"\n";
   t++;
}
}
