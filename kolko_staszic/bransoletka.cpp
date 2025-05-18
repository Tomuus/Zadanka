#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long i,n,tmp,ans=0;
    priority_queue<long long, vector<long long>, greater<long long>> tab;
    cin>>n;
    for (i=0;i<n;i++) {
        cin>>tmp;
        tab.push(tmp);
    }
    for(i=1;i<n;i++)
    {
        tmp=tab.top();
        tab.pop();
        ans+=tmp+tab.top();
        tab.push(tmp+tab.top());
        tab.pop();
    }
    cout<<ans;
    return 0;
}
