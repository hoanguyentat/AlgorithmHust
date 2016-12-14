#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <math.h>
#define N 1000000
using namespace std;
 
int cnt;
 
void recursive(char a [])
{
    char org[15];
    strcpy (org, a);
 
    for ( int i = 0; i < 11; i++ ) {
        if ( a [i] == 'o' && a [i + 1] == 'o' ) {
            if ( i + 2 < 12 && a [i + 2] == '-' ) {
                a[i + 2] = 'o';
                a[i] = a[i + 1] = '-';
                recursive (a);
                strcpy (a, org);
            }
            if ( i - 1 >= 0 && a [i - 1] == '-' ) {
                a [i - 1] = 'o';
                a [i] = a [i + 1] = '-';
                recursive (a);
                strcpy(a, org);
            }
        }
    }
 
    int c = 0;
 
    for ( int i = 0; i < 12; i++ ) {
        if ( a[i] == 'o' ) c++;
    }
 
    if ( c < cnt )
        cnt = c;
}
 
int main ()
{
    int testCase;
    scanf ("%d", &testCase);
 
    while ( testCase-- ) {
        char input[12 + 3];
        scanf("%s", input);
 
        cnt = 100;
 
        recursive(input);
 
        printf("%d\n", cnt);
    }
 
    return 0;
}