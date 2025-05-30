#include<iostream>
#include <algorithm>

using namespace::std;

void solw ()
{
    long long tab[1000007];
    long long n,i=1,p,f,w;
    cin>>n>>p;
    fill(tab, tab + p + 2, 0);
    for(i=1;i<=n;i++)
    {
        cin>>w>>f;
        for(long long j=p;j>0;j--) if(j>=w) tab[j]=max(tab[j],tab[j-w]+f);
    }
    cout<<tab[p]<<endl;
    return;
}

int main()
{
    long long i,n;
    cin>>n;
    for(i=0;i<n;i++) solw();
}
