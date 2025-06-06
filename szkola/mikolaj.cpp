#include <iostream>
#include <algorithm>

using namespace::std;

const int a=807;
long long tab[a][a];
long long dp[a][a];
long long pow[a][a];

int main()
{
    int n,m,i=0,j=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++) cin>>tab[i][j];
    }
    dp[0][0]=tab[0][0];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(j+1<m) dp[i][j+1]=max(dp[i][j+1],dp[i][j]+tab[i][j+1]);
            if(i+1<n) dp[i+1][j]=max(dp[i+1][j],dp[i][j]+tab[i+1][j]);
        }
    }
    cout<<dp[n-1][m-1];
}
