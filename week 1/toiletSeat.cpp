/**
	* Doc tung dong input
	* Kiem tra dau vao khong hop le
	* Ung voi moi truong hop tinh so thay doi
	* do phuc tap O(n)
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;
char pos1, pos2, pos3;
char input[1001];
int len, up = 0, down = 0, old = 0;
void readData(){
	cin >> input;
	pos1 = pos2 = pos3 = input[0];
	len = strlen(input);
	// if(len < 2 || len > 1000 ) exit(0);
	// for(int i = 0; i < len; i++){
	// 	if(input[i] != 'U' && input[i] != 'D') exit(0);
	// }
}

void leave(){
	for (int i = 1; i < len; i++){
		// Tinh so thay doi theo truong hop roi khoi lat len
		if(input[i] != pos1) up++;
		if(input[i] != 'U') up++;
		pos1 = 'U';
		
		// Roi khoi lat xuong
		if(input[i] != pos2) down++;
		if(input[i] != 'D') down++;
		pos2 = 'D';
		
		// roi khoi giu nguyen
		if(input[i] != pos3) old++;
		pos3 = input[i];
	}
}

int main(){
	readData();
	leave();
	cout << up << "\n" << down << "\n" << old;
	return 0;
}

