#include <iostream>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,n,tmp,a,b;
    bool state=true;
    cin>>n;
    if(n==1) {cout<<"TAK"; return 0;}
    cin>>a>>b;
    if(n==2 and a==b) {cout<<"NIE"; return 0;}
    if (a==b) {cout<<"NIE"; return 0;}
    state=a<b;
    for(i=2;i<n;i++)
    {
        cin>>tmp;
        if(tmp==b) {cout<<"NIE"; return 0;}
        if(!state and tmp>b) {cout<<"NIE"; return 0;}
        if (state and tmp<b) state=false;  
        b=tmp;
    }
    cout<<"TAK";
}