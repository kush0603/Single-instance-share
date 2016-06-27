#include <iostream>
#include<string.h>
using namespace std;

int main() 
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,s;
        cin>>n;
        cin>>s;
        string k="";
        if(s==0)
        {
            cout<<-1<<"\n";
            continue;
        }
        
        while(s>0 && n>0)
        {
            n--;
            if(s>=9)
            {
                k = k+"9";
                s= s-9;
            }
            else
            {
                char z = '0'+s;
                k = k+z;
                s=0;
            }
        }
        if(n==0 && s==0)
        cout<<k<<"\n";
        else if(n==0 && s!=0)
        cout<<-1<<"\n";
        else if(n>0 && s==0)
        {
            while(n>0)
            {
                k = k+"0";
                n--;
            }
            cout<<k<<"\n";
        }
        
    }
	
}
