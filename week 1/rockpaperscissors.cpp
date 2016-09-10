/**
	* Doc tung dong input
	* Kiem tra dau vao khong hop le
	* Ham kiem tra kha nang thang thu cua mot van
	* Khi nguoi choi thang, thua thi cong them mot vao bien nho tuong ung voi nguoi do, hoa thi giu nguyen
	* do phuc tap O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int n = 1, k, total;

char a[100][10];

// kiem tra thang, thua
int check(char x[], char y[]){
	if (strcmp(x, y) == 0) return 0;
	if (strcmp(x, "rock") == 0)
	{
		if (strcmp(y, "paper") == 0)
		{
			return 1;
		}
		else return -1;
	}
	else if (strcmp(x, "paper") == 0)
	{
		if (strcmp(y, "scissors") == 0)
		{
			return 1;
		}
		else return -1;
	}

	else
	{
		if (strcmp(y, "rock") == 0)
		{
			return 1;
		}
		else return -1;
	}
}

// In ket qua ra man hinh
void result(int b[], int c[], int num){
	cout << "\n";
	for (int i = 0; i < num; ++i)
	{
		if (b[i] == 0 && c[i] == 0)
		{
			printf("-\n");
		}
		else printf("%3.3f\n", (double) b[i] /(b[i] + c[i]) );
	}
}
void readData(){
	//Tang bien dem khi thang hoac thua tuong ung voi nguoi choi
	while( n != 0){
		cin >> n;
		cin >> k;
		int win[100] = {0}, los[100] = {0};
		total = k * n*(n-1)/2;
		for(int i  = 0; i < total; i++){
			int p, q;
			cin >> p;
			cin >> a[p-1];
			cin >> q;
			cin >> a[q-1];
			;
			if (check(a[p-1], a[q-1]) == 1)
			{
				win[q-1]++;
				los[p-1]++;
			}
			if (check(a[p-1], a[q-1]) == -1)
			{
				win[p-1]++;
				los[q-1]++;
			}
		}
		result(win, los, n);
	}
}

int main(int argc, char const *argv[])
{
	readData();
	return 0;
}