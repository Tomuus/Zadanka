#include <iostream>

using namespace std;

unsigned long long d;

unsigned long long bins(unsigned long long s,unsigned long long p,unsigned long long l)
{
    unsigned long long m=(p+l)/2;
    if(l<p) return m;
    if(m*m*m+d*m==s) return m;
    if((m*m*m)+(d*m)>s) return bins(s,p,m-1);
    else return bins(s,m+1,l);
}

int main()
{
    unsigned long long i,n,m,tmp,ans;
    cin>>m;
    //for(i=0;i<n;i++) cin>>tab[i];
    for(i=0;i<m;i++)
    {
        cin>>d>>tmp;
        ans=bins(tmp,0,3000000);
        //cout<<ans;
        if((ans*ans*ans)+d*ans==tmp)cout<<ans;
        else cout<<"NIE";
        cout<<endl;
    }

}
