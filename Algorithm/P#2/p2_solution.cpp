#include <iostream>
#include "p2_solution.h"
using namespace std;

int Solution::kMost(std::vector<int> &arr, int len, int k)
{
    //Fill up here with your own code.

    // vector<int> arr;
    // int K = 0, len = 0, ans, tmp;
    // Solution s;
    cin >> k;
    cin >> arr;
    int ans = 0;

    int count[k + 1];
    for (int i = 0; i < k + 1; i++)
        count[i] = 0;

    for (int i = 0; i < len; i++)
        count[arr[i]]++;

    for (int i = 0, j = 0; i <= k; i++)
    {
        while (count[i] > 0)
        {
            arr[j] = i;
            j++;
            count[i]--;
        }
    }

    return ans;
}

/* 
K번째로 많은 원소 찾기
개요 및 요구사항
주어진 길이 n의 정수 배열에서, K번째로 많이 등장한 원소를 반환하는 알고리즘을 작성하세요.

입출력예
(입력1)
10
5
1 1 2 2 3 3 4 4 4 5

(출력1)
5

4 - 3개
1 - 2개
2 - 2개
3 - 2개
5 - 1개 
5번째로 많은 수 == 5
(입력2)
10
2
1 1 2 2 3 3 4 4 4 5

(출력2)
1

4 - 3개
1 - 2개
2 - 2개
3 - 2개
5 - 1개 
2번째로 많은 수 == 1 or 2 or 3
첫째줄에, 배열의 길이 len이 입력됩니다.

둘째줄에, K가 입력됩니다.

셋째줄에, 배열의 원소들이 입력됩니다.

제공한 sample1.txt 파일과, main.cpp 파일을 참고하세요.

상세조건
0 < len <= 10,000

0 < K <= the number of unique elements in arr

0 < each element <= 10,000

정답이 다수인 경우, 그 중 하나만 출력해도 정답으로 인정 (위 입력2의 경우 1,2,3 모두 정답으로 인정함)

*/