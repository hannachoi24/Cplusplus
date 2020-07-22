#include <iostream>
using namespace std;

class PFArrayl
{
public:
    PFArrayl();
    PFArrayl(int capacityValue):capacity(capacityValue), used(0){
        a = new int[capacity];
    }   //배열 생성
    PFArrayl(const PFArrayl& pfaObject):capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed()){
        a = new int[capacity];
        for(int i=0; i<used; i++)
            a[i] = pfaObject.a[i];
    }
    ~PFArrayl(){        //소멸자
        delete [] a;
    }

    void addElement(int element){
        if(used >= capacity){
            cout<<"Attempt to exceed capacity in PFArrayD.\n";
            exit(0);
        }
        a[used] = element;
        used++;
    }
    bool full() const {return (capacity == used);}
    int getCapacity() const {return capacity;}
    int getNumberUsed() const {return used; }
    void emptyArray(){ used = 0;}
    int& operator[](int index){
        if(index >= used){
            cout<<"Illegal index in PFArrayD. \n";
            exit(0);
        }
        return a[index];
    }

    PFArrayl& operator = (const PFArrayl& rightside);

private:
      int *a;           //배열을 위한 포인터
      int capacity;     //배열의 크기
      int used;         //현재 사용중인 배열의 위치
};

void testPFArrayl();

int main()
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayl temp(cap);

    cout << "Enter up to "<< cap <<" nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";
    int next;
    cin >> next;
    while ((next >=0 ) && (!temp.full()))
    {
        temp.addElement(next);
        cin >> next;
    }

    cout << "You entered the following "<< temp.getNumberUsed() << " numbers:\n";
    int index;
    int count = temp.getNumberUsed();
    for (index = 0; index < count; index++)
            cout << temp[index] << " ";
    cout << endl;

}