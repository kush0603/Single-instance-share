#include<iostream>
#include<map>
#include<math.h>
#include<string.h>
using namespace std;
int q[30001];
map<int,int> val;

int find(int z,int n,int d)
{
	cout<<z<<"  "<<n<<" "<<d<<"\n";
	if(z==0 || z==d)
	return 0;
	if(n>=z)
	return q[n];
	else
	{
	int a,b,c;
	int x,y,l;
	if(d>0)	
	x=find(z,n+d,d)+q[a];
	if(d>1)
 	y=find(z,n+d-1,d-1)+q[b];
 	if(d>0)
    l=find(z,n+d+1,d+1)+q[c];
/*
	if(x<a)
	x = a;
	if(y<b)
	y = b;
	if(z<c)
	z = c;
*/
  //cout<<"maximum is  "<<max(x,max(y,l))<<"\n";
	return max(x,max(y,l));
	
}
}

int main()
{
	 memset(q,sizeof q,0);
        int n;
		int d;
        cin>>n;
        cin>>d;
        int k;
        for(int i=0;i<n;i++)
        {
        	cin>>k;
        	q[k]++;
		}
		long long t = q[d]+find(k,d,d);
		cout<<t;
	}
