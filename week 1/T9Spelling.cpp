/**
	* Doc tung dong input
	* Kiem tra dau vao khong hop le
	* Duyet tung ki tu, chen them xau tuong ung vao trong ket qua
	* do phuc tap O(n)
*/

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
int numberCases;
char arr[101][1001];
char ch[1001];
void readData(){
	cin >> numberCases;
	if (numberCases < 1 || numberCases > 100){
		exit(0);
	}
	for (int i = 0; i < numberCases; ++i){
		fflush(stdin);
		
		fgets(ch, 1001, stdin);
		fflush(stdin); 
		if (strlen(ch) > 1000){
			exit(0);
		}		
		strcpy(arr[i],ch);
	}
}

//Tra ve ket qua ung voi moi ki tu
void check(){
	for(int i = 0 ; i < numberCases; i++){
		char result[5000] = "";
		for(int j = 0; j < strlen(arr[i]) - 1; j++){
			if ((arr[i][j] < 'a' || arr[i][j] > 'z') && arr[i][j] != ' '){
				exit(0);
			}

			//Tra ve ket qua ung voi moi ki tu
			switch(arr[i][j]){
				case ' ': strcat(result, "0"); break;
				case 'a': strcat(result, "2"); break;
				case 'b': strcat(result, "22"); break;
				case 'c': strcat(result, "222"); break;
				case 'd': strcat(result, "3"); break;
				case 'e': strcat(result, "33"); break;
				case 'f': strcat(result, "333"); break;
				case 'g': strcat(result, "4"); break;
				case 'h': strcat(result, "44"); break;
				case 'i': strcat(result, "444"); break;
				case 'j': strcat(result, "5"); break;
				case 'k': strcat(result, "55"); break;
				case 'l': strcat(result, "555"); break;
				case 'm': strcat(result, "6"); break;
				case 'n': strcat(result, "66"); break;
				case 'o': strcat(result, "666"); break;
				case 'p': strcat(result, "7"); break;
				case 'q': strcat(result, "77"); break;
				case 'r': strcat(result, "777"); break;
				case 's': strcat(result, "7777"); break;
				case 't': strcat(result, "8"); break;
				case 'u': strcat(result, "88"); break;
				case 'v': strcat(result, "888"); break;
				case 'w': strcat(result, "9"); break;
				case 'x': strcat(result, "99"); break;
				case 'y': strcat(result, "999"); break;
				case 'z': strcat(result, "9999"); break;
			}
			//chen them khoang trang voi cac ki tu cung mot so
			if(arr[i][j] == ' ' && arr[i][j + 1] == ' '){
					strcat(result, " ");
			}
			if(arr[i][j] >= 'a' && arr[i][j] <= 'c'){
				if (arr[i][j+1] >= 'a' && arr[i][j+1] <= 'c')
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 'd' && arr[i][j] <= 'f'){
				if (arr[i][j+1] >= 'd' && arr[i][j+1] <= 'f')
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 'g' && arr[i][j] <= 'i'){
				if (arr[i][j+1] >= 'g' && arr[i][j+1] <= 'i')
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 'j' && arr[i][j] <= 'l'){
				if (arr[i][j+1] >= 'j' && arr[i][j+1] <= 'l')
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 'm' && arr[i][j] <= 'o'){
				if (arr[i][j+1] >= 'm' && arr[i][j+1] <= 'o')
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 'p' && arr[i][j] <= 's'){
				if (arr[i][j+1] >= 'p' && arr[i][j+1] <= 's')
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 't' && arr[i][j] <= 'v'){
				if (arr[i][j+1] >= 't' && arr[i][j+1] <= 'v')
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 'w' && arr[i][j] <= 'z'){
				if (arr[i][j+1] >= 'w' && arr[i][j+1] <= 'z')
				{
					strcat(result, " ");
				}
			}
		}
		// cout <<"Case #"<< i + 1 << ": " << result ;
		printf("Case #%d: %s\n",i+1, result);
	}
}
int main()
{
	fflush(stdin);
	readData();
	check();
	return 0;
}

