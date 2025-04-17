#include<iostream>

using namespace::std;

int main()
{
    int n,i,tmp,tmp1;
    cin>>n;
    int tab[n];
    tab[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>tmp;
        tab[i]=tab[i-1]+tmp;
    }
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tmp>>tmp1;
        cout<<tab[tmp1]-tab[tmp-1]<<endl;
    }
    return 0;
}