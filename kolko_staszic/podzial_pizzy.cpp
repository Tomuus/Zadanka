#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,i,p=-1,k=-1,sum=0,m=0,mn=10000000000000;
    cin>>n;
    int tab[n];
    for(i=0;i<n;i++)
    {
        cin>>tab[i];
        sum+=tab[i];
    }
    //cout<<sum;
    while(p<n)
    {
        if(m<sum-m and k<n-1)
        {
            k++;
            m+=tab[k];
            //cout<<'+';
        }
        else
        {
            p++;
            m-=tab[p];
            //cout<<'-';
        }
        mn=min(mn,abs(m-(sum-m)));
        //cout<<m;
    }
    cout<<mn;
}