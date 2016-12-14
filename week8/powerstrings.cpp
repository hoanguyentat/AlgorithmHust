/** 
    Cho mot day ki tu dau vao
    Dua ra so luy thua cao nhat cua day do
    Khoi tao day moi temp = str[1:n] + str; (str[1:n] lay het ki tu cua chuoi str tru ki tu dau tien)
    Tim vi tri xuat hien cua chuoi str trong temp: p=> vay vong luy thua se xuat hien len(str)/(p+1)
    Do phuc tap O(n)
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define M 2000010
using namespace std;

int main() {
    
    char* s = new char[M];
    char* temp = new char[M * 2];
    
    while (cin >> s && s[0] != '.') {
        int n = strlen(s);
        
        strcpy(temp, s + 1);
        strcpy(temp + n - 1, s);
        int p = strstr(temp, s) - temp;
        
        cout << n / (p + 1) << "\n";    
    }
    return 0;
}
