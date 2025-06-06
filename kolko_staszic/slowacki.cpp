#include <iostream>
#include <vector>

using namespace std;

vector <pair<long long, long long>> graf[500007];
long long jump[500007][20];
long long deph[500007];
long long patyk[500007];
long long kijek[500007];

void kolejki(int p, int parent)
{
    jump[p][0]=parent;
    patyk[p]=patyk[parent]+kijek[p]; //wannabe sumy prefiksowe (to ma taie male szanse ze dziala)
    long long i;
    for(i=1;i<20;i++) jump[p][i]=jump[jump[p][i-1]][i-1];
    for(auto [i,w] : graf[p])
    {
        if(i==parent) continue;
        kijek[i]=w;
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int i,n,m,a,b,p;
    cin>>n>>m;
    for(i=1;i<n;i++)
    {
        cin>>a>>b>>p;
        graf[a].push_back({b,p});
        graf[b].push_back({a,p});
    }
    deph[1]=0;
    patyk[1]=0;
    kolejki (1,1);
    //for(i=1;i<=5;i++) cout<<patyk[i]<<' ';
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        int x=lca(a,b);
        cout<<patyk[a]+patyk[b]-patyk[x]-patyk[x]<<endl;
    }
}
