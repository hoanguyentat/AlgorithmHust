#include<bits/stdc++.h>
using namespace std;

long long int dp[10000005];

long long int coins(long long int n)
{
    if(n==0)
        return 0;

    if(n>=10000000)
        return max(n,coins(n/2)+coins(n/3)+coins(n/4));

    if(dp[n]!=0)
        return dp[n];

    dp[n]=max(n,coins(n/2)+coins(n/3)+coins(n/4));

        return dp[n];
}

long long int n;
int main()
{
    memset(dp,0,sizeof(dp));
    while(scanf("%lld",&n)!=EOF)
        printf("%lld\n",coins(n));

return 0;
}
