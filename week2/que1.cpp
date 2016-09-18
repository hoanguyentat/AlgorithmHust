/**
	* Doc tung dong input
	* Kiem tra so hau tren cung mot hang, cot, duong cheo
	* Ứng với mỗi dãy nhập vào mà có trọng số bằng 0 thì 
	  thằng nhỏ nhất trong tất cả sẽ là thằng đứng đầu tiên khi duyệt xong thì 
	  loại bỏ số đó ra khỏi danh sách và kiểm tra xem đối với những số còn lại 
	  số nào nhỏ hơn số vừa loại thì trừ trọng số đi 1, tiếp tục duyệt như trên 
	  cho đến khi số phần tử bằng 0
	* do phuc tap O(n2)
*/
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int count;

int result(int *a, int *b, int mem){
	if (mem <= 0){
		free(a);
		free(b);
		return 0;
	}
	int min = 1000000;
	for (int i = 0; i < mem; ++i){
		if (b[i] == 0){
			if (a[i] < min){
				min = a[i];
			}
		}
	}
	printf("%d ", min);
	int *p = (int*) malloc ((mem-1) * sizeof(int));
	int *q = (int*) malloc ((mem-1) * sizeof(int));
	int k = 0;
	for (int i = 0; i < mem; ++i){
		if (a[i] != min){
			p[k] = a[i];
			if (a[i] < min){
				q[k] = b[i]-1;
			}
			else{
				q[k] = b[i];
			}
			k++;
		}
	}
	free(a);
	free(b);
	result(p, q, mem-1);
}

void readData(){
	cin >> count;
	for (int i = 0; i < count; ++i){
		int *a;
		int *b;
		int mem;
		cin >> mem;
		a = (int*) malloc (mem* sizeof(int));
		b = (int*) malloc (mem* sizeof(int));
		for (int j = 0; j < mem; ++j){
			cin >> a[j];
		}
		for (int j = 0; j < mem; ++j){
			cin >> b[j];
		}
		result(a, b, mem);
	}
}

int main()
{
	readData();
	return 0;
}


