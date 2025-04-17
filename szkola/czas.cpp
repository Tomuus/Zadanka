#include <iostream>

using namespace::std;

int main()
{
    int a,b,c;
    cin>>a;
    b=a/3600;
    c=a/60-60*b;
    cout<<b<<'g'<<c<<'m'<<a%3600-60*c<<'s';
}