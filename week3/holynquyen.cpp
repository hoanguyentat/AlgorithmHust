#include <stdio.h>
#include <math.h>
#include <iostream>

int n = 1, count, holes;
int a[100];
int x[100], y[100];

int uvch(int j, int k){

	for (int i = 0; i < holes; ++i)
	{
		if (k - 1 == x[i] && j - 1 == y[i])
		{
			return 0;
		}
	}
	for(int i=1; i<k; i++)
	   if ((j == a[i]) || (std::abs(j-a[i]) == (k-i))) return 0;
	return 1;
}


int Hau(int i){
	for(int j=1; j<=n;j++)
	    if(uvch(j,i)){
	    	a[i] = j;
	    	if (i==n) {
	    		count++;
	    	}
	        else Hau(i+1);
	    }
}


int main(){
	while (1){
		scanf("%d",&n);
		if (n == 0)
		{
			return 0;
		}
		scanf("%d", &holes);
		for (int i = 0; i < holes; ++i)
		{
			scanf("%d", &x[i]);
			scanf("%d", &y[i]);
		}
		count = 0; 
		Hau(1);
		printf("\n%d",count);
	} 
}
