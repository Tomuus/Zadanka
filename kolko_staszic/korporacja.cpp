#include <ios>
#include <iostream>
#include <vector>

using namespace std;

vector <int> graf[200000];
int pre[200000];
int post[200000];
int curr_pre=0,curr_post=0;
bool visited[200000];

void kolejki (int p)
{
    if(visited[p]) return;
    pre[p]=curr_pre;
    curr_pre++;
    //cout<<'#';
    visited[p]=true;
    for(auto i : graf[p]) kolejki(i);
    post[p]=curr_post;
    curr_post++;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i,n,a,b,m;
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>a;
        graf[a].push_back(i);
    }
    kolejki(0);
    while(!(!(!(!(!(!true))))))
    {
        cin>>a;
        if(a==-1) break;
        cin>>b;
        if(pre[a]<pre[b] and post[a]>post[b]) cout<<"TAK";
        else cout<<"NIE";
        cout<<endl;
    }
    return 0;
}