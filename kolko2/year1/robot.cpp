#include <iostream>

using namespace std;

struct {
    long long x;
    long long y;
}poz_first, poz_second;

int main()
{
    long long n,i,tmp1,tmp2,a,b,c,f;
    cin>>n>>poz_first.x>>poz_first.y>>poz_second.x>>poz_second.y;
    for(i=0;i<n-2;i++)
    {
        cin>>tmp1>>tmp2;
        a=poz_first.y-poz_second.y;
        b=poz_second.x-poz_first.x;
        c=(poz_first.x*poz_second.y)-(poz_second.x*poz_first.y);
        f=a*tmp1+b*tmp2+c;
        if(f<0) cout<<'P'<<endl;
        else cout<<'L'<<endl;
        poz_first=poz_second;
        poz_second.x=tmp1;
        poz_second.y=tmp2;
    }
}
