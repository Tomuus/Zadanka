#include<iostream>

using namespace::std;

long long tab[10007];

int main()
{
    long long n,i=1,p,f,w;
    cin>>n>>p;
    for(i=1;i<=n;i++)
    {
        cin>>w>>f;
        for(int j=p;j>0;j--) if(j>=w) tab[j]=max(tab[j],tab[j-w]+f);
    }
    cout<<tab[p];
}
