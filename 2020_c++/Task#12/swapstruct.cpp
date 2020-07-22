#include <iostream>
using namespace std;

struct CDAccountV1 

{
    double balance;
    double interestRate;
    int term;
};

void swap(struct CDAccountV1& v1, struct CDAccountV1& v2)
{   
    struct CDAccountV1 v3; // 전체적으로 바꿔주기 위해서 똑같이 struct 변수타입의 중간다리를 놓아주어야한다.
    v3 = v1;
    v1 = v2;
    v2 = v3;

   
}


int main()
{
    struct CDAccountV1 v1 = {10.0, 0.01, 60};
    struct CDAccountV1 v2 = {50.0, 0.02, 30};

    swap (v1, v2);
    cout << "balance: " << v1.balance
            <<" interest: " << v1.interestRate
            <<" terms: " << v1.term << endl;

    cout << "balance: " << v2.balance
             << " interest: " << v2.interestRate
             << " terms: " << v2.term << endl;        
    
}