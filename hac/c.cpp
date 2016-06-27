#include <iostream>
#include<queue>
using namespace std;

int main()
{
   int test;
   cin>>test;
   while(test--)
   {
   	priority_queue<int> c;
   	long long int n,k;
   	scanf("%lld",&n);
   	scanf("%lld",&k);
   	long long int r;
   	while(n--)
   	{
   		scanf("%lld",&r);
   		c.push(r);
   	}
   long long sum=0,f;
   	while(k--)
   	{ 
   		f = c.top();
   		if(f==0)
   		break;
   		c.pop();
   		sum = sum+f;
   		c.push(f/2);
   		
   	}
   printf("%d\n",sum);
   }
}

