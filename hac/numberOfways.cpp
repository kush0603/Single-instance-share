#include<iostream>
#include<string.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   long long a[n];
   long long sum=0;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
       sum = sum+a[i];
   }
   
   if(sum%3!=0)
   {
        cout<<0;
   }
  else
  {
  int p=1,q=n-1,i=0;
  long long s1=a[0],s3=0;
  while(s1!=sum/3 && p<q)
  {
      s1 = s1+a[p];
      p = p+1;
  }
  while(s3!=sum/3 && q>p)
  {
      s3 = s3+a[q];
      q--;
  }
  if(q==n-1)
  q--;
//  cout<<s1<<"  "<<p<<"  "<<s3<<"  "<<q<<"\n";
  if(s1!=sum/3 || s3!=sum/3)
    cout<<0;
  else if(q-p<0)
    cout<<0;
  else
  {
  long long  count=0,cou=0,ind=p,s2=0;
  for(i=p;i<=q;i++)
  {
      s2 = s2+a[i];
//      cout<<a[i]<<"\n";
      if(s2==0)
      {
//      	cout<<"milaa\n";
          ind = i;
          count++;
      }
  }
//   cout<<"\n"<<cou<<"  "<<count<<"\n";
   if(s1==0 && count==1)
      cout<<1;
    else
    {
      s2=0;
      for(i=q;i>=p;i--)
      {
          s2 = s2+a[i];
          if(s2==0)
          cou++;
      }
//      cout<<cou<<"  "<<count<<"\n";
      if(cou==0 && count==0)
      cout<<1;
      else if(cou==0||count==0)
      cout<<cou+count+1;
      else if(count==cou && cou+count>q-p+1)
      cout<<(cou)*(cou+1)/2;
      else if(count==cou==1)
      cout<<(cou+1)*(count+1)-1;
      else
      cout<<(cou+1)*(count+1);
    } 
  }
  }
}
