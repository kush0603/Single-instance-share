#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<string> str;
    vector<string> modi; 
	vector<string>final; 
    
    
        string s;
        int c=0;
    for(int i=0;i<n;i++)
        {
        cin>>s;
        for(int j=0;j<str.size();j++)
        {
            if(s==(str[j]))    
            {
             c=1;
             break;
             }
        } 
		   if(c==1)
		      c=0;
            else
            {
               
                str.push_back(s);    
            }  
        }
     sort(str.begin(),str.end());
    for(int i=0;i<str.size();i++)
        {
        	int a[10]={0,0,0,0,0,0,0,0,0,0};
        	string p="";
        	
           for(int j=0;j<str[i].length();j++)
           a[str[i][j]-'0']++;      
        
           for(int l=0;l<10;l++)
           {
            char c = '0'+a[l];
            char d = '0'+l;
            p = p+d+c;
           }
        modi.push_back(p);
       }
       
    
    int max=0;
    int index;
    int count=0;
    int total=0;
    int co[str.size()];
   for(int i=0;i<str.size();i++)
   {
   	if(co[i]==-1)
   	{
   		continue;
	   }
   	count=0;
   	co[i]=0;
   	 for(int j=i;j<str.size();j++)
   	 {
   	 	if(modi[i]==modi[j])
   	 	{
   	 		count++;
   	 		co[j]=-1;
   	 		
			}
   	 	
		}
		if(count>max)
		{
			max=count;
		}
		co[i] = count;
		
	} 
	for(int i=0;i<str.size();i++)
	  {
	  	if(co[i]>0)
	  	total++;
	  }
    cout<<total<<"\n";
    
    for(int i=0;i<str.size();i++)
    {  
    string fin="";
    	if(co[i]==max)
    	{
    		for(int j=modi.size()-1;j>=i;j--)
    		{
    		//	cout<<"start "<<modi[in[i]]<<"\n";
    			if(modi[i].compare(modi[j])==0)
    			{
    				//cout<<"modi[i]  "<<modi[i]<<" modi[j] "<<modi[j]<<"\n";
    				fin = fin+str[j]+" ";
    				//str.erase(str.begin()+j);
    				//modi.erase(modi.begin()+j);
    				
				}
    			
			}
			final.push_back(fin);
			//modi[in[i]].erase();
		}
		
	}
	sort(final.begin(),final.end());
    for(int i=0;i<final.size();i++)
    {
    	cout<<final[i]<<"\n";
	}
}

