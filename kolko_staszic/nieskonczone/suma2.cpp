#include<iostream>

using namespace::std;

int main()
{
    int n,i=0,sl=0,tmp,miejsce;
    cin>>n;
    int tab[n];
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        tab[i]=tmp;
        sl+=tmp;
    }
    cin>>n;
    cout<<sl<<endl;
    for(i=0;i<n;i++)
    {
        cin>>miejsce>>tmp;
        sl-=tab[miejsce-1];
        sl+=tmp;
        tab[miejsce-1]=tmp;
        cout<<sl<<endl;
    }
    return 0;
}