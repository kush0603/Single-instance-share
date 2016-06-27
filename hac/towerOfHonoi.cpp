#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int N,count=0;
    cin >> N;
    vector<int> f;
    vector<int> b;
    vector<int> c;
    vector<int> d ;

    int x;
   for(int i=0;i<N;i++)
       {
       cin>>x;
      if(x==1)
         f.push_back(i+1);
        if(x==2)
            b.push_back(i+1);
        if(x==3)
         c.push_back(i+1); 
        if(x==4)
          d.push_back(i+1);

   }
    //cout<<f.size()<<" "<<b.size()<<" "<<c.size()<<" "<<d.size()<<" "<<"\n";
     int k=N,l;
    while(1)
    {   
     // cout<<"size of f is  "<<f.size()<<" "<<f[f.size()-1]<<"\n";
      //  cout<<"entered";
      //  cout<<k;
      if(f[f.size()-1]==1 && f.size()==N)
          break;
    
    
	   if(f[f.size()-1]==k && f.size()==N-k+1)
       
       {
       //	cout<<"aaya"<<"\n";
       //	cout<<b.size()<<"\n";
           if( b.size()>0)
            {
            	if(b[b.size()-1]==k-1)
            	{
				
            //	cout<<"b mai mila"<<"\n";
               f.push_back(k-1);
               b.pop_back();
               k=k-1;
               count++;
               continue;
           }
       }
            if(c.size()>0)
            {
            	if(c[c.size()-1]==k-1)
            	{
				
            //	cout<<"c mai mila"<<"\n";
               f.push_back(k-1);
               c.pop_back();
               k=k-1;
               count++;
               continue;
           }
       }
            if(d.size()>0)
            {
            	if(d[d.size()-1]==k-1)
            	{
				
            //	cout<<"d mai mila"<<"\n";
               f.push_back(k-1);
               d.pop_back();
               k=k-1;
               count++;
               continue;
           }
       }
       } 
       
        else if(f.size()>0)
        {
        	//	cout<<"Yaha aaya"<<"\n";
            l = f[f.size()-1];
            f.pop_back();
           
           if(b.size()>0)
           {
            if(b[b.size()-1]<l)
            {
               b.push_back(l);
                count++;
                continue;
             }
           }
              else
              {
             
			  b.push_back(l);
              continue;
			 }
          if(c.size()>0) 
          {
		  
			if(c[c.size()-1]<l)
            {
               c.push_back(l);
                count++;
                continue;
           }
       }
           else
           {
           	c.push_back(l);
           	continue;
		   }
           if(d.size()>0)
           {
		   
			  if(d[d.size()-1]<l)
            {
               d.push_back(l);
                 count++;
                 continue;
           }
       }
           else
           {
		   
           d.push_back(l);
           continue;
       }
        }
        
        else
            {
            	//	cout<<"kaha aaya"<<"\n";
               if(b.size()>0)
            {
            	if(b[b.size()-1]==k )
            	{
				  b.pop_back();
                  f.push_back(k);
                  
                count++;
           }
       }
            else if( c.size()>0)
            {
            	if(c[c.size()-1]==k)
            	{
				c.pop_back();
               f.push_back(k);
               
                count++;
           }
       }
             else if(d.size()>0)
            {
            	if(d[d.size()-1]==k)
            	{
				d.pop_back();
               f.push_back(k);
                 
                 count++;
           }
       }
        }
     }
    cout<<count;

}

