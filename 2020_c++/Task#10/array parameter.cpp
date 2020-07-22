#include <iostream>
using namespace std;

int fillarray(int arr[], int size)

{ 
    int i;
    for (i=0; i<5; i++)
    cin >> arr[i];
    return *arr;
}

void printarray(int arr[], int size)
{   
    int i;
    cout << "Array elements are ";
    for (i=0; i<5; i++)
    cout << arr[i] << ' ';
    cout << endl;     
       
}    


int main()
{
    int arr[5];
    fillarray (arr,5);
    printarray (arr,5);
   
}