#include <iostream>

using namespace std;

long long binsu(long long s,long long p,long long l)
{
    long long ans = l+1;
    while(p<=l)
    {
        long long m=(p+l)/2;
        if(m*m>s)
        {
            ans=m;
            l=m-1;
        }
        else p=m+1;
    }
    return ans;
}

int main()
{
    long long n;
    cin>>n;
    cout<<binsu(n,0,2000000000);
}
