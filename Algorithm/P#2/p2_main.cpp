#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "p2_solution.h"
using namespace std;

Solution s;

/* The following main function is for your convinience. 
 * Evaluation will be conducted through our own evaluation system, not this file.
 * You are free to utilize/edit source codes of "main.cpp".
 * But, DO NOT include the "main.cpp" file into your homework submission.
 */ 

int main (void)
{
    vector<int> arr;
    int K=0, len=0, ans, tmp;
    Solution s;
    
    /* Initialize */
    ifstream ifs ("sample1.txt");
    if (ifs.is_open())
    {
        ifs >> len >> K;
        for (int i=0; i<len; i++)
        {
            ifs >> tmp;
            arr.push_back(tmp);
        }
    }

    if (len <= 0)
        return -1;

    /* Run your codes */
    clock_t begin = clock();    
    ans = s.kMost (arr, len, K);
    clock_t end = clock();
    
    /* Print output */
    cout << ans;
    cout << "Elapsed time: " << double (end - begin)/CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}