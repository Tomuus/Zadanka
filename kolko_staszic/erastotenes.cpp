#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long i,n,j,ct=0;
    cin>>n;
    long long lim=n*log(n)+n*log(log(n))+5;
    vector <bool> prim(lim,true);
    for(i=2;ct<n;i++)
    {
        if(!prim[i]) continue;
        cout<<i<<endl;
        ct++;
        for(j=i*i;j<lim;j+=i) prim[j]=false;
    }
}
