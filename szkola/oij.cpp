#include <iostream>
#include <string>
using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n;
    int cur=1,w=0;
    cin>>n;
    for(auto i : n)
    {
        if(i=='o' and cur==1) cur++;
        if(i=='i' and cur==2) cur++;
        if(i=='j' and cur==3)
        {
            cur=1;
            w++;
        }
    }
    if(w==0) cout<<"NIE";
    else cout<<w;
}