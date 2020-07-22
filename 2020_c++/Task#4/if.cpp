#include <iostream>
using namespace std;

int main()
{
    int discretemath,programminglanguage,datastructure;
    double avg;

    cout << "Put the discrete math score: ";
    cin >> discretemath;
    std::cout << "Put the programming language score: ";
    cin >> programminglanguage;
    std::cout << "Put the data structure score: ";
    cin >> datastructure;
    avg= (int) (discretemath+programminglanguage+datastructure)/3;



    if(avg>85)
    cout << "The average score is 86.33 and the grade is B+" << endl;
    else if(avg>80)
    cout << "B0" << endl;
    else if(avg>75)
    cout << "C+" << endl;
    else if(avg>70)
    cout << "C0" << endl;
    else
    cout << "F" << endl;

    
    

}



