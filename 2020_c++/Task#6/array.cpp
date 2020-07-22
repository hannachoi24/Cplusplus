#include <iostream>
using namespace std;

int main()
{  
    int a[4][4]= {10,20,30,40,
                     5,4,3,99,  
                     55,100,42,100,
                     0,105,2,11};
   int max = 0;
   int secondlargest = 0; 
    

    for (int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if (a[i][j]>max){
            secondlargest = max;
            max = a[i][j];}
        }
             
    }        
        
   cout << "The largest number is "<< max << endl;
   cout << "The second-largest number is "<< secondlargest << endl;

   return 0;

}  