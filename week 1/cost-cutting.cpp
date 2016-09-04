#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>

using namespace std;

int cutting(int a, int b, int c){
	int tem;
	if (a < b)
	{
		if (a > c)
		{
			tem = a;
		}
		else if (b < c)
		{
			tem = b;
		} else tem = c;
	}
	else {
		if (a < c)
		{
			tem = a;
		} else if (b > c)
		{
			tem = b;
		} else tem = c;
	}
	return tem;
}

int main(int argc, char const *argv[])
{
	int number;
	cin >> number;
	for (int i = 0; i < number; ++i)
	{
		int a[3];
		for (int i = 0; i < 3; ++i)
		{
			cin >> a[i];
		}
		cout << "Case " << i +1 << ": " << cutting(a[0], a[1], a[2]) << "\n";
	}
	return 0;
}

