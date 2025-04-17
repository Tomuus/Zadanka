#include <iostream>

using namespace::std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if((a==c or b==d) and !(a==c and b==d)) cout<<"TAK";
    else cout<<"NIE";
}