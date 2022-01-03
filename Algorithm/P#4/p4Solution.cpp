#include "p4Solution.hpp"
/* Write Your Code Below*/
/* You Can Decalre anoter Function In this file */
const int MAX = 4001;
int dir[MAX];
bool check[MAX];
bool visit[MAX];

struct Node
{
    int val, idx, k;
};

bool Solution::IsPossible(vector<int> &stones)
{
    int N = stones.size();

    for (int i = 0; i < N; i++)
    {
        check[stones[i]] = true; // 돌의 존재여부(true면 있는 돌)
        dir[stones[i]] = i;      // 점프했을 때 돌의 인덱스
    }

    queue<Node> q;
    q.push({stones[0], 0, 0});

    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        int k = now.k;   // k: 이전 점프값
        int v = now.val; // v: 현재 내가 위치해 있는 돌

        if (now.idx == N - 1)
            return true;
        if (visit[v])
            continue;

        visit[v] = true;

        if (!visit[v + k + 2] && check[v + k + 2] == true)
        {
            q.push({v + k + 2, dir[v + k + 2], k + 2});
        }
        if (!visit[v + k + 1] && check[v + k + 1] == true)
        {
            q.push({v + k + 1, dir[v + k + 1], k + 1});
        }
        if (!visit[v + k] && check[v + k] == true)
        {
            q.push({v + k, dir[v + k], k});
        }
        if (!visit[v + k - 1] && check[v + k - 1] == true)
        {
            q.push({v + k - 1, dir[v + k - 1], k - 1});
        }
        if (!visit[v + k - 2] && check[v + k - 2] == true)
        {
            q.push({v + k - 2, dir[v + k - 2], k - 2});
        }
    }

    return false;
}
