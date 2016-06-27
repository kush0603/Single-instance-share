#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
	int sum=0;
    int a[26],min=999999;
    for(int i=0;i<26;i++)
        {
        cin>>a[i];
        sum = sum+a[i];
        if(min>a[i] && a[i]>0)
        min = a[i];
    }
    string s="";
    //cout<<min;
    while(s.length()!=sum)
    {
    for(int i=0;i<26;i++)
    {
        if(a[i]==min && min !=999999)
         {
         	a[i]=999999;
         	//cout<<a[i];
            while(min--)
                {
                 char c = 97+i;
                 //cout<<c;
                 s = s+c;
                }
            }
        }
        min = *min_element(a,a+25);
        //cout<<s;
        //cout<<s.length()<<"\n";
    }
    cout<<s;
}

