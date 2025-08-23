#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

vector <ll> djikstra (vector<pair<ll, int>> graf[], int size, int start){
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
  vector <ll> odl(size, 999999999);
  odl[start] = 0;
  q.push({0, start});
  while(!q.empty()){

    int curr_p = q.top().second, curr_w = q.top().first;
    q.pop();

    for (auto [weight, p] : graf[curr_p]){
      if (odl[p]>odl[curr_p] + weight)
      {
        odl[p] = odl[curr_p] + weight;
        q.push({odl[p], p});
      }
    }
  }
  return odl;
}

int main(){
  int n;
  cin>>n;
  n++;
  vector<int> ceny = {0};
  for(int tmp, i=1; i<n; i++){
    cin>>tmp;
    ceny.push_back(tmp);
  }
  int m;
  cin>>m;
  vector < pair<ll, int> > przem[n];
  vector < pair<ll, int> > powrot[n];
  for (int a, b, cena, i=0; i<m; i++){
    cin>>a>>b>>cena;
    przem[a].push_back({cena, b});
    powrot[b].push_back({cena, a});
  }
  vector <ll> in_price;
  vector <ll> out_price;
  in_price = djikstra(przem, n, 1);
  out_price = djikstra(powrot, n, 1);
  ll ans = ceny[1]/2;
  for(int i=1; i<n; i++){ 
    //cout<<ceny[i]/2<<' '<<in_price[i]<<' '<<out_price[i]<<endl;
    if(in_price[i] == 0 or out_price[i] == 0) continue;
    ans=min(ceny[i]/2 + in_price[i] + out_price[i], ans);
  }
  cout<<ans;
}
