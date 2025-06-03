#include <ios>
#include <iostream>

using namespace std;

int szef[100007];
int team[100007];

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
    team[a]+=team[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill(team,team+100007,1);
    int i,n,m,a,b;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        join(a,b);
        cout<<team[find(1)]<<endl;
    }
}
