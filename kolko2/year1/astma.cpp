#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
vector <pair<long long,long long>> graf[100007];
vector <long long> h;
bool visited[100007];
long long mxg=-1;

void kolejki(long long s)
{
    long long mx=-1;
    visited[s]=1;
    q.push({h[s],s});
    mxg=h[s];
    while(!q.empty())
    {
        long long i=q.top().second;
        cout<<i<<'h'<<h[i]<<' ';
        mxg=max(mxg,h[i]);
        q.pop();
        if(i==h.size()-1) return;
        for(auto k:graf[i])
        {
            long long j=k.second;
            if(visited[j]) continue;
            visited[j]=1;
            cout<<"add:"<<j<<' ';
            q.push({h[j],j});
        }
    }
    mxg=-1;
    return;
}

int main()
{
    long long n,m,i,tmp,tmp2;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        h.push_back(tmp);
    }
    for(i=0;i<m;i++)
    {
        cin>>tmp>>tmp2;
        tmp--;
        tmp2--;
        graf[tmp].push_back({h[tmp2],tmp2});
        graf[tmp2].push_back({h[tmp],tmp});
    }
    kolejki(0);
    if(mxg!=-1)cout<<mxg;
    else cout<<"NIE ISTNIEJE";
}
