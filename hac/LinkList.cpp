#include<iostream>
#include<malloc.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};


//insert at end
Node* InsertLast (Node* head,int data)
{
	struct Node* k = (struct Node*) malloc(sizeof(struct Node));
	struct Node* current = head;
	k->data = data;
	k->next = NULL;
	if(head==NULL)
	{
		cout<<"empty link list"<<"\n";
			head = k;
			return head;
	}
     else
	{
		while(current->next!=NULL)
		{
			current= current->next;
		}
			current->next = k;
			return head;
	}

}

//inset at any spacific position
Node* InsertNth(Node *head, int data, int position)
{
  Node* k = (Node *) malloc(sizeof(Node));
    k->data=data;
    if(position==0)
        {
        k->next = head;
        head = k;
        return head;
    }
    Node* current = head;
    for(int i=0;i<position-1;i++)
        current = current->next;
        k->next=current->next;
        current->next = k;
    
    return head;
        
}

//insert ar begining
Node* InsertFirst(Node *head,int data)
{
  Node* k = (Node *) malloc(sizeof(Node));
    k->data = data;
    k->next = head;
    head = k;
    return head;
}


//Delete from any specific position 
Node* Delete(Node *head, int position)
{
    if(position==0)
        {
         head = head->next;
         return head;
    }
    Node* current = head;
    for(int i=0;i<position-1;i++)
       current = head->next; 
    current->next = current->next->next;
    return head;
}

//To print the link list in revers order

void ReversePrint(Node *head)
{
     Node* current = head;
     Node* prev = NULL;
     Node* ah  = head;
        if (head==NULL)
            {}
       else if(head->next==NULL)
           cout<<head->data<<"\n";
       else
           {
             while(current->next!=NULL)
             {
               ah= current->next;   
               current->next = prev;
               prev = current; 
               current = ah;  
                 
             }
            current->next = prev;
           while(current!=NULL)
               {
                cout<<current->data<<"\n";
                current = current->next;
           }
       }
    
}

//Compare two link list
int CompareLists(Node *headA, Node* headB)
{
    int k=0;
    Node* a =headA;
    Node* b = headB;
  if(headA==NULL || headB==NULL)
      return 1;
  while(a!=NULL && b!=NULL)
  {
        if(a->data == b->data)
            {
             a = a->next;
             b = b->next;
            }
      else
          return 0;
  }
   if(a==NULL && b==NULL) 
    return 1;
   else
    return 0;
}

//Mearge to sorted Link List
Node* MergeLists(Node *headA, Node* headB)
{
  Node* head = NULL;
  Node* current = NULL; 
  if(headA==NULL)
      return headB;
   if(headB==NULL)
       return headA;
    while(headA!=NULL && headB!=NULL)
     {
        //cout<<headA->data<<" "<<headB->data<<"\n";
        //cout<<current->data<<"\n";
        if(headA->data>headB->data)
            {
              
               if(head ==NULL)
               {
                  head = headB;
                  current = headB;
                  
               }
                  
              else
                  {
                    current->next = headB;
                    current = current->next;
                  }
            headB = headB->next;
        }
            
        else
            { 
              if(head ==NULL)
               {
                  head = headA;
                  current = head;
              }
                  
              else
                  {
                    current->next= headA;
                    current = current->next;
                  }
              headA = headA->next;
            }
     }
    if(headA==NULL)
        current->next = headB;
    else if(headB==NULL)
         current->next =headA;
   // cout<<"head pointer at"<<head->data<<"\n";    
    return head;
}


//print kth element from last
int GetNode(Node *head,int k)
{
  int count = 0;
  Node* current = head;
  Node* p = head;
  while(current!=NULL)
   {
     if(count>k)
        p = p->next;
      current = current->next;
      count++;
  }
    return p->data;
}

//Remove duplicate from sorted link list
Node* RemoveDuplicates(Node *head)
{
  Node* current = head;
  Node* temp = head;
    
    while(temp!=NULL)
    {
       if(temp->data == current->data)
           {
             temp = temp->next;
       }
        else
            {
              current->next = temp;
              current = current->next;
              temp=temp->next;
        }
    
        current->next = NULL;
        
}
    return head;
}

//to find the common point of two coonected link list
int FindMergeNode(Node *headA, Node *headB) {
    Node* currentA = headA;
    Node* currentB = headB;

    while(currentA != currentB)
    {
            if(currentB->next == NULL)
            {
              currentB = headB;
              currentA = currentA->next;
            }
        
        else
        {
            currentB = currentB->next;
        }
    }
    return currentB->data;
}


int main()
{
	
	struct Node* head = NULL;
	
	int data = 2;
	head = InsertFirst(head,data);
	cout<<"data is "<<head->data<<"\n";
	head = InsertFirst(head,3);
	cout<<"data is "<<head->data<<"   "<<head->next->data;
	
	
	
	
}
