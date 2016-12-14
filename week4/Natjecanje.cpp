#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

void readData(){
	int n, s, r;
	scanf("%d%d%d",&n,&s, &r);
	int arrS[s], arrR[r];
	for (int i = 0; i < s; ++i)
	{
		scanf("%d",&arrS[i]);
		printf("%d",arrS[i]);
	}
	printf("\n");
	for (int i = 0; i < r; ++i)
	{
		scanf("%d",&arrR[i]);
		printf("%d",arrR[i]);
	}
}
int main(int argc, char const *argv[])
{
	readData();
	return 0;
}
