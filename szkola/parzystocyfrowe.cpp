#include <iostream>
#include <string>

using namespace::std;

string convert(long long n, long long k)
{
    string wynik;
    while(n>0)
    {
        wynik=char('0'+((n%k)*2))+wynik;
        n/=5;
    }
    return wynik;
}

int main()
{
    long long n,i,out=0;
    cin>>n;
    cout<<convert(n,5);
}