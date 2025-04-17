#include <iostream>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,i=0,nc,sum=0;
    cin>>n;
    long long tab[n];
    while(i<n)
    {
        cin>>tab[i];
        i++;
    }
    nc=tab[n-1];
    i=n-1;
    while(i>=0)
    {
        if(tab[i]<nc) nc=tab[i];
        sum+=nc;
        i--;
        //cout<<'*';
    }
    cout<<sum;
}