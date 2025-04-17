#include <iostream>
#include <vector>

using namespace::std;

vector <int> graf[100004];
int visited[100004];

void kolejki (int p)
{
    if(visited[p]) return;
    //cout<<'#';
    visited[p]=true;
    for(auto i : graf[p]) kolejki(i);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(visited, visited + 100004, false);
    int n,m,i,a,b;
    cin>>n>>m;
    //cout<<"ffghyj";
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    //cout<<"qefrg";
    kolejki(1);
    for(i=1;i<=n;i++)
    {
        if(visited[i]) cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;
    }
}