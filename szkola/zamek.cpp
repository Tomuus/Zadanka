#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long i,n,m,tmp,pmt,l;
    cin>>n>>m;
    long long tab[n+1];
    tab[0]=0;
    for(i=1;i<=n;i++) {cin>>tab[i]; tab[i]+=tab[i-1];}
    l=tab[n];
    for(i=0;i<m;i++)
    {
        cin>>tmp>>pmt;
        if((l-tab[pmt-1])*2<=l-tab[tmp-1]) cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;
    }
}