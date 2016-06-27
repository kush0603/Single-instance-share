#include <cmath>
#include <cstdio>
#include <list>
#include<stack>
#include<queue>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
   int n;
    int q;
    cin>>n;
    cin>>q;
    long long a;
    //long long l[n];
    list<long long> k;
    stack<long long > t;
    queue<long long > to;
    std::list<long long >::iterator it1,it2;
    for(int i=0;i<n;i++)
    {
      cin>>a;
//        cout<<a<<" ";
        k.push_back(a);
     }
//    cout<<"number inserted\n";
    int p,x,y;
//    cout<<"loop ke bahar\n";
    while(q--)
    {
//        cout<<"loop ke ander\n";
        cin>>p;
//        cout<<p<<"  loop ke ander p aa gaya\n";
        cin>>x;
//        cout<<x<<"  loop ke ander x aa gaya\n";
        cin>>y;
//        cout<<y<<"  y number aa gaye\n";
//        cout<<p<<" "<<x<<"  "<<y<<"\n";
//        cout<<"yaha kyo nhi\n";
        it1 = k.begin();
        if(p==1)
        {
            advance (it1,x-1);
             for(int i=x;i<=y;i++)
                {
//                   cout<<*it1<<" ";
                   t.push(*it1);
                   k.erase(it1);
                   it1++;
                 }
//                 cout<<"\n";
            for(int i=x;i<=y;i++)
                {
                	k.push_front(t.top());
                	t.pop();
				}
        }
        else
        {
        	advance (it1,x-1);
            for(int i=x;i<=y;i++)
                {
//                   cout<<*it1<<" ";
                   to.push(*it1);
                   k.erase(it1);
                   it1++;
                 }
//                 cout<<"\n";
            for(int i=x;i<=y;i++)
                {
                	k.push_back(to.front());
                	to.pop();
				}
        }
        
    }
    cout<<abs(k.front()-k.back())<<"\n";
    for(it1 = k.begin(); it1 != k.end();++it1)
      cout<<*it1<<" ";
      
}

