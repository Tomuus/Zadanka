#include <deque>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<int> graf[200'015];
bool visited[200'015];
int odl[200'015];

void bfs(int s){
  visited[s] = true;
  odl[s] = 0;
  deque<pair<int, bool>> q;
  q.push_back({s,true});
  while (!q.empty())
  {
    cout<<"ent"<<q.front().first<<endl;
    int a = q.front().first;
    bool rail = q.front().second;
    q.pop_front();
    for (auto i : graf[a])
    {
      cout<<'e'<<i<<endl;
        if (visited[i]) continue;
        if (i == a+100'007 and !rail) continue;
        if (i == a+100'007)
        {
          visited[i] = true;
          odl[i] = odl[a];
          q.push_front({i,false});
          cout<<"swap"<<endl;
          continue;
        }
        visited[i] = true;
        odl[i] = odl[a] + 1;
        cout<<"push"<<i;
        if ( i < 100'007 ) q.push_back({i, rail});
        else {
          q.push_back({i, rail});
          if (!visited[i-100'007]) {
            visited[i - 100'007] = true;
            odl[i-100'007] = odl[a] + 1;
            q.push_front({i-100'007, false});
          }
        }
     }
  }
  return;
} 

int main (){
  int n, m, x, y;
  cin>>n>>m>>x>>y;
  for (int i=0; i<=n; i++) {
    graf[i].push_back(i+100'007);
    graf[i+100'007].push_back(i);
  }
  for (int a, b, i=0; i<m; i++) {
    cin>>a>>b;
    graf[a].push_back(b);
    graf[b+100'007].push_back(a+100'007);
  }
  bfs(x);
  if (odl[y] == 0 and x!=y) odl[y]--;
  cout<<odl[y];
}
