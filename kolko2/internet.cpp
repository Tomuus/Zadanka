#include <iostream>
#include <vector>

using namespace std;

vector <long long> graf[200007];
bool visited[200007];
long long przod[200007];

long long kolejki (int p)
{
    int dzieci=0;
    //cout<<'#';
    visited[p]=true;
    for(auto i : graf[p]) if(!visited[i]) dzieci+=(kolejki(i)+1);
    przod[p]=dzieci+1;
    return dzieci;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long i,n,a,b,m,wynik,mx=-1;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>a>>b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    wynik=kolejki(1);
    for(i=1;i<=n;i++) {mx=max(mx,przod[i]*(n-przod[i])); /*cout<<przod[i];*/}
    cout<<mx;
    return 0;
}
