#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace::std;

queue <int> td;
vector <int> graf[100004];
int visited[100004];
vector <pair<int,int>> pkt;

void kolejki (int p)
{
    if(visited[p]) return;
    visited[p]=true;
    for(auto i : graf[p]) kolejki(i);
    return;
}

int odl (pair<int,int> a, pair<int,int> b) {return ((a.first-b.first)*(a.first-b.first)) + ((a.second-b.second))*(a.second-b.second);}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(visited, visited + 100004, 0);
    int n,m,i,a,b,s,p,kt=1,j,wynik=-1;
    cin>>n>>m>>p;
    //cout<<"ffghyj";
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        pkt.push_back({a,b});
    }
    for(i=0;i<pkt.size();i++)
    {
        for(j=i+1;j<pkt.size();j++)
        {
            if(odl(pkt[i],pkt[j]))
            {
                graf[i].push_back(j);
                graf[j].push_back(i);
            }
        }
    }
    kolejki(0);
    for(i=0;i<n;i++) if(visited[i]) wynik=max(wynik,odl({0,0},pkt[i]));
    cout<<sqrt(wynik);
    return 0;
}
