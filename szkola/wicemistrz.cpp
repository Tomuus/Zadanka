#include <iostream>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long i,n,mx=-1,mxi=-1;
    cin>>n;
    int tab[n];
    for(i=0;i<n;i++)
    {
        cin>>tab[i];
        if(tab[i]>mx) {mx=tab[i]; mxi=i;}
    }
    for(i=0;i<n;i++) if(tab[i]>mx) {mx=tab[i]; mxi=i;}
    mx=-1;
    tab[mxi]=0;
    mxi=-1;
    for(i=0;i<n;i++) if(tab[i]>mx) {mx=tab[i]; mxi=i;}
    cout<<mx;
}