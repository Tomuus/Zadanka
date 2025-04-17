#include <iostream>

using namespace std;

long long nwd (long long a,long long b)
{
    if(a%b==0) return b;
    return nwd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,i,pop,tmp;
    cin>>n>>pop;
    for(i=1;i<n;i++)
    {
        cin>>tmp;
        pop=nwd(pop,tmp);
    }
    cout<<pop;
}