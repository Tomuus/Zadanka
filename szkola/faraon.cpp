#include<iostream>
#include <algorithm>

using namespace::std;

void solw ()
{
    int tab[1000007];
    int n,i=1,p,f,w;
    cin>>n>>p;
    for(i=1;i<=n;i++)
    {
        cin>>w>>f;
        for(int j=p;j>0;j--) if(j>=w) tab[j]=max(tab[j],tab[j-w]+f);
    }
    cout<<tab[p]<<endl;
    return;
}

int main()
{
    int i,n;
    cin>>n;
    for(i=0;i<n;i++) solw();
}
