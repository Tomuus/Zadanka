#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,i,tmp,best=999999999999999999,end,ind;
    cin >> n;
    long long tab[n];
    tab[0]=0;
    for(i=1;i<=n-1;i++)
    {
        cin>>tab[i];
        tab[i]+=tab[i-1];
    }
    end=tab[n-1];
    for(i=1;i<=n-1;i++) if (best>min(best,max(tab[i],end-tab[i]))) {best=min(best,max(tab[i],end-tab[i])); ind=i;}
    cout<<ind+1;
}