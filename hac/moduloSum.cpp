#include<iostream>
#include<set>
#include <cstring>
#include<cmath>

using namespace std;
int main()
{
  long long int n;
  int k;
  cin>>n;
  cin>>k;
 int  a[k];
  int  b[k];
  
  for(int y=0;y<k;y++)
  {
  	a[y]=0;
  	b[y]=0;
  }
  int t,q=0;
  for(int i=0;i<n;i++)
  {
  	 cin>>t;
  	 b[t%k]=1;
  	 for(int j=0;j<k;j++)
  	 {
  	 	if(a[j]==1)
  	 	{
  	 		//cout<<"a mai one mila  "<<j<<"  "<<t<<"  "<<(j+t)%k<<"\n";
  	 		b[(j+t)%k] = 1;
  	 		//cout<<b[2]<<"\n";
		   }
  	 	
	 if(j!=t%k && b[j]!=1)
		        b[j] = a[j];
	    if(b[0]==1)
	    {
		cout<<"YES";
		q =1;
		break;
		}	 
	}
	
	if(q==1)
	break;
	memcpy(a,b,sizeof a);
	memset(b,0,sizeof b);
 }	 
 if(q==0)
 cout<<"NO";
}
