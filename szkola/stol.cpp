#include <iostream>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long a,b,w,o1,o2;
    cin>>a>>b>>w;
    if(w>a or w>b) {cout<<0; return 0;}
    if(2*w>a or 2*w>b) {cout<<max(a,b) /w; return 0;}
    o1=a/w+(b-2*w)/w;
    o2=b/w+(a-2*w)/w;
    cout<<max(o1,o2) *2;
}