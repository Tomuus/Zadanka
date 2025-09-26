#include <iostream>
#include <string>

using namespace std;

long long tab[1000000];

string wypisz(long long n)
{
    string ret="";
    for(;n>0;n>>=1)
    {
        if(n%2==1) ret='P'+ret;
        else ret='F'+ret;
    }
    return ret;
}

int main()
{
    long long n,i,m,j,mx=-1,klucz_int=0,wynik_low,mxwl=-1;
    string tmp;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        for(j=0;j<m;j++) if(tmp[j]=='P') tmp[j]='1'; else tmp[j]='0';
        tab[i]=stoi(tmp,nullptr,2);
        //cout<<tab[i]<<' ';
        mx=max(mx,tab[i]);
        //cout<<'1';
    }
    for(i=0;i<mx;i++)
    {
        wynik_low=99999999999;
        //cout<<'2';
        for(j=0;j<n;j++)
        {
            wynik_low=min(wynik_low,m-(i^tab[j]));
        }
        cout<<wynik_low<<' ';
        if(mxwl<wynik_low)
        {
            mxwl=wynik_low;
            klucz_int=i;
        }
    }
    cout<<wypisz(klucz_int)<<endl<<mxwl;
}
