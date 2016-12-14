/**
	* Doc tung du lieu dau vao va xu ly luon de in ra ket qua
	* Doi voi n > 10000000 thi khong luu lai ket qua ung voi n do khong du bo nho
	* Doi voi n < 10000000 thi luu lai cac ket qua vao mot mang de khi gap n thi chi 
		* viec in ra ket qua ma khong can tinh toan lai
	* Muc do thuat toan O(n^2)
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
long long int d[10000005];

using namespace std;

long long int result(long long int n){
	
	if (n == 0)return 0;
	

	
	if(n >= 10000000){
		if (n > result(n/2) + result(n/3) + result(n/4)){
			return n;
		}else{
			return result(n/2) + result(n/3) + result(n/4);
		}
	}
	
	if(d[n]!=0) return d[n];
	else{
		if (n > result(n/2) + result(n/3) + result(n/4)){
			d[n] = n;
		}else{
			d[n] = result(n/2) + result(n/3) + result(n/4);
		}
	}
	return d[n];
}

void readData(){
	long long int n;
	for (int i = 0; i < 10000005; ++i)
	{
		d[i]= 0;
	}
	while(scanf("%lld", &n) != EOF) {
		printf("%lld\n",result(n));
	}
}

int main(int argc, char const *argv[])
{
	readData();
	return 0;
}

