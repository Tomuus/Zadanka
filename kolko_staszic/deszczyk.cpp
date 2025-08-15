#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long i,n,m,q,a,b,tmp;
    cin>>n>>q>>m;
    long long tab[q+2];
    fill(tab,tab+q+2,0);
    for(i=0;i<n;i++)
    {
        cin>>a>>b>>tmp;
        tab[a]+=tmp;
        if(b<q+1) tab[b+1]-=tmp;
    }
    for(i=1;i<=q;i++) tab[i]+=tab[i-1];
    for(i=0;i<m;i++)
    {
        cin>>tmp;
        cout<<tab[tmp]<<endl;
    }
    //for(auto i: tab) cout<<i<<' ';
}
