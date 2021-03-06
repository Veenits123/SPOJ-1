#include<bits/stdc++.h>
using namespace std;
#define mx 2002
#define ll long long
int sze[mx], val[mx];
int dp[mx][mx];
int solve(int pos, int rem)
{
    if(pos<=0 || rem==0) return 0;
    int& ret = dp[pos][rem];
    if(ret!=-1) return ret;
    ret = solve(pos-1,rem);
    if(rem>=sze[pos])
        ret = max(ret,val[pos] + solve(pos-1, rem-sze[pos]));
    return ret;
}
int main()
{
    memset(dp, -1, sizeof dp);
    int s,n;
    scanf("%d%d",&s,&n);
    for(int i=1; i<=n; i++)
        scanf("%d%d",&sze[i], &val[i]);
    printf("%d\n",solve(n,s));
}
