#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
vector <pair<long long,long long>> graf[500007];
bool visited[500007];
long long odl[500007];

void kolejki(long long s)
{
    long long mx=-1;
    visited[s]=1;
    q.push({0,s});
    odl[s]=0;
    while(!q.empty())
    {
        long long i=q.top().second, h=q.top().first;
        //cout<<i<<'h'<<h<<' ';
        q.pop();
        visited[i]=1;
        for(auto k:graf[i])
        {
            long long j=k.second;
            long long h=k.first;
            if(visited[j]) continue;
            //cout<<"add:"<<odl[j]<<' '<<h<<' '<<odl[i];
            if(odl[j]>odl[i]+h)
            {
                //cout<<'p'<<j<<' ';
                odl[j]=odl[i]+h;
                q.push({odl[j],j});
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    long long n,m,i,tmp,tmp2,h;
    fill(odl, odl + 500007, 500000000007);
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>tmp>>tmp2>>h;
        tmp--;
        tmp2--;
        graf[tmp].push_back({h,tmp2});
        graf[tmp2].push_back({h,tmp});
    }
    kolejki(0);
    for(i=0;i<n;i++)
    {
        if(visited[i])cout<<odl[i]<<' ';
        else cout<<-1;
        cout<<"\n";
    }
}
