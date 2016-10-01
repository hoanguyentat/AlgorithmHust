#include <stdio.h>
#include <stdlib.h>
int x[10000];
int n = 0, k;
int count = 0;
int vitri;
 // in to hop
void print() {
   if (count == vitri)
   {
      for(int i= 1; i <=k;i++)
         printf("%d ",x[i]);
      exit(0);
   }    
}


 // hàm quay lui
void Try(int i) {
    for(int j = x[i-1] +1; j <= n-k + i; j++) {
            x[i] = j;
            if(i==k){
               count++;
               print();
            }   
            else  Try(i+1);
    }
}
 
int main (){
   scanf("%d",&n);
   scanf("%d", &k);
   scanf("%d", &vitri);
   x[0] = 0;
   Try(1);
   if (count < vitri)
   {
      printf("-1");
   }
  return 0;
}
