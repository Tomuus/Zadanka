#include <iostream>
#include <vector>

using namespace std;

vector <int> graf[200000];
bool visited[200000];
int przod[200000];

int kolejki (int p)
{
    int dzieci=0;
    if(visited[p]) return 0;
    //cout<<'#';
    visited[p]=true;
    for(auto i : graf[p]) dzieci+=(kolejki(i)+1);
    przod[p]=dzieci;
    return dzieci;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i,n,a,b,m,wynik;
    cin>>n;
    for(i=2;i<=n;i++)
    {
        cin>>a;
        graf[a].push_back(i);
    }
    wynik=kolejki(1);
    for(i=1;i<=n;i++) cout<<przod[i]<<' ';
    return 0;
}
