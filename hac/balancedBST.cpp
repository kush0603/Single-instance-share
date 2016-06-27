#include <iostream>
using namespace std;
#include<malloc.h>

struct node
{
    int data;
    node* left;
    node* right;
};

struct node* BST(int *a,int start,int end)
{
  
//   cout<<"mid is  "<<mid<<"\n";
    if(start>end)
    return NULL;
        int mid = start+ (end-start)/2;
        node* root = (node*)malloc(sizeof(node));
        root->data = a[mid];
//        cout<<a[mid]<<"\n";
        root->left = BST(a,start,mid-1);
        root->right= BST(a,mid+1,end);
        return root;
    
}

void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


int main() 
{
	int test;
	cin>>test;
	while(test--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    
	    
	    if(a[0]>a[n-1] && n>1)
	    {
	    	int temp;
	    	for(int i=0;i<n/2;i++)
	    	{
	    		temp = a[i];
	    		a[i] = a[n-1-i];
	    		a[n-1-i] = temp;
			}
		}
//	    std::reverse(begin(a), end(a));
	    node* root = BST(a,0,n-1);
//	    cout<<"data inserted  \n";
	    preorder(root);
	    cout<<"\n";
	}
	
}
