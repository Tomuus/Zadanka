#include<iostream>

using namespace::std;

int main()
{
    int n,i=0,start=-1,koniec=0,w,kap=0,roz=0,odp=1000007;
    cin>>n>>w;
    int tab[n];
    for (i=0;i<n;i++) cin>>tab[i];
    while(start<n or kap<=w and koniec<n)
    {
        //cout<<'a';
        if(roz<w and start<n){
            start++;
            if(tab[start]==0)kap++;
            else roz++;
        }
        else
        {
            if(tab[koniec]==0)kap--;
            else roz--;
            koniec++;
        }
        //cout<<'k'<<kap<<'r'<<roz<<' ';
        if(roz==w) odp=min(odp,kap);
    }
    if(odp!=1000007)cout<<odp;
    else cout<<"NIE";
}