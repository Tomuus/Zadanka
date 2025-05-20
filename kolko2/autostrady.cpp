#include <iostream>
#include <vector>
#include <queue>

using namespace::std;

queue <int> td;
vector <int> graf[100004];
int gang[100004];
int visited[100004];

void kolejki (int p, int g)
{
    if(visited[p]) return;
    visited[p]=true;
    gang[p]=g;
    for(auto i : graf[p]) kolejki(i,g);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(gang, gang + 100004, -1);
    fill(visited, visited + 100004, 0);
    int n,m,i,a,b,s,p,kt=1;
    cin>>n>>m>>p;
    //cout<<"ffghyj";
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        graf[a].push_back(b); //wczytywanie
        graf[b].push_back(a);
    }
    for(i=1;i<=n;i++) if(!visited[i]) {kolejki(i,kt); kt++;}
    for(i=0;i<p;i++)
    {
        cin>>a>>b;
        if(gang[a]==gang[b]) cout<<"TAK";
        else cout<<"NIE";
        cout<<endl;
    }
    return 0;
}
