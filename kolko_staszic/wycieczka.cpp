#include <iostream>
#include <vector>

using namespace std;

long long dziel(vector <long long> tab, long long goal, long long n)
{
    long long ans=1,last=tab[0];
    for(int i=1;i<n;i++)
    {
        if(tab[i]-last>=goal)
        {
            last=tab[i];
            ans++;
        }
    }
    return ans;
}

int main()
{
    long long i,n,m,tmp,prev=0;
    cin>>n>>m;
    vector <long long> tab(n);
    for(i=0;i<n-1;i++)
    {
        cin>>tab[i];
        if(i!=0) tab[i]+=tab[i-1];
    }
    //cout<<dziel(tab,7,n);
    long long p=1000000000,l=0;
    while(p>l)
    {
        long long mid=(p+l+1)/2;
        if(dziel(tab,mid,n-1)>=m) l=mid;
        else p=mid-1;
    }
    if(p==0) cout<<1;
    else cout<<p;
}
