#include<iostream>
#include<malloc.h>
using namespace std;


struct node
{
	int data;
	node* left;
	node* right;
};


node* insert(node* root , int data)
{
	if(root==NULL)
	{
		node* k = (struct node*) malloc( sizeof( struct node ) );
		k->data=data;
		k->left=NULL;
		k->right=NULL;
		return k;
	}
	else if(root->left==NULL)
	root->left  = insert(root->left,data);
	else
	root->right = insert(root->right,data);
}

//to get height of tree
int height(node * root)
{
    if(root==NULL)
      return -1;
    else
        {
        
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh)+1 ;
}
int main()
{
      node* root = (struct node*) malloc( sizeof( struct node ) );
      node* temp= (struct node*) malloc( sizeof( struct node ) );
      
    root=NULL;
    int data;
	root = insert(root,2);
 	temp = insert(root ,3);	
 	temp = insert(root,4);
 	temp = insert(root,5);
 	cout<<root->data<<" "<<root->left->data<<" "<<root->right->data;
	
}
