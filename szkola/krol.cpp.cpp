#include <iostream>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,out=8;
    char b;
    cin>>b>>a;
    if(a==8 or a==1) out-=3;
    if(b=='a' or b=='h') out-=3;
    if(out==2) out++;
    cout<<out;
}