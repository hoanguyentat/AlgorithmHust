/**
	* Doc tung dong input
	* Kiem tra dau vao khong hop le
	* Kiem tra so hau tren cung mot hang, cot, duong cheo
	* do phuc tap O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


int arr[8][8] = {0};
int count = 0; // tong so hau tren ban co
int rows[8] = {0}, cols[8] = {0}, diagonalL[16] = {0}, diagonalR[16] = {0}; 

// Doc du lieu dau vao va khoi tao mang hai chieu the hien vi tri quan hau tren ban co
void readData(){
	char input;
	for(int i= 0; i < 8; i++){ 
		for(int j = 0; j < 8; j++){
			cin >> input;
			if(input == '*'){
				count++;  // cong them mot khi co hau
				arr[i][j] = 1;
			}
			else if (input == '.'){
				arr[i][j] = 0;
			}
			else{
				cout << "invalid";
				exit(0);
			}
		}
	}
}

// kiem tra hau co an nhau khong?
void check(){
	for(int i= 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(arr[i][j] == 1 ){
				rows[i]++;
				cols[j]++;
				diagonalL[i-j + 8]++;
				diagonalR[i+j]++;
			}
		}
	}
}

int main(){
	readData();
	
	if (count < 8) {
		cout << "\ninvalid";
		return 0;
	}
	check();
	
	for(int i = 0; i < 8; i++){
		if(rows[i] > 1 || cols[i] > 1){
			cout << "\ninvalid";
			return 0;
		}
	}
	for(int i = 0; i < 16; i++){
		if(diagonalL[i] > 1 || diagonalR[i] > 1){
			cout << "\ninvalid";
			return 0;
		}
	}
	cout << "\nvalid";
	return 0;
}
