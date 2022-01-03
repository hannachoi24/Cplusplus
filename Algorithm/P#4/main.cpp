#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>
#include "p4Solution.hpp"
using namespace std;

/* This main function is only for reference. 
 * Evaluation will be made by other main function tailored for grading 
 * Please, DO NOT submit main.cpp and solution.h files 
 */

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> problem;
    int len;
    int tmp;

    /* Initialize */
    ifstream ifs("C:/Users/choihanna/Desktop/C++/Algorithm/P#4/sample1.txt");
    if (ifs.is_open())
    {
        ifs >> len;
        for (int i = 0; i < len; i++)
        {
            ifs >> tmp;
            problem.push_back(tmp);
        }
    }

    /* Run your codes */
    clock_t begin = clock();
    bool answer;

    answer = s.IsPossible(problem);
    clock_t end = clock();

    cout << "answer(1:true 0:false): ";
    if (answer)
        std::cout << "True"
                  << " " << endl;
    else
        std::cout << "TFalse"
                  << " " << endl;
    cout << "Elapsed time: " << double(end - begin) / CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}