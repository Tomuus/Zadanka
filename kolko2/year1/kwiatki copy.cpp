#include <iostream>
#include <algorithm>

using namespace::std;

const int a=1e3+1;
long long tab[a][a];
long long dp[a][a];

int main()
{
    int n,m,i=0,j=0,mn=999999;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++) cin>>tab[i][j];
    }
    for(i=0;i<n;i++) dp[i][0]=tab[i][0];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(j+1<m) dp[i][j+1]=min(dp[i][j+1],dp[i][j]+tab[i][j+1]);
            if(i+1<n) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+tab[i+1][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        if(dp[i][m-1]<mn) dp[i][m-1];
    }
}
