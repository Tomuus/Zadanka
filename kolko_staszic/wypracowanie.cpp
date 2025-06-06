#include <iostream>
#include <string>

using namespace std;

int szef[1000007];
int jmn[1000007];
int jmx[1000007];
int slow[1000007];

int find(int x)
{
    if(szef[x]==0) return x;
    szef[x]=find(szef[x]);
    return szef[x];
}

void join(int x,int y)
{
    int a=find(x);
    int b=find(y);
    if(a==b) return;
    szef[b]=a;
    jmn[a]=min(jmn[a],jmn[b]);
    jmx[a]=max(jmx[a],jmx[b]);
    slow[a]+=slow[b];
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int i,n,tmp,tmp1;
    string a;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>tmp>>tmp1;
        slow[i]=tmp;
        jmn[i]=tmp1;
        jmx[i]=tmp1;
    }
    do{
        cin>>a>>tmp;
        if(a=="GRUPA")
        {
            cin>>tmp1;
            join(tmp,tmp1);
            continue;
        }
        if(a=="LICZBA_SLOW")
        {
            cout<<slow[find(tmp)];
            cout<<endl;
            continue;
        }
        if(a=="JAKOSC_MIN")
        {
            cout<<jmn[find(tmp)];
            cout<<endl;
            continue;
        }
        cout<<jmx[find(tmp)];
        cout<<endl;
    }while(a!="k");
    return 0;
}
