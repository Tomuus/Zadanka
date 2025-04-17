#include <iostream>

using namespace::std;

const long long big=1e9;
long long tab[1<<21 + 1];
long long ll=1;

void zamiana (long long i, long long nowe)
{
    i+=ll;
    tab[i]+=nowe;
    while(i>1)
    {
        i/=2;
        tab[i]=max(tab[i*2], tab[i*2+1]);
    }
}

long long przedzial(long long p, long long k, long long a, long long b, long long i) {
    if (p <= a && b <= k + 1) return tab[i];
    if (b <= p || k + 1 <= a) return -99999999999999;
    long long mid = (a + b) / 2;
    return max (przedzial(p, k, a, mid, i * 2) , przedzial(p, k, mid, b, i * 2 + 1));
}

int main()
{
    fill(tab, tab + (1<<21+1), -99999999999999);
    long long i,n,m,index,nw;
    char tmp;
    cin>>n>>m;
    while(ll<n) ll*=2;
    for(i=0;i<n;i++) cin>>tab[ll+i]; //wczytywanie
    for(i=ll-1;i>0;i--) tab[i]=max(tab[i*2],tab[i*2+1]); //dopelnianie
    //for(i=0;i<n+5;i++) cout<<tab[i]<<' ';
    for(i=0;i<m;i++)
    {
        cin>>tmp>>index>>nw;
        if(tmp=='+') zamiana(index-1, nw);
        else cout<<przedzial(index-1,nw-1,0,ll,1)<<endl;
    }
}