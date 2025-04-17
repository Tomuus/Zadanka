#include <iostream>

using namespace std;

int tab[7];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,i,tmp=1,x,ost=-1,pi=-1;
    bool fs=true;
    cin>>n>>x;
    for(i=1;i<=n;i++)
    {
        cin>>tmp;
        if(tmp==x and fs) {pi=i; fs=false;}
        if(tmp==x) ost=i;
    }
    cout<<pi<<' '<<ost;
}