#include <iostream>
#include "solution.h"
using namespace std;

void insertion_sort(int arr[], int len)
{
	cout << "Insertion" << '\n';
	bool flag = false;

	for (int i = 0; i < len; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] > arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
				flag = true;
			}
			else
			{
				break;
			}
		}

		if (flag)
		{
			for (int i = 0; i < len; i++)
			{
				cout << arr[i] << ' ';
			}
			cout << '\n';
		}
		flag = false;
	}
}

void bubble_sort(int arr[], int len)
{
	cout << "Bubble" << '\n';
	bool flag = false;

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < (len - 1) - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = true;
			}
		}

		if (flag)
		{
			for (int i = 0; i < len; i++)
			{
				cout << arr[i] << ' ';
			}
			cout << endl;
		}

		flag = false;
	}
}

/* 
Sorting algorithm implementation 
개요 및 요구사항
주어진 배열을 내림차순으로 정렬하는 두 가지 정렬 알고리즘을 작성하세요.

정렬 알고리즘 수행 중, 각 단계별 (each outer loop) 중간 값을 출력하여 작동을 확인하세요.

입/출력예
main.cpp

int arr[5] = {1,2,4,3,5};
int arr2[5] = {1,2,4,3,5};
int len = 5;

insertion_sort (arr, len);
bubble_sort (arr2, len);
출력

Insertion
2 1 4 3 5
4 2 1 3 5
4 3 2 1 5
5 4 3 2 1

Bubble
2 4 3 5 1 
4 3 5 2 1 
4 5 3 2 1
5 4 3 2 1
위 예제와 같이, outer loop의 매 iteration 마다 결과를 출력하세요.
*/