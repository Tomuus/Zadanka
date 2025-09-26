#include <iostream>
#include <list>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int ans = n;
  list<long long> box;
  for (long long tmp, prev=-1, pcount=0, ccount=1, i=0; i<n; i++)
  {
    cin>>tmp;
    box.push_back(tmp);
    if (box.front() < box.back())
    {
      ans--;
      box.pop_front();
    }
  }
  cout<<ans;
}
