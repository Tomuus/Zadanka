#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

tuple <int,int,int,int> graf[1000007];
int szef[1000007];

int find(int x)
{
    if(szef[x]==0) return x;
    szef[x]=find(szef[x]);
    return szef[x];
}

void join(int x, int y)
{
    int a=find(x);
    int b=find(y);
    szef[a]=b;
}

int main ()
{
    int i,n,m,a,b,h;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>h;
        graf[i-1]={h,i,a,b};
    }
    sort(graf,graf+m);
    for(i=0;i<m;i++)
    {
        if(find(get<2>(graf[i]))==find(get<3>(graf[i]))) continue;
        cout<<get<1>(graf[i])<<endl;
        join(get<2>(graf[i]),get<3>(graf[i]));
    }
}
