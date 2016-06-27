#include<iostream>
#include<queue>
#include<malloc.h>
#include<stack>
#include<math.h>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};


node* add(int value)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = value;
	temp->right = NULL;
	temp->left = NULL;
	//cout<<value<<"  ";
	return temp;
}

int search(int* in,int st,int en, int value)
{
	int i;
	for(i=st;i<=en;i++)
	{
		if(in[i]==value)
		return i;
	}
}


node* buildTree(int* in,int* pr,int st,int en)
{
 	static int k=0;
	if(st>en)
	return NULL;
	node *curr = add(pr[k++]);
	if(st==en)
	return curr;
	
	int p = search(in,st,en,curr->data);
	
    curr->left = buildTree(in,pr,st,p-1);
    curr->right = buildTree(in,pr,p+1,en);
    
    return curr;	
}

void display(node* head)
{
	if(head==NULL)
    return;
        display(head->left);
        cout<<head->data<<" ";
        display(head->right);
	
}


int main()
{
	int n;
	cin>>n;
	int in[n];
	int pr[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>pr[i];
	}
  	
  node *head = buildTree(in,pr,0,n-1);	
  
  cout<<"tree is constructed\n";
  
  display(head);
  
  
  
  
  
}
