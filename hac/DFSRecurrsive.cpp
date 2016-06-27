#include<iostream>
#include<malloc.h>
#include<string.h>
#include<vector>
#include<stack>
#include <list>
using namespace std;


void dfs(int s, vector<int> g[], bool* vis[])
{
    cout<<"nodes jo aa rahe  "<<s<<"\n";
    if(*vis[s]==1)
    return;
    cout<<s<<" ";
    *vis[s]=1;
    for(int i=0;i<g[s].size();i++)
    {
        if(*vis[g[s][i]]!=1)
        dfs(g[s][i],g,vis);
    }
    

}
int main()
{
	int v;
	int ne;
	cin>>v;
	cin>>ne;
	bool* vis[v];
	memset(vis,sizeof v,0);
	//cout<<"Queue is created"<<"\n";
    //cout<<"array of node is created"<<"\n";
    vector<int> g[v];
	int x,y;
	for(int i=1;i<=ne;i++)
	{
		cin>>x;
		cin>>y;
		x = x-1;
		y = y-1;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0,g,vis);
}
