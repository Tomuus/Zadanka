#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

vector <int> djikstra (vector<pair<ll, int>> graf[], int size, int start){
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
  vector <ll> odl(size, 999999999);
  vector <int> parent(size);
  odl[start] = 0;
  q.push({0, start});
  while(!q.empty()){

    int curr_p = q.top().second, curr_w = q.top().first;
    q.pop();

    for (auto [weight, p] : graf[curr_p]){
      if (odl[p]>odl[curr_p] + weight)
      {
        odl[p] = odl[curr_p] + weight;
        parent[p] = curr_p;
        q.push({odl[p], p});
      }
    }
  }
  return parent;
}

int main ()
{
  int n, m;
  cin>>n>>m;
  n++
  vector <pair<ll, int>> graf[n];
  for (int a, b , w, i=1; i<n; i++)
  {
    cin>>a>>b>>w;
    graf[a].push_back({w, b});
  }
  vector <int> ans = djikstra(graf, n, 1)
}
