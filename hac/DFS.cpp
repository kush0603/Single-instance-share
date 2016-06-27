#include<iostream>
#include<malloc.h>
#include<string.h>
#include<vector>
#include<stack>
#include <list>
using namespace std;

struct edge
{
	int v;
	int w;
};
struct node
{

	int color;
	int no;
	list<edge> edgelist;
};
int main()
{
	int v;
	int ne;
	cin>>v;
	cin>>ne;
	stack <node *> sta;
	//cout<<"Queue is created"<<"\n";
	node* array;
    array = new node[v+1];
    //cout<<"array of node is created"<<"\n";

	struct edge e;
	int x,y;
	int a[v];
	memset(a,sizeof a,0);
	a[0]=0;
	for(int i=1;i<=ne;i++)
	{
		cin>>x;
		cin>>y;
		a[x-1]++;
		e.v = y;
		array[x].edgelist.push_back(e);
		e.v=x;
		array[y].edgelist.push_back(e);
	}
	int t=0;
	for(int i=1; i<=v; i++)
	{
		if(a[i-1]==0)
		{
			t=1;
		}
		array[i].no = i;
		array[i].color = 0;
	}
	long long sum=0,max=v;
//	cout<<"t is  "<<t;
	if(t==1)
	{
	 cout<<1<<"\n";	
	 return 0;
	}
	
   int s = 1;
//  		cout<<s<<" ye index aaya\n";
	array[s].color = 1;
	sta.push(array+s);
	sum = 1;
	while(!sta.empty())
	{
//		cout<<s<<" index pr sum   "<<sum<<"  ";
		node *temp = sta.top();
		cout<<temp->no<<" ";
		sta.pop();
		
		for(list<edge>::iterator i = (temp->edgelist).begin(); i != (temp->edgelist).end(); ++i)
		{
			if(array[(*i).v].color==0)
			{
				array[(*i).v].color=1;
				sum = sum+1;
//				cout<<sum;
				sta.push(array+((*i).v));
	    	}
		}
		  
		    //cout<<temp->no<<"  ";
			temp->color = 2;
	}
	     if(sum<max && sum!=1)
		  max = sum;	  

	cout<<"\n"<<max<<"\n";
 
}
