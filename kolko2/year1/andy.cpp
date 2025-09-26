#include <iostream>

using namespace std;

int main()
{
    unsigned long long n,licznik=0,i=0;
    cin>>n;
    for(;n>0;n>>=1) licznik+=n&1;
    cout<<64-licznik;
}
