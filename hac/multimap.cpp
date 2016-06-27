#include <iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;


compare(pair<int,string> a,pair<int,string> b)
{
	if(a.first>b.first)
	return 0;
	if(a.first==b.first)
	{
		if(a.second>b.second)
		return 1;
		else
		return 0;
	}
	return 1;
}

int main()
{
  int n;
  cin>>n;
  //d::vector<std::pair<K,V>> items;
  vector<std::pair<int,string> > mar;
  vector<std::pair<int,string> > ::reverse_iterator k;
  string s;
  int m;
  for(int i=0;i<n;i++)
  {
  	cin>>s;
  	cin>>m;
  	mar.push_back(pair<int, string>(m, s));

  }
  sort(mar.begin(),mar.end(),compare);
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  cout<<"\n";
  for(k=mar.rbegin();k!=mar.rend();++k)
  {
  	cout<<k->second<<" "<<k->first<<"\n";
  }
}
