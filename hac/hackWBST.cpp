#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long  index[n],lft[n],rgt[n];
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==0)
        {
              index[i] = 1;
              lft[i] = 0;
              rgt[i] = 1000000;
         }
        else{
        int j = i-1;
        while(a[i]>rgt[j] || a[i] < lft[j])
            j--;
        if(a[i] > a[j])
        {
           index[i] = (2*index[j]+1)%1000000007;
            rgt[i] = rgt[j];
            rgt[j] = a[i];
            lft[i] = a[j];
        }
        else
        {
            index[i] = (2*index[j])%1000000007;
            lft[i] = lft[j];
            lft[j] = a[i];
            rgt[i] = a[j];
            
        }
        }
        cout<<index[i]<<" "; 
    }
}
