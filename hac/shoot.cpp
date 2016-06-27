#include<iostream>
#include<set>
#include<cmath>
using namespace std;
int main()
{
	int n,x0,y0;
	cin>>n>>x0>>y0;
	set<double> s;
	int  x,y;
	double slope;
	for(int i=0;i<n;i++)
	{

		cin>>x>>y;
		if((x-x0)!=0)
		slope=(y-y0)/(x-x0);
		else
		slope=99999;
		s.insert(slope);
		
	}
	int size1=s.size();
	cout<<size1;
	
	
	return 0;
}
