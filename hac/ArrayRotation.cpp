#include <iostream>
using namespace std;



int gcd(int n,int d)
{
   int g;
   for(int i=d;i>=1;i--)
   {
       if(d%i==0 && n%i==0)
        return i;
   }
}

int main()
{
  int test;
  cin>>test;
  while(test--)
  {
      int n,d;
      cin>>n;
      cin>>d;
      int a[n];
      int g = gcd(n,d);
     // cout<<g<<"\n";
      for(int i=0;i<n;i++)
      {
          cin>>a[i];
      }
      int t = d,k=0,i=0,j=0;
      while(t--)
      {
              int temp;
              temp = a[i];
              k = i;
              while(k+g<n)
              {
                  //cout<<a[k]<<"  "<<a[k+g]<<" ";
                  a[k] = a[k+g];
                  k = k+g;
              }
              //cout<<"\n";
              a[k] = temp;
              if(g>1)
              j++;
              if(j==d/g)
              {
                j=0;
                i++;
              }
             // cout<<"j is = "<<j<<" i is = "<<i<<"\n";
              
            
      }
      for(int i=0;i<n;i++)
      {
          cout<<a[i]<<" ";
      }
      cout<<"\n";
}

}
