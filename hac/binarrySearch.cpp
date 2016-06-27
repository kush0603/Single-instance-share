#include <iostream>
#include<algorithm>
using namespace std;


int search(int *a, int s,int e,int f)
{
    int k=0;
     while(e>=s)
        {
            if(a[e-(e-s)/2]==f)
            {
            	k=1;
                cout<<e-(e-s)/2<<"\n";
                return 0;
            }
            else if(a[e-(e-s)/2]<f)
            s= e-(e-s)/2 + 1;
            else
            e = e-(e-s)/2-1;
        }
        
        if(k==0)
        cout<<"-1"<<"\n";
        return 0;
}


int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int f,s=0,e=n-1;
        cin>>f;
        int k=0;
        while(e>s+1)
        { 
           cout<<a[s]<<"  "<<a[e]<<"\n";
            if(a[s]<a[e] && e==n-1)
            {
                break;
            }
            else if(a[e]<a[e-(e-s)/2])
            {
                s = e-(e-s)/2;
            }
            else if(a[e]>a[e-(e-s)/2])
            {
            	
            	e = e-(e-s)/2;
            }
           
        }
        
        cout<<e<<"  "<<s<<"  "<<f<<"\n";
        cout<<a[e-1]<<"  "<<a[0]<<"  "<<a[s+1]<<" "<<a[n-1]<<"\n";
         if(f<=a[e-1] && f>=a[0])
        {
            cout<<"first mai gaya"<<"\n";
            search(a,0,e-1,f);
        }
        else if(f<=a[n-1] && f>=a[s+1])
        {
            cout<<"Second  mai gaya"<<"\n";
            search(a,s+1,n-1,f);
        }
        else
        cout<<"-1"<<"\n";
    }
}
