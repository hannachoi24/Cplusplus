#include <iostream>
using namespace std;

void sort_three (int& a, int& b, int& c)  // & callby reference 주소참조이기 때문에 변화된 값이 도출
                                          // &가 없으면 callby value 변화된 값 도출 않하고 원래 할당된 값이 도출 

{
    int temp;
    if(a<b){              // 조건 안맞아서 실행않됨
        temp = a;
        a = b;
        b = temp;       
    }
    if(a<c){              
        temp = a;         // a는 새로운 값 받을 준비가 되었음
        a = c;
        c = temp;         // a=500, c=100 temp는 중간다리 역할 
    }
    if(b<c){
        temp = b;         // b는 새로운 값 받을 준비가 되었음.
        b = c;
        c = temp;         // b=100, c=90
    }
}
                          // 하나의 조건문으로 만들어지지 않기 때문에 else if(하나의 조건문으로 실행) 사용 불가
                          

int main()
{
    int i1 = 100, i2 = 90, i3 = 500;
    sort_three (i1,i2,i3);
    cout << "Three numbers are: " << i1 << " , " << i2 << " , " << i3 << endl;
    
    return 0;

}