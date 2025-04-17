#include <iostream>
#include <vector>
#include <queue>

using namespace::std;

queue <int> td;
vector <int> graf[100004];
int odl[100004];
int visited[100004];
int mx=-1,mxg=-1;

void kolejki (int p)
{
    visited[p]=1;
    odl[p]=0;
    td.push(p);
    while(!td.empty())
    {
        for(auto i : graf[td.front()])
        {
            if (visited[i]==0)
            {
                visited[i]=1;
                odl[i]=odl[td.front()]+1;
                mx=max(mx,odl[i]);
                td.push(i);
            }
        }
        td.pop();
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(odl, odl + 100004, -1);
    fill(visited, visited + 100004, 0);
    int n,m,i,a,b;
    cin>>n;
    m=n-1;
    //cout<<"ffghyj";
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        graf[a].push_back(b); //wczytywanie
        graf[b].push_back(a);
    }
    //cout<<"qefrg";
    for(i=1;i<=n;i++)
    {
        fill(visited, visited + 100004, 0);
        fill(odl, odl + 100004, -1);
        kolejki(i);
        mxg=max(mxg,mx);
        mx=-1;
    }
    cout<<mxg;
}