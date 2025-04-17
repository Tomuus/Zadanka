#include <iostream>

using namespace::std;

int main()
{
  ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,n,first,last,f_sec=-1,l_sec;
    bool fs=true;
    cin>>n;
    int tab[n];
    for(i=0;i<n;i++)
    {
        cin>>tab[i];
        if(i==0) {first=i; continue;}
        if(tab[first]!=tab[i] and fs) {f_sec=i; fs=false;}
    }
    if(f_sec==-1) {cout<<"BRAK"; return 0;}
    last=n-1;
    i=n-2;
    while(true)
    {
        if(tab[i]!=tab[last])
        {
            l_sec=i;
            break;
        }
        i--;
    }
    if(tab[first]!=tab[last]) cout<<last-first;
    else cout<<max(last-f_sec,l_sec-first);
    //cout<<endl<<first<<' '<<f_sec<<' '<<last<<' '<<l_sec;
}