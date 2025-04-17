#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long l,m,n,i,wynik=0,usuniete=0;
    cin>>l>>m>>n;
    long long tab[n];
    for (i=0; i<n; i++) {
        cin>>tab[i];
    }
    sort(tab,tab+n);
    for(i=n-l;i<n;i++)
    {
        wynik=max(wynik,(l-usuniete)*(tab[i]-m));
        usuniete++;
    }
    cout<<wynik;
}