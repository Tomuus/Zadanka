#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main(){
  int n, m, k;
  for (int a, b, i; i<m; i++){
    cin>>a>>b;
    graf[a].push_back(b);
    graf[b].push_back(a);
  }
  for (int a, b, c, i=0; i<n; i++){
    cin>>a>>b>>c;
    if(gang[a]!=gang[b] and gang[a]!=0 and gang[b]!=0) {cout<<"NIE"; continue;}
    if(odl[a][b]>=)
  }
}
