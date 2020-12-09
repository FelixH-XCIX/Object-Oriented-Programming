#include "PrintCombination.h"
#include <iostream>
using namespace std;

void PrintCombination(int* arr, const int& n, const int& r)
{
	int* data = new int[r];
	combinationUtil(arr, n, r, 0, data, 0);
}


void combinationUtil(int arr[], int n, int r, int index, int data[], int i)
{
	if (index == r)
	{
		for (int j = 0; j < r; j++)
		{
			if(j == r-1)
				cout << data[j];
			else
				cout << data[j] << " ";
		}
			
		cout << endl;
		return;
	}
	if (i >= n)
		return;

	data[index] = arr[i];
	combinationUtil(arr, n, r, index + 1, data, i + 1);

	combinationUtil(arr, n, r, index, data, i + 1);
}