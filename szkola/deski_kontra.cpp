#include <algorithm>
#include <iostream>

using namespace::std;

long long tab[5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long i,n,tmp;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        tab[4]=max(max(max(tmp/4,min(tmp/3,tab[1])),max(min(tmp/2,tab[2]),min(tmp,tab[3]))),tab[4]);
        tab[3]=max(max(max(tmp/3,min(tmp/2,tab[1])),min(tmp,tab[2])),tab[3]);
        tab[2]=max(max(tmp/2,min(tmp,tab[1])),tab[2]);
        tab[1]=max(tab[1],tmp);
    }
    cout<<tab[4]*tab[4];
}