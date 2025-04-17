#include <iostream>

using namespace std;

int nwd (long long a,long long b)
{
    if(a%b==0) return b;
    return nwd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a,n,i=0,poprzednia;
    cin>>n;
    while(i<n)
    {
        cin>>a;
        if(i==0) poprzednia=a;
        poprzednia=nwd(a,poprzednia);
        i++;
    }
    cout<<poprzednia;
    return 0;
}