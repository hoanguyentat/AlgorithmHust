#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>

using namespace std;
int numberCases;
char arr[100][1001];

void readData(){
	cin >> numberCases;
	if (numberCases < 1 || numberCases > 100)
	{
		exit(0);
	}
	for (int i = 0; i < numberCases; ++i)
	{
		char ch[1001];
		fflush(stdin);
		fgets(ch, 1001, stdin);
		fflush(stdin); 
		if (strlen(ch) > 1000)
		{
			exit(0);
		}
		strcpy(arr[i], ch);
	}
}

//Tra ve ket qua ung voi moi ki tu
void check(){
	for(int i =0 ; i < numberCases; i++){
		char result[5000] = "";
		for(int j = 0; j < strlen(arr[i]) - 1; j++){
			if ((arr[i][j] < 'a' || arr[i][j] > 'z') && arr[i][j] != ' ')
			{
				exit(0);
			}
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
			if(arr[i][j] == ' ' && arr[i][j + 1] == ' '){
					strcat(result, " ");
			}
			if(arr[i][j] >= 97 && arr[i][j] <= 99){
				if (arr[i][j+1] >= 97 && arr[i][j+1] <= 99)
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 100 && arr[i][j] <= 102){
				if (arr[i][j+1] >= 100 && arr[i][j+1] <= 102)
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 103 && arr[i][j] <= 105){
				if (arr[i][j+1] >= 103 && arr[i][j+1] <= 105)
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 106 && arr[i][j] <= 108){
				if (arr[i][j+1] >= 106 && arr[i][j+1] <= 108)
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 109 && arr[i][j] <= 111){
				if (arr[i][j+1] >= 109 && arr[i][j+1] <= 111)
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 112 && arr[i][j] <= 115){
				if (arr[i][j+1] >= 112 && arr[i][j+1] <= 115)
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 116 && arr[i][j] <= 118){
				if (arr[i][j+1] >= 116 && arr[i][j+1] <= 118)
				{
					strcat(result, " ");
				}
			}
			if(arr[i][j] >= 119 && arr[i][j] <= 122){
				if (arr[i][j+1] >= 119 && arr[i][j+1] <= 122)
				{
					strcat(result, " ");
				}
			}
		}
		cout <<"Case #"<< i + 1 << ": " << result << "\n";
	}
}
int main(int argc, char const *argv[])
{
	readData();
	check();
	return 0;
}

