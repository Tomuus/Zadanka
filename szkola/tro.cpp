#include <iostream>

using namespace::std;

int main()
{
    int a,b,c;
    cin>>a>>b;
    cout<<a*b/2;
    if(a*b%2!=0) cout<<".5";
    else cout<<".0";
}