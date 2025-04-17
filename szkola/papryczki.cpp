#include <iostream>
#include <cmath>
using namespace::std;

int main()
{
    int n,i=0,sum=0,tmp,p=1;
    cin>>n;
    while(i<=n)
    {
        cin>>tmp;
        sum+=tmp*p;
        p*=2;
        i++;
    }
    cout<<sum+1;
    return 0;
}