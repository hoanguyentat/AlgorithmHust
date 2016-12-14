/**
	* Đọc từng phàn tử
	* Sinh ngẫu nhiên các xâu nhị phân bằng đệ toán đệ quy  trong khi sinh kiem tra 
		* day con da sinh xem co chua i so 0 lien tiep k, neu co thi loai bo truong hop nay,
		* neu khong thi tiep tuc duyet, neu k == n - 1 cộng thêm giá trị cho biến đếm, 
		* khi biến đếm bằng số thự tự đầu vào thì in ra
	*  In ra ket qua
	* Muc do phuc tap thuat toan O(n2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int n, k, i;
int count = 0;
int a[10001];

// kiem tra xem xau co chua i day con lien tiep khong!
bool checkString(int m){
	int check = 0;
	for (int j = 0; j <= m; ++j){
		if (a[j] == 0){
			check++;
			if (check >= i) return 0;
		}
		else check = 0;
	}
	return 1;
}

void print(){
	count++;
	if (count == k){
		for (int j = 0; j < n; ++j){
		 	(j < n - 1) ? printf("%d ", a[j]) : printf("%d", a[j]);
		}
//		printf("\n");
		exit(0);
	}	
}

// De quy sinh phan tu
void Try(int k){
	for (int j = 0; j <= 1; ++j){
		a[k] = j;
		if (!checkString(k)){
			continue;
		}
		if (k == n-1){
			print();
		}
		else Try(k+1);
	}
}

int main(int argc, char const *argv[]){
	cin >> n;
	cin >> k;
	cin >> i;
	Try(0);
	if(count < k) printf("-1");
	return 0;
}

