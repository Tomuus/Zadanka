#include <deque>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<int> graf[200'015];
bool visited[200'015];
int odl[200'015];

void bfs(int s){
  odl[s] = 0;
  deque<pair<int, bool>> q;
  q.push_back({s,true});
  while (!q.empty())
  {

    int a = q.front().first;
//    cout<<"ent"<<q.front().first<<" "<<odl[a]<<endl;
    bool rail = q.front().second;
    q.pop_front();
    if (visited[a]) continue;
    visited[a] = true;
    
    for (auto i : graf[a])
    {

     // if (visited[i] and odl[i]>odl[a]+1) {odl[i] = odl[a]+1; continue;}
    //  if (visited[i] and (i==a+100'007 or i==a-100'007)) {odl[i] = odl[a]; continue;}

//      cout<<'e'<<i<<endl;
        if (visited[i]) continue;
        if (i == a+100'007 and !rail) continue;
        if (i == a+100'007 or i == a-100'007)
        {
          odl[i] = odl[a];
          q.push_front({i,false});
//          cout<<"swap"<<endl;
          continue;
        }
//        cout<<"push"<<i<<endl;
        if(odl[i]!=0) odl[i] = min(odl[a] + 1, odl[i]);
        else odl[i] = odl[a] + 1;
        q.push_back({i,rail});
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
