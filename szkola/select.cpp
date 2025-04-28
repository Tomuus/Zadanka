#include <iostream>

using namespace std;

int main()
{
    long long n,i,j,mn,ind;
    cin>>n;
    int tab[n];
    for(i=0;i<n;i++) cin>>tab[i];
    for(i=0;i<n-1;i++)
    {
        mn=999999999999999999;
        for(j=i;j<n;j++)
        {
            if(tab[j]<mn)
            {
                ind=j;
                mn=tab[j];
            }
        }
        swap(tab[i],tab[ind]);
        for(j=0;j<n;j++) cout<<tab[j]<<' ';
        cout<<"\n";
    }
}
