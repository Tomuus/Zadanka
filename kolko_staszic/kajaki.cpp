#include <iostream>

using namespace std;

int ind(int tab[], int s, int k) {
    int p = 0, m, wynik = 0;
    while (p < k) {
        m = (p + k) / 2;
        if (tab[m] <= s) { 
            wynik = m; 
            p = m + 1;
        } else {
            k = m;
        }
    }
    return wynik;
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,i=0,m,tmp;
    cin>>n>>m;
    int tab[n+1];
    tab[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>tmp;
        tab[i]=max(tab[i-1],tmp);
    }
    for(i=0;i<m;i++)
    {
        cin>>tmp;
        cout<<ind(tab,tmp-1,n+1)<<' ';
    }
    return 0;
}