#include <iostream>
#include <vector>
#include <queue>

using namespace::std;

queue <int> td;
vector <int> graf[100004];
int gang[100004];
int nfgang[100004];
int visited[100004];

void kolejki (int p, int g, int k)
{
    if(visited[p]!=0 and visited[p]!=k) nfgang[g]=true;
    if(visited[p]) return;
    visited[p]=k;
    gang[p]=g;
    for(auto i : graf[p]) kolejki(i,g,3-k);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(gang, gang + 100004, -1);
    fill(visited, visited + 100004, 0);
    int n,m,i,a,b,s,p,kt=1;
    cin>>n>>m;
    //cout<<"ffghyj";
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        graf[a].push_back(b); //wczytywanie
        graf[b].push_back(a);
    }
    for(i=1;i<=n;i++) if(!visited[i]) {kolejki(i,kt,1); kt++;}
    for(i=1;i<=n;i++) if(!nfgang[gang[i]]) cout<<"fajne"<<endl; else cout<<"niefajne"<<endl;
    return 0;
}
