#include <iostream>
using namespace std;

int main()
{
    int discretemath,programminglanguage,datastructure;
    double avg;
    
    switch (discretemath,programminglanguage,datastructure)
    {
        case 1:
        cout << " Put the discrete math score: "<< endl;
        cin>> discretemath;
        break;

        case 2:
        cout << " Put the programming language score: "<< endl;
        cin>> programminglanguage;
        break;

        case 3:
        cout << " Put the data structure score: "<< endl;
        cin>> datastructure;
        break;

        case 4:
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

    break;


   
      default: 
      cout << "none"<< endl;


    } 
}