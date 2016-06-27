#include <iostream>
#include<math.h>
using namespace std;

int main() 
{
   int test;
   cin>>test;
   while(test--)
   {
       int n,m;
       cin>>n;
       cin>>m;
       string s1,s2;
       cin>>s1;
       cin>>s2;
       int d[n+1][m+1];
       for(int i=0;i<=n;i++)
       d[i][0]=i;
       for(int j=0;j<=m;j++)
       d[0][j]=j;
       int s=0;
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
            //   cout<<s1[i-1]<<"  "<<s2[j-1]<<"  ";
               if(s1[i-1]==s2[j-1])
               s = d[i-1][j-1];
               else
               s = d[i-1][j-1]+1;
               d[i][j] = min(s,min(d[i-1][j]+1,d[i][j-1]+1));
            //   cout<<s<<" "<<d[i][j]<<"\n";
           }
       }
       cout<<d[n][m]<<"\n";
   }
}
