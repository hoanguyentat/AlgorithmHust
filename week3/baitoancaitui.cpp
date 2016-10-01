#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
int n;
float b, a[30], c[30];
int check[30];
float sum = 0, count = 0, maxSum = 0;
void readData(){
	cin >> n;
	cin >> b;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		cin >> c[i];
		check[i] = 0;
	}
}
void duyet(int k){
	for (int i = 0; i < n; ++i)
	{
		if (count + a[i] <= b && check[i] == 0)
		{
			count += a[i];
			sum += c[i];
			if (sum > maxSum)
			{
				maxSum = sum;
			}
			check[i] = 1;
			duyet(k+1);
			count -= a[i];
			sum -= c[i];
			check[i] = 0;
		}
	}
}

int main(int argc, char const *argv[])
{
	readData();
	duyet(1);
	printf("%3.2f", maxSum);
	return 0;
}

