#include<iostream>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i,tmp,tmp1;
    cin>>n>>m;
    int tab[n+1];
    tab[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>tmp;
        tab[i]=tab[i-1]+tmp;
    }
    for(i=0;i<m;i++)
    {
        cin>>tmp>>tmp1;
        cout<<tab[tmp1]-tab[tmp-1]<<endl;
    }
}