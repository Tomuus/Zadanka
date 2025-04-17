#include<iostream>

using namespace::std;

int main()
{
    int ilosc_morow,szerokosc,tmp,mn=99999999,miejsca=0,i=0;
    cin>>ilosc_morow>>szerokosc;
    int dol[szerokosc+1], gora[szerokosc+1];
    while(i<=szerokosc+1){
        dol[i]=0;
        gora[i]=0;
        i++;
    }
    for(int i=1;i<=ilosc_morow;i++)
    {
        if(i%2==1){
            cin>>tmp;
            dol[tmp]++;
        }
        else{
            cin>>tmp;
            gora[tmp]++;
        }
    }
    i=szerokosc-1;
    for(;i>0;i--)
    {
        dol[i]+=dol[i+1];
        //cout<<dol[i]<<'#';
        gora[i]+=gora[i+1];
        //cout<<gora[i]<<'@';
    }
    i=szerokosc;
    for(;i>0;i--)
    {
        dol[i]+=gora[szerokosc-i+1];
    }
    i=1;
    for(;i<=szerokosc;i++)
    {
        if(dol[i]<mn){miejsca=0; mn=dol[i];}
        if(dol[i]==mn) miejsca++;
    }
    cout<<mn<<' '<<miejsca;
}