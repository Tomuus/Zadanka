#include <iostream>

using namespace std;

int tab[38];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,m,j,i,l=0,tmp ;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        for(j=0;j<m;j++)
        {
            cin>>tmp;
            l+=tmp;
        }
        cout<<l<<endl;
        l=0;
    }
}