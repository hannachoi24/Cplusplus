#include <iostream>
using namespace std;

class A
{
public:
    int a;
     A(){
         cout<<"Constructor in class A executed\n";
     }

     ~A(){
         
         cout<<"Destructor in class A executed\n";      
     }
};

class B : public A
{
public:
    int b;
     B(){
         cout<<"Constructor in class B executed\n";
     }

     ~B(){
         
         cout<<"Destructor in class B executed\n";      
     }    
};
 
class C : public B
{
public:
    int c;
     C(){
         cout<<"Constructor in class C executed\n";
     }

     ~C(){
         
         cout<<"Destructor in class C executed\n";      
     }    
};


int main()
{
    C* pc =new C;  
    delete pc;
}