#include<iostream>
#include<map>
#include<math.h>
using namespace std;

map<int,int> val;

long long int find(long long int n)
{
	if(val.find(n)!=val.end())
	return  val[n];
	long long int a = n/2;
 	long long int b = n/3;
	long long int c = n/4;
	
	if(n==1)
	return 1;
	if(n==0)
	return 0;
  long long int x=find(a);
	long long int y=find(b);
	long long int z=find(c);
/*
	if(x<a)
	x = a;
	if(y<b)
	y = b;
	if(z<c)
	z = c;
*/
	val[a] = x;
	val[b] = y;
	val[c]=z;
	if(n>a+b+c)
	return n;
	
	return x+y+z;
	
	
}

int main()
{
        int n;
		

	while(cin>>n)
	{
		
		long long t =find(n);
		val[n] = t;
		cout<<t<<"\n";	
	}
}
