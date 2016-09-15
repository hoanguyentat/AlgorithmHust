#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void readData(){
	int no1, no2;
	cin >> no1;
	cin >> no2;
	while (no2 != 0 or no1 != 0){
		int jack[no1];
		int jin[no2];
		int count = 0;
		for (int i = 0; i < no1; ++i)
		{
			cin >> jack[i];
		}
		for (int i = 0; i < no2; ++i)
		{
			cin >> jin[i];
			for (int j = 0; j < no1; ++j)
				if (jack[j] == jin[i])
				{
					++count;
				}
		}
		cout << count;
		cin >> no1;
		cin >> no2;
	}
}

int main(int argc, char const *argv[])
{
	readData();
	return 0;
}

