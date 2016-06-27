#include<iostream>
#include<queue>
#include<malloc.h>
#include<stack>
#include<math.h>
using namespace std;


struct node
{
	int data;
	node* right;
	node* left;
};


node* insert(node* head,int value)
{
	node* curr = head;
	if(curr==NULL)
	{
		node* k = (node *)malloc(sizeof(node));
		k->data = value;
		k->left = NULL;
		k->right =NULL;
		return k;
	}
	
	else if(value>curr->data)
	{
		if(curr->right!=NULL)
		insert(curr->right,value);
		else
		{
			node* k = (node *)malloc(sizeof(node));
			k->data = value;
			k->left = NULL;
			k->right =NULL;
			curr->right = k;
			return curr;
			
		}
	}
	else
	{
		if(curr->left!=NULL)
		insert(curr->left,value);
		else
		{
			node* k = (node *)malloc(sizeof(node));
			k->data = value;
			k->left = NULL;
			k->right =NULL;
			curr->left = k;
			return curr;
			
		}
		
	}
}
 display(node* head,int* k,int *sum)
{
//	cout<<"k is  "<<*k<<"\n";
	if(head==NULL)
	return 0;
	
	
	else
	{
		if(*k==0)
		*sum=0;
        if(head->left!=NULL)
        {
        	*k =*k-1;
        	display(head->left,k,sum);
		}
		if(*k==0)
		*sum=0;
		*sum = *sum+head->data;
        cout<<head->data<<" ";
        if(head->right!=NULL)
        {
        	*k =*k-1;
        	display(head->right,k,sum);
		}
		if(*k==0)
		*sum=0;
		
        
	}
}



int size(node* head)
{
	if(head==NULL)
	return 0;
	int lh = size(head->left);
	int rh = size(head->right);
	return lh+rh+1;
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,k;
        cin>>n;
        cin>>k;
	    node* head = NULL;
	    node* temp = NULL;
	    int t;
	    for(int i=0;i<n;i++)
	    {
	      cin>>t;     
	      if(head==NULL)
	      head = insert(head,t);
	      else
	      temp = insert(head,t);
	    }
	    int s = size(head->right);
	    if(s<k)
	    cout<<-1<<"\n";
	    else
	    {
	    	int w = n-k;
	    	int st = 0;
	        int z = display(head,&w,&st);
	        cout<<st<<"\n";
	    }
    }
    
}
