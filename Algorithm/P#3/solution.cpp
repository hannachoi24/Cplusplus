#include <iostream>
#include "solution.h"
#include <queue>
#include <fstream>
using namespace std;

/* Fill free to implement any function on here */
unsigned long long int result;
unsigned long long int temp;

void leafSearch(TreeNode *node)
{
    if (node->left != NULL)
    {
        temp = temp * 10 + node->val;
        leafSearch(node->left);
        if (node->right != NULL)
            leafSearch(node->right);
        temp = temp / 10;
    }
    else
        result += node->val + temp * 10;
}

unsigned long long int Solution::getPathSum(struct TreeNode *root)
{

    /* Fill up with your own codes */
    result = temp = 0;
    leafSearch(root);
    return result;
}

struct TreeNode *Solution::buildTree(string filename)
{
    /* Fill up with your own codes */
    int n = 0;
    TreeNode *root = new TreeNode;
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> n;
        n -= 1;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            ifs >> front->val;
            if (n > 0)
            {
                front->left = new TreeNode;
                q.push(front->left);
                --n;
            }
            else
                front->left = NULL;

            if (n > 0)
            {
                front->right = new TreeNode;
                q.push(front->right);
                --n;
            }
            else
                front->right = NULL;
        }
    }
    return root;
}

/*
트리의 경로 합 계산
개요 및 요구사항
0-9 사이의 값을 가지는 이진 트리 (Binary tree) 에서, 루트에서 리프로 가는 모든 경로들의 값의 합을 구하는 프로그램을 작성하세요

각 경로의 값은 경로 상에 존재하는 각 노드의 값을 10^i 자리에 배치하여 결정함.

예: 1->2->3 노드를 거치는 경로의 값: 123

주어진 입력 값을 linked list 형태의 완전이진트리 (Complete binary tree) 로 구성하세요.

구성한 이진트리에서, 루트에서 출발하여 리프에 도달하는 모든 경로의 값을 더한 값을 계산하여 출력하세요.

첨부된 코드 템플릿 및 입력 샘플을 참조하세요

입력 및 연산 예
첫 번째 줄에, 노드의 갯수가 입력됩니다.

두 번째 줄에, 각 노드 값의 목록이 입력됩니다.

일반적으로 사용하는 트리의 배열 구현 규칙을 활용하여 완전이진트리를 linked list 형태의 자료구조로 구성하세요. 완전이진트리를 BFS로 탐색하였을 때와 동일한 순서로 노드값이 입력됨에 유의하세요.

예시1:
3
1 2 3

  1 
 /  ⧵ 
2    3

경로 1->2 의 값: 12
경로 1->3 의 값: 13
모든 경로의 합 = 12+13 = 25

예시2:
5
2 3 0 1 2

    2
   / ⧵
  3   0 
 / ⧵  
1   2  

경로 2->3->1 의 값: 231
경로 2->3->2 의 값: 232
경로 2->0 의 값: 20
모든 경로의 합 = 231 + 232 + 20 = 483
*/