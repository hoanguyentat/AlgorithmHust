/**
  	* Đọc từng phàn tử
	* Dùng một mảng lưu lại giá trị của các hoán vị
	* Một mảng khỏi tại ban đầu bằng flase để kiểm tra xem phần tử đó đã được duyệt chưa
  	* Sinh ngẫu nhiên các tổ hợp bằng đệ toán đệ quy trong khi sinh kiem tra 
  		* Phần tử i đã được lưu trong mảng chưa, nếu chưa thì thên vào
    	* dãy con nếu k == n - 1 cộng thêm giá trị cho biến đếm,
  	*  In ra ket qua khi biến đếm bằng với vị trí đầu vào và thoát chương trình
  	* Muc do phuc tap thuat toan O(n2)
*/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;	

int arr[10000];

int hoanvi[10000];
int k, n;
int count = 0;

void Try(int index){
	if(index > n){
		count++;
		if (count == k)
		{
			for(int i=1;i<=n;i++){
				cout<<hoanvi[i] << " ";
			}
			exit(0);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(arr[i] == false){
			hoanvi[index] = i;
			arr[i] = true;
			Try(index+1);
			arr[i] = false;
		}
	}
}
int main(){
	scanf("%d", &n);
	scanf("%d", &k);
	for(int i=1; i <= n; i++){
		arr[i] = false;
	}
	Try(1);
	if (count < k)
	{
		printf("-1");
	}
	return 0;
}
