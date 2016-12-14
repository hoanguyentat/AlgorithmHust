/**
  	* Đọc từng phần tử
	* Dùng hai mảng lưu lại giá trị và trọng lượng
  	* Dùng đệ quy trong khi sinh kiem tra:
  		* Túi đó đã được sử dụng chưa
  		* Tổng trọng lượng đã vượt quá trọng lượng cho phép chưa, nếu chưa thì cộng thêm vào giá trị hiện tại
  		* giá trị của cái túi vừa trọn, tiếp tực đệ quy với các túi còn lại
  		* Kiểm tra tổng giá trị vừa thêm vào nếu lớn hơn tổng giá trị toàn cục thì gán cho tổng giá trị toàn cục giá trị đó
  	* In ra ket qua và thoát chương trình
  	* Muc do phuc tap thuat toan O(n2)
*/


#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
int n;
int b, a[30], c[30];
int sum = 0, count = 0, maxSum = 0;

void readData(){
	scanf("%d%d", &n, &b);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &a[i], &c[i]);
	}
}
int duyet(int k){
	if (k >= n){
		maxSum = maxSum > sum ? maxSum : sum;
		return 0;
	}
	else
		for (int i = 0; i < 2; ++i){	
			if (i){
				if (count + a[k] <= b){
					count += a[k];
					sum += c[k];
					duyet(k+1);
					count -= a[k];
					sum -= c[k];
				}
			} else duyet(k+1);			
		}
}

int main(int argc, char const *argv[]){
	readData();
	duyet(0);
	printf("%d", maxSum);
	return 0;
}

