#include <iostream>
#include <iostream>

using namespace::std;

bool sk[1000007];
long long tab[1000007];
int main()
{
    long long n,a,b,c,i=0;
    cin>>n;
    cin>>a>>b>>c;
    while(i<n)
    {
        cin>>tab[i];
        i++;
    }
    i=0;
    sk[0]=true;
    while(i<n)
    {
        if(sk[i])
        {
            if(i+a<n and tab[i+a]==0) sk[i+a]=true;
            if(i+b<n and tab[i+b]==0) sk[i+b]=true;
            if(i+c<n and tab[i+c]==0) sk[i+c]=true;
        }
        i++;
    }
    n--;
    while(n>=0)
    {
        if(sk[n]){cout<<n+1; return 0;}
        n--;
    }
}
