/**
	* Du lieu duoc doc theo tung phan tu
	* Doc va luu ket qua va trong mot mang da duoc khai bao + them phan tu ban dau a[0] = 0
	* Sau khi doc xong, dung ham tinh toan gan a[i] bang tong cua cac phan tu tu a[0] den a[i]
	* Dung ham map bien cont: hai thuoc tinh first co gia tri a[j], second gia tri la 1
	* Duyet tung phan tu moi cua mang tu buoc 2, cong bien result them gia tri cua cont[a[i] - 47]
		* do a[i] sau buoc 2 tro thanh tong cua cac phan tu truoc no va chinh a[i], gia su tu j den i 
		* co tong cac phan tu bang 47 thi a[i] - 47 = a[j] ma cont[a[j]] = 1 nen result += 1 vao ket qua
	* Muc do phuc tap thuat toan la O(n)
*/

#include <stdio.h>
#include <map>
#include <iostream>

using namespace std;

int a[1000001];

int main(){
    int test_cases, num;
    scanf("%d",&test_cases);
    
    for (int i = 0; i < test_cases; ++i){
        scanf("%d",&num);
        a[0] = 0;
        for(int i = 1;i<=num;++i) scanf("%d",&a[i]);
        for(int i = 1;i<=num;++i) {
            a[i] += a[i-1];
        }
        
        map<long long,int> cont;
        cont[0] = 1;
        
        int result = 0;
        
        for(int i = 1;i<=num;++i){
            result += cont[a[i]-47];
            ++cont[a[i]];
        }
        
        printf("%d\n",result);
    }
    
    return 0;
}