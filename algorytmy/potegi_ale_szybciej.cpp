#include <iostream>

using namespace std;

const long long dziel=1000000007;

long long qp(long long base, long long pow)
{
    long long ans=1;
    base%=dziel;
    while(pow>0)
    {
        if(pow%2==1) ans=(ans*base)%dziel;
        base=(base*base)%dziel;
        pow/=2;
    }
    return ans;
}

int main()
{
    long long a,b,n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        cout<<qp(a,b)<<endl;
    }
}
