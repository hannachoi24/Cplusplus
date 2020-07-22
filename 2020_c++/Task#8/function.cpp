#include <iostream>
#include <cmath>
using namespace std;


int Add(int a, int b)
{
    return a+b;
}

int Sub(int a, int b)
{
    return a-b;
}

int Div(int a, int b)
{
    return a/b;
}

int Mul(int a, int b)
{
    return a*b;
}

int main()
{


    int a= 20, b= 10;

    cout << "Add: " << Add(a,b) << endl;
    cout << "Sub: " << Sub(a,b) << endl;
    cout << "Div: " << Div(a,b) << endl;
    cout << "Mul: " << Mul(a,b) << endl;

    return 0;
    

}