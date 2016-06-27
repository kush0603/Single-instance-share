#include<iostream>
#include<map>
#include<malloc.h>
using namespace std;

struct trieNode
{
	map<char,trieNode*> child;
	bool leaf;
	trieNode() { leaf = false; }
};


void print_word(map<char, trieNode*> tree) {
  if (tree.empty()) 
  {
  	cout<<"\n";
    return;
  }
  for (map<char, trieNode*>::iterator it=tree.begin(); it!=tree.end(); ++it) {
    cout << it->first;
    
    print_word(it->second->child);
  }
//  cout<<"\n";
}

void print(trieNode* head) {
  map<char,trieNode*> current_tree = head->child;
  print_word(current_tree);
}

int main()
{
	string s;
    trieNode *root = new trieNode;
//    map<char,trieNode*>::iterator it,it1,it2;
    trieNode *curr = root;
//    enter number of words to insert in trie
	int t;
    cin>>t;
   while(t--)
   { 
   cin>>s;
   curr = root;
//   insert each char of string  in trai (map)
	for(int i=0;i<s.length();i++)
	{
//		if the char exist in the trai (map)
		if(curr->child.find(s[i])!=curr->child.end())
		   curr = curr->child[s[i]];
//        enter a new char as a new trieNode		   
		   else
		   {
			char c = s[i];
			curr->child[s[i]] = new trieNode;
			curr = curr->child[s[i]];
		  }
	}
	curr->leaf =1;
	
   }
//   print all the words in trie
   print(root);
}
