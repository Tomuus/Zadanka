#include <iostream>

using namespace::std;

int main()
{
    int n;
    cin>>n;
    while(n%10==0) n/=10;
    if((n/10)%10!=0)cout<<(n/10)%10;
    cout<<n%10;
    return 0;
}