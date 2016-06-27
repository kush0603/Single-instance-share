#include<iostream>
#include<stack>
#include <ctype.h>
using namespace std;

	stack<char> op;
	stack<char> opt;

int compare(char k)
{
    if(k=='(')
    opt.push(k);
    else if(k==')')
    {
        return 1;
    }
    else if(k=='^')
    opt.push(k);
    else if(k=='*' || k=='/')
    {
        if(opt.top()!='^')
        opt.push(k);
        else
        return 1;
    }
    else if(k=='+' || k=='-')
    {
        if(opt.top()!='^' && opt.top()!='*' && opt.top()!='/')
        opt.push(k);
        else
        return 1;
    }
    return 0;
}

void insert(char k)
{
   // cout<<opt.empty()<<"\n";
//    cout<<"aaya"<<"\n";
    if(opt.empty())
    {
        opt.push(k);
  //      cout<<opt.top()<<"\n";
        //cout<<"kuch thaa stack mai"<<"\n";
    }
       
    else
    {
      //  cout<<"stack mai kuch hai"<<"\n";
        int i = compare(k);
        if(i==0)
        {
        //    cout<<"done"<<"\n";  
        }
        else
        {
            if(k==')')
            {
                string s="";
                while(opt.top()!='(' && !opt.empty())
                {
                    char o = opt.top();
                    opt.pop();
                    char a = op.top();
                    op.pop();
                    char b = op.top();
                    op.pop();
                    cout<<b<<" "<<a<<" "<<o<<"\n";
                    s = s+b+a+o;
                    cout<<s;
                }
                if(opt.empty())
                {
                    cout<<"invalid expression\n";
                    exit;
                }
                opt.pop();
               // for(int )
            }
            else if(k=='*' || k =='/')
            {
                //cout<<"yaha aa gaya"<<"\n";
                string s ="";
                while(opt.top()=='^' && !opt.empty())
                {
                    cout<<opt.top()<<"\n";
                    char o = opt.top();
                    opt.pop();
                    char a = op.top();
                    op.pop();
                    char b = op.top();
                    op.pop();
                    cout<<b<<" "<<a<<" "<<o<<"\n";
                    s = s+b+a+o;
                    cout<<s;
                    if(opt.empty())
                    break;
                }
                opt.push(k);
            }
            
             else if(k=='+' || k=='-')
             {
                 string s="";
                 while(opt.top()=='^' || opt.top()=='*' || opt.top()=='/')
                    {
                        cout<<opt.top()<<"\n";
                        char o = opt.top();
                        opt.pop();
                        char a = op.top();
                        op.pop();
                        char b = op.top();
                        op.pop();
                        cout<<b<<" "<<a<<" "<<o<<"\n";
                        s = s+b+a+o;
                        cout<<s;
                        if(opt.empty())
                        break;
                    }
                    opt.push(k);
    }
        }
    }
}

int main()
{
	string s;
	cin>>s;

	for(int i=0;i<s.length();i++)
	{
	    if(isalpha(s[i]))
	    {
	        op.push(s[i]);
	    }
	    else
	    {
	         //cout<<"opertator   "<<opt.top()<<"\n";
	        insert(s[i]);
	       // if(!opt.empty())
             //cout<<"opertator   "<<opt.top()<<"\n";
	    }
	}
	string opst="";
	string oos="";
	   cout<<"aa riya hai\n";
	while(!opt.empty() && !op.empty())
	{
	 
	                    
                        char o = opt.top();
                        opt.pop();
                        char a = op.top();
                        op.pop();
                        
                       
                        opst = o+opst;
                       oos = a+oos;
                        
	}
	oos = op.top()+oos;
	op.pop();
cout<<oos+opst<<"\n";
	return 0;
}

