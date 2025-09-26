#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main()
{
  int n;
  cin>>n;
  map<long long, int> box;
  for (long long tmp, i=0; i<n; i++)
  {
    cin>>tmp;
    box[tmp]++;
  }
  int ans = 0;
  for (auto& [key, val] : box)
  {
    if (box.find(key + 1) == box.end()) {ans += val; continue;}
    ans += max(val - box[key + 1], 0);
  }
  cout<<ans;
}
