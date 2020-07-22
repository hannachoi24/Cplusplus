#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
    string firstlow, secondlow, thirdlow, fourthlow, fifthlow, sixthlow ;
    fstream inputstream;

    inputstream.open("love.txt");

    inputstream >> firstlow >> secondlow;

    cout << firstlow, secondlow, thirdlow, fourthlow, fifthlow, sixthlow << secondlow << endl;
    inputstream.close();

    return 0;

}