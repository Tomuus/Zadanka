#include <iostream>

using namespace::std;

int main()
{
    int a,b,c,w=0,i;
    cin>>a>>b;
    c=a/b;
    if(a%b!=0) c++;
    cout<<c;
}