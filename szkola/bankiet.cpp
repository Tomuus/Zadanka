#include <iostream>

using namespace::std;

int tab[30005];

bool spr[30005];

void prz (int n,int z)
{
    spr[n]=true;
    if(n==z) return;
    prz(tab[n],z);
}

int main()
{
    int i=1,n,s=0,tmp;
    cin>>n;
    while(i<=n)
    {
        cin>>tmp;
        tab[i]=tmp;
        i++;
    }
    i=1;
    while(i<n)
    {
        if(!spr[i]) {
            prz(tab[i],i);
            s++;
        }
        i++;
    }
    cout<<s;
}