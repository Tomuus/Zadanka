#include <iostream>

using namespace std;

#define nulpojnter nullptr
#define fols false

int main()
{
    ios_base::sync_with_stdio(fols);
    cin.tie(nulpojnter);
    int i,n,tmp;
    cin>>n;
    bool f=true;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        if(i+1==tmp and f) {cout<<tmp; f=fols;}
    }
    if(f) cout<<0;
}
