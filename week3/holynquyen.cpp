/**
	* Đọc từng phần tử cho đến khi gặp n = 0
	* Lưu lại tọa độ của hố bằng hai mảng một chiều
	* Dùng đệ toán đệ quy sinh vị trị của từng con hậu trên bàn cờ, trong khi sinh kiểm tra:
		* Vị trí hậu vừa sinh phải không nằm trong khả năng đi được của các con hậu trước
		* Vị trí hậu vừa sinh phải không ở vị trí hố
		* khi số hậu bằng n thì cộng giá trị biến đếm thêm một
	*  In ra kết quả
	* Muc do phuc tap thuat toan O(n2)
*/

#include <stdio.h>
#include <math.h>
#include <iostream>

int n = 1, count, holes;
int a[100];
int x[100], y[100];

// Kiểm tra khả năng có thể bị ăn hay không?
int uvch(int j, int k){

	for (int i = 0; i < holes; ++i)
	{
		if (k - 1 == x[i] && j - 1 == y[i])
		{
			return 0;
		}
	}
	for(int i=1; i<k; i++)
	   if ((j == a[i]) || (std::abs(j-a[i]) == (k-i))) return 0;
	return 1;
}

// Đệ quy sinh vị trí
int Hau(int i){
	for(int j=1; j<=n;j++)
	    if(uvch(j,i)){
	    	a[i] = j;
	    	if (i==n) {
	    		count++;
	    	}
	        else Hau(i+1);
	    }
}


int main(){
	while (1){
		scanf("%d",&n);
		if (n == 0)
		{
			return 0;
		}
		scanf("%d", &holes);
		for (int i = 0; i < holes; ++i)
		{
			scanf("%d", &x[i]);
			scanf("%d", &y[i]);
		}
		count = 0; 
		Hau(1);
		printf("\n%d",count);
	} 
}
