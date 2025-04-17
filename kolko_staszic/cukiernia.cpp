#include<iostream>
#include <algorithm>

using namespace::std;

int tab[1007];

int main()
{
    int n,i=1,p,f,w;
    cin>>n>>p;
    for(i=1;i<=n;i++)
    {
        cin>>w>>f;
        for(int j=p;j>0;j--) if(j>=w) tab[j]=max(tab[j],tab[j-w]+f);
    }
    cout<<tab[p];
}