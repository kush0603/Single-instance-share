#include <iostream>
#include<malloc.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct TrieNode {
  map<char, TrieNode*> child;
  bool isend;
};

void insert(TrieNode* root,string s)
{
	cout<<s;
	TrieNode* curr = (TrieNode*)malloc(sizeof(TrieNode));
	cout<<"insertion start\n";
	for(int i=0;i<s.length();i++)
	{
		
			cout<<s[i]<<"\n";
//			char c = s[i];
//			TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
			cout<<"yaha aaya\n";
//			node->isend = 0;
			cout<<"yaha bhi\n";
			curr->child[s[i]] = new TrieNode;
			cout<<"yaha bhi\n";
			curr = curr->child[s[i]];
//			cout<<c<<"  inserted\n";
		}
	}

void print(TrieNode* root)
{
	map<char,TrieNode*>::iterator it;
	if(root==NULL)
	return;
	it = root->child.begin();
	cout<<it->first;
	print(it->second);
	
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		TrieNode* root = NULL;
		insert(root,s);
		cout<<"value inserted\n";
		print(root);
	}
	
}
