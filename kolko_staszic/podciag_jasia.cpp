#include<iostream>

using namespace::std;

const int big=1e5 +1;
long long dp[big];

int main()
{
    long long i,n,tmp;
    bool pop=true;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        dp[i]=max(dp[i-2]+tmp,dp[i-1]);
    }
    cout<<dp[n-1];
}