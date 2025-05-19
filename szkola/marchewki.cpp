#include <iostream>
#include <cmath>

using namespace std;

long long pkt(long long r)
{
    long long ans = 0;
    for (long long x = 0; x <= r; ++x)
    {
        long long y_limit = (long long)floor(sqrt((long double)r * r - (long double)x * x));
        ans += 4 * y_limit + 1;
    }
    return ans-r;
}


long long bins(long long s,long long p,long long l)
{
    long long m=(p+l)/2;
    if(l<p) return p;
    if(pkt(m)==s) return m;
    if(pkt(m)>s) return bins(s,p,m-1);
    else return bins(s,m+1,l);
}


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    long long n;
    //cout<<pkt(2);
    cin >> n;
    cout<<bins(n,0,1000000);
    return 0;
}
