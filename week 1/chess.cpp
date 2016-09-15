/**
	* Doc o dong input
	* Kiem tra dau vao khong hop le
	* Kiem tra kha nang co the an nhau cua quan tinh, qua ot nuoc, hai nuoc hoac khong the
	* do phuc tap O(n)
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;
char a[100][5];
void check(char a[], char b[]){
	a[0] -= 65;
	b[0] -= 65;
	a[1] -= 49;
	b[1] -= 49;
	if (a[0] < 0 || a[0] > 7 || a[1] < 0 || a[1] > 7 || b[1] < 0 || b[1] > 7 || b[0] < 0 || b[0] > 7)
	{
		cout << "Impossible\n";
	}
	else if ((abs(a[0] - a[1])%2 == 1 && abs(b[0] - b[1])%2 == 0) || (abs(a[0] - a[1])%2== 0 && abs(b[0] - b[1])%2 == 1) )
	{
		cout << "Impossible\n";
	}
	// Cung tren mot duong cheo
	else if( a[0] == b[0] && a[1] == b[1]){
		printf("0 %c %c\n",a[0]+65, a[1]+49);
	}
	else if(abs(a[0] - b[0]) == abs(a[1] - b[1])){
		printf("1 %c %c %c %c\n",a[0]+65, a[1]+49, b[0]+65, b[1]+49);
	}
	// Nam tren hai duong cheo khac nhau
	else
	{
		int midX = (a[0] - a[1] + b[0] + b[1])/2;
		int midY = (b[0] + b[1] - a[0] + a[1])/2;
		if (midY > 7 || midY < 0 || midX > 7 || midX < 0)
		{
			midX = (b[0] - b[1] + a[0] + a[1])/2;
			midY = (a[0] + a[1] - b[0] + b[1])/2;
		}
		printf("2 %c %c %c %c %c %c\n",a[0]+65, a[1]+49,midX+65, midY+49, b[0]+65, b[1]+49);
	}
}

void readData(){
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		char a[2], b[2];
		// char ch[10];
		// cin >> ch;
		cin >> a[0];
		cin >> a[1];
		cin >> b[0];
		cin >> b[1];
		check(a, b);
	}
}

int main()
{
	readData();
	return 0;
}
