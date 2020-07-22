#include <iostream>
using namespace std;

int arrSize;
int* allocArray(int size){  //포인터함수 선언
    int *d = new int[size]; //p31 그림참조
    return d;
}

void printArray(int *arr){ //배열내용출력함수 선언
    
    cout << "Array elements are: : ";
    for(int i=0; i<arrSize; i++){
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}

void freeArray(int *arr){  //동적할당된 배열의 메모리를 해제하는 함수 선언
    delete [] arr;
}

int main()
{
    int* arr;
    int size;

    cout << " Enter the array size: ";
    cin >> size;
    arrSize = size;
    arr = allocArray(size);
    for (int i=0; i<size; i++)
    {
        cout << "Put an array element: ";
        cin >> arr[i];
    }
    printArray(arr);
    freeArray(arr);
return 0;
}
