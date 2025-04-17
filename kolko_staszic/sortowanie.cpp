#include <iostream>
#include <algorithm>

using namespace::std;

bool comp(int a, int b) {return a>b;}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,i;
    cin>>n;
    int tab[n];
    for(i=0;i<n;i++) cin>>tab[i];
    sort (tab,tab + n , comp);
    for(int i: tab) cout<<i<<' ';
}