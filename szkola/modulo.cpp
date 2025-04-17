#include <iostream>

using namespace std;

int tab[38];

int main()
{
    long long n,i=1,l=0;
    for(i=0;i<15;i++)
    {
        cin>>n;
        if(tab[n%37]==0) l++;
        tab[n%37]++;
    }
    cout<<l;
}