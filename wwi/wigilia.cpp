#include <ios>
#include <iostream>
#include <vector>

using namespace std;

vector<int> graf[1'000'007];
int pre[1'000'007];
int post[1'000'007];
bool visited[1000'007];
int curr_pre = 0, curr_post = 0;

void bfs (int s) {
  if(visited[s]) return;
  visited[s] = true;
  pre[s]=curr_pre;
  curr_pre++;
  for (auto i : graf[s]) bfs(i);
  post[s] = curr_post;
  curr_post++;
  return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin>>n>>q;
  for(int a, b, i=1; i<n; i++) {
    cin>>a>>b;
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
  bfs(1);
  for(int a, b, i=0; i<q; i++) {
    cin>>a>>b;
    if( (pre[b] > pre[a] and post[b] < post[a]) or a==b) cout<<"TAK";
    else cout<<"NIE";
    cout<<endl;
  }
}
