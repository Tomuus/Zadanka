#include <iostream>

using namespace std;

int main()
{
    long long i,n,tmp,curr=0,best=-1,mn=9223372000000000000;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        curr+=tmp;
        mn=min(mn,curr);
        best=max(best,curr-mn);
    }
    cout<<best;
}
