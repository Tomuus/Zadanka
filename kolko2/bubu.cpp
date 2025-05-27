#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <pair<long long,long long>> graf[500007];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
bool visited[500007];
long long odl[500007];

void kolejki (long long s)
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
        //if(i==1) return;
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
    //cout<<12345;
    //ios_base::sync_with_stdio(0);
    //cin.tie(nullptr);
    //cout<<'a';
    vector <long long> straz;
    long long n,m,i,tmp,tmp2,h,s;
    fill(odl, odl + 500007, 999999999);
    cin>>n>>m>>s;
    for(i=0;i<m;i++)
    {
        //cout<<12345;
        cin>>tmp>>tmp2>>h;
        graf[tmp].push_back({h,tmp2});
        graf[tmp2].push_back({h,tmp});
    }
    cout<<'!';
    for(i=0;i<s;i++)
    {
        cin>>tmp;
        straz.push_back(tmp);
    }
    cin>>tmp;
    kolejki(tmp);
    int goal=odl[1];
    //cout<<goal;
    for(auto k: straz)
    {
        q={};
        fill(odl, odl + 500007, 999999999);
        fill(visited, visited + 500007, 0);
        kolejki(k);
        if(odl[1]<goal)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<goal;
}
