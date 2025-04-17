#include <iostream>
#include <algorithm>

using namespace::std;

int tab[1007][1007];
int dp[1007][1007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i,j,mx=-1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>tab[i][j];
            dp[i][j]=tab[i][j]==0;
            if(dp[i][j]==1) mx=1;
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=n-2;j>=0;j--)
        {
            if(dp[i][j])
            {
                if(j<n-1) dp[i][j]+=min(dp[i][j+1],min(dp[i-1][j+1],dp[i-1][j]));
            }
            mx=max(dp[i][j],mx);
        }
    }
    cout<<mx;
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++) cout<<dp[i][j]<<' ';
        cout<<"\n";
    }*/
}