#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<queue>
#include <algorithm>
using namespace std;


int main()
{
  int n;
  cin>>n;
  int p=0;
 // queue<long long int>distance;
  queue<long long int>amount;
  for(long long int i=0;i<n;i++)
   {
     long long int d,a;
      cin>>a;
      cin>>d;
      amount.push(a-d);
    }
    
    long long int t=0,am=0,k=0;
    while(t!=n+1 && !amount.empty())
    {
        am = am+amount.front();
        amount.pop();
        //cout<<am<<" "<<t<<"   "<<k<<"\n";
      if(am>=0 && k==0)
          k=t;
      if(am<0)
      {
      	k = 0;
      	am=0;
      	
	  }
       
      t++;
    }
    cout<<k;
}

