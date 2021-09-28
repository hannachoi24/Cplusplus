#include <iostream>
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
