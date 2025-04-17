#include <iostream>

using namespace std;

int tab[38];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,i,tmp;
    cin>>n;
    long long tab[n];
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        if(i%2==0) cout<<tmp<<' ';
        else tab[i]=tmp;
    }
    cout<<endl;
    for(i=1;i<n;i+=2) cout<<tab[i]<<' ';
}