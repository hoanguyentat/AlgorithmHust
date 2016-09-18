/**
	* Doc tung dong input
	* Nếu a > b thì a ^ b < b ^a : a, b thuộc N* trừ trường hợp a = 2, b = 3(đã chứng minh)
	* Trong lúc đọc dữ liệu nếu giá trị biến là 1 thì in ra màn hình ngược lại thì cho vào mảng
	* Sắp xếp mảng dữ liệu vừa nhập và in ra kết quả theo chiều giảm dần đến trường hợp 2 và 3 thì in theo 2 trước 3 sau
	* do phuc tap O(nlogn) theo độ phức tạp của thuật toán sắp xếp
*/


#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void result(int*, int, int);
void readData(){
	int test_cases;
	cin >> test_cases;
	for (int i = 0; i < test_cases; ++i){
		int number;
		int input, number1 = 0, count = 0;
		cin >> number;
		int *arr = new int[number];
		for (int j = 0; j < number; ++j){
			cin >> input;
			if (input == 1)
			{
				number1++;
			}
			else{
				arr[count++] = input;
			}
		}
		result(arr, count, number1);
		delete []arr;
	}
}

void result(int *a, int count, int number1){
	for (int i = 0; i < number1; ++i)
	{
		printf("1 ");
	}
	sort(a, a + count);
	if (count == 2 && a[0] == 2 && a[1] == 3){
		cout << "2 3\n";	
	}
	else{
		for (int i = count -1 ; i >= 0 ; --i){
			cout << a[i] << " ";
		}
		cout << "\n";
	}
}

int main(int argc, char const *argv[])
{
	readData();
	return 0;
}

