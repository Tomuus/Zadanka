#include <iostream>
#include <vector>

using namespace::std;

vector <int> graf[100004];
int visited[100004];
bool flag=true;

void kolejki (int p, int o)
{
    if(visited[p]) {flag=false; return;}
    //cout<<'#';
    visited[p]=true;
    for(auto i : graf[p]) {if(i!=o) kolejki(i,p);}
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
    kolejki(1,0);
    for(i=1;i<=n;i++) {if(!visited[i]) flag=false;}
    if(flag) cout<<"TAK";
    else cout<<"NIE";
}