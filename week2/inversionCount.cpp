#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int result(int *a,int number){
	int re = 0;
	for (int i = 0; i < number; ++i)
	{
		for (int j = i+1; j < number; ++j)
		{
			if (a[i] > a[j])
			{
				re++;
			}
		}
	}
	return re;
}

unsigned long long int merge_sort(int *a, int left,int mid, int right){
	int i = left;
	int j = mid+1;
	unsigned long long int count = 0;
	int* tmp = new int[right+1];
	for (int k = left; k <= right; ++k)
	{
		if (i > mid)
		{
			tmp[k] = a[j];
			j++;
		}
		else if (j > right)
		{
			tmp[k] = a[i];
			i++;
		}
		else if (a[i] < a[j])
			{
				tmp[k] = a[i];
				i++;
			}
		else{
			tmp[k] = a[j];
			count += mid + 1 - i;
			j++;
		}
	}
	for (int k = left; k <= right; ++k)
	{
		a[k] = tmp[k];
	}
	delete []tmp;
	return count;
}

unsigned long long int merge(int *a, int left, int right){
	if (right - left < 1){
		return 0;
	}
	int mid = (left + right)/2;
	return 	merge(a,left, mid) + merge(a, mid+1, right) + merge_sort(a, left, mid, right);
}

void readData(){
	int test_cases;
	cin >> test_cases;
	for (int i = 0; i < test_cases; ++i)
	{
		int number;
		int *arr;
		cin >> number;
		arr = new int[number];
		for (int j = 0; j < number; ++j)
		{
			cin >> arr[j];
		}
		
		cout << merge(arr, 0, number - 1) <<"\n" ;
		delete []arr;
	}
}

int main(int argc, char const *argv[])
{
	readData();
	return 0;
}
