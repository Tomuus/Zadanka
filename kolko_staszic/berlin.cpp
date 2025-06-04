#include <ios>
#include <iostream>
#include <vector>

using namespace std;

int szef[1000007];
int team;

int find(int x)
{
    if(szef[x]==0) return x;
    szef[x]=find(szef[x]);
    return szef[x];
}

void join(int x,int y)
{
    int a=find(x);
    int b=find(y);
    if(a==b) return;
    szef[b]=a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector <pair<int,int>> kol;
    int i,n,m,a,b,k,ans=0;
    cin>>n>>m>>k;
    team=n;
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        kol.push_back({a,b});
    }
    for(i=m-1;i>=0;i--)
    {
        //cout<<"!"<<team<<' ';
        if(team==k)
        {
            while(find(kol[i].first)==find(kol[i].second)) {ans++; i--;}
            cout<<m-ans+1;
            return 0;
        }
        a=kol[i].first;
        b=kol[i].second;
        ans++;
        if(find(a)==find(b)) continue;
        team--;
        //cout<<'n'<<a<<'i'<<b;
        join(a,b);

    }
    cout<<1<<endl;
    return 0;
}
