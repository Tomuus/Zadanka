#include <iostream>

using namespace::std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i,n,x,y,xmx=-9999999,xmn=9999999,ymx=-9999999,ymn=9999999,a,b;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>x>>y;
        xmx=max(xmx,x);
        xmn=min(xmn,x);
        ymx=max(ymx,y);
        ymn=min(ymn,y);
    }
    a=xmx-xmn;
    b=ymx-ymn;
    //cout<<xmx<<' '<<xmn<<' '<<ymx<<' '<<ymn;
    cout<<(a*2)+(b*2);
}