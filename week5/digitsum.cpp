/**
	* Doc tung du lieu dau vao theo dong
	* Cach tinh result = result(end) - result(start -1);
	* Ham result:
		* Doi voi gia tri truyen vao < 10 thi tra ve tong cac so
		* Doi voi gia tri truyen vao(n) > 10:
			* n = 10*k -1 tra ve 10 * result(n/10) + (n/10+1)*45;
			* n != 10*k +1 tra ve result(n-1) + digitSum(n);
			Ham digitSum la ham tinh tong cac chu so cua n(dung de qui)
	* Muc do phuc tap thuat toan O(n2);	
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int digitsum(int n){
	if (n < 10){
		return n;
	}
	return digitsum(n/10) + (n%10); 
}

int getResult(int b){
	if (b < 10){
		int sum = 0;
		for(int i = 0; i <= b; i++) sum += i;
		return sum;
	} else {
		if (b % 10 == 9){
			return (10 * getResult(b/10) + (b/10+1)*45);
		} else {
			return (getResult(b-1) + digitsum(b));
		}
	}
}

void readData(){
	int test_cases;
	cin >> test_cases;
	for (int i = 0; i < test_cases; ++i)
	{
		int start, end;
		scanf("%d%d", &start, &end);
		// cout << getResult(start-1) << " " << getResult(end) << endl;
		int result = getResult(end) - getResult(start-1);
		cout << result <<"\n";
	}
}

int main(int argc, char const *argv[])
{
	readData();
	return 0;
}


