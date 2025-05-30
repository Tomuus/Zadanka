#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dziel(vector <long long> tab, long long goal, long long n)
{
    long long ans=1,curr=tab[0];
    for(int i=1;i<n;i++)
    {
        if(curr+tab[i]>goal)
        {
            curr=tab[i];
            ans++;
        }
        else curr+=tab[i];
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
    }
    //cout<<dziel(tab,7,n);
    long long p=999999999999999999,l=*max_element(tab.begin(), tab.begin() + n - 1);;
    while(p>l)
    {
        long long mid=(p+l)/2;
        //cout<<dziel(tab,mid,n-1)<<'d'<<mid<<' ';
        if(dziel(tab,mid,n-1)>m) l=mid+1;
        else p=mid;
    }
    if(p==0) cout<<1;
    else cout<<l;
}
