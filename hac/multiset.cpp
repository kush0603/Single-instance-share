#include <iostream>
#include<set>
using namespace std;

int main()
{
   int test;
   cin>>test;
   while(test--)
   {
   multiset<int> c;
   multiset<int>::iterator it;
   	int n,k;
   	cin>>n;
   	cin>>k;
   	int r;
   	while(n--)
   	{
   		cin>>r;
   		c.insert(r);
   	}
   	
   long long sum=0,f;
   	while(k--)
   	{ 
   	   it = c.end();
       it--;
   	    f = *it;
   		c.erase(*it);
   		if(f==0)
   		break;
   		sum = sum+f;
   		c.insert(f/2);
   		
   	}
   	cout<<sum<<"\n";
   }
}

