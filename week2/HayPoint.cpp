#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
void readData(){
	int point;
	int test_cases;
	cin >> point;
	cin >> test_cases;
	char a[point][17];
	int *b = new int[point];
	for (int i = 0; i < point; ++i)
	{	
		scanf("%s %d", a[i], &b[i]);
//		cin >> b[i];
	}
	for (int i = 0; i < test_cases; ++i)
	{
		char input[17] = " ";
		int salaryTotal = 0;
		while(strcmp(input, ".") != 0){
			scanf("%s",input);
			for (int j = 0; j < point; ++j)
			{
				if (strcmp(input, a[j]) == 0)
				{
					salaryTotal += b[j];
					break;
				}
			}
		}
		cout << salaryTotal << "\n";
	}
	delete []b;
}

int main(int argc, char const *argv[])
{
	readData();
	return 0;
}
