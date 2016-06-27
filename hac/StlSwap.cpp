#include <iostream>
#include<string.h>
using namespace std ;


int main( ) {
	char  s[8];
	gets(s);
    int a = 10, b = 20 ;
    float c = 10.5, d = 20.5 ;
            swap(c , d);          // function swapping ‘int’ elements 
   // swap(c , d);  
	cout<<c<<" " <<d;               // function swapping ‘float’ elements 
    return 0;
}
