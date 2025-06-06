#include <iostream>
#include <vector>

using namespace std;

vector <long long> graf[100007];
long long jump[100007][20];
long long deph[100007];

void kolejki(int p, int parent)
{
    jump[p][0]=parent;
    long long i;
    for(i=1;i<20;i++) jump[p][i]=jump[jump[p][i-1]][i-1];
    for(auto i : graf[p])
    {
        deph[i]=deph[p]+1;
        kolejki(i,p);
    }
}

int lift(int b,int t)
{
    for(int i=19;i>=0;i--)
    {
        if(deph[jump[b][i]]>=deph[t]) b=jump[b][i];
    }
    return b;
}

int lca(int a, int b)
{
    if(deph[a]<deph[b]) swap(a,b);
    a=lift(a,b);
    if(a==b) return a;
    for(int i=19;i>=0;i--)
    {
        if(jump[a][i]!=jump[b][i])
        {
            a=jump[a][i];
            b=jump[b][i];
        }
    }
    return jump[a][0];
}

int main()
{
    int i,n,m,a,b,q;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        graf[a].push_back(b);
    }
    deph[1]=0;
    kolejki (1,1);
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>a>>b;
        cout<<lca(a,b);
    }
}
