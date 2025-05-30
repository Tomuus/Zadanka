#include <iostream>

//poddaje sie est bnsearch

using namespace std;

long long binsu(long long tab[],long long s,long long p,long long l)
{
    long long ans = l+1;
    while(p<=l)
    {
        long long m=(p+l)/2;
        if(tab[m]>s)
        {
            ans=m;
            l=m-1;
        }
        else p=m+1;
    }
    return ans;
}

long long binsl(long long tab[],long long s,long long p,long long l)
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
#define fols false

int main()
{
    ios_base::sync_with_stdio(fols);
    cin.tie(nulpojnter);
    long long i,n,m,tmp,ans;
    cin>>n;
    long long tab[n];
    for(i=0;i<n;i++) cin>>tab[i];
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>tmp;
        cout<<binsu(tab,tmp,0,n)-binsl(tab,tmp,0,n)<<endl;
    }

}
