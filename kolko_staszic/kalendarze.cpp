#include <algorithm>
#include <iostream>
#include <sched.h>

using namespace :: std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int i,arbuz,banan,tmp,tmp1,n,dzien;
    char k;
    cin>>arbuz>>banan;
    int taba[arbuz+1];
    int tabb[banan+1];
    taba[0]=0;
    tabb[0]=0;
    for(i=1;i<=arbuz;i++)
    {
        cin>>tmp;
        taba[i]=taba[i-1]+tmp;
    }
    for(i=1;i<=banan;i++)
    {
        cin>>tmp;
        tabb[i]=tabb[i-1]+tmp;
    }
    cin>>n;
    //cout<<'a';
    for(int j=0;j<n;j++)
    {
        cin>>tmp>>tmp1>>k;
        i=0;
        if(k=='A')
        {
            dzien=taba[tmp1-1]+tmp;
            i=lower_bound(tabb,tabb+banan+1,dzien)-tabb;
            cout<<dzien-tabb[i-1]<<' '<<i;
        }
        else
        {
            dzien=tabb[tmp1-1]+tmp;
            i=lower_bound(taba,taba+arbuz+1,dzien)-taba;
            cout<<dzien-taba[i-1]<<' '<<i;
        }
        //cout<<'*'<<dzien<<'#';
        cout<<endl;
    }
}
