#include<iostream>

using namespace::std;

const int big=1e5;
int tab[big];
int dp[big];

int il[10];

int main()
{
    //cout<<2345;
    int i,n,roz=-1,tmp;
    cin>>n;
    for(i=0;i<n;i++)
    {
        //cout<<'*';
        cin>>tmp;
        tab[i]=tmp;
    }
    //cout<<3456;
    for(i=n-1;i>=0;i--)
    {
        //cout<<'@';
        il[tab[i]]=i;
        dp[i]=1;
        if(il[tab[i]+1]!=0) dp[i]+=dp[il[tab[i]+1]];
        roz=max(roz,dp[i]);
        //cout<<dp[i];
    }
    cout<<roz;
}
