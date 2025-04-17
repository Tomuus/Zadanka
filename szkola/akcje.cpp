#include <iostream>

using namespace std;

int dp[1000007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,n,mn=1000000009,tmp,mx=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        dp[i]=max(tmp-mn,mx);
        mx=dp[i];
        mn=min(mn,tmp);
    }
    cout<<mx;
}