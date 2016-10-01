#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;


int result(int a[],int num){
    int count = 0;
    int sum[1000000] = {0};
    sum[0]  = a[0];
    for (int i = 1; i < num; ++i){
        for (int j = 0; j <= i; ++j)
        {
            sum[j] = sum[j] + a[i];
            if (sum[j] == 47)
            {
                count++;
            }
        }
    }
    return count;
}

void readData(){
    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i){
        int num;
        cin >> num;
        int a[num];
        for (int j = 0; j < num; ++j){
            cin >> a[j];
        }
        printf("%d\n", result(a, num)); 
    }
}

int main(int argc, char const *argv[]){
    readData();
    return 0;
}
