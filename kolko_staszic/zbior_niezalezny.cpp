#include <iostream>
#include <vector>

using namespace::std;

vector <int> graf[200004];
int visited[200004];
bool chosen[200004];

int kolejki (int p)
{
    if(visited[p]) return 0;
    int ans=0;
    bool can=true;
    //cout<<'#';
    visited[p]=true;
    for(auto i : graf[p])
    {
        ans+=kolejki(i);
        if(chosen[i]) can=false;
    }
    if(can) {ans+=1; chosen[p]=true;}
    return ans;
}

int main()
{
    //ej jaka sigma przeszlo za pierwszym razem i to nawet nie debugowalem
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(visited, visited + 200004, false);
    int n,m,i,a,b,ans;
    cin>>m;
    //cout<<"ffghyj";
    for(i=1;i<m;i++)
    {
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    //cout<<"qefrg";
    ans=kolejki(1);
    cout<<ans;
}
