#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int n, k, i;
int count = 0;
int a[10001];

bool checkString(int m){
	int check = 0;
	for (int j = 0; j <= m; ++j){
		if (a[j] == 0){
			check++;
			if (check >= i) return 0;
		}
		else check = 0;
	}
	return 1;
}

void print(){
	count++;
	if (count == k){
		printf("\n");
		for (int j = 0; j < n; ++j){
			printf("%d ", a[j]);
		}
		exit(0);
	}	
}

void Try(int k){
	for (int j = 0; j <= 1; ++j){
		a[k] = j;
		if (!checkString(k)){
			continue;
		}
		if (k == n-1){
			print();
		}
		else Try(k+1);
	}
}

int main(int argc, char const *argv[]){
	cin >> n;
	cin >> k;
	cin >> i;
	Try(0);
	if(count < k) printf("-1");
	return 0;
}

