#include <iostream>
#include <cmath>

using namespace std;

long long pkt(long long r)
{
    long long ans = 0;
    for (long long x = -r; x <= r; ++x)
    {
        long long max_y = (long long)floor(sqrt((long double)r * r - (long double)x * x));
        ans += 2 * max_y + 1;
    }
    return ans;
}

int bins(int s,int p,int l)
{
    int m=(p+l)/2;
    if(l<p) return m+1;
    if(pkt(m)==s) return m;
    if(pkt(m)>s) return bins(s,p,m-1);
    else return bins(s,m+1,l);
}


int main()
{
    long long n;
    //cout<<pkt(2);
    cin >> n;
    cout<<bins(n,0,1000000);
    return 0;
}
