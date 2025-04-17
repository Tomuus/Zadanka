#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,i,x,w,l;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>w;
        l=0;
        while(x<w) {x*=2; l++;}
        cout<<l<<endl;
    }
}