#include <iostream>
#include <cmath>

using namespace std;

long long pkt(long long r)
{
    long long ans = 0;
    for (long long x = -r; x <= r; ++x)
    {
        long long troj=(long long)floor(sqrt((long double)r * r - (long double)x * x));
        ans+=troj+1;
    }
    return ans*4 - 4*r - 3;
}


int main()
{
    long long n;
    //cout<<pkt(8765543);
    cin >> n;
    int lewy=0,prawy=(long long)ceil(sqrt(n / M_PI)) + 1000;
    while(lewy<prawy)
    {
        long long m=(lewy+prawy)/2;
        if(pkt(m)>=n) prawy=m;
        else lewy=m+1;
    }
    cout<<lewy;
    return 0;
}
