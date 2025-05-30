#include <ios>
#include <iostream>
#include <vector>
#include <queue>
//zjazd po wezu ma czasem sens (jak jutro wstane to w to nie uwierze ale tak jest)
using namespace::std;

queue<int> td;
int odl[103];
int visited[103];
int telep[103];

void kolejki (int p)
{
    visited[p]=1;
    odl[p]=0;
    td.push(p);
    while(!td.empty())
    {
        int w=td.front();
        for(int i=w+1;i<=w+6 and i<=100;i++)
        {
            if(visited[telep[i]]) continue;
            int j=telep[i];
            odl[j]=odl[w]+1;
            visited[j]=1;
            td.push(j);
        }
        td.pop();
    }
    return;
}

void solv()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill(odl, odl + 103, -1);
    fill(visited, visited + 103, 0);
    fill(telep,telep+103,0);
    int n,i,a,b;
    for(i=1;i<=100;i++) telep[i]=i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        telep[a]=b;
    }
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        telep[a]=b;
    }
    //cout<<"qef";
    kolejki(1);
    cout<<odl[100]<<endl;
}

#define nulpojnter nullptr

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nulpojnter);
    int i,n;
    cin>>n;
    for(i=0;i<n;i++) solv();
}

