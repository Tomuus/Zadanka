#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long n,i,x,y,len,mod=1000000007;
    string a;
    cin>>a;
    long long hasz[a.size()+1],pow[a.size()+2];
    pow[1]=1;
    hasz[0]=0;
    for(i=1;i<=a.size();i++)
    {
        hasz[i]=(((int(a[i-1])-96)*pow[i])+hasz[i-1])%mod;
        pow[i+1]=pow[i]*27;
    }
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y>>len;
        if((hasz[x+len-1]-hasz[x-1])*pow[y-1]%mod==(hasz[y+len-1]-hasz[y-1])*pow[x-1]%mod) cout<<'=';
        if((hasz[x+len-1]-hasz[x-1])*pow[y-1]%mod<(hasz[y+len-1]-hasz[y-1])*pow[x-1]%mod) cout<<'<';
        if((hasz[x+len-1]-hasz[x-1])*pow[y-1]%mod>(hasz[y+len-1]-hasz[y-1])*pow[x-1]%mod) cout<<'>';
        cout<<endl;
    }
}
