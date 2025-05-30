#include <iostream>

using namespace std;

long long bins(long long tab[],long long s,long long p,long long l)
{
    long long ans = l+1;
    while(p<=l)
    {
        long long m=(p+l)/2;
        if(tab[m]>=s)
        {
            ans=m;
            l=m-1;
        }
        else p=m+1;
    }
    return ans;
}

#define nulpojnter nullptr

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nulpojnter);
    long long i,n,m,tmp,ans;
    cin>>n;
    long long tab[n];
    for(i=0;i<n;i++) cin>>tab[i];
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>tmp;
        ans=bins(tab,tmp,0,n);
        //cout<<ans;
        if(ans>=n) cout<<n;
        else cout<<ans;
        cout<<endl;
    }

}
