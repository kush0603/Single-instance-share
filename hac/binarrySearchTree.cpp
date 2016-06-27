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

//sum property for binary tree (Not binary search tree)
int sumProperty(struct node* head)
{
    if(head==NULL || (head->left==NULL && head->right==NULL))
	 return 1;
	else
	{
        int a=0,b=0;
        if(head->left!=NULL)
        a = head->left->data;
        if(head->right!=NULL)
        b = head->right->data;
        if(head->data!=a+b)
        return 0;
        return sumProperty(head->left) && sumProperty(head->right);
	}
	return 1;
}


//to make tree sum balanced 
int ToSumProperty(struct node* node)
{
/* left_data is left child data and right_data is for right child data*/
int a = 0, b= 0;

/* If node is NULL or it's a leaf node then
	return true */
if(node == NULL ||
	(node->left == NULL && node->right == NULL))
	return 1;
else
{
    ToSumProperty(node->left);
	ToSumProperty(node->right);
	if(node->left != NULL)
	a = node->left->data;
	if(node->right != NULL)
	b = node->right->data;
	if(node->data<=a+b)
	  node->data = a+b;
	else
	{
	    node->right->data = node->data-node->left->data;
	    ToSumProperty(node->right);
	}
	
}
}


//inorder (sorted)
int  display(node* head)
{
	static int sum = 0;
	if(head==NULL)
	cout<<"tree is empty"<<"\n";
	else
	{
        if(head->right!=NULL)
        display(head->right);
        sum = sum+head->data;
        cout<<head->data<<" ";
        
        if(head->left!=NULL)
        display(head->left);
        return sum;
	}
	return sum;
}


int height(node *head)
{
	node* curr = head;
	if(head==NULL)
	return -1;
	
	int lh = 1+height(curr->left);
	int rh = 1+height(curr->right);
	if(lh>rh)
	return lh;
	return rh;
}


Tdeletion(node *head)
{
	if(head==NULL)
	cout<<"tree is deleted";
	if(head->right!=NULL)
	Tdeletion(head->right);
	if(head->left!=NULL)
	Tdeletion(head->left);
	cout<<head->data<<" ";
	free(head);
}




void printleaf(node* head,vector<int> path)
{
	if(head==NULL)
	return;
	else
	{
		path.push_back(head->data);
		
		if(head->right==NULL && head->left==NULL)
		   {
		   	  for(int i=0;i<path.size();i++)
		   	  cout<<path[i]<<" ";
		   	  cout<<"\n";
		   }
		else
		{
			printleaf(head->left,path);
			printleaf(head->right,path);
		   }   
	}
}


//mirror image of tree
void mirror(node* head) 
{
    //cout<<head<<"\n";
	if(head==NULL)
	{
	    return;
	 }
	else
	{
	
	if(head->left!=NULL)
	mirror(head->left);
	if(head->right!=NULL)
	mirror(head->right);
	//cout<<head->data<<" ";
	if(head->left!=NULL || head->right!=NULL)
	{
	    node* temp = head->left;
	    head->left = head->right;
	    head->right = temp;
	}
   }
}

int compare(node *head, node *head1)
{
	if(head1==NULL && head!=NULL)
	return 1;
	if(head==NULL && head1!=NULL)
	return 1;
	if(head==NULL && head1==NULL)
	return 0;
	else
	{
         if(head->data!=head1->data)
          return 1;
        if(head->left!=NULL)
        {
        	compare(head->left,head1->left);
		}
        
       
        if(head->right!=NULL)
        {
        	compare(head->right,head1->right);
		}
        
	}
	return 0;
}



int Balanced(node* head,int *h)
{
	if(head==NULL)
	{
		
		return 1;
	
	}
     
   int hl=0,hr=0;
   int dl=0,dr=0;
   dl = Balanced(head->left,&hl);
   dr = Balanced(head->right,&hr);
   
   //*h = height(head)+1;
   *h = max(hl,hr)+1;
   if(abs(hl-hr)>1)
   return 0;
   else
   return dr&&dl; 
}

int Diameter(node* head,int *h)
{
   if(head==NULL)
   return 0;
   int hl=0,hr=0;
   int dl=0,dr=0;
   if(head->left!=NULL)
   dl = Diameter(head->left,&hl);
   if(head->right!=NULL)
   dr = Diameter(head->right,&hr);
   
   //*h = height(head)+1;
   *h = max(hl,hr)+1;
    return max(hl+hr+1,max(dl,dr));
}


int size(node* head)
{
	if(head==NULL)
	return 0;
	int lh = size(head->left);
	int rh = size(head->right);
	return lh+rh+1;
}


//Spiral level order

queue<node*>level;
stack<int> odd;
void spiralLevelOrder(node* head)
{
	int i=1;
	if(head==NULL)
	{
		cout<<"tree is empty\n";
	}
	else
	{
			node* curr = head;
		    level.push(curr);
		while(!level.empty())
		{
	
		int count = level.size();
		while(count--)
		{
			curr = level.front();
			level.pop();
			if(i%2==0)
			cout<<curr->data<<" ";
			else
			odd.push(curr->data);
			if(curr->left!=NULL)
			level.push(curr->left);
			if(curr->right!=NULL)
			level.push(curr->right);
			
		}
		if(i%2==1)
		{
			while(!odd.empty())
			{
				cout<<odd.top()<<" ";
				odd.pop();
			}
		}
		i++;
		cout<<"\n";
	}
}
	
}

//level order traversal
void LevelOrder(node* head)
{
	int i=1;
	if(head==NULL)
	{
		cout<<"tree is empty\n";
	}
	else
	{
			node* curr = head;
		    level.push(curr);
		   while(!level.empty())
		   {
	
			curr = level.front();
			level.pop();
			cout<<curr->data<<" ";
			if(curr->left!=NULL)
			level.push(curr->left);
			if(curr->right!=NULL)
			level.push(curr->right);
			
		   }
	
		cout<<"\n";
	}
}



int main()
{
	node* head = NULL;
	node* temp = NULL;
	head = insert(head,2);
	temp = insert(head,3);
	temp = insert(head,9);
	temp = insert(head,8);
	temp = insert(head,11);
	temp = insert(head,13);
	temp = insert(head,14);
	temp = insert(head,1);
	temp = insert(head,5);
	temp = insert(head,6);
	temp = insert(head,7);
	temp = insert(head,4);
	node* head1 = NULL;
	node* temp1 = NULL;
	head1 = insert(head1,5);
	temp1 = insert(head1,3);
	temp1 = insert(head1,8);
//	temp1 = insert(head1,8);
//	temp1= insert(head1,11);
//	temp1 = insert(head1,13);
//	temp1 = insert(head1,14);
//	temp1 = insert(head1,1);
//	temp1 = insert(head1,5);
//	temp1 = insert(head1,6);
//	temp1 = insert(head1,7);
//	temp1 = insert(head1,4);
	
	//temp = insert(head,5);
	int hd=0;
	int su = display(head);
	
	cout<<"\n"<<su<<"\n";
	display(head1);
	cout<<"\ndeleting node with data \n";
	//Tdeletion(head1);
    //head1 = NULL;
	int c = compare(head,head1);
	if(c==0)
	cout<<"\nTree are identical";
	else
	cout<<"\nTree are not identical";
	cout<<"\n"<<height(head)<<"\n";
	cout<<"level order traversal is\n";
	LevelOrder(head);
//	display(head1);
	LevelOrder(head1);
	int d = Diameter(head,&hd);
	cout<<"Diamerter is  "<<d<<"\n";
	cout<<"size is  "<<size(head)<<"\n";
	vector<int> path;
	cout<<"leaf path are \n";
	printleaf(head,path);
     int s = sumProperty(head1);
	 if(s==1)
	 cout<<"sum property hold\n";	
	 else
	 cout<<"sum property do not hold\n";
	int b=0;
	if(Balanced(head1,&b))
	cout<<"Tree is balanced\n";
	else
	cout<<"Tree is not balance\n";
}
