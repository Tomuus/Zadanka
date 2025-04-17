#include <iostream>

using namespace std;

int tab[7];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,i,tmp;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>tmp;
        tab[tmp]++;
    }
    cout<<tab[1]<<' '<<tab[2]<<' '<<tab[3]<<' '<<tab[4]<<' '<<tab[5]<<' '<<tab[6];
}