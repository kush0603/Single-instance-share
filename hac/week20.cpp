#include<iostream>
using namespace std;

int main()
{
	int n,k;
	cin>>n;
	cin>>k;
	int sum=0;
	int a[n],m[k];
	for(int i=0;i<k;i++)
	m[i]=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		m[(a[i])%k]++;
	}

	for(int i=1;i<=k/2;i++)
	{
		if(m[i]>m[k-i])
		sum = sum+m[i];
		else
		sum = sum + m[k-i];
	}
	if(m[0]>0)
	sum++;

	cout<<sum;
}
