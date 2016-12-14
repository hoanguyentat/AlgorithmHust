#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;
void readData(){
	int k, l, n;
	scanf("%d%d%d", &k, &l, &n);
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		printf("%d\n", a[i]);
	}
}
int main(int argc, char const *argv[])
{
	readData();
	return 0;
}