#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;	

int arr[10000][2];

int hoanvi[10001];
int k, n;
int count = 0;

void Try(int index){
	if(index > n){
		count++;
		if (count == k)
		{
			for(int i=1;i<=n;i++){
				cout<<hoanvi[i] << " ";
			}
			exit(0);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(arr[i][1] == false){
			hoanvi[index] = arr[i][0];
			arr[i][1] = true;
			Try(index+1);
			arr[i][1] = false;
		}
	}
}
int main(){
	scanf("%d", &n);
	scanf("%d", &k);
	for(int i=1; i <= n; i++){
		arr[i][0] = i;
		arr[i][1] = false;
	}
	Try(1);
	if (count < k)
	{
		printf("-1");
	}
	return 0;
}
