#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void readData(){
	int test;
	scanf("%d", &test);
	int a[100000];
	for (int i = 0; i < test; ++i)
	{
		scanf("%d", &a[i]);
	}
	int maxSum = 0;
	for (int i = 0; i < test; ++i)
	{
		int sum = 0;
		for (int j = i; j < test; ++j)
		{
			sum += a[j];
			if (maxSum < sum)
			{
				maxSum = sum;
			}
		}
	}
	printf("%d", maxSum);
}

int main(int argc, char const *argv[])
{
	readData();
	return 0;
}
